#pragma once
#ifndef _IOBSERVER_H_
#define _IOBSERVER_H_

class IObserver {
public:
	virtual void handleEvent() = 0;
	virtual ~IObserver() {}
};

#endif 