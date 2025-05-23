#include <bits/stdc++.h>
#include <iostream>
#include <sys/utsname.h>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <vector>
#include "misc.h"

using namespace std;

vector<string> split(string input) {
    string token;
    vector<string> tokens;
    istringstream iss(input);
    while (iss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

vector<string> split(string input, char delimiter) {
    string token;
    vector<string> tokens;
    stringstream ss(input);
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

OsInfo get_os_info() {
    struct utsname sys_os_info{};
    uname(&sys_os_info);
    OsInfo os_info;
    os_info.os_type = sys_os_info.sysname;
    os_info.architecture = sys_os_info.machine;
    os_info.kernel_version_long = sys_os_info.version;
    os_info.kernel_version = sys_os_info.release;
    os_info.hostname = sys_os_info.nodename;
    os_info.domain_name = sys_os_info.domainname;
    return os_info;
}

string hex_to_ascii(string hexa) {
    string ascii = "";
    for (int i = 0; i < hexa.length(); i += 2) {
        string element = hexa.substr(i, 2);
        char ascii_char = stoul(element, nullptr, 16);
        ascii += ascii_char;
    }
    return ascii;
}

string ascii_to_hex(string ascii) {
    ostringstream stream;
    for (char character : ascii) {
        stream << hex << setw(2) << std::setfill('0') << static_cast<int>(character);
    }
    return stream.str();
}
