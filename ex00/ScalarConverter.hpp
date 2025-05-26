#pragma once

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
	CHAR, INT, FLOAT, DOUBLE, INVALID
};
