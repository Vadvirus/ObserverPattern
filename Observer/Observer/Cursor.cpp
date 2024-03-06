#include "Cursor.h"

void Cursor::subscribe(std::unique_ptr<IObserver> observer) {
	if (!observer) {
		throw std::invalid_argument("Error: Invalid observer pointer!");
	}
	observers.push_back(std::move(observer));
}

void Cursor::updateCursorPosition() {
	notify();
}

void Cursor::notify() {
	for (auto& observer : observers) {
		observer->handleEvent();
	}
}