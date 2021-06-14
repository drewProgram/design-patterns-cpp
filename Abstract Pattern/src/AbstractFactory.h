#pragma once

#include "AbstractProductA.h"
#include "AbstractProductB.h"

/**
 * The Abstract Factory interface declares a set of methods that return
 * different abstract products. These products are called family and are
 * related by a high-level theme or concept. Products of one family are usually
 * able to collaborate among themselves. A family of products may have several
 * variants, but the products of one variant are incompatible with products
 * of another.
 */
class AbstractFactory
{
public:
	virtual AbstractProductA* CreateProductA() const = 0;
	virtual AbstractProductB* CreateProductB() const = 0;
};