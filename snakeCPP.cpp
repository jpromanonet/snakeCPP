// snakeCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.

// Calling libraries and namespaces
#include <iostream>
#include <list>
#include <thread>
using namespace std;
#include <Windows.h>

// Defining the console screen size
int nScreenWidth = 120;
int nScreenHeight = 30;

// Defining the snake position using an structure
struct sSnakeSegment {
	int x;
	int y;
};

// The game!
int main()
{
	// Create Screen Buffer
	wchar_t* screen = new wchar_t[nScreenWidth * nScreenHeight];
	for(int i = 0; i < nScreenWidth*nScreenHeight; i++) screen[i] = L' ':
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

	while (1) {
		// Reset to known state
		list<sSnakeSegment> snake = { {60,15},{61,15},{62,15},{63,15},{64,15},{65,15},{66,15},{67,15},{68,15},{69,15} };
		int nFoodX = 30;
		int nFoodY = 15;
		int nScore = 0;
		int nSnakeDirection = 3;
		bool bDead = false;
		bool bKeyLeft = false, bKeyRight = false, bKeyLeftOld = false, bKeyRightOld = false;

		while (!bDead) {

		}
	}

	return 0;
}