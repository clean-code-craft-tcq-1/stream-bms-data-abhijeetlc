#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "Sender_Header.h"

TEST_CASE("To check if file was successfully opened to read") 
{
  Sender_InType InVal = FileInput ; 
  REQUIRE(InputValue(InVal) != PASS); 
}


/*TEST_CASE("test") 
{
  Sender_OutType OutVal = PrintToConsole ;
  REQUIRE(OutputValue(OutVal)== PASS);
  
}
*/
