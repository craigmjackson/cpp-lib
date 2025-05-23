#include <string>
#include "deps/json.hpp"
using namespace std;
using json = nlohmann::json;

#ifndef JSON_H
#define JSON_H

json parse_json(string json_string);
string generate_json(json json_object);
string generate_json(json json_object, int spaces);

#endif // JSON_H
