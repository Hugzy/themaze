//
// Created by Magida on 10-11-2018.
//

#include "json_routine.h"
#include <sstream>
#include <fstream>

using namespace json11;

Json read_from_file() {
    std::ifstream in;
    in.open("map.json");
    std::stringstream sstr;
    sstr << in.rdbuf();
    std::string json_str = sstr.str();
    auto err = std::string{"error parsing"};
    auto json = Json::parse(json_str, err);
    return json;
}

const bool write_to_file(const std::string &map, const std::string &file) {
    std::ofstream out;
    out.open("map.json");
    out << map;
    out.close();
    return true;
}

const bool write_to_file(const Json &map, const std::string &file) {
    write_to_file(map.dump(), file);
}

const bool append_to_file(const Json &map, const std::string &file){
    auto json = read_from_file();
    auto items = json.object_items();
    for(auto pair : map.object_items()){
        items.insert(pair);
    }

    auto jjson = Json::object{items};
    write_to_file(jjson);
}

