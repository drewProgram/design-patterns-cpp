#include "Data.h"

Data::Data(int a)
	: m_Data(a)
{
}

int Data::GetData()
{
	return m_Data;
}

void Data::SetData(int a)
{
	m_Data = a;
}
