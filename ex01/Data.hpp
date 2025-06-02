#pragma once

#include <string>
class Data
{
	public:
		Data(const std::string &str);
		Data(const Data &cpy);
		Data &operator=(const Data &cpy);
		~Data();

		std::string getName() const;
	private:
		const std::string str;
};
