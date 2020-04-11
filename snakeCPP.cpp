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
			// Frame timer that compensate for the aspect ratio of the command line
			auto t1 = chrono::system_clock::now();
			while ((chrono::system_clock::now() - t1) < ((nSnakeDirection % 2 == 1) ? 120ms : 200ms)) {
				
				// Get the user input
				bKeyRight = (0x8000 & GetAsyncKeyState((unsigned char)('\x27'))) != 0;
				bKeyLeft = (0x8000 & GetAsyncKeyState((unsigned char)('\x25'))) != 0;

				if (bKeyRight && !bKeyRightOld) {
					nSnakeDirection++;
					if (nSnakeDirection == 4) nSnakeDirection = 0;
				}

				if (bKeyLeft && !bKeyLeftOld) {
					nSnakeDirection--;
					if (nSnakeDirection == -1) nSnakeDirection = 3;
				}

				bKeyLeftOld = bKeyRight;
				bKeyLeftOld = bKeyLeft;

			}

			// Game logic!

			// Update the snake position and move the head to the correct place
			switch (nS)
			{
			// Up
			case 0: 
				snake.push_front({ snake.front().x, snake.front().y - 1 });
				break;
			// Right
			case 1: 
				snake.push_front({ snake.front().x + 1, snake.front().y });
				break;
			// Down
			case 2: 
				snake.push_front({ snake.front().x, snake.front().y + 1 });
				break;
			// Left
			case 3: 
				snake.push_front({ snake.front().x - 1, snake.front().y });
				break;
			}
		}
	}

	return 0;
}