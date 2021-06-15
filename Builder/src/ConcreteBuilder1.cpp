#include "ConcreteBuilder1.h"

ConcreteBuilder1::ConcreteBuilder1()
{
	this->Reset();
}

ConcreteBuilder1::~ConcreteBuilder1()
{
	delete product;
}

void ConcreteBuilder1::Reset()
{
	this->product = new Product1();
}

void ConcreteBuilder1::ProducePartA() const
{
	this->product->parts.push_back("PartA1");
}

void ConcreteBuilder1::ProducePartB() const
{
	this->product->parts.push_back("PartB1");
}

void ConcreteBuilder1::ProducePartC() const
{
	this->product->parts.push_back("PartC1");
}

/**
 * Please be careful here with the memory ownership. Once you call GetProduct
 * the user of this function is responsible to release this memory. Here could
 * be a better option to use smart pointers to avoid memory leaks.
 */
// TODO: implement smart pointers
Product1* ConcreteBuilder1::GetProduct()
{
	Product1* result = this->product;
	this->Reset();

	return result;
}
