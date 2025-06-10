#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <typeinfo>

Base *generate()
{
	int rdm = rand() % 3;

	switch (rdm)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		default:
			return new C;
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Identified as A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Identified as B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Identified as C" << std::endl;
	else
		std::cout << "Not identified" << std::endl;
}

void identify(Base &p)
{
	try {
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Identified as A" << std::endl;
		return ;
	} catch (const std::bad_cast &ignored){};
	try {
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Identified as B" << std::endl;
		return ;
	} catch (const std::bad_cast &ignored){};
	try {
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Identified as C" << std::endl;
		return ;
	} catch (const std::bad_cast &ignored){};
	std::cout << "Not identified" << std::endl;
}

int main(void)
{
	srand(time(0));
	Base *b = generate();
	identify(*b);
	identify(NULL);
	identify(b);
	identify(NULL);
	delete b;
}
