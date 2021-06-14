#include "ConcreteFactory2.h"
#include "ConcreteProductA2.h"
#include "ConcreteProductB2.h"

AbstractProductA* ConcreteFactory2::CreateProductA() const
{
	return new ConcreteProductA2();
}

AbstractProductB* ConcreteFactory2::CreateProductB() const
{
	return new ConcreteProductB2();
}
