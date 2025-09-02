#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <limits>

bool isInt(const std::string &str)
{
	int start = 0;
	if (str[0] == '+' || str[0] == '-')
		start++;
	for (int i = start; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return false;
	}
	return true;
}

bool isComma(const std::string &str, bool checkFloat)
{
	int dot = str.find('.');
	int i;
	//Check if first part is good
	for (i = dot - 1; i < 0; i--)
		if (!((i == 0 && (str[0] == '+' || str[0] == '-')) || (str[i] >= '0' && str[i] <= '9')))
			return false;
	//Check if second part is good
	for (i = dot + 1; str[i] != '\0'; i++)
		if (!((str[i] >= '0' && str[i] <= '9') || (str[i] == 'f' && str[i + 1] == '\0')))
			return false;
	if (checkFloat)
		return str[i - 1] == 'f';
	return true;
}

bool isChar(const std::string &str)
{
	size_t len = str.length();

	if (len == 3 && str[0] == '\'' && str[2] == '\'')
		return true;
	return len == 1;
}

bool isSpecial(const std::string &str)
{
	return str == "+inf" || str == "-inf" || str == "nan" || str == "+inff" || str == "-inff" || str == "nanf";
}

bool isZero(std::string str)
{
	for(std::string::iterator it = str.begin(); it != str.end(); it++)
		if (*it > '0' && *it <= '9')
			return false;
	return true;
}

type getType(const std::string &str)
{
	type t = INVALID;
	if (str.empty())
		return INVALID;
	if (isInt(str))
		t = INT;
	else if (isComma(str, true))
		t = FLOAT;
	else if (isComma(str, false))
		t = DOUBLE;
	else if (isChar(str))
		t = CHAR;
	else if (isSpecial(str))
		t = SPECIAL;
	return t;
}


/*---------------------------------------------------
*----------------------PRINTERS----------------------
*----------------------------------------------------
*/


std::string stringType(type t)
{
	switch (t)
	{
		case INT:
			return "Integer";
		case FLOAT:
			return "Float";
		case DOUBLE:
			return "Double";
		case CHAR:
			return "Character";
		case SPECIAL:
			return "Special";
		default:
			return "Invalid";
	}
}

void printInfo(long value)
// void printInfo(long value, int i, char c, float f, double d)
{
	std::cout << "Char: ";
	if (value < 0 || value > 127)
		std::cout << "Not in char range";
	else
	{
		if (isprint(value))
			// std::cout << "'" << c << "'";
			std::cout << "'" << static_cast<char>(value) << "'";
		else
			std::cout << "Not printable";
	}
	std::cout << std::endl;
	std::cout << "Int: ";
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		std::cout << "Overflow";
	else
		std::cout << static_cast<int>(value);
	std::cout << std::endl;
	std::cout << "Float: ";
	if (value < std::numeric_limits<float>::min() || value > std::numeric_limits<float>::max())
		std::cout << "Overflow";
	else
		std::cout << static_cast<float>(value) << 'f';
	std::cout << std::endl;
	std::cout << "Double: ";
	if (value < std::numeric_limits<double>::min() || value > std::numeric_limits<double>::max())
		std::cout << "Overflow";
	else
		std::cout << static_cast<double>(value);
	std::cout << std::endl;
}

void toInt(const std::string &str)
{
	const char *startPtr = str.c_str();
	char *endPtr;
	long value = std::strtol(startPtr, &endPtr, 10);

	// int i = static_cast<int>(value);
	// char c = static_cast<char>(value);
	// float f = static_cast<float>(value);
	// double d = static_cast<double>(value);
	// printInfo(value, i, c, f, d);
	printInfo(value);
}

void toFloat(const std::string &str)
{
	const char *startPtr = str.c_str();
	char *endPtr;
	long value = std::strtol(startPtr, &endPtr, 10);

	printInfo(value);
}

void toDouble(const std::string &str)
{
	const char *startPtr = str.c_str();
	char *endPtr;
	long value = std::strtol(startPtr, &endPtr, 10);
	
	printInfo(value);
}

void toChar(const std::string &str)
{
	char c = str[0];
	if (str.length() == 3)
		c = str[1];
	std::cout << "Char: ";
	if (isprint(c))
		std::cout << '\'' << c << '\'';
	else
		std::cout << "Not printable";
	std::cout << std::endl;
	std::cout << "Int: " << static_cast<int>(c) << std::endl;
	std::cout << "Float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "Double: " << static_cast<double>(c) << ".0" << std::endl;
}

void toSpecial(const std::string &str)
{
	std::string realStr = str;
	if (str == "+inff")
		realStr = "+inf";
	else if (str == "-inff")
		realStr = "-inf";
	else if (str == "nanf")
		realStr = "nan";
	std::cout << "Char: Impossible" << std::endl;
	std::cout << "Int: Impossible" << std::endl;
	std::cout << "Float: " << realStr << "f" << std::endl;
	std::cout << "Double: " << realStr << std::endl;
}

void ScalarConverter::convert(const std::string &str)
{
	type t = getType(str);

	std::cout << "Type is " << stringType(t) << std::endl;
	switch (t)
	{
		case FLOAT:
			toFloat(str);
			break;
		case DOUBLE:
			toDouble(str);
			break;
		case CHAR:
			toChar(str);
			break;
		case INT:
			toInt(str);
			break;
		case SPECIAL:
			toSpecial(str);
			break;
		default:
			std::cout << "Not possible to convert :(" << std::endl;
	}
}
