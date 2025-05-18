#include <string>
using namespace std;

#ifndef MISC_H
#define MISC_H

struct Platform {
    string os_type;
    string architecture;
    string kernel_version_long;
    string kernel_version;
};

Platform get_platform();
char split_whitespace(string string_val);
string ascii_from_hex(string hex_val);
string hex_from_ascii(string ascii_val);
int get_random_int(int min, int max);

#endif // MISC_H
