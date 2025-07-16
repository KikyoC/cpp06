#include "Data.hpp"

Data::Data(): str("hey") {}

Data::Data(const std::string &str): str(str) {}

Data::Data(const Data &cpy): str(cpy.str) {}

Data &Data::operator=(const Data &cpy)
{
	(void)cpy;
	return *this;
}

Data::~Data()
{

}

std::string Data::getName() const
{
	return this->str;
}
