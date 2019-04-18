#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>
#include "../StatusCode.hpp"
#include "CLI/CLI.hpp"
#include "nlohmann/json.hpp"
#include <string>
#define DATABASE_PATH "database/database.json"

using Json = nlohmann::json;

const std::map<char,std::string> categoryValues = {
        {'1',"informational"},
        {'2',"success"},
        {'3',"redirection"},
        {'4',"clientError"},
        {'5',"serverError"}
    };

TEST_CASE("Getting information about a specific code","[Specific code test]"){

    INFO("Getting information about http status code 200 ");
    
    const std::string enteredCode = "200";
    static std::string category; 
    Json json ;

    // Reading the file into the json 
    std::ifstream database(DATABASE_PATH);

    database >> json ;

    auto it = categoryValues.find(enteredCode.at(0));
    
    if( it != categoryValues.end()){
        category = it->second;
        auto foundCode = json[category][0][enteredCode];
      
        REQUIRE( foundCode["code"] == "200");
        REQUIRE( foundCode["category"] == "success");
        REQUIRE( foundCode["shortDescr"] == "OK,The request has succeeded.");
        REQUIRE( foundCode["description"] == "The payload sent in a 200 response depends on the request method. For the methods defined by this specification, the intended meaning of the payload can be summarized as:\n\n    GET a representation of the target resource\n    HEAD the same representation as GET, but without the representation data\n    POST a representation of the status of, or results obtained from, the action;\n        PUT DELETE a representation of the status of the action;\n        OPTIONS a representation of the communications options;\n        TRACE a representation of the request message as received by the end server.\n");
        REQUIRE( foundCode["details"] == "Aside from responses to CONNECT, a 200 response always has a payload, though an origin server MAY generate a payload body of zero length. If no payload is desired, an origin server ought to send 204 No Content instead. For CONNECT, no payload is allowed because the successful result is a tunnel, which begins immediately after the 200 response header section.\n\nA 200 response is cacheable by default; i.e., unless otherwise indicated by the method definition or explicit cache controls");
    }else{
        FAIL("No such category found");
    }

}