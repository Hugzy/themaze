#include "definitions.h"
#include <iostream>
#include <string>
#include "fmt/format.h"
#include "include/catch2/catch.hpp"
#include "include/json11/json11.hpp"
#include "util/json_utility.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace json11;

TEST_CASE("WRITE TO FILE", "[OUT]") {
    Json my_json = Json::object{
            {"key11", "value1"},
            {"key22", false},
            {"key33", Json::array{1, 2, 3}},
    };
    append_to_file(my_json, "map.json");
}

TEST_CASE("READ FROM FILE", "[IN]") {
    read_from_file();
}

