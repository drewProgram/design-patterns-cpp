#pragma once

#include "AbstractProductA.h"
#include "AbstractProductB.h"

class ConcreteProductB2 : public AbstractProductB
{
	std::string UsefulFunctionB() const override;
	/**
	 * The variant, Product B2, is only able to work correctly with the
	 * variant, Product A2. Nevertheless, it accepts any instance of AbstractProductA
	 * as an argument.
	 */
	std::string AnotherUsefulFunctionB(const AbstractProductA& collaborator) const override;
};