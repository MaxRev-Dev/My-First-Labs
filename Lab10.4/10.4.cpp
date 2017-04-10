#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <memory>
void prompt();
using namespace std;
int count;
double X;
long double *x;
char pr[] = "Processing!";
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
void readFile(char _cqnt[], int _length) {
	std::string d(_cqnt);
	std::ifstream ars("C:\\Users\\MaxRev\\Desktop\\SHORTCUTS\\MyArs10.4.txt");
	int _qnt;
	if (isUint(d) == false) {
		std::cout << std::endl << "Це не число! Але ось перше число)" << std::endl;
		_qnt = 1;
	}
	else { _qnt = atoi(_cqnt); }

	if (ars.is_open())
	{
		int i = 0, num = 0, arr = 0;
		char sym, **arrsOfNums = new char*[_qnt];
		for (int i = 0; i <= _qnt; i++)	arrsOfNums[i] = new char[_length];
		ars.get(sym);
		while (!ars.eof()) {

			if (arr == _qnt) break;
			
			if (sym == '-' || sym == '.' || isdigit(sym)) {
				arrsOfNums[arr][num] = sym;
				num++;
			}
			 if (sym == ' ' ) {
				arrsOfNums[arr][num] = '\0';
				while (sym == ' ')
				{
					ars.get(sym);
				}
				arr++; num = 0;
				arrsOfNums[arr][num] = sym;
				num++;
			} 
			 ars.get(sym);


		}

		//convert array... to double nums
		if (arr < _qnt) { _qnt = arr+1; i = -3; }

		x = new long double[_qnt];
		std::cout << std::endl << "Числа з файлу..." << std::endl;
		for (int i = 0; i < _qnt; i++) {
				x[i] = strtold(arrsOfNums[i], NULL);
				std::cout << "arr[" << i + 1 << "] = " << x[i] << std::endl;
		}
		if (i == -3) cout << "Це всі що є!" << endl;
		ars.close();

		if (arrsOfNums) {
			 delete [] *arrsOfNums;
		}
		
	}
	else
	{
		std::cout << "Файл не знайдено.";
	}

}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "\n";

	char _qnt[20];
	std::cout << "Кількість чисел, які потрібно вивести: ";
	std::cin >> _qnt;
	animateThink();
	readFile(_qnt, 30);
	
	if (x) {
		delete [] x;
	}
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