#pragma once

#include "Target.h"
#include "Adaptee.h"

class Adapter : public Target
{
private:
	Adaptee* m_Adaptee;

public:
	Adapter(Adaptee* adaptee);

	std::string Request() const override;
};