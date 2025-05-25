#include <ctime>
#include <string>
using namespace std;

#ifndef TIME_H
#define TIME_H

string get_time_string(time_t unix_time);
time_t get_unix_time();
void sleep(int seconds);

#endif // TIME_H
