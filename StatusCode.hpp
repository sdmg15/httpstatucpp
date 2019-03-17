#ifndef HTTPSTATUCPP_STATUSCODE_HPP
#define HTTPSTATUCPP_STATUSCODE_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

class StatusCode {

protected:
    std::__cxx11::string category;
    std::__cxx11::string code;
    std::__cxx11::string shortDesc;
    std::string details;

    std::__cxx11::string desc;
  
public:
    StatusCode();
    //StatusCode(std::string category, unsigned int code, std::string sd);
    virtual ~StatusCode();

    std::__cxx11::string getCategory() const;

    std::__cxx11::string getCode() const ;

    std::__cxx11::string getShortDesc() const;

    std::__cxx11::string getDesc() const;

    std::string getDetails() const; 

    void setCategory(const std::__cxx11::string& );

    void setCode(const std::__cxx11::string& );

    void setShortDesc(const std::__cxx11::string& );
    void setDesc(const std::__cxx11::string& );
    void setDetails(const std::string&);

};

#endif //HTTPSTATUSCPP_STATUSCODE_HPP
