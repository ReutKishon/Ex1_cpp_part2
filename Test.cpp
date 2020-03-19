#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <string>
#include "doctest.h"
#include "PhoneticFinder.hpp"

using namespace std;
TEST_CASE("Test PhoneticFind -> Sanity")
{
    CHECK(1 == 1);
    CHECK(find(string("dont"), string("Dond vorri be haffy")).compare(string("Dond")) == 0);
}
