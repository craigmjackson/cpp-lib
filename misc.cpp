#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>

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


