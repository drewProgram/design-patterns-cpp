#pragma once

#include "ISubject.h"

#include <list>

/**
 * The subject owns some important state and notifies observers when the
 * state changes.
 */
class Subject : public ISubject
{
private:
	std::list<IObserver*> m_ListObserver;
	std::string m_Message;

public:
	virtual ~Subject();

	/**
	 * The subscription management methods
	 */
	void Attach(IObserver* observer) override;
	void Detach(IObserver* observer) override;
	void Notify() override;
	void CreateMessage(std::string message = "Empty");
	void PrintObserversCount();
	/**
	 * Usually, the subscription logic is only a fraction of what a Subject
	 * can really do. Subjects commonly hold some important business logic,
	 * that triggers a notification method whenever something important
	 * is about to happen (or after it).
	 */
	void SomeBusinessLogic();
};