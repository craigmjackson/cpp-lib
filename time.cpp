// #include <string>
#include <chrono>

using namespace std;

// string get_time_string(int unix_time) {
//     time_t result = time((time_t)unix_time);
//     cout << "get_time_string()" << endl;
//     return "";
// }

int get_unix_time() {
    auto now = chrono::system_clock::now();
    int unix_time_int = chrono::duration_cast<chrono::seconds>(now.time_since_epoch()).count();
    return unix_time_int;
}
// void sleep(int seconds) {
//     cout << "sleep()" << endl;
// }
