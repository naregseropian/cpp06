#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs)
{
    (void)rhs;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(const std::string& literal)
{
	char *end;
	errno = 0;

	/* Check for special nan or nanf values */ 
	if (literal == "nan" || literal == "nanf")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: nanf\n";
		std::cout << "double: nan\n";
		return;
	}
	
	/* Check for special floating-point values */
	if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: +inff\n";
		std::cout << "double: +inf\n";
		return;
	}

	/*	Check for -inf or -inff values */	
	if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: -inff\n";
		std::cout << "double: -inf\n";
		return;
	}

	/* Check if it's a char */
	if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
	{
		char c = literal[0];
		std::cout << "char: \'" << c << "\'\n";
		std::cout << "int: " << static_cast<int>(c) << "\n";
		std::cout << "float: " << static_cast<float>(c) << "f\n";
		std::cout << "double: " << static_cast<double>(c) << "\n";
		return;
	}

	/* Check if it's an int */
	long int i = std::strtol(literal.c_str(), &end, 10);
	if (*end == '\0' && errno != ERANGE && i >= INT_MIN && i <= INT_MAX)
	{
		/* Check for non-displayable range */
		if (i < 0 || i > 127)
		{
			std::cout << "char: impossible\n";
		}
		else if (i < ' ' || i > '~')
		{
			std::cout << "char: Non displayable\n";
		}
		else
		{
			std::cout << "char: \'" << static_cast<char>(i) << "\'\n";
		}
		std::cout << "int: " << i << "\n";
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f\n";
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << "\n";
		return;
	}

	/* Check if it's a float */
    errno = 0;
    float f = std::strtof(literal.c_str(), &end);

    if ((*end == 'f' || *end == 'F') && *(end + 1) == '\0' && errno != ERANGE) {
        std::cout << "char: ";
        if (f >= 0 && f <= 127 && std::isprint(static_cast<int>(f))) {
            std::cout << "'" << static_cast<char>(f) << "'\n";
        } else if (f < 0 || f > 127) {
            std::cout << "impossible\n";
        } else if (f < ' ' || f > '~') {
            std::cout << "Non displayable\n";
        } else {
            std::cout << "impossible\n";
        }

        std::cout << "int: ";
        if (f >= static_cast<float>(INT_MIN) && f <= static_cast<float>(INT_MAX)) {
            std::cout << static_cast<int>(f) << "\n";
        } else {
            std::cout << "impossible\n";
        }

        std::cout << "float: ";
        if (f > FLT_MAX || f < -FLT_MAX) {
            std::cout << "impossible\n";
        } else {
            std::cout << std::fixed << std::setprecision(1) << f << "f\n";
        }

        std::cout << "double: ";
        if (f > DBL_MAX || f < -DBL_MAX) {
            std::cout << "impossible\n";
        } else {
            std::cout << std::fixed << std::setprecision(1) << static_cast<double>(f) << "\n";
        }

        return;
    }

	/* Check if it's a double */
    double d = std::strtod(literal.c_str(), &end);
    errno = 0;
    if (*end == '\0' && errno != ERANGE) {
        std::cout << "char: ";
        if (d >= 0 && d <= 127 && std::isprint(static_cast<int>(d))) {
            std::cout << "'" << static_cast<char>(d) << "'\n";
        } 
		else
		{
			/* Check for non-displayable range */
			if (d < 0 || d > 127)
			{
				std::cout << "impossible\n";
			}
			else if (d < ' ' || d > '~')
			{
				std::cout << "Non displayable\n";
			}
        }

        std::cout << "int: ";
        if (d >= static_cast<double>(INT_MIN) && d <= static_cast<double>(INT_MAX)) {
            std::cout << static_cast<int>(d) << "\n";
        } else {
            std::cout << "impossible\n";
        }

        std::cout << "float: ";
		if (d > FLT_MAX) {
			std::cout << "+inf" << "f\n";
		} else if (d < -FLT_MAX) {
			std::cout << "-inf" << "f\n";
		} else {
			std::cout << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f\n";
		}

		
        // if (d > FLT_MAX || d < -FLT_MAX) {
        //     std::cout << "inf" << "f\n";
        // } else {
        //     std::cout << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f\n";
        // }

        std::cout << "double: ";
        if (d > DBL_MAX || d < -DBL_MAX) {
            std::cout << "inf\n";
        } else {
            std::cout << std::fixed << std::setprecision(1) << d << "\n";
        }
		return;
	}
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: impossible\n";
	std::cout << "double: impossible\n";
}