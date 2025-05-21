#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split_whitespace(string input) {
    vector<string> tokens;
    istringstream iss(input);
    string token;
    while (iss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}
