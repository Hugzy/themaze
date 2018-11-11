#include "definitions.h"
#include <iostream>
#include <string>
#include "fmt/format.h"
#include "include/catch2/catch.hpp"
#include "include/json11/json11.hpp"
#include "util/json_routine.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace json11;

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

