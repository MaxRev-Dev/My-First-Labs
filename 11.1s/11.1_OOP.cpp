#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <Windows.h>

using namespace std;
string globalPath = "....\\marks_DB.txt";

class Student
{
public:
	char surname[20];
	int matan;
	int prog;
	int OS;
	int algGeo;

};

void consoleOut(Student x) {
	for (size_t i = 0; i < strlen(x.surname); ++i) {
		cout << x.surname[i];
	}
	cout << "\t"<< x.matan << "\t" << x.OS<<endl;
}
void consoleOutFull(Student x) {
	for (size_t i = 0; i < strlen(x.surname); ++i) {
		cout << x.surname[i];
	}
	cout << "\t"<< x.matan << "\t"<< x.prog << "\t" << x.OS<< "\t"<< x.algGeo << endl;
}
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
Student trim(char* x) {
	/*Please, don't try to recognise this. MaxRev */
	size_t i = 0;
	char nums[] = "1234567890";

	Student st;
	char * tab = strchr(x, '|');
	int surnl = strcspn(x, tab);
	for (int i = 0; i < surnl; i++) {
		st.surname[i] = x[i];
	}	st.surname[surnl] = '\0';
	char*t2 = strchr((tab + 1), '\t');
	size_t num1 = strcspn(t2, nums);
	st.matan = t2[1] - '0';

	char*t3 = strchr((t2 + 1), '\t');
	num1 = strcspn(t3, nums);
	st.prog = t3[1] - '0';

	char*t4 = strchr((t3 + 1), '\t');
	num1 = strcspn(t4, nums);
	st.OS = t4[1] - '0';

	char*t5 = strchr((t4 + 1), '\t');
	num1 = strcspn(t5, nums);
	st.algGeo = t5[1] - '0';
	return st;
}
void readFile() {
	ifstream ars(globalPath);
	if (ars.is_open())
	{
		char chr[50];
		Student *st = new Student[1];
		int size = 0;
		cout << endl;
		
		cout << endl << "\tПрізвище    | Матан | Прога | ОС | Алгебра і геом." << endl; // Весь файл
		while (!ars.eof()) {
			ars.getline(chr, 50);
			if (chr[0] != '\0') {
				cout << "   [" << size + 1 << "] " << "\t";
				st[size] = trim(chr);
				consoleOutFull(st[size]); // Весь файл
				st = newStud(st, ++size);
			}
		}
		cout <<endl<< "\tПрізвище     |  Матан | ОС"<<endl;
		for (int i = 0; i < size; ++i) {
			cout << "   [" << i + 1 << "] " << "\t";
			consoleOut(st[i]);
		}
		ars.close();

		delete[] st;

	}
	else
	{
		std::cout << "Файл не знайдено.";
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	readFile();
	_getch();
	return 0;
}
