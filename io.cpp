#include <ctime>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <iostream>
#include <filesystem>
#include "io.h"
#include "misc.h"
#include "time.h"

using namespace std;

void print_shell_result(ShellResult result) {
    cout << "Result:" << endl;
    cout << "  command: \"" << result.command << "\"" << endl;
    cout << "  cwd: \"" << result.cwd << "\"" << endl;
    cout << "  return_code: " << result.return_code << endl;
    cout << "  output:" << endl;
    cout << result.output << endl;

}

ShellResult run_command(string command, string cwd, bool debug) {
    ShellResult result;
    result.command = command;
    char command_c_string[1024];
    strcpy(command_c_string, command.c_str());
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
        strcpy(cwd_c_string, cwd.c_str());
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
    char buffer[128];
    result.cwd = (cwd == "") ? string(existing_cwd_c_string) : cwd;
    if (cwd != "") {
        getcwd(existing_cwd_c_string, 1024);
        strcpy(cwd_c_string, cwd.c_str());
        chdir(cwd_c_string);
    }
    if (debug) {
        cout << "Running command \"" << command << "\" from directory \"" << result.cwd << "\"..." << endl;
    }
    handle = popen(command_c_string, "r");
    if (handle == NULL) {
        cout << "Could not open handle for running command: \"" << command << "\"";
        return result;
    }
    while (fgets(buffer, sizeof(buffer), handle) != nullptr) {
        result.output.append(buffer);
    }
    result.return_code = pclose(handle);
    if (cwd != "") {
        chdir(existing_cwd_c_string);
    }
    return result;
}

void write_file(string path, string str) {
    ofstream handle(path);
    if (handle.is_open()) {
        handle << str;
        handle.close();
    } else {
        cout << "Unable to open file \"" << path << "\" for writing";
    }
}

void append_file(string path, string str) {
    ofstream handle(path, ios_base::app);
    if (handle.is_open()) {
        handle << str;
        handle.close();
    } else {
        cout << "Unable to open file \"" << path << "\" for appending";
    }
}


string read_file(string path) {
    string contents;
    string line;
    ifstream handle(path);
    if (handle.is_open()) {
        while (getline(handle, line)) {
            contents.append(line);
            contents.append("\n");
        }
        handle.close();
        return contents;
    } else {
        cout << "Unable to open file \"" << path << "\" for reading";
    }
    return "";
}

string getLogLevelString(LogLevel log_level) {
    switch (log_level) {
        case LogLevel::TRACE:
            return "TRACE";
        case LogLevel::DEBUG:
            return "DEBUG";
        case LogLevel::INFO:
            return "INFO";
        case LogLevel::WARN:
            return "WARN";
        case LogLevel::ERROR:
            return "ERROR";
        case LogLevel::FATAL:
            return "FATAL";
        default:
            return "UNKNOWN";
    }
}

void log(string log_file, string text, LogLevel log_level) {  
    time_t unix_time = get_unix_time();
    string time_string = get_time_string(unix_time);
    ostringstream entry;
    entry << time_string << " " << getLogLevelString(log_level) << ": " << text << endl;
    cout << entry.str();
    append_file(log_file, entry.str());
}

bool file_exists(string path) {
    return filesystem::exists(path);
}

string get_symlink_target(string path) {
    if (file_exists(path)) {
        if (filesystem::is_symlink(path)) {
            return filesystem::read_symlink(path);
        }
        cout << "\"" << path << "\" is not a symlink" << endl;
        return "";
    }
    cout << "\"" << path << "\" does not exist" << endl;
    return "";
}
