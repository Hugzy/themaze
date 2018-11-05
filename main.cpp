#include "definitions.h"
#include <iostream>
#include <string>
#include "fmt/format.h"
#include "include/catch2/catch.hpp"
#include "include/json11/json11.hpp"
#include <vector>
using namespace json11;

struct Wall{

};

struct Door{

};

struct Room{
    std::vector<Door> doors;
    std::vector<Wall> walls;
};

void generate(const int &seed){
    auto v = std::vector<Room>();
    for (int i = 0; i < seed; i++) {
        v.push_back(Room{});
    }
}

std::string s(){
    return fmt::format("The answer is {}", 42);
}

TEST_CASE("ROOM", "CONSTRUCTOR"){
}

TEST_CASE("JSON"){
    Json my_json = Json::object {
            { "key1", "value1" },
            { "key2", false },
            { "key3", Json::array { 1, 2, 3 } },
    };
    std::string json_str = my_json.dump();
    fmt::print("json: {}", json_str);

}

