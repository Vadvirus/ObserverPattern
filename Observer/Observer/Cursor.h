#pragma once
#ifndef _OBSERVED_CURSOR_H_
#define _OBSERVED_CURSOR_H_

#include "ISubject.h"

#include <Windows.h>
#include <stdexcept>

class Cursor : public ISubject {
public:
	virtual void subscribe(std::unique_ptr<IObserver> observer);
	void updateCursorPosition();
private:
	virtual void notify();

	std::vector<std::unique_ptr<IObserver>> observers;
};

#endif 