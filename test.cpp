#include <iostream>
#include "misc.h"
#include "io.h"
#include <typeinfo>

using namespace std;

void test_string_to_c_str() {
    cout << "test_string_to_c_str()" << endl;
    string hello = "Hello, World";
    char hello_c_string[1024];
    string_to_c_str(hello, hello_c_string);
    cout << "Type of hello: " << typeid(hello).name() << endl;
    cout << "Value of hello: " << hello << endl;
    cout << "Type of hello_c_string: " << typeid(hello_c_string).name() << endl;
    cout << "Value of hello_c_string: ";
    printf("%s", hello_c_string);
    cout << endl << endl << endl;
}

void test_run_command() {
    cout << "test_run_command()" << endl;
    cout << "Running ls -l..." << endl;
    ShellResult result = run_command("ls -l", "", false);
    print_shell_result(result);
    cout << endl;
    cout << "Running ls -l with debug..." << endl;
    ShellResult result_with_debug = run_command("ls -l", "", true);
    print_shell_result(result_with_debug);
    cout << endl;
    cout << "Running ls -l from /..." << endl;
    ShellResult result_with_cwd = run_command("ls -l", "/", false);
    print_shell_result(result_with_cwd);
    cout << endl;
    cout << "Running ls -l from / with debug..." << endl;
    ShellResult result_with_cwd_and_debug = run_command("ls -l", "/", true);
    print_shell_result(result_with_cwd_and_debug);
    cout << endl << endl << endl;
}

void test_return_output() {
    cout << "test_return_output()" << endl;
    cout << "Running ls -l..." << endl;
    ShellResult result = return_output("ls -l", "", false);
    print_shell_result(result);
    cout << endl;
    cout << "Running ls -l with debug..." << endl;
    ShellResult result_with_debug = return_output("ls -l", "", true);
    print_shell_result(result_with_debug);
    cout << endl;
    cout << "Running ls -l from /..." << endl;
    ShellResult result_with_cwd = return_output("ls -l", "/", false);
    print_shell_result(result_with_cwd);
    cout << endl;
    cout << "Running ls -l from / with debug..." << endl;
    ShellResult result_with_cwd_and_debug = return_output("ls -l", "/", true);
    print_shell_result(result_with_cwd_and_debug);
    cout << endl << endl;
}

int main() {
    test_string_to_c_str();
    test_run_command();
    test_return_output();
    return 0;
}
