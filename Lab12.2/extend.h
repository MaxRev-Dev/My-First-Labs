#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <Windows.h>
#include "D:\important!labs_path\filecfg.h"

void prompt(int);
void loop();
const char *numsCan(int);
using namespace std;
struct Student
{
	long width;
	char surname[20];
	int matan;
	int prog;
	int OS;
	int algGeo;
	const enum x {
		mat, prg, os, alg
	};
	x xd;
	int gett(int i) {
		switch (i)
		{
		case Student::x::mat:
			return this->Student::matan;
			break;
		case Student::x::prg:
			return this->Student::prog;
			break;
		case Student::x::os:
			return this->Student::OS;
			break;
		case Student::x::alg:
			return this->Student::algGeo;
			break;
		default:
			return xd;
		}
	}

};
struct RF {
	std::string path;
};
/*bool isUint(const std::string& s) {
return s.find_first_not_of("0123456789") == std::string::npos;
}*/
/*Init of RF*/
RF init(RF &file) {
	file.path = "MyArs12.2.txt";
	return file;
}

/*Open file*/
std::ifstream UniFy(RF file) {
	extern string glpath;
	string fl = glpath;
	fl += file.path;
	std::ifstream ars(fl);
	/*if (isUint(d) == false) {
	std::cout << std::endl << "Це не число!" << std::endl;
	prompt();
	}
	else { _qnt = atoi(file._cqnt); }*/
	return ars;
}

/*Creating bigger struct
Current struct and it`s size*/
Student* newStud(Student* x, int size) {
	Student *tmp = new Student[size + 1];

	for (int i = 0; i < size; i++) {
		tmp[i].algGeo = x[i].algGeo;
		tmp[i].matan = x[i].matan;
		tmp[i].OS = x[i].OS;
		tmp[i].prog = x[i].prog;
		strcpy_s(tmp[i].surname, x[i].surname);
	}

	return tmp;
}

/*Trim line from file for using in struct*/
Student trim(char* x) {
	size_t i = 0;
	char nums[] = "1234567890";

	Student *st = new Student[1];
	char * tab = strchr(x, '|');
	int surnl = strcspn(x, tab);
	for (int i = 0; i < surnl; i++) {
		cout << x[i];
		st->surname[i] = x[i];
	}	st->surname[surnl] = '\0';
	char*t2 = strchr((tab + 1), '\t');
	size_t num1 = strcspn(t2, nums);
	cout << t2[0] << t2[1];
	st[0].matan = t2[1] - '0';

	char*t3 = strchr((t2 + 1), '\t');
	num1 = strcspn(t3, nums);
	cout << t3[0] << t3[1];
	st[0].prog = t3[1] - '0';

	char*t4 = strchr((t3 + 1), '\t');
	num1 = strcspn(t4, nums);
	cout << t4[0] << t4[1];
	st[0].OS = t4[1] - '0';

	char*t5 = strchr((t4 + 1), '\t');
	num1 = strcspn(t5, nums);
	cout << t5[0] << t5[1];
	st[0].algGeo = t5[1] - '0';
	cout << endl;
	return st[0];
}

const char* numsCan(int x) {
	switch (x)
	{
	case 1: {
		return "одинич";
		break;
	}
	case 2: {
		return "двій";
		break;
	}
	case 3: {
		return "трій";
		break;
	}
	case 4: {
		return "четвір";
		break;
	}
	case 5: {
		return "п'ятір";
		break;
	}
	case 6: {
		return "шестір";
		break;
	}
	case 7: {
		return "сім";
		break;
	}
	case 8: {
		return "вісім";
		break;
	}
	case 9: {
		return "дев'ят";
		break;
	}
	case 10: {
		return "десят";
		break;
	}
	default:
		return "";
		break;
	}
}
int findTr(Student* x, int size, int desn) {
	int counter = 0, reaper = 0;
	cout << endl;

	for (int i = 0; i < size; ++i) {

		for (int j = Student::x::mat; j < Student::x::alg; j++) {
			if (x[i].gett(j) == desn) {
				counter++;
			}
		}
		if (counter != 0)
		{
			reaper++;
			for (size_t j = 0; j < strlen(x[i].surname); ++j) {
				std::cout << x[i].surname[j];
			} cout << " має " << counter << " " << numsCan(desn) << ((counter == 1) ? "ку" : ((counter == 2 || counter == 3 || counter == 4) ? "ки" : "ок")) << endl;
			counter = 0;
		}
		/* // Old Style
		if (x[i].algGeo == 3 || x[i].matan == 3 || x[i].OS == 3 || x[i].prog == 3) {
		for (size_t j = 0; j < strlen(x[i].surname); ++j) {
		std::cout << x[i].surname[j];
		} std::cout << endl; counter++;
		}*/
	} return reaper;
}

/*Reading file and creating struct*/
void readFile(std::ifstream ars) {
	if (ars.is_open())
	{
		int desn;
		char chr[50];
		Student *st = new Student[1];
		int size = 0;
		cout << endl;
		while (!ars.eof()) {
			ars.getline(chr, 50);
			if (chr[0] != '\0') {
				cout << "   [" << size + 1 << "] " << "\t";
				st[size] = trim(chr);
				st = newStud(st, ++size);
			}
		}

		cout << "Знайти оцінку: ";
		cin >> desn;
		int zz = findTr(st, size, desn);
		cout << endl << "Отже, " << zz << " з " << size << " cтудентів ма" << ((zz == 1) ? "є" : "ють") << " " << numsCan(desn) << "ки" << endl;
		cout << endl;
		ars.close();

		cout << "Потрібно щось видалити?? [enter]" << endl;
		_getch();
		if (GetKeyState(VK_RETURN) < 0) {
			int x;
			cout << "Номер запису:  ";
			cin >> x;
			x -= 1;

			RF file;
			file = init(file);
			ofstream xxx(file.path, ios_base::trunc);
			for (int i = x; i < size - 1; ++i) {
				st[i] = st[i + 1];
			}
			for (int i = 0; i < size - 1; ++i) {
				for (size_t j = 0; j < strlen(st[i].surname); j++) {
					xxx << st[i].surname[j];
				}
				xxx << "\t\t|\t" << st[i].matan << "\t" << st[i].prog << "\t" << st[i].OS << "\t" << st[i].algGeo << "\t|" << endl;
			}
			xxx.close();
		}
		delete[] st;

		loop();
	}
	else
	{
		std::cout << "Файл не знайдено.";
	}
}
void createNew() {
	RF file;
	file = init(file);
	ofstream ars(file.path, ios_base::app);
	if (ars.is_open()) {
		Student x;
		char a;
		cin.get(a);
		cout << "Введіть ім'я студента: ";
		cin.get(x.surname, 20);
		cout << "Оцінка з матаналізу: ";
		cin >> x.matan;
		cout << "Оцінка з програмування: ";
		cin >> x.prog;
		cout << "Оцінка з ОС: ";
		cin >> x.OS;
		cout << "Оцінка з Алегебри та геометрії: ";
		cin >> x.algGeo;
		cout << endl;
		ars << '\n' << x.surname << "\t\t|\t" << x.matan << "\t" << x.prog << "\t" << x.OS << "\t" << x.algGeo << "\t|";
		ars.close();
	}
}
void loop() {
	cout << "Додати новий запис?? [enter], ESC - exit, Refresh - R" << endl;
	_getch();
	if (GetAsyncKeyState(VK_ESCAPE) < 0) exit(0);
	else if (GetAsyncKeyState(0x52) < 0) prompt(1);
	else if (GetAsyncKeyState(VK_RETURN) < 0) {
		RF file;
		init(file);
		createNew();
		prompt(1);
	}
	else {
		prompt(0);
	}
}