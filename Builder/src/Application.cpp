#include <iostream>

#include "Director.h"
#include "ConcreteBuilder1.h"

/**
 * The client code creates a builder object, passes it to the director
 * and then initiates the construction process. The end result is
 * retrieved from the builder object.
 * 
 * It has been used raw pointer for simplicity but it may be better
 * to use smart pointers here.
 */
// TODO: check smart pointer implementation here.
void ClientCode(Director& director)
{
	ConcreteBuilder1* builder = new ConcreteBuilder1();
	director.SetBuilder(builder);
	std::cout << "Standard basic product:" << std::endl;
	director.BuildMinimalViableProduct();

	Product1* p = builder->GetProduct();
	p->ListParts();
	delete p;

	std::cout << "Standard full featured product:" << std::endl;
	director.BuildFullFeaturedProduct();

	p = builder->GetProduct();
	p->ListParts();
	delete p;

	delete builder;
}

int main()
{
	std::cout << "BUILDER PATTERN!!\n" << std::endl;
	
	Director* director = new Director();
	ClientCode(*director);

	delete director;

	return 0;
}