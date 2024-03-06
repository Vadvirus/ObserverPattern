#pragma once
#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include "IObserver.h"
#include "Utils.h"

#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>

class Console : public IObserver {
public:
	virtual void handleEvent() override;
};

#endif 