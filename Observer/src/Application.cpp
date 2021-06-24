#include <iostream>

#include "Subject.h"
#include "Observer.h"

void ClientCode()
{
	Subject* subject = new Subject();
	Observer* observer1 = new Observer(*subject);
	Observer* observer2 = new Observer(*subject);
	Observer* observer3 = new Observer(*subject);
	Observer* observer4;
	Observer* observer5;

	subject->CreateMessage("Hello World!! :D");
	observer3->RemoveMeFromList();

	subject->CreateMessage("The weather is hot today! :p");
	observer4 = new Observer(*subject);

	observer2->RemoveMeFromList();
	observer5 = new Observer(*subject);

	subject->CreateMessage("My new car is great! ;)");
	observer5->RemoveMeFromList();

	observer4->RemoveMeFromList();
	observer1->RemoveMeFromList();

	delete observer5;
	delete observer4;
	delete observer3;
	delete observer2;
	delete observer1;
	delete subject;
}

int main()
{
	std::cout << "--------------------------------- OBSERVER PATTERN ------------------------------------------" << std::endl;

	ClientCode();

	return 0;
}
