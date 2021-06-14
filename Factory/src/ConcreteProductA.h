#pragma once

#include "Product.h"

/**
 * Concrete Products provides various implementations of the Product interface.
 */
class ConcreteProductA : public Product
{
public:
	std::string Operation() const override;
};
