#include <string>
#include <vector>
using namespace std;

#ifndef MISC_H
#define MISC_H

struct OsInfo {
    string os_type = ""; // osInfo.sysname
    string architecture = ""; // osInfo.machine
    string kernel_version_long = ""; // osInfo.version
    string kernel_version = ""; // osInfo.release
    string hostname = "";
    string domain_name = "";
};

vector<string> split(string string_val);
vector<string> split(string string_val, char delimiter);
OsInfo get_os_info();
string ascii_to_hex(string ascii_val);
string hex_to_ascii(string hex_val);
int get_random_int(int min, int max);

#endif // MISC_H
