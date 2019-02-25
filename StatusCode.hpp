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

    std::__cxx11::string desc;
    std::ifstream codeFile;

public:
    StatusCode(const std::__cxx11::string&);
    //StatusCode(std::string category, unsigned int code, std::string sd);
    virtual ~StatusCode();

    std::__cxx11::string getCategory() const;

    std::__cxx11::string getCode() const ;

    std::__cxx11::string getShortDesc() const;

    std::__cxx11::string getDesc() const;

    void setCategory(const std::__cxx11::string& );

    void setCode(const std::__cxx11::string& );

    void setShortDesc(const std::__cxx11::string& );
    void setDesc(const std::__cxx11::string& );

};

#endif //HTTPSTATUSCPP_STATUSCODE_HPP
