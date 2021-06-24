#include "Subject.h"

#include <iostream>

Subject::~Subject()
{
	std::cout << "Goodbye, I was the Subject." << std::endl;
}

void Subject::Attach(IObserver* observer)
{
	m_ListObserver.push_back(observer);
}

void Subject::Detach(IObserver* observer)
{
	m_ListObserver.remove(observer);
}

void Subject::Notify()
{
	std::list<IObserver*>::iterator iterator = m_ListObserver.begin();

	PrintObserversCount();

	while (iterator != m_ListObserver.end())
	{
		(*iterator)->Update(m_Message);
		++iterator;
	}
}

void Subject::CreateMessage(std::string message)
{
	this->m_Message = message;
	Notify();
}

void Subject::PrintObserversCount()
{
	std::cout << "There are " << m_ListObserver.size() <<
		" observers in the list." << std::endl;
}

void Subject::SomeBusinessLogic()
{
	this->m_Message = "change message message";
	Notify();
	std::cout << "I'm about to do something important" << std::endl;
}
