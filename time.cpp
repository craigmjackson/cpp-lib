#include <chrono>
#include <csignal>
#include <iostream>
#include "time.h"

using namespace std;

void get_time_string(int unix_time) {
    chrono::time_point timepoint = chrono::system_clock::from_time_t(unix_time);
    cout << "timepoint" << endl;
    // TODO: Make a string out of this timepoint
}

int get_unix_time() {
    chrono::time_point now = chrono::system_clock::now();
    int unix_time = chrono::system_clock::to_time_t(now);
    return (int)unix_time;
}
