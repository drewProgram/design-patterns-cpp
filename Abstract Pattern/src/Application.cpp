#include <iostream>

#include "AbstractFactory.h"
#include "ConcreteFactory1.h"
#include "ConcreteFactory2.h"

/**
 * The client code works with factories and products only through abstract
 * types: AbstractFactory and AbstractProduct. This lets you pass any factory
 * of product subclass to the client code without breaking it.
 */
void ClientCode(const AbstractFactory& factory)
{
	const AbstractProductA* productA = factory.CreateProductA();
	const AbstractProductB* productB = factory.CreateProductB();

	std::cout << productB->UsefulFunctionB() << std::endl;
	std::cout << productB->AnotherUsefulFunctionB(*productA) << std::endl;

	delete productA;
	delete productB;
}

int main()
{
	std::cout << "Hello Abstract Factory!" << std::endl;

	std::cout << "Client: Testing client code with the first factory type:" << std::endl;
	ConcreteFactory1* f1 = new ConcreteFactory1();
	ClientCode(*f1);
	delete f1;

	std::cout << std::endl;

	std::cout << "Client: Testing the same client code with the second factory type:" << std::endl;
	ConcreteFactory2* f2 = new ConcreteFactory2();
	ClientCode(*f2);
	delete f2;

	return 0;
}