#pragma once

#include "Product.h"

class ConcreteProductB : public Product
{
public:
	std::string Operation() const override;
};
