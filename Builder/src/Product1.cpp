#include "Product1.h"

#include <iostream>

void Product1::ListParts() const
{
	std::cout << "Product parts: ";
	for (size_t i = 0; i < parts.size(); i++)
	{
		if (parts[i] == parts.back())
		{
			std::cout << parts[i];
			continue;
		}

		std::cout << parts[i] << ", ";
	}

	std::cout << "\n\n";
}
