#include "Data.hpp"

Data::Data()
: id(0), name("default")
{}

Data::Data(const Data& other)
: id(other.id), name(other.name) 
{}

Data& Data::operator=(const Data& rhs)
{
    if (this != &rhs)
    {
        id = rhs.id;
        name = rhs.name;
    }
    return *this;
}

Data::~Data()
{}