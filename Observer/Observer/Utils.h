#pragma once
#ifndef _UTILS_H_
#define _UTILS_H_

#include <Windows.h>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <random>

int generateRandomNumberInRange(int rangeBegin, int rangeEnd);
std::string getRandomTextColor();
std::string getCurrentTime();
bool isCursorInConsole();
void showConsoleCursor(bool showFlag);

#endif 