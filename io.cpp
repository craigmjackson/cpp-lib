#include <string>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <iostream>
#include "io.h"
#include "misc.h"

using namespace std;

void print_shell_result(ShellResult result) {
    cout << "Result:" << endl;
    cout << "  command: \"" << result.command << "\"" << endl;
    cout << "  cwd: \"" << result.cwd << "\"" << endl;
    cout << "  output: \"" << result.output << "\"" << endl;
    cout << "  return_code: " << result.return_code << endl;
}

ShellResult run_command(string command, string cwd, bool debug) {
    ShellResult result;
    result.command = command;
    char command_c_string[1024];
    string_to_c_str(command, command_c_string);
    char existing_cwd_c_string[1024];
    getcwd(existing_cwd_c_string, 1024);
    if (cwd == "") {
        result.cwd = string(existing_cwd_c_string);
        if (debug) {
            cout << "Running command \"" << command << "\" from directory \"" << result.cwd << "\"..." << endl;
        }
        result.return_code = system(command_c_string);
    } else {
        result.cwd = cwd;
        char cwd_c_string[1024];
        string_to_c_str(cwd, cwd_c_string);
        chdir(cwd_c_string);
        if (debug) {
            cout << "Running command \"" << command << "\" from directory \"" << cwd << endl;
        }
        result.return_code = system(command_c_string);
        chdir(existing_cwd_c_string);
    }
    return result;
}

ShellResult return_output(string command, string cwd, bool debug) {
    ShellResult result;
    char command_c_string[1024];
    int return_code;
    char path[1024];
    char existing_cwd_c_string[1024];
    char cwd_c_string[1024];
    FILE *handle;

    strcpy(command_c_string, command.c_str());
    result.command = command;
    if (debug) {
        cout << "Running command \"" << command << "\" from directory \"" << result.cwd << "\"..." << endl;
    }
    result.cwd = (cwd == "") ? string(existing_cwd_c_string) : cwd;
    if (cwd != "") {
        getcwd(existing_cwd_c_string, 1024);
        strcpy(cwd_c_string, cwd.c_str());
        chdir(cwd_c_string);
    }
    handle = popen(command_c_string, "r");
    if (handle == NULL) {
        cout << "Could not open handle for running command: \"" << command << "\"";
        return result;
    }
    // TODO: Check into wait() call to handle return codes elegantly
    result.return_code = pclose(handle);
    if (cwd != "") {
        chdir(existing_cwd_c_string);
    }
    return result;
}

