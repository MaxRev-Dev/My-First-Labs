#include <iostream>
#include <string>
#include <fstream> 
#include <Windows.h>

using namespace std;
int array_size;
class table {
private:
	string name;
	int matan, program, os, alg;
public:
	void printTable();	
	friend void printTask();
	void trim(string);
};

table *arr = new table[25];
void table::trim(string str) {
	char *tml = "1234567890";
	arr[array_size].name = str.substr(0, str.find_first_of(tml));
	arr[array_size].matan=atoi(str.substr(str.find_first_of(tml)).substr(0, 1).c_str());
	arr[array_size].program = atoi(str.substr(str.find_first_of(tml)).substr(2, 3).c_str());
	arr[array_size].os = atoi(str.substr(str.find_first_of(tml)).substr(4, 5).c_str());
	arr[array_size].alg = atoi(str.substr(str.find_first_of(tml)).substr(6, 7).c_str());
}

void table::printTable() {
	cout << name << "\t" << matan << "\t" << program << "\t" << os << "\t" << alg << "\n";
}

void printTable();

int main() {
	SetConsoleOutputCP(1251);
	string lol;
	
	while (true) {
		array_size = 0;
		int menu;
		ifstream inp("D:\\MaxRev\\Desktop\\SHORTCUTS\\Labs\\table[17.1].txt");
		string tmp;
		while (inp) {
			getline(inp, tmp);
			if (tmp != "") {
				arr[array_size].trim(tmp);
				array_size++;
			}
		}

		cout << "1. Показати таблицю\n2. Завдання\n3. Вихід\n";
		cin >> menu;
		switch (menu) {
		case 1:
			printTable();
			break;
		case 2:
			printTask();
			break;
		case 3: exit(0);
			return 0;
		default: cout << "Недопустимий ввід\n";
			break;
		}
		inp.close();
	}
	return 0;
}

void printTable() {
	cout << "Прізвище\tМатан\tПрогр\tОС\tАлгебра\n";
	for (int i = 0; i < array_size; i++) {
		arr[i].printTable();
	}
}

void printTask() {
	cout << "\nМатан\tПрогр\tОС\tАлгебра\n";
	for (int i = 0; i < array_size; i++) {
		if ((arr[i].matan + arr[i].program + arr[i].os + arr[i].alg) / 4 < 4) {
			arr[i].printTable();
			cout << "average mark is " << (double)(arr[i].matan + arr[i].program + arr[i].os + arr[i].alg) / 4 << endl;
		}
	}
}