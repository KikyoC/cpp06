#pragma once

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &cpy);
		ScalarConverter &operator=(const ScalarConverter &cpy);
		~ScalarConverter();
	public:
		static void	convert(const std::string &str);
};

enum type {
	CHAR, INT, FLOAT, DOUBLE, INVALID, SPECIAL
};

template <typename T>
void printInfo(T value, const std::string &origin)
{
	double checker = std::strtod(origin.c_str(), NULL);
	std::cout << "Char: ";
	if (value < 0 || value > 127)
		std::cout << "Not in char range";
	else
	{
		if (isprint(value))
			std::cout << "'" << static_cast<char>(value) << "'";
		else
			std::cout << "Not printable";
	}
	std::cout << std::endl;
	std::cout << "Int: ";
	if (checker < std::numeric_limits<int>::min() || checker > std::numeric_limits<int>::max() || checker == HUGE_VAL)
		std::cout << "Overflow";
	else
		std::cout << static_cast<int>(value);
	std::cout << std::endl;
	std::cout << "Float: ";
	if (checker < -std::numeric_limits<float>::max() || checker > std::numeric_limits<float>::max() || checker == HUGE_VAL)
		std::cout << "Overflow";
	else
		std::cout << static_cast<float>(value) << 'f';
	std::cout << std::endl;
	std::cout << "Double: ";
	if (checker < -std::numeric_limits<double>::max() || checker > std::numeric_limits<double>::max() || checker == HUGE_VAL)
		std::cout << "Overflow";
	else
		std::cout << static_cast<double>(value);
	std::cout << std::endl;
}
