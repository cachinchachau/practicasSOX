#include "consoleControl.h"

consoleControl consoleControl::GetInstance()
{
	static CC instance;

	return instance;
}

HANDLE consoleControl::GetConsole()
{
	return GetInstance()._console;
}

void consoleControl::SetColor(ConsoleColor textColor, ConsoleColor backgroundColor)
{
	WORD color = (backgroundColor << 4) | textColor ;
	SetConsoleTextAttribute(GetConsole(), color);
}

void consoleControl::SetPosition(short int x, short int y)
{
	COORD pos{ x, y };
	SetConsoleCursorPosition(GetConsole(), pos);
}

void consoleControl::Clear()
{
	std::cout << "\033[2J\033[1;1H";
}

void consoleControl::FillWithCharacter(char character, ConsoleColor textColor, ConsoleColor backgroundColor)
{
	COORD topLeft = { 0, 0};
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;
	HANDLE console = GetConsole();

	WORD color = (backgroundColor << 4 | textColor);
	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(console, character, screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
	FillConsoleOutputAttribute(
		console, color, screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
	SetConsoleCursorPosition(console, topLeft);
}

void consoleControl::ClearKeyBuffer()
{
	while (_kbhit())
	{
		_getch();
	}
}

int consoleControl::ReadNextKey()
{

	int KB_code = 0;

	if (_kbhit())
	{
		KB_code = _getch();
	}

	return KB_code;
}

int consoleControl::WaitForReadNextKey()
{
	int KB_code = 0;

	while (KB_code == 0)
	{
		if (_kbhit())
		{
			KB_code = _getch();
		}
	}

	return KB_code;
}

char consoleControl::WaitForReadNextChar()
{
	char c = 0;

	while (c == 0)
	{
		if (_kbhit())
		{
			c = _getch();
		}
	}

	return c;
}

void consoleControl::Lock()
{
	GetInstance()._consoleMutex->lock();
}

void consoleControl::Unlock()
{
	GetInstance()._consoleMutex->unlock();
}


