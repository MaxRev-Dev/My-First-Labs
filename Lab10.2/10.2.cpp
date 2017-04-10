#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <memory>
#include <Windows.h>

struct RF {
	std::string path;
	int _length;
	char ex_chr;
	char _cqnt[20];
};
bool isUint(const std::string& s) {
	return s.find_first_not_of("0123456789") == std::string::npos;
}
/*Init of RF*/
RF init(RF file) {
	std::cin >> file._cqnt;
	file._length = 30;
	file.path = "C:\\Users\\MaxRev\\Desktop\\SHORTCUTS\\MyArs10.2.txt";
	return file;
}

/*Кількіть масивів та їх довжина*/
void UniFy(RF file) {
	int _length = file._length, _qnt;
	std::string d(file._cqnt);
	std::ifstream ars(file.path);
	if (isUint(d) == false) {
		std::cout << std::endl << "Це не число! Але ось перше слово)" << std::endl;
		_qnt = 1;
	}
	else { _qnt = atoi(file._cqnt); }

	if (ars.is_open())
	{
		int i = 0, ii = 0, curI = 0;
		register char sym;
		
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
			}
			else {
				if (i > _qnt) { break; }
				arrsOfNums[i][ii] = sym;
				ii++;
				ars.get(sym);
			}

		}
		if (ars.eof()) { curI = _qnt; _qnt = i + 1; }
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
		if (curI > _qnt) std::cout << "Нажаль це всі що є(" << std::endl;
		ars.close();

		delete [] arrsOfNums;
	}
	else
	{
		std::cout << "Файл не знайдено.";
	}

}

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

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	RF file;
	std::cout << "Кількість слів які потрібно вивести: ";
	file = init(file);
	UniFy(file);
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
