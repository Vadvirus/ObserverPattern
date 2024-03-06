#pragma once
#ifndef _ISUBJECT_H_
#define _ISUBJECT_H_

#include "IObserver.h"

#include <vector>
#include <memory>

class ISubject {
public:
	virtual void subscribe(std::unique_ptr<IObserver> observer) = 0;
	virtual ~ISubject() {}
private:
	virtual void notify() = 0;

	std::vector<std::unique_ptr<IObserver>> observers;
};

#endif 