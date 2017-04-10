#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <Windows.h>

void prompt();
/*Кількіть масивів та їх довжина*/
char** readFile(int _qnt, int _length) {

	std::ifstream ars("C:\\Users\\MaxRev\\Desktop\\SHORTCUTS\\MyArs10.1.txt");

	
	if (ars.is_open())
	{
		int i = 0, ii = 0;
		char sym;
		char **arrsOfNums = new char*[_qnt+1];
		for (int i = 0; i < _qnt+1; i++) arrsOfNums[i] = new char[_length+1];
		for (int i = 0; i < _qnt+1; i++) *arrsOfNums[i] = 0;

		while (!ars.eof()) {
			ars.get(sym);

			if (sym == ' ') {
				ars.get(sym);
			}
			if (sym == '\n') {
				arrsOfNums[i][ii] = '\0';
				i++;
				ii = 0;
			}
			else {
				if (i > _qnt) { break; }
				arrsOfNums[i][ii] = sym;
				ii++;

			}
		}

		//COUT generated
		for (int i = 0; i < _qnt; i++) {
			std::cout.width(5);
			std::cout<< "[" << i + 1 << "]";
			std::cout.width(10);
			for (int j = 0; j <strlen(arrsOfNums[i]); j++) {
				std::cout<< arrsOfNums[i][j];
			}
				std::cout.width(5);
			std::cout<< std::endl;
		}

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
	int _qnt = 15;
	char **x = readFile(_qnt,20);
	size_t min = 20, max = 0,tmp=0,loc;

	int res1, res2,res3,res4;
	for (int i = 0; i < _qnt; i++) {
		for (int j = 0; j < _qnt; j++) {
			if (x[i] != x[j]) {
				loc = strlen(x[i]) + strlen(x[j]);
				if (loc > max) { res1 = i; res2 = j; max = loc; }
				if (loc < min) { res3 = i; res4 = j; min = loc; }
				
			}
		}
	}
	std::cout << "Processing";
	for (int i = 0; i < 5; i++) {
		Sleep(200);
		std::cout << ".";
	}
	std::cout << std::endl;

	std::cout << "Максимальна сума [" << res1+1<<"] + ["<<res2+1<< "] = "<< max << std::endl <<"Мінімальна сума [" << res3+1<<"] + ["<<res4+1<< "] = "<<min;
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
