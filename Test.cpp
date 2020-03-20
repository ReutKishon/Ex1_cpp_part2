#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <string>
#include "doctest.h"
#include "PhoneticFinder.hpp"

using namespace std;
TEST_CASE("Test PhoneticFind -> Sanity")
{

    CHECK(find(string("dont"), string("Dond vorri be haffy")).compare(string("Dond")) == 0);
    CHECK(find(string("worry"), string("Dond vorri be haffy")).compare(string("vorri")) == 0);
    CHECK(find(string("be"), string("Dond vorri be haffy")).compare(string("be")) == 0);
}
TEST_CASE("Test PhoneticFind -> More than one spelling error")
{
    CHECK(find(string("dog"), string("Y luwe tuj bor sure")).compare(string("tuj")) == 0);
    CHECK(find(string("for"), string("Y luwe tuj bor sure")).compare(string("bor")) == 0);
    CHECK(find(string("love"), string("Y luwe tuj bor sure")).compare(string("luwe")) == 0);
}
// TEST_CASE("Test PhoneticFind ->  Not Alaphbet letters")
// {
//     CHECK(find(string("dog"),string("$#@@ #% ^7")).compare(string("^7"))==0);
// }

TEST_CASE("Test PhoneticFind -> No spelling errors at all")
{
    CHECK(find(string("rx"), string("ae elmn rx")).compare(string("rx")) == 0);
}

TEST_CASE("Test PhoneticFind -> Word not found")
{
    CHECK(find(string("hi"), string("live laugh love")).compare(string("hi")) == 0);
}
