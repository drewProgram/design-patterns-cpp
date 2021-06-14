#pragma once

#include "Creator.h"
#include "ConcreteProductB.h"

class ConcreteCreatorB : public Creator
{
public:
	Product* FactoryMethod() const override
	{
		return new ConcreteProductB();
	}
};