#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data *data = new Data("Hello world");

	std::cout << "Stored value is " << data->getName() << std::endl;

	uintptr_t raw = Serializer::serialize(data);
	Data *d = Serializer::deserialize(raw);

	std::cout << "Stored value is " << d->getName() << std::endl;

	delete data;
}
