#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include "D:\important!labs_path\filecfg.h"
using namespace std;

void prompt();
void prompt(int);
struct RF {
	std::string path;
};
bool isUint(const std::string& s) {
	return s.find_first_not_of("0123456789") == std::string::npos;
}
/*Init of RF*/
RF init(RF file) {
	file.path = "MyArs11.2.txt";
	return file;
}

/*Open file*/
std::ifstream UniFy(RF file) {
	extern string glpath;
	string fl = glpath;
	fl += file.path;
	std::ifstream ars(fl);
	return ars;
}

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

void consoleOut(human, human, int, int);
void findSameSal(human*, int);
void writeFile(human&);
void outFile(human*, int);

/*Creating bigger struct
Current struct and it`s size*/
human* newX(human* x, int size) {
	human *tmp = new human[size + 1];
	string str;
	for (int i = 0; i < size; i++) {
		if (x[i].surname)strcpy_s(tmp[i].surname, x[i].surname);
		tmp[i].bYear = x[i].bYear;

		if (x[i].adr) strcpy_s(tmp[i].adr, x[i].adr);
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
	st[0].bYear = (tab[2]-'0')*1000+(tab[3]-'0')*100+(tab[4]-'0')*10+tab[5]-'0';
	std::cout << "\t|\t";
	cout << st[0].bYear<< "\t|   ";

	char*t2 = strchr((tab + 1), '|');
	size_t num1 = strcspn(t2, nums);
 
	int adr_len = strcspn(t2+2, "\t");
	for (int i = 2; i < adr_len+2; ++i) {
		cout << t2[i];
		st[0].adr[i-2] = t2[i];
	} st[0].adr[adr_len] = '\0';

	cout << "\t|";
	char*t3 = strchr((t2 + 1), '|');
	char*nxt = strchr(t3 + 2, '\t');
	
	cout << "\t"<<t3[2]<<"\t|";
	st[0].isMan = (t3[2] - '0' == 1) ? true:false ;

	char tonum[15];

	char*t4 = strchr((t3 + 2), '|');
	int sal_len = strcspn(t4 + 2, "\t");
	int j = 0; cout << '\t';
	for (int i = 2; i < sal_len+2; ++i) {
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
			st[0].woman.salary =atoi(tonum);
			char*t5 = strchr((t4 + 1), '|');
			num1 = strcspn(t5, nums);
			std::cout << "\t|\t" << t5[2];
			st[0].woman.chld = t5[2] - '0';

			char*t6 = strchr((t5 + 1), '|');
			num1 = strcspn(t6, nums);
			
			std::cout << "\t|\t"<< t6[2] << "\t|";
			st[0].woman.isMar = (t6[2] - '0' == 1) ? true : false;
		}
	
	std::cout << endl;
	return st[0];
}

/* Creating main struct*/
void structRoutine(ifstream ars) {
	if (ars.is_open())
	{

		system("cls");
		char chr[100];

		human *x = new human[1];
		int size = 0;
		std::cout << endl;

		ars.getline(chr, 70);

		cout << "\tПрізвище\t|\tb.y.\t|\t\tadr\t|\tg\t|     salary\t|\tchl\t|\tmar\t|";
		cout << endl<<endl;

		while (!ars.eof()) {
			ars.getline(chr, 100);
			if (chr[0] != '\0') {
				std::cout << "  [" << size + 1 << "] " << "\t";
				x[size] = trim(chr);
				x = newX(x, ++size);
			}
		}
		findSameSal(x, size);
		std::cout << endl;
		ars.close();
		std::cout << "Потрібно щось видалити?? [enter]" << endl;
		_getch();
		if (GetKeyState(VK_RETURN) < 0) {
			int z;
			cout << "Номер запису:  ";
			cin >> z;
			z -= 1;
			for (int i = z; i < size - 1; ++i) {
				x[i] = x[i + 1];
			}
			outFile(x, size);
		}
		
		cout << "Додати новий запис?? [enter]";
		_getch();
		if (GetKeyState(VK_RETURN) < 0) {
			
			writeFile(x[size]);
			outFile(x, size+2);
			x = newX(x, size++);
			
		}

		delete[] x;
		prompt(1);
	}
	else
	{
		std::cout << "Файл не знайдено.";
	}

}

void outFile(human *x, int size) {
	RF file;
	file = init(file);
	ofstream xxx(file.path, ios_base::trunc);
	xxx << "\tПрізвище\t\t|\tb.y.\t\t|\t\tadr\t\t\t\t|\tg\t|     salary\t|\tchl\t|\tmar |\n";

	for (int i = 0; i < size -1; ++i) {
		for (size_t j = 0; j < strlen(x[i].surname); j++) {
			xxx << x[i].surname[j];
		}
		xxx << "\t\t|\t" << x[i].bYear;
		xxx << "\t| ";
		for (size_t j = 0; j < strlen(x[i].adr); j++) {
			xxx << x[i].adr[j];
		}
		xxx << "\t\t|\t" << ((x[i].isMan) ? (const char*)"1" : (const char*)"0");
		xxx << "\t|\t" << ((x[i].isMan) ? x[i].man.salary : x[i].woman.salary);
		char c = x[i].woman.chld + '0';
		xxx << "\t|\t" << ((x[i].isMan) ? (const char)'-' : c);
		xxx << "\t|\t" << ((x[i].isMan) ? "-" : ((x[i].woman.isMar) ? "1" : "0")) << "\t|" << endl;
	}
	xxx.close();
}

/*Finding same salary*/
void findSameSal(human* x,int size) {
	cout << endl <<endl<< "|";
	for (int i = 0; i < 127; ++i) cout << "-";
	cout << "|\n\tОднакова заробітня плата:\n";
	for (int i = 0; i < size-1; ++i) {
		for (int j = i + 1; j < size; ++j) {
			if (x[i].isMan&&x[j].isMan) {
				if (x[i].man.salary == x[j].man.salary)
				consoleOut(x[i], x[j], i, j);
			}
			else if (!x[i].isMan&&x[j].isMan) {
				if (x[i].woman.salary == x[j].man.salary)
					consoleOut(x[i], x[j], i, j);
			} else if (x[i].isMan&&!x[j].isMan) {
				if (x[i].man.salary == x[j].woman.salary)
					consoleOut(x[i], x[j], i, j);
			}
			else {
				if (x[i].woman.salary == x[j].woman.salary)
					consoleOut(x[i], x[j], i, j);
			}
		}
	}

	cout << "|";
	for (int i = 0; i < 127; ++i) cout << "-";
	cout << "|" << endl;
}
void consoleOut(human w, human y, int i, int j) {
	human *x = new human[2];
	x[0] = w;
	x[1] = y;
	cout << endl;

	for (int j = 0; j < 2; ++j) {
		for (size_t i = 0; i < strlen(x[j].surname); ++i) {
			cout << x[j].surname[i];
		} cout << "\t\t|\t";
		cout << x[j].bYear << "\t|  ";
		for (size_t i = 0; i < strlen(x[j].adr); ++i) {
			cout << x[j].adr[i];
		} cout << "\t|\t";
		cout << (int)x[j].isMan << "\t|\t";
		cout << ((x[j].isMan) ? (int) x[j].man.salary : (int)x[j].woman.salary);
		cout << "\t|\t";
		char tl = x[j].woman.chld + '0';
		cout << ((x[j].isMan) ? (const char)'-' : tl);
		cout << "\t|\t";
		tl = x[j].woman.isMar + '0';
		cout << ((x[j].isMan) ? (const char)'-': tl);
		cout << "\t|";
		cout << endl;
	}
	delete x;
}
void writeFile(human &x) {
	cout << endl;

	cout << "Введіть П.І.Б: ";
	cin.ignore();
	cin.getline(x.surname, sizeof(x.surname));
	cout << "Рік народження: ";
	cin >> x.bYear;
	cout << "Адреса: ";
	cin.ignore();
	
	cin.getline(x.adr, sizeof(x.adr));
	cout << "Стать Ч-[1], Ж-[0]: ";
	cin >> x.isMan;
	cout << "Зарплата: ";
	
	cin >> ((x.isMan) ? x.man.salary : x.woman.salary);

	if (!x.isMan) {
		cout << "Кількість дітей: ";
		cin >> x.woman.chld;
		cout << "Одружена? [1][0]: ";
		cin >> x.woman.isMar;
	}
}
