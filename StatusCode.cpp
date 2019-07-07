#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "StatusCode.hpp"



StatusCode::StatusCode(){}

StatusCode::~StatusCode() {
}

auto StatusCode::getCategory() const -> std::string {
    return this->category;
}

auto StatusCode::getCode() const -> std::string{
    return this->code;
}

std::string StatusCode::getShortDesc() const {
    return this->shortDesc;
}
auto StatusCode::getDesc() const->std::string  {
    return this->desc;
}

auto StatusCode::getDetails() const -> std::string{
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