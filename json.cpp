#include <string>
#include "deps/json.hpp"

using namespace std;
using json = nlohmann::json;

json parse_json(string json_string) {
    json json_object = json::parse(json_string);
    return json_object;
};

string generate_json(json json_object) {
    string json_string = json_object.dump(4);
    return json_string;
};
string generate_json(json json_object, int spaces) {
    string json_string = json_object.dump(spaces);
    return json_string;
};

