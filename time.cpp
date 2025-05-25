#include <chrono>
#include <sstream>
#include <string>
#include <csignal>
#include "time.h"

using namespace std;

string get_time_string(time_t unix_time) {
    tm gmt = *gmtime(&unix_time);
    stringstream string_stream;
    string format = "%Y-%m-%d-%H:%M:%S";
    string_stream << put_time(&gmt, format.c_str());
    return string_stream.str();
}

time_t get_unix_time() {
    chrono::time_point now = chrono::system_clock::now();
    time_t unix_time = chrono::system_clock::to_time_t(now);
    return unix_time;
}
