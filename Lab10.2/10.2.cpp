#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <Windows.h>

char pr[] = "Processing!";
void prompt();
void looper(int slp) {
	for (size_t i = 0; i < strlen(pr); i++) {
		std::cout << pr[i];
		Sleep(slp);
	}
}
void looper(int slp, const char* chr) {
	for (size_t i = 0; i < strlen(chr); i++) {
		std::cout << chr[i];
		Sleep(slp);
	}
}
void looper(int slp, char chr) {
	for (size_t i = 0; i < strlen(pr); i++) {
		std::cout << chr;
		Sleep(slp);
	}
}
void animateThink() {
	std::cout << std::endl;

	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);

	for (int i = 0; i < 3; i++) {
		std::cout << '\r';
		looper(30, pr);
		Sleep(50);
		std::cout << '\r';
		looper(30, ' ');
		std::cout << '\r';
		looper(30);
	}
	looper(10, '.');
	std::cout << "OK";
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = TRUE;
	SetConsoleCursorInfo(handle, &structCursorInfo);
	
	std::cout << std::endl;
}
bool isUint(const std::string& s) {
	return s.find_first_not_of("0123456789") == std::string::npos;
}
/*Кількіть масивів та їх довжина*/
char** readFile(char _cqnt[], int _length) {
	std::string d(_cqnt);
	std::ifstream ars("C:\\Users\\MaxRev\\Desktop\\MyArs10.2.txt");
	int _qnt;
	if (isUint(d) == false) {
		std::cout << std::endl << "Це не число! Але ось перше слово)"<<std::endl;
		_qnt = 1;
	}
	else { _qnt = atoi(_cqnt); }

	if (ars.is_open())
	{
		int i = 0, ii =0,curI=0;
		char sym;
		char **arrsOfNums = new char*[_qnt + 5];
		for (int i = 0; i < _qnt + 5; i++) arrsOfNums[i] = new char[_length + 5];
		ars.get(sym);
		while (!ars.eof()) {
			
			if (sym == ',') {
				ars.get(sym);
			}
			else if (sym == '\n' || sym == ' ') {
				ars.get(sym);
				if (ii != 0) {
					arrsOfNums[i][ii] = '\0';
					i++;
					ii = 0;
				}
			} else {
					if (i > _qnt) { break; }
					arrsOfNums[i][ii] = sym;
					ii++;
					ars.get(sym);
				}
			
			}
		if (ars.eof()) { curI = _qnt; _qnt = i+1; }
		arrsOfNums[i][ii] = '\0';
		
		//COUT generated
		for (int i = 0; i < _qnt; i++) {
				std::cout.width(5);
				std::cout << "[" << i + 1 << "]";
				std::cout.width(5);
				for (size_t j = 0; j < strlen(arrsOfNums[i]); j++) {
					std::cout << arrsOfNums[i][j];
				}
				std::cout.width(5);
				std::cout << std::endl;
		}
		if (curI > _qnt) std::cout<< "Нажаль це всі що є(" << std::endl;
		ars.close();
		return arrsOfNums;
	}
	else
	{
		std::cout << "Файл не знайдено.";
		return nullptr;
	}

}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char _qnt[20];

	std::cout << "Кількість слів яку потрібно вивести: ";
	std::cin >> _qnt;
	animateThink();
	char **x = readFile(_qnt, 30);
	//result
	_getch();
	prompt();
	return 0;
}

void prompt() {
	std::cout << std::endl << "Ще раз?? " << "ESC - вихід" << std::endl;
	_getch();
	if (GetAsyncKeyState(VK_ESCAPE)) exit(0);
	else main();
}