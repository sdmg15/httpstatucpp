#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "StatusCode.hpp"



StatusCode::StatusCode(){}

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

std::string StatusCode::getDetails() const{
    return this->details; 
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

void StatusCode::setDetails(const std::string& details){
    this->details = details;
}