#include <iostream>
#include "libs/CLI11.hpp"
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include "StatusCode.hpp"

#define pathDatabase "pathDatabase"

int main(int argc,char** argv) {



    auto envPath = getenv(pathDatabase);

    assert(nullptr != envPath );

    std::string path = std::string(envPath);

    CLI::App app{"Get http statuses code meaning right in your terminal ! "};

    app.require_subcommand(1);

    std::string enteredCode;

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
                   "The code that the meaning should be displayed");

    code->callback([&](){

        if(sCode.empty()) {

            std::cerr << "Sorry but the code is required !"<< std::endl;
        }else {
            std::string codePath = path+"/"+sCode+".txt";

            StatusCode statusCode(codePath);

            std::cout<< "Code : " << statusCode.getCode() << std::endl;

            std::cout<< "" << std::endl;

            std::cout<< "Short Description :" << statusCode.getShortDesc() << std::endl;

            std::cout<< "" << std::endl;

            std::cout<< "Category :" << statusCode.getCategory() << std::endl;

            std::cout<< "" << std::endl;
            std::cout<< "Description :" << statusCode.getDesc() << std::endl;

        }
    });

    CLI11_PARSE(app, argc, argv);

    std::cout<< "" << std::endl;


}