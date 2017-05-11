#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <Windows.h>

struct lines
{
	std::string name,number;
	int size;
} *line;
using namespace std;
void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ofstream data("....FILE_OUT_PATH....txt", ios::trunc);
	string str[30],default_nums="+0123456789";
	int iter = -1;
	cout << "Введіть П.І.Б. і через пробіл телефон. Пуста стрічка для завершення" << endl;
	cout << "\tП.І.Б.\t|\tНомери\t\t|" << endl;
	while (true) {
		++iter;
		getline(cin, str[iter]);
		if (str[iter].empty()) break;
	}

	line = new lines[iter];
	
	for (int i = 0; i < iter; ++i) {
	  size_t numStart= str[i].find_first_of(default_nums);
	  line[i].name = str[i].substr(0, numStart);
	  line[i].number = str[i].substr(numStart);
	}
	cout << "\t\t---Структура---"<<endl;
	cout << "\t\tП.І.Б.\t\t|\t\tНомери\t\t|" << endl;

	for (int i = 0; i < iter; ++i) cout << "  [" << i + 1 << "]  " << line[i].name << "\t-|-\t" << line[i].number << endl;
	
	for (int i = 0; i < iter; ++i) data << "  [" << i + 1 << "]  " << line[i].name << "\t-|-\t" << line[i].number << endl;
	data.close();

	_getch();
}