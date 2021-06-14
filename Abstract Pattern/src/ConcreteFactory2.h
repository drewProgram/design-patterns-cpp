#pragma once

#include "AbstractFactory.h"

/**
 * Each Concrete Factory has a corresponding product variant.
 */
class ConcreteFactory2 : public AbstractFactory
{
public:
	AbstractProductA* CreateProductA() const override;
	AbstractProductB* CreateProductB() const override;
};