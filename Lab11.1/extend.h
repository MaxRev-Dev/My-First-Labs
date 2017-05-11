#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <algorithm>
#include <string>
#include <Windows.h>
#include "D:\important!labs_path\filecfg.h"

void prompt();
void prompt(int);
void loop();
const char *numsCan(int);
using namespace std;

string path = glpath+"MyArs11.1.txt";

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

class Student
{
private:
	char surname[20];
	int matan;
	int prog;
	int OS;
	int algGeo;
	
public:	
	const enum x {
		mat,prg,os,alg
	};
	x xd;
	friend int findTr(Student*,int,int);
	friend void readFile(ifstream);
	void newParam();
	void trim(char*);
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

void Student::newParam() {
	ofstream ars(path, ios_base::app);
	if (ars.is_open()) {
		char a;
		cin.get(a);
		cout << "Введіть ім'я студента: ";
		cin.get(this->surname, 20);
		cout << "Оцінка з матаналізу: ";
		cin >> this->matan;
		cout << "Оцінка з програмування: ";
		cin >> this->prog;
		cout << "Оцінка з ОС: ";
		cin >> this->OS;
		cout << "Оцінка з Алегебри та геометрії: ";
		cin >> this->algGeo;
		cout << endl;
		ars << '\n' << this->surname << "\t\t|\t" << this->matan << "\t" << this->prog << "\t" << this->OS << "\t" << this->algGeo << "\t|";
		ars.close();
	}

}

Student* expand(Student*x,int size) {
	Student *tmp = new Student[size+1];
	for (int i = 0; i < size; i++) {
		tmp[i] = x[i];
	} 
	return tmp;
}

/*Trim line from file for using in class(struct)*/
void Student::trim(char* x) {
	size_t i = 0;
	char nums[] = "1234567890";

	char * tab = strchr(x, '|');
	int surnl = strcspn(x, tab);
	for (int i = 0; i < surnl; i++) {
		cout << x[i];
		this->surname[i] = x[i];
	}	this->surname[surnl] = '\0';
	char*t2 = strchr((tab + 1), '\t');
	size_t num1 = strcspn(t2, nums);
	cout << t2[0] << t2[1];
	this->matan = t2[1] - '0';

	char*t3 = strchr((t2 + 1), '\t');
	num1 = strcspn(t3, nums);
	cout << t3[0] << t3[1];
	this->prog = t3[1] - '0';

	char*t4 = strchr((t3 + 1), '\t');
	num1 = strcspn(t4, nums);
	cout << t4[0] << t4[1];
	this->OS = t4[1] - '0';

	char*t5 = strchr((t4 + 1), '\t');
	num1 = strcspn(t5, nums);
	cout << t5[0] << t5[1];
	this->algGeo = t5[1] - '0';
	cout << endl;
}

int findTr(Student*x, int size, int desn) {
	int counter=0,reaper =0;
	cout << endl;

	for (int i = 0; i < size; ++i) {
		
		for (int j = x[i].mat; j < x[i].alg; j++) {
			if (x[i].gett(j) == desn) {
				counter++;
			}
		}
		if (counter != 0)
		{
			reaper++;
			for (size_t j = 0; j < strlen(x[i].surname); ++j) {
				std::cout << x[i].surname[j]; 
			} cout << " має " << counter << " "<< numsCan(desn) << ((counter == 1) ? "ку" : ((counter == 2|| counter == 3|| counter == 4) ? "ки" : "ок")) << endl;
			counter = 0;
		}
	} return reaper;
}

/*Reading file and creating list(struct)*/
void readFile(std::ifstream ars) {
	if (ars.is_open())
	{
		int desn;
		char chr[50];
		Student *MainList = new Student[1];
		int size = 0;
		cout << endl;
		while (!ars.eof()) {
			ars.getline(chr, 50);
			if (chr[0] != '\0') {
				cout << "   [" << size + 1 << "] " << "\t";
				MainList[size].trim(chr); ++size;
				MainList = expand(MainList, size);
			}
		}

		cout << "Знайти оцінку: ";
		cin >> desn;
		int zz = findTr(MainList, size, desn);
		cout << endl<< "Отже, " << zz << " з "<< size << " cтудентів ма" <<((zz == 1) ? "є": "ють") << " "<< numsCan(desn)<< "ки"<<endl;
		cout << endl;
		ars.close();

		cout << "Потрібно щось видалити?? [enter]"<<endl;
		_getch();
		if (GetKeyState(VK_RETURN) < 0) {
			int x;
			cout << "Номер запису:  ";
			cin >> x;
			--x;

			ofstream xxx(path, ios_base::trunc);
			for (int i = x; i < size - 1; ++i) {
				MainList[i] = MainList[i + 1];
			}
			for (int i = 0; i < size - 1; ++i) {
				for (size_t j = 0; j < strlen(MainList[i].surname); j++) {
					xxx << MainList[i].surname[j];
				}
				xxx << "\t\t|\t"<< MainList[i].matan << "\t" << MainList[i].prog << "\t" << MainList[i].OS << "\t" << MainList[i].algGeo <<"\t|"<<endl;
			}
			xxx.close();

			readFile(ifstream(path));
		}
		MainList = nullptr;
		loop();
	}
	else
	{
		std::cout << "Файл не знайдено.";
	}
}

void loop() {
		cout << "Додати новий запис?? [enter], ESC - exit, Refresh - R" << endl;
		_getch();
		if (GetAsyncKeyState(VK_ESCAPE)<0) exit(0);
		if (GetAsyncKeyState(0x52)<0) prompt(1);
		if (GetAsyncKeyState(VK_RETURN)<0) {
			Student *X = new Student();
			X->newParam();			
			readFile(ifstream(path));
			prompt(1);
		}
		else prompt(1);
}
