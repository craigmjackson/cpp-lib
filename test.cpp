#include <iostream>
#include <string>
#include <vector>
#include "misc.h"
#include "io.h"
#include "json.h"
#include "time.h"

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

void test_write_file() {
    cout << "test_write_file()" << endl;
    string str = "Test string\nTest after newline\n";
    cout << "Contents of string:" << endl;
    cout << str << endl;
    write_file("/tmp/test_io.txt", str);
    cout << endl << endl;
}

void test_read_file() {
    cout << "test_read_file()" << endl;
    string contents = read_file("/tmp/test_io.txt");
    cout << "Contents of file:" << endl;
    cout << contents << endl;
    cout << endl << endl;
}

void test_append_file() {
    cout << "test_append_file()" << endl;
    string str = "Test string\nTest after newline\n";
    cout << "Contents of string:" << endl;
    cout << str << endl;
    append_file("/tmp/test_io.txt", str);
    str.append(str);
    cout << "Contents of string after doubling:" << endl;
    cout << str << endl;
    string after_append = read_file("/tmp/test_io.txt");
    if (str.compare(after_append) == 0) {
        cout << "str is identical to after_append" << endl;
    } else {
        cout << "str is different from after_append" << endl;
    }
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

void test_get_unix_time() {
    cout << "get_unix_time()" << endl;
    time_t unix_time = get_unix_time();
    cout << "Unix time: " << unix_time << endl;
    cout << endl << endl;
}

void test_get_time_string() {
    cout << "get_time_string()" << endl;
    time_t unix_time = get_unix_time();
    string time_string = get_time_string(unix_time);
    string time_string_specified = get_time_string(1748154207);
    cout << "Time string (now): " << time_string << endl;
    cout << "Time string specified: " << time_string_specified << endl;
    cout << endl << endl;
}

void test_log() {
    cout << "test_log()" << endl;
    run_command("rm -f /tmp/test.log", "", false);
    LogLevel log_level = LogLevel::INFO;
    log("/tmp/test.log", "Test log entry", log_level);
    string logfile_text = read_file("/tmp/test.log");
    cout << "Logfile text: " << endl;
    cout << logfile_text << endl;
    cout << endl << endl;
}

void test_file_exists() {
    cout << "test_file_exists()" << endl;
    cout << "Creating file /tmp/file.ext..." << endl;
    write_file("/tmp/file.ext", "file.ext");
    if (file_exists("/tmp/file.ext")) {
        cout << "/tmp/file.ext exists" << endl;
    } else {
        cout << "/tmp/file.ext does not exist" << endl;
    }
    if (file_exists("/tmp/file.extension")) {
        cout << "/tmp/file.extension does not exist" << endl;
    }
    run_command("rm -f /tmp/file.ext", "", false);
    cout << "Creating directory /tmp/directory..." << endl;
    run_command("mkdir -p /tmp/directory", "", false);
    if (file_exists("/tmp/directory")) {
        cout << "/tmp/directory exists" << endl;
    } else {
        cout << "/tmp/directory does not exist" << endl;
    }
    if (file_exists("/tmp/not_a_directory")) {
        cout << "/tmp/not_a_directory exists" << endl;
    } else {
        cout << "/tmp/not_a_directory does not exist" << endl;
    }
    run_command("rm -rf /tmp/directory", "", false);
    cout << endl << endl;
}

void test_get_symlink_target() {
    cout << "test_get_symlink_target()" << endl;
    run_command("touch /tmp/symlink_target", "", false);
    run_command("ln -sf /tmp/symlink_target /tmp/symlink_source", "", false);
    string symlink_source = get_symlink_target("/tmp/symlink_source");
    cout << "Symlink target for /tmp/symlink_source: " << symlink_source << endl;
    string symlink_target = get_symlink_target("/tmp/symlink_target");
    cout << "Symlink target for /tmp/symlink_target: " << symlink_target << endl;
    string fake_file = get_symlink_target("/tmp/fake_file");
    cout << "Symlink target for /tmp/fake_file: " << fake_file << endl;
    cout << endl << endl;
}

void test_create_dir() {
    cout << "test_create_dir()" << endl;
    cout << "Checking existence before creation..." << endl;
    if (file_exists("/tmp/test/dir")) {
        cout << "Directory /tmp/test/dir exists" << endl;
    } else {
        cout << "Directory /tmp/test/dir does not exist" << endl;
    }
    cout << "Creating directory /tmp/test/dir..." << endl;
    create_dir("/tmp/test/dir");
    if (file_exists("/tmp/test/dir")) {
        cout << "Directory /tmp/test/dir exists" << endl;
    } else {
        cout << "Directory /tmp/test/dir does not exist" << endl;
    }
    cout << endl << endl;
}

void test_remove_dir() {
    cout << "test_remove_dir()" << endl;
    cout << "Checking existence before removal..." << endl;
    if (file_exists("/tmp/test/dir")) {
        cout << "Directory /tmp/test/dir exists" << endl;
    } else {
        cout << "Directory /tmp/test/dir does not exist" << endl;
    }
    cout << "Removing directory /tmp/test/dir..." << endl;
    remove_dir("/tmp/test/dir");
    if (file_exists("/tmp/test/dir")) {
        cout << "Directory /tmp/test/dir exists" << endl;
    } else {
        cout << "Directory /tmp/test/dir does not exist" << endl;
    }
    cout << endl << endl;
}

void test_copy_dir() {
    cout << "test_copy_dir()" << endl;
    cout << "Checking for source existence..." << endl;
    if (file_exists("/tmp/test/source/dir") == 0) {
        cout << "Populating source dir..." << endl;
        create_dir("/tmp/test/source/dir");
        write_file("/tmp/test/source/dir/file.txt", "test text");
    }
    if (file_exists("/tmp/test/target/dir") == 1) {
        cout << "Directory /tmp/test/target/dir exists" << endl;
    } else {
        cout << "Directory /tmp/test/target/dir does not exist" << endl;
    }
    if (file_exists("/tmp/test/target/dir/file.txt")) {
        cout << "File /tmp/test/target/dir/file.txt exists" << endl;
    } else {
        cout << "File /tmp/test/target/dir/file.txt does not exist" << endl;
    }
    cout << "Creating /tmp/test/target..." << endl;
    create_dir("/tmp/test/target");
    cout << "Copying /tmp/test/source/dir/ to /tmp/test/target/dir/..." << endl;
    copy_dir("/tmp/test/source/dir", "/tmp/test/target/dir");
    if (file_exists("/tmp/test/target/dir")) {
        cout << "Directory /tmp/test/target/dir exists" << endl;
    } else {
        cout << "Directory /tmp/test/target/dir does not exist" << endl;
    }
    if (file_exists("/tmp/test/target/dir/file.txt")) {
        cout << "File /tmp/test/target/dir/file.txt exists" << endl;
    } else {
        cout << "File /tmp/test/target/dir/file.txt does not exist" << endl;
    }
    remove_dir("/tmp/test/target/dir");
    cout << endl << endl;
}


int main() {
    test_run_command();
    test_return_output();
    test_write_file();
    test_read_file();
    test_append_file();
    test_split();
    test_get_os_info();
    test_ascii_to_hex();
    test_hex_to_ascii();
    test_get_random_int();
    test_parse_json();
    test_generate_json();
    test_get_unix_time();
    test_get_time_string();
    test_log();
    test_file_exists();
    test_get_symlink_target();
    test_create_dir();
    test_remove_dir();
    test_copy_dir();
    return 0;
}
