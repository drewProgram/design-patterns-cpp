#pragma once

#include "AbstractProductA.h"

class ConcreteProductA2 : public AbstractProductA
{
	std::string UsefulFunctionA() const override;
};