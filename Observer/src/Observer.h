#pragma once

#include "IObserver.h"
#include "Subject.h"

class Observer : public IObserver
{
private:
	std::string m_MessageFromSubject;
	Subject& m_Subject;
	static int m_StaticNumber;
	int m_Number;

public:
	Observer(Subject& subject);
	virtual ~Observer();

	void Update(const std::string& messageFromSubject) override;
	void RemoveMeFromList();
	void PrintInfo();
};