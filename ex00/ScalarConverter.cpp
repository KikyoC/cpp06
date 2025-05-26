#include "ScalarConverter.hpp"
#include <iostream>



type getType(const std::string &str)
{
	int i;
	type t = INT;

	//Check if it's a Char
	if (str.length() == 1)
		return CHAR;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			continue;
		if (str[i] == '.')
		{
			if (t == DOUBLE)
				return INVALID;
			t = DOUBLE;
			continue ;
		}
		if (str[i] == 'f')
		{
			if (t == DOUBLE && str[i + 1] == '\0' && i >= 1 && str[i - 1] >= '0' && str[i - 1] <= '9')
				return FLOAT;
			return INVALID;
		}
		else if (str[i] < '0' || str[i] > '9')
			return INVALID;
	}
	return t;
}

std::string stringType(type t)
{
	switch (t)
	{
		case INVALID:
			return "Invalid";
		case INT:
			return "Integer";
		case FLOAT:
			return "Float";
		case DOUBLE:
			return "Double";
		case CHAR:
			return "Character";
	}
	return ("Bruh");
}

void ScalarConverter::convert(const std::string &str)
{
	(void)str;
	std::cout << "Type is " << stringType(getType(str)) << std::endl;
	std::cout << "Char: " << "to_print" << std::endl;
	std::cout << "Int: " << "to_print" << std::endl;
	std::cout << "Float: " << "to_print" << std::endl;
	std::cout << "Double: " << "to_print" << std::endl;
	
}
