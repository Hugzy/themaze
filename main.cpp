#include "test_main.h"
#include <iostream>
#include "vendors/catch2/catch.hpp"

template<typename ... T>
int sum(T... t) {
    return (... +t);
}

TEST_CASE("compute sum") {
    REQUIRE(sum(1, 2, 3, 4, 5) == 15);
}
