#include "Utils.h"

int generateRandomNumberInRange(int rangeBegin, int rangeEnd) {
	if (rangeBegin > rangeEnd) {
		throw std::invalid_argument("Error: Invalid range!");
	}
	std::random_device randomDevice;
	std::mt19937 generator(randomDevice());
	std::uniform_int_distribution<> distribution(rangeBegin, rangeEnd);

	return distribution(generator);
}

std::string getRandomTextColor() {
	const std::vector<std::string> textColors{
		"color 1", "color 2", "color 3", "color 4",
		"color 5", "color 6", "color 9", "color A", 
		"color B", "color C", "color D", "color E"
	};

	return textColors[generateRandomNumberInRange(0, textColors.size() - 1)];
}

std::string getCurrentTime() {
	auto currentTime = std::time(0);
	auto localTime = *std::localtime(&currentTime);

	std::ostringstream os;
	os << std::put_time(&localTime, "%d-%m-%Y %H:%M:%S");

	return os.str();
}

bool isCursorInConsole() {
	HWND consoleWindow = GetConsoleWindow();
	if (!consoleWindow) {
		throw std::runtime_error("Error: Console window not found!");
	}

	RECT consoleRectangle;
	if (!GetWindowRect(consoleWindow, &consoleRectangle)) {
		throw std::runtime_error("Error: Unable to get console window rectangle!");
	}

	POINT cursorPosition;
	GetCursorPos(&cursorPosition);
	if (!GetCursorPos(&cursorPosition)) {
		throw std::runtime_error("Error: Unable to get cursor position!");
	}

	return PtInRect(&consoleRectangle, cursorPosition);
}

void showConsoleCursor(bool showFlag) {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	if (out == INVALID_HANDLE_VALUE) {
		throw std::runtime_error("Error: Invalid handle to console output!");
	}

	CONSOLE_CURSOR_INFO cursorInfo;
	if (!GetConsoleCursorInfo(out, &cursorInfo)) {
		throw std::runtime_error("Error: Failed to get console cursor information!");
	}

	cursorInfo.bVisible = showFlag;
	if (!SetConsoleCursorInfo(out, &cursorInfo)) {
		throw std::runtime_error("Error: Failed to set console cursor information!");
	}
}