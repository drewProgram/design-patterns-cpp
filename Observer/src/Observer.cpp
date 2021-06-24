#include "Observer.h"

#include <iostream>

int Observer::m_StaticNumber = 0;

Observer::Observer(Subject& subject)
	: m_Subject(subject)
{
	this->m_Subject.Attach(this);
	std::cout << "Hi, I was the Observer \"" << ++Observer::m_StaticNumber
		<< "\"." << std::endl;
	this->m_Number = Observer::m_StaticNumber;
}

Observer::~Observer()
{
	std::cout << "Goodbye, I was the Observer \"" <<
		this->m_Number << "\"." << std::endl;
}

void Observer::Update(const std::string& messageFromSubject)
{
	m_MessageFromSubject = messageFromSubject;
	PrintInfo();
}

void Observer::RemoveMeFromList()
{
	m_Subject.Detach(this);
	std::cout << "Observer \"" << m_Number <<
		"\" removed from the list." << std::endl;
}

void Observer::PrintInfo()
{
	std::cout << "Observer \"" << this->m_Number <<
		"\": a new message is available --> " << 
		this->m_MessageFromSubject << std::endl;
}
