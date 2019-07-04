#include <iostream>
#include "CLI/CLI.hpp"
#include <vector>
#include <fstream>
#include <cstdlib>
#include <map>
#include <cassert>
#include <stdexcept>
#include "StatusCode.hpp"
#include "nlohmann/json.hpp"
#include <typeinfo>
#include <cstdio>
#include <catch2/catch.hpp>
#include "src/Utils.hpp"
#include "src/Table.hpp"

#define DATABASE_PATH "database/database.json"

using Json = nlohmann::json;



template <typename T>
void display(StatusCode& s,const T& json){

    s.setCode(json["code"]);
    s.setShortDesc(json["shortDescr"]);
    s.setDesc(json["description"]);
    s.setDetails(json["details"]);
    s.setCategory(json["category"]);

    CliTable::Options opt;
    CliTable::TableBody content = {
                            { "Code"     ,        s.getCode() },
                            { "Category" ,        s.getCategory()        },
                            { "Short Description"         ,     s.getShortDesc() },
                            { " Description"     ,   s.getDesc() },
                            { "Details" ,  s.getDetails()    },
                        };

    CliTable::Table table(opt,content);
    //Generating the final table 

    table.generate();
}

void displayCategory(const std::string& category, const Json& json){
    auto codes = json[category][0];

    for(auto const& codeCategory: codes){
        StatusCode statusCode;
        display<decltype(codeCategory)>(statusCode,codeCategory);
    }

}

int main(int argc,char** argv) {

    //auto envPath = getenv(DATABASE_PATH);

    const std::map<char,std::string> categoryValues = {
        {'1',"informational"},
        {'2',"success"},
        {'3',"redirection"},
        {'4',"clientError"},
        {'5',"serverError"}
    };

    std::ifstream database(DATABASE_PATH);
    Json json;
    // Reading the database into json
    database >> json ;

    CLI::App app{"Get http status codes meaning right in your terminal ! "};

    app.require_subcommand(1);

    bool bInformational,bSuccess,bRedirection,bClient,bServer;

    auto code = app.add_subcommand("code","Retrieves the meaning of the specified code");
         code->add_flag("-i,--informational",bInformational,"Displays Informational codes and their meanings");
         code->add_flag("-s,--success",bSuccess,"Displays Success codes and their meanings");
         code->add_flag("-r,--redirection",bRedirection,"Displays Success codes and their meanings");
         code->add_flag("-c,--client-error",bClient,"Displays Client error codes and their meanings");
         code->add_flag("-e,--server-error",bServer,"Displays Server error codes and their meanings");


    std::string sCode;

    code->add_option("code",
                   sCode,
                   "The code which the meaning should be displayed");

    code->callback([&](){

        if(sCode.empty()) {
            // Either it's an error or we want to display for a specific category
            if(bInformational) displayCategory("informational",json);
            if(bSuccess) displayCategory("success",json);
            if(bRedirection) displayCategory("redirection",json);
            if(bClient) displayCategory("clientError",json);
            if(bServer) displayCategory("serverError",json);

        }else { 
            // Reading information about the code from the Json 
            // If the size of the sCode is greater than 3 then bad code 

            if( sCode.size() > 3){
                std::cerr << "The specified code is invalid :(" << std::endl;
                return;
            }
            try{

                //Looking for the code's category inside the map 
                std::string category;

                auto it = categoryValues.find(sCode.at(0));

                if(  it != categoryValues.end() ){
                    // Now we know the category to which the code belongs to
                    category = it->second;
                    
                    auto foundCode = json[category][0][sCode];
                    StatusCode statusCode;

                     display<decltype(foundCode)>(statusCode,foundCode);

                }else{
                    std::cerr << "The specified code is invalid "<< std::endl ;
                }

            }catch(const std::exception& e){
                std::cerr << "Cannot open the file" << std::endl;
            }
        }
    });

    CLI11_PARSE(app, argc, argv);

    std::cout << "\n"<< std::endl;

    std::cout<< "Information took from https://httpstatuses.com/" << std::endl;


}