#include <windows.h>
#include <conio.h>
#include <iostream>
#include <random>

const int optionSize = 3;

void wyswietl(bool, bool, bool);
void gotoXY(int, int);
void changeColor(int);
void clear();

HWND console = GetConsoleWindow();
RECT conR;

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> distr(0, optionSize-1);

int options[optionSize] = {};
int chosen{};

bool a = true, b = true, c = true;

char k;

int main() {
	GetWindowRect(console, &conR);
	options[distr(gen)] = 1;
	wyswietl(a, b, c);
	std::cout << "Wybierz jedna z " << optionSize << " opcji."<<std::endl;
	std::cin >> chosen;
	if (options[chosen - 1] == 1) {
		if (chosen == 1) b = true; else if (chosen == 2) c = true; else a = true;
	}
	else {
		if ((chosen == 2 && options[0] == 0)||(chosen == 3 && options[0] == 0)) a = true;
		if ((chosen == 1 && options[1] == 0)||(chosen == 3 && options[1] == 0)) b = true;
		if ((chosen == 1 && options[2] == 0)||(chosen == 2 && options[2] == 0)) c = true;
	}
	wyswietl(a, b, c);
	std::cout << "Wybrales opcje " << chosen << ", czy chcesz zmienic swoj wybor? (t/n)" << std::endl;
	k = _getch();
	if (k == 't') {
		wyswietl(true, true, true);
		clear();
		if (options[chosen - 1] == 0) {
			std::cout << "WYGRANA!!!" << std::endl;
		}
		else {
			std::cout << "Niestety, nie tym razem..." << std::endl;
		}
	}
	else {
		wyswietl(true, true, true);
		clear();
		if (options[chosen - 1] == 1) {
			std::cout << "WYGRANA!!!" << std::endl;
		}
		else {
			std::cout << "Niestety, nie tym razem..." << std::endl;
		}
	}
	
	return 0;
}

void wyswietl(bool a, bool b, bool c) {
	if (!a) changeColor(15); else if (options[0] == 1) changeColor(10); else changeColor(12);
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++)
		{
			gotoXY(j, i);
			std::cout << (char)219;
		}
	}
	if (!b) changeColor(15); else if (options[1] == 1) changeColor(10); else changeColor(12);
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++)
		{
			gotoXY(j + 10, i);
			std::cout << (char)219;
		}
	}
	if (!c) changeColor(15); else if (options[2] == 1) changeColor(10); else changeColor(12);
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++)
		{
			gotoXY(j + 20, i);
			std::cout << (char)219;
		}
	}
	std::cout << std::endl << std::endl;

	changeColor(15);
}

void gotoXY(int _x, int _y) {
	COORD newPos;
	newPos.X = _x;
	newPos.Y = _y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), newPos);
}

void changeColor(int k)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k);
}

void clear() {
	gotoXY(0, 8);
	std::cout << "                                                         ";
	gotoXY(0, 8);
}