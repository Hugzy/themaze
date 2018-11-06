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

bool read_from_file(){
    std::ifstream in;
    in.open("map.json");
    std::stringstream sstr;
    sstr << in.rdbuf();
    std::string json_str = sstr.str();
    auto err = std::string{"error parsing"};
    auto json = Json::parse(json_str, err);
    fmt::print("value1 is: {}", json["key1"].string_value());
    return true;
}

bool write_to_file(){
    std::ofstream out;
    out.open("map.json");
    Json my_json = Json::object {
            { "key1", "value1" },
            { "key2", false },
            { "key3", Json::array { 1, 2, 3 }},
            { "key 4", Json::object {
                    {"key5", "value2"},
                    {"key6", true},
                    {"key7", Json::array{4,5,6}}
            }
            }
    };
    std::string json_str = my_json.dump();
    fmt::print("json: {} \n", json_str);
    out << json_str;
    out.close();
    return true;
}

std::string s(){
    return fmt::format("The answer is {}", 42);
}

TEST_CASE("FMT", "CONSTRUCTOR"){
    REQUIRE(s() == "The answer is 42");
}

TEST_CASE("WRITE TO FILE", "[OUT]"){
    REQUIRE(write_to_file());
}

TEST_CASE("READ FROM FILE", "[IN]"){
    REQUIRE(read_from_file());
}

