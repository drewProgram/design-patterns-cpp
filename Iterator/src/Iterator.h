#pragma once

#include <vector>

/**
 * C++ has its own implementation of iterator that works with a
 * different generics containers defined by the standard library.
 */
template <typename T, typename U>
class Iterator
{
public:
	typedef typename std::vector<T>::iterator iter_type;
	Iterator(U* pData, bool reverse = false)
		: m_PData(pData)
	{
		m_Iterator = m_PData->m_Data.begin();
	}

	void First()
	{
		m_Iterator = m_PData->m_Data.begin();
	}

	void Next()
	{
		m_Iterator++;
	}

	bool IsDone()
	{
		return (m_Iterator == m_PData->m_Data.end());
	}

	iter_type Current() { return m_Iterator; }

private:
	U* m_PData;
	iter_type m_Iterator;
};
