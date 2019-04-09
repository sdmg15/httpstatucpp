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

    std::string getCategory() const;

    std::string getCode() const ;

    std::string getShortDesc() const;

    std::string getDesc() const;

    std::string getDetails() const; 

    void setCategory(const std::string& );

    void setCode(const std::string& );

    void setShortDesc(const std::string& );
    void setDesc(const std::string& );
    void setDetails(const std::string&);

};

#endif //HTTPSTATUSCPP_STATUSCODE_HPP
