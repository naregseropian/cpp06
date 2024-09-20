#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct Data
{
    int         id;
    std::string name;

    Data();
    Data(const Data& other);
    Data& operator=(const Data& rhs);
    ~Data();
};

#endif