#include "definitions.h"
#include <iostream>
#include <string>
#include "fmt/format.h"
#include "include/catch2/catch.hpp"
#include "include/json11/json11.hpp"
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace json11;

Json read_from_file() {
    std::ifstream in;
    in.open("map.json");
    std::stringstream sstr;
    sstr << in.rdbuf();
    std::string json_str = sstr.str();
    auto err = std::string{"error parsing"};
    auto json = Json::parse(json_str, err);
    fmt::print("value1 is: {}", json["key1"].string_value());
    return json;
}

bool write_to_file(const std::string &map, const std::string &file = "") {
    std::ofstream out;
    out.open("map.json");
    fmt::print("json: {} \n", map);
    out << map;
    out.close();
    return true;
}

bool write_to_file(const Json &map, const std::string &file = "") {
    write_to_file(map.dump(), file);
}


std::string s() {
    return fmt::format("The answer is {}", 42);
}

TEST_CASE("FMT", "CONSTRUCTOR") {
    REQUIRE(s() == "The answer is 42");
}

TEST_CASE("WRITE TO FILE", "[OUT]") {
    Json my_json = Json::object{
            {"key1", "value1"},
            {"key2", false},
            {"key3", Json::array{1, 2, 3}},
    };
    write_to_file(my_json, "map.json");
}

TEST_CASE("READ FROM FILE", "[IN]") {
}

