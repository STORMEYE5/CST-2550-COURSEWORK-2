#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../main.cpp"

TEST_CASE("test input string", "[hashFunction]")
{
    REQUIRE(hashFunction(100));
    REQUIRE(hashFunction(2));
}

TEST_CASE("test data written to table")
{
    Track table[1];
    table->setName("John");
    table->setArtist("Jones");
    table->setDuration("200");

    REQUIRE(table->getName() == "John");
    REQUIRE(table->getArtist() == "Jones");
    REQUIRE(table->getDuration() == "200");
}

TEST_CASE("test exit", "[exit_program]")
{
    REQUIRE(exit_program);
}