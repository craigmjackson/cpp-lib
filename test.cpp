#include <iostream>
#include <string>
#include "misc.h"
#include "io.h"
#include "json.h"
#include "time.h"
#include <vector>

using namespace std;

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

void test_split() {
    cout << "test_split()" << endl;
    string bunch_of_text = "Honey bunches of      text of randomness";
    cout << "string: \"" << bunch_of_text << "\"" << endl;
    cout << "split on whitespace: " << endl;
    vector<string> whitespace_split = split(bunch_of_text);
    for ( string element: whitespace_split ) {
        cout << "  element: \"" << element << "\"" << endl;
    }
    cout << "split on \"o\": " << endl;
    vector<string> o_split = split(bunch_of_text, 'o');
    for ( string element: o_split ) {
        cout << " element: \"" << element << "\"" << endl;
    }
    cout << endl << endl;
}

void test_get_os_info() {
    cout << "test_get_os_info()" << endl;
    OsInfo os_info = get_os_info();
    cout << "  os_type: \"" << os_info.os_type << "\"" << endl;
    cout << "  architecture: \"" << os_info.architecture << "\"" << endl;
    cout << "  kernel_version_long: \"" << os_info.kernel_version_long << "\"" << endl;
    cout << "  kernel_version: \"" << os_info.kernel_version << "\"" << endl;
    cout << "  hostname: \"" << os_info.hostname << "\"" << endl;
    cout << "  domain_name: \"" << os_info.domain_name << "\"" << endl;
    cout << endl << endl;
}

void test_ascii_to_hex() {
    cout << "text_ascii_to_hex()" << endl;
    string cooka = "I cooka da pizza";
    cout << "  ascii: " << cooka << endl;
    string cooka_hex = ascii_to_hex(cooka);
    cout << "  hex: " << cooka_hex << endl;
    cout << endl << endl;
}

void test_hex_to_ascii() {
    cout << "test_hex_to_ascii()" << endl;
    string cooka_hex = "4920636f6f6b612064612070697a7a61";
    cout << "  hex: " << cooka_hex << endl;
    string cooka = hex_to_ascii(cooka_hex);
    cout << "  ascii: " << cooka << endl;
    cout << endl << endl;
}

void test_get_random_int() {
    cout << "test_get_random_int()" << endl;
    int random_int = get_random_int(1, 50);
    cout << "Random int between 1 and 50: " << random_int << endl;
    cout << endl << endl;
}

void test_parse_json() {
    cout << "test_parse_json()" << endl;
    string json_string = R"(
        {
            "hello": "world",
            "other": [
                "boring",
                "phrases"
            ]
        }
    )";
    json json_object = parse_json(json_string);
    cout << "hello: " << json_object["hello"] << endl;
    cout << "other[0]: " << json_object["other"][0] << endl;
    cout << "other[1]: " << json_object["other"][1] << endl;
    cout << endl << endl;
}

void test_generate_json() {
    cout << "test_generate_json()" << endl;
    json json_object = {
        {"hello", "world"},
        {"other", {
            "boring",
            "phrases"
        }}
    };
    cout << "  4 spaces (default):" << endl;
    cout << generate_json(json_object);
    cout << "  8 spaces (specified):" << endl;
    cout << generate_json(json_object, 8);
    cout << endl << endl;
}

// void test_get_time_string() {
//     time_t unix_time = time(0);
//     cout << get_time_string(unix_time) << endl;
// }

void test_get_unix_time() {
    cout << "get_unix_time()" << endl;
    cout << get_unix_time() << endl;
    cout << endl << endl;
}

// void test_sleep() {
//     cout << "Sleeping for 5 seconds..." << endl;
//     sleep(5);
//     cout << "Done" << endl;
// }

int main() {
    test_run_command();
    test_return_output();
    test_split();
    test_get_os_info();
    test_ascii_to_hex();
    test_hex_to_ascii();
    test_get_random_int();
    test_parse_json();
    test_generate_json();
    // test_get_time_string();
    test_get_unix_time();
    // test_sleep();
    return 0;
}
