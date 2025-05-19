#include <iostream>
#include "misc.h"
#include <typeinfo>

using namespace std;

void test_string_to_c_str() {
    string hello = "Hello, World";
    char hello_c_string[1024];
    string_to_c_str(hello, hello_c_string);
    cout << "Type of hello: " << typeid(hello).name() << endl;
    cout << "Value of hello: " << hello << endl;
    cout << "Type of hello_c_string: " << typeid(hello_c_string).name() << endl;
    cout << "Value of hello_c_string: ";
    printf("%s", hello_c_string);
    cout << endl;
}

int main() {
    test_string_to_c_str();
    return 0;
}
