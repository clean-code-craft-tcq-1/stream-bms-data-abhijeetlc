#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "Sender_Header.h"

TEST_CASE("To check if file was successfully opened to read") 
{
 
  REQUIRE(inputvalue(inputvalue)== PASS); 
}

TEST_CASE("To check data is printed on the console") 
{
  REQUIRE(outputtoconsole(outputvalue)== PASS);
  
}
