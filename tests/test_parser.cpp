#include "rhythm_io_facilities.h"
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <utility>

using std::make_pair;

TEST_CASE( "valid input" )
{
    REQUIRE( make_pair(4,4) == parse_time_sig("4/4"));
    REQUIRE( make_pair(15,8) == parse_time_sig("15/8"));
    REQUIRE( make_pair(15,8) == parse_time_sig(" 15 / 8 "));
}

TEST_CASE( "invalid input" )
{
    REQUIRE_THROWS( make_pair(15,8) == parse_time_sig("apple"));
    REQUIRE_THROWS( make_pair(15,8) == parse_time_sig("15/"));
    REQUIRE_THROWS( make_pair(15,8) == parse_time_sig("/8"));
    REQUIRE_THROWS( make_pair(15,8) == parse_time_sig("15"));
}
