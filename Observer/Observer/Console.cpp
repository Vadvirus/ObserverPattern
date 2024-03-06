#include "Console.h"

void Console::handleEvent() {
	std::ofstream fout("log.txt", std::ios::app);
	if (!fout.is_open()) {
		throw std::runtime_error("Error: Unable to open log file!");
	}

	std::string textColor;

	bool isCursorInConsoleNow = isCursorInConsole();
	static bool isCursorInConsoleBefore = !isCursorInConsoleNow;
	
	if (isCursorInConsoleNow && !isCursorInConsoleBefore) {
		fout << "Enter: " << getCurrentTime() << std::endl;
		std::system(getRandomTextColor().c_str());
		isCursorInConsoleBefore = true;
	}
	else if(!isCursorInConsoleNow && isCursorInConsoleBefore) {
		fout << "Leave: " << getCurrentTime() << std::endl;
		std::system("color 7");
		isCursorInConsoleBefore = false;
	}
	fout.close();
}