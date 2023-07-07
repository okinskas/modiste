#include "modiste/modiste.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Name is modiste", "[library]")
{
  REQUIRE(name() == "modiste");
}
