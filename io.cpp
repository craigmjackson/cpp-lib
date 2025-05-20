#include <string>
#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include "io.h"
#include "misc.h"

using namespace std;

string get_cwd() {
    char path[1024];
    if (getcwd(path, 1024) != NULL) {
        return string(path);
    }
    cerr << "Error gettting current working directory";
    return "";
}

// ShellResult run_command(string command, string cwd) {
//     if (cwd == "") {
//         system(command);
//     } else {
//         char path[PATH_MAX];
//         string_to_c_str(command, path);
//         string getcwd(path, PATH_MAX);
//         chdir(path);
//         system(command);
//         chdir(existing_cwd);
//     }
//
// }
