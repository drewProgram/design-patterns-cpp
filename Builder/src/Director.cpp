#include "Director.h"

void Director::SetBuilder(Builder* builder)
{
	this->builder = builder;
}

void Director::BuildMinimalViableProduct()
{
	this->builder->ProducePartA();
}

void Director::BuildFullFeaturedProduct()
{
	this->builder->ProducePartA();
	this->builder->ProducePartB();
	this->builder->ProducePartC();
}
