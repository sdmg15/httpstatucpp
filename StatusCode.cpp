#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "StatusCode.hpp"


std::string& split(std::string& s){

    auto pos = s.find_first_of(':');

    std::string res;

    if(pos != std::string::npos){
        for( auto i(pos+1); i < s.size();i++)
            res+= s.at(i);
    }
    s = res;

    return s;

}


StatusCode::StatusCode(const std::string& fileCode): shortDesc("n/a"),desc("n/a"),code("n/a"),category("n/a") {

    this->codeFile.open(fileCode); // Opening the file to read

    if( this->codeFile.is_open()){

        // reading the code first

        std::string fileOut;
        std::vector<std::string> vDetails;

        while(  getline(this->codeFile,fileOut) ){
            std::string res = split(fileOut);
            vDetails.push_back(res);
        }

        this->setCode(vDetails.at(0));
        this->setShortDesc(vDetails.at(1));
        this->setCategory(vDetails.at(2));
        this->setDesc(vDetails.at(3));

    }else {
        std::cout << "Cannot open such file ... "  << std::endl ;
    }

}

StatusCode::~StatusCode() {
}

std::string StatusCode::getCategory() const{
    return this->category;
}

std::string StatusCode::getCode() const {
    return this->code;
}

std::string StatusCode::getShortDesc() const {
    return this->shortDesc;
}
std::string StatusCode::getDesc() const {
    return this->desc;
}

void StatusCode::setCategory(const std::string& s){
    this->category = s;
}

void StatusCode::setCode(const std::string& code){
    this->code = code;
}

void StatusCode::setShortDesc(const std::string& shortDesc){
    this->shortDesc = shortDesc;
}

void StatusCode::setDesc(const std::string& desc){
    this->desc = desc;
}
