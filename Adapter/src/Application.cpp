#include <iostream>

#include "Target.h"
#include "Adaptee.h"
#include "Adapter.h"

/**
 * The client code supports all classes that follow the Target interface.
 */
void ClientCode(const Target* target)
{
	std::cout << target->Request();
}

int main()
{
	std::cout << "ADAPTER PATTERN!" << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;

	std::cout << "Client: I can work just fine with the Target objects: " << std::endl;
	Target* target = new Target;
	ClientCode(target);
	std::cout << "\n\n";

	Adaptee* adaptee = new Adaptee;
	std::cout << "Client: The Adaptee class has a weird interface." <<
		" See, I don't understand it:" << std::endl;
	std::cout << "Adaptee: " << adaptee->SpecificRequest();
	std::cout << "\n\n";

	std::cout << "Client: But I can work with it via the Adapter: " << std::endl;
	Adapter* adapter = new Adapter(adaptee);
	ClientCode(adapter);
	std::cout << "\n";

	delete target;
	delete adaptee;
	delete adapter;
	
	return 0;
}