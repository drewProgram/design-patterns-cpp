#pragma once

#include "Iterator.h"

/**
 * Generic Collections/Containers provides one or several methods for retrieving
 * fresh iterator instances compatible with the collection class.
 */
template <class T>
class Container
{
	friend class Iterator<T, Container>;

private:
	std::vector<T> m_Data;

public:
	void Add(T a)
	{
		m_Data.push_back(a);
	}

	Iterator<T, Container>* CreateIterator()
	{
		return new Iterator<T, Container>(this);
	}
};