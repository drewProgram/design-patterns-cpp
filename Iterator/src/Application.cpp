#include <iostream>

#include "Container.h"
#include "Iterator.h"
#include "Data.h"

/**
 * The client code may or may not know about the Concrete Iterator or Collection
 * classes, for this implementation the container is generic so you can
 * use it with an int or with a custom class.
 */
void ClientCode()
{
	std::cout << "_________________Iterator with int_______________________" << std::endl;

	Container<int> container;
	for (int i = 0; i < 10; i++)
		container.Add(i);

	Iterator<int, Container<int>>* iterator = container.CreateIterator();
	for (iterator->First(); !iterator->IsDone(); iterator->Next())
		std::cout << *iterator->Current() << std::endl;

	Container<Data> container2;
	Data a(100), b(1000), c(10000);
	container2.Add(a);
	container2.Add(b);
	container2.Add(c);

	std::cout << "__________________Iterator with custom Class_______________________" << std::endl;
	
	Iterator<Data, Container<Data>>* iterator2 = container2.CreateIterator();
	for (iterator2->First(); !iterator2->IsDone(); iterator2->Next())
		std::cout << iterator2->Current()->GetData() << std::endl;

	delete iterator;
	delete iterator2;
}

int main()
{
	std::cout << "ITERATOR PATTERN" << std::endl;
	std::cout << "----------------------------------------------------\n" << std::endl;

	ClientCode();

	return 0;
}