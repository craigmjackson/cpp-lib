#include <string>
#include <cstring>

using namespace std;

void string_to_c_str(string string_val, char *c_string_val) {
    strcpy(c_string_val, string_val.c_str());
}
