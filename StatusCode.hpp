#ifndef HTTPSTATUCPP_STATUSCODE_HPP
#define HTTPSTATUCPP_STATUSCODE_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

class StatusCode {

protected:
    std::string shortDesc;
    std::string category;
    std::string code;
    std::string details;

    std::string desc;
  
public:
    StatusCode();
    //StatusCode(std::string category, unsigned int code, std::string sd);
    virtual ~StatusCode();

    auto getCategory() const -> std::string;

    auto getCode() const-> std::string ;

    auto getShortDesc() const-> std::string;

    auto getDesc() const -> std::string;

    auto getDetails() const-> std::string; 

    void setCategory(const std::string& );

    void setCode(const std::string& );

    void setShortDesc(const std::string& );
    void setDesc(const std::string& );
    void setDetails(const std::string&);

};

#endif //HTTPSTATUSCPP_STATUSCODE_HPP
