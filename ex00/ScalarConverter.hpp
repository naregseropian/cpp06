#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <cstdlib> // isdigit and isprint
#include <cctype> // strtol and strtod

#include <iostream>
#include <cerrno>
#include <climits>
#include <cfloat>
#include <iomanip>
#include <limits>
#include <cmath>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter&);
        ScalarConverter& operator=(const ScalarConverter&);
        ~ScalarConverter();
    
    public:
        static void convert(const std::string& literal);
};

enum literalType
{
    CHAR_TYPE,
    INT_TYPE,
    FLOAT_TYPE,
    DOUBLE_TYPE,
    PLUS_INF,
    NEG_INF,
    NOT_A_NUMBER,
    UNKNOWN_TYPE
};

#endif