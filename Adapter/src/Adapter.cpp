#include "Adapter.h"

Adapter::Adapter(Adaptee* adaptee)
	: m_Adaptee(adaptee)
{
}

std::string Adapter::Request() const
{
	std::string toReverse = this->m_Adaptee->SpecificRequest();
	std::reverse(toReverse.begin(), toReverse.end());

	return "Adapter: (TRANSLATED) " + toReverse;
}
