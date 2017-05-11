#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <Windows.h>

using namespace std;

struct men {
	int salary;
};
struct women {
	int chld;
	bool isMar;
	int salary;
};
struct human {
	char surname[20];
	int bYear;
	char adr[20];
	bool isMan;
	men man;
	women woman;
};

void consoleOut(human);
void findAverSal(human*, int);

human* newX(human* x, int size) {
	human *tmp = new human[size + 1];
	string str;
	for (int i = 0; i < size; i++) {
		if (x[i].surname)strcpy(tmp[i].surname, x[i].surname);
		tmp[i].bYear = x[i].bYear;

		if (x[i].adr) strcpy(tmp[i].adr, x[i].adr);
		if (x[i].isMan == true) {
			tmp[i].man.salary = x[i].man.salary;
			tmp[i].isMan = true;
		}
		else {
			tmp[i].isMan = false;
			tmp[i].woman.chld = x[i].woman.chld;
			tmp[i].woman.isMar = x[i].woman.isMar;
			tmp[i].woman.salary = x[i].woman.salary;
		}
	}
	return tmp;
}

/*Trim line from file for using in struct*/
human trim(char* x) {
	size_t i = 0;
	char nums[] = "1234567890";

	human *st = new human[1];

	char * tab = strchr(x, '|');
	int surn_len = strcspn(x, "\t");
	//surname
	for (int i = 0; i < surn_len; i++) {
		std::cout << x[i];
		st->surname[i] = x[i];
	}	st->surname[surn_len] = '\0';

	//year
	st[0].bYear = (tab[2] - '0') * 1000 + (tab[3] - '0') * 100 + (tab[4] - '0') * 10 + tab[5] - '0';
	std::cout << "\t|\t";
	cout << st[0].bYear << "\t|   ";

	char*t2 = strchr((tab + 1), '|');
	size_t num1 = strcspn(t2, nums);

	int adr_len = strcspn(t2 + 2, "\t");
	for (int i = 2; i < adr_len + 2; ++i) {
		cout << t2[i];
		st[0].adr[i - 2] = t2[i];
	} st[0].adr[adr_len] = '\0';

	cout << "\t|";
	char*t3 = strchr((t2 + 1), '|');
	char*nxt = strchr(t3 + 2, '\t');

	cout << "\t" << t3[2] << "\t|";
	st[0].isMan = (t3[2] - '0' == 1) ? true : false;

	char tonum[15];

	char*t4 = strchr((t3 + 2), '|');
	int sal_len = strcspn(t4 + 2, "\t");
	int j = 0; cout << '\t';
	for (int i = 2; i < sal_len + 2; ++i) {
		if (t4[i] != ' ') {
			cout << t4[i];
			tonum[j++] = t4[i];
		}
	} tonum[j] = '\0';

	if (st[0].isMan) {
		st[0].man.salary = atoi(tonum);
		std::cout << "\t|\t-\t|\t-\t|";
	}
	else {
		st[0].woman.salary = atoi(tonum);
		char*t5 = strchr((t4 + 1), '|');
		num1 = strcspn(t5, nums);
		std::cout << "\t|\t" << t5[2];
		st[0].woman.chld = t5[2] - '0';

		char*t6 = strchr((t5 + 1), '|');
		num1 = strcspn(t6, nums);

		std::cout << "\t|\t" << t6[2] << "\t|";
		st[0].woman.isMar = (t6[2] - '0' == 1) ? true : false;
	}

	std::cout << endl;
	return st[0];
}

/* Creating main struct*/
void structRoutine() {
	ifstream ars("...humans_DB.txt");
	if (ars.is_open())
	{
		system("cls");
		char chr[100];

		human *x = new human[1];
		int size = 0;
		std::cout << endl;

		cout << "\tПрізвище\t|\tb.y.\t|\t\tadr\t|\tg\t|     salary\t|\tchl\t|\tmar\t|";
		cout << endl << endl;

		ars.getline(chr, 70);
		while (!ars.eof()) {
			ars.getline(chr, 100);
			if (chr[0] != '\0') {
				std::cout << "  [" << size + 1 << "] " << "\t";
				x[size] = trim(chr);
				x = newX(x, ++size);
			}
		}
		findAverSal(x, size);
		ars.close();

		delete[] x;
	}
	else
	{
		std::cout << "Файл не знайдено.";
	}

}

void findAverSal(human* x, int size) {
	cout << endl << endl << "|";
	for (int i = 0; i < 127; ++i) cout << "-";

	long avg = 0;
	for (int i = 0; i < size; ++i) {
		if (x[i].isMan) {
			avg += x[i].man.salary;
		}
		else
		{
			avg += x[i].woman.salary;
		}
	}
	avg /= (size + 1);
	cout << "|\n\tСередня заробітня плата:" << avg << "\n";
	for (int i = 0; i < size; ++i) {
		if (x[i].isMan) {
			if (x[i].man.salary > avg) consoleOut(x[i]);
		}
		else {
			if (x[i].woman.salary > avg) consoleOut(x[i]);
		}
	}

	cout << "|";
	for (int i = 0; i < 127; ++i) cout << "-";
	cout << "|" << endl;
}
void consoleOut(human x) {
	for (size_t i = 0; i < strlen(x.surname); ++i) {
		cout << x.surname[i];
	} cout << "\t\t|\t";
	cout << x.bYear << "\t|  ";
	for (size_t i = 0; i < strlen(x.adr); ++i) {
		cout << x.adr[i];
	} cout << "\t|\t";
	cout << (int)x.isMan << "\t|\t";
	cout << ((x.isMan) ? (int)x.man.salary : (int)x.woman.salary);
	cout << "\t|\t";
	char tl = x.woman.chld + '0';
	cout << ((x.isMan) ? (const char)'-' : tl);
	cout << "\t|\t";
	tl = x.woman.isMar + '0';
	cout << ((x.isMan) ? (const char)'-' : tl);
	cout << "\t|";
	cout << endl;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	structRoutine();
	_getch();
	return 0;
}

