#include <string>
using namespace std;

#ifndef IO_H
#define IO_H

struct ShellResult {
    int return_code = -1;
    string command = "";
    string cwd = "";
    string output = "";
};

void print_shell_result(ShellResult result);
ShellResult run_command(string command, string cwd, bool debug);
ShellResult return_output(string command, string cwd, bool debug);
string read_file(string path);
void write_file(string path, string text);
void append_file(string path, string text);
void log(string path, string text);
int file_exists(string path);
string get_symlink_target(string path);
void create_dir(string path);
void remove_dir(string path);
void copy_dir(string src_path, string src_dest);
void copy_file(string src_path, string src_dest);
void create_archive(string dir_path, string archive_path);
void extract_archive(string archive_path, string extract_path);
string get_file_dir(string path);

#endif // IO_H
