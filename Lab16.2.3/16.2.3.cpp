#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <Windows.h>
//#include "D:\important!labs_path\filecfg.h"

using namespace std;
string glpath = "D:\\MaxRev\\Desktop\\SHORTCUTS\\Lab16.2.3[1].txt";
string glpath2 = "D:\\MaxRev\\Desktop\\SHORTCUTS\\Lab16.2.3[2].txt";
string glpathOut = "D:\\MaxRev\\Desktop\\SHORTCUTS\\Lab16.2.3[out].txt";

void prompt();

class CustomList {
	string *elem;
	int size=2, iter = 0;
public: 
	string* expand(string *,int);
	void delLine(string*, int);
	void inpFunc(ifstream&);
	void showLines(string);
	void outToFile(ofstream&);
	friend CustomList ConcatX(CustomList, CustomList);
};

CustomList ConcatX(CustomList x, CustomList y) {
	CustomList n;
	n.elem = new string[n.size];
	for (int i = 0; i < x.iter; ++i) {
		for (int j = 0; j < y.iter; ++j) {
			if (x.elem[i] == y.elem[j]) {
				n.elem[n.iter] = x.elem[i];
				n.elem = n.expand(n.elem, 1);
				n.iter++;
			}
		}
	}
	return n;
}
string* CustomList::expand(string* x, int size) {
	string *tmp = new string[this->size + size];
	for (int i = 0; i < this->size; ++i) {
		if (!x[i].empty()) tmp[i] = x[i];
	} this->size++; return tmp;
}

void CustomList::delLine(string *x, int i) {
	for (int iter = i; iter < this->size - 1; ++iter) {
	  this->elem[iter] = this->elem[iter + 1];
	}this->size--;
}

void CustomList::inpFunc(ifstream &inp) {
	string tmp;
	this->elem = new string[this->size];
	while (inp) {
		getline(inp, tmp);
		if (!tmp.empty() || tmp.length() > 1) {
			this->elem = expand(this->elem, 1);
			this->elem[this->iter++] = tmp;
		}
	} inp.close();
}
void CustomList::showLines(string s) {
	cout << "\t\t----" << endl;
	cout << s << endl;
	for (int i = 0; i < this->iter; ++i) {
		cout << "[" << i + 1 << "]" <<this->elem[i] << endl;
	}
	cout << "\t\t----" << endl;
}
void CustomList::outToFile(ofstream& out) {
	cout << "\t\t----" << endl;
	for (int i = 0; i < this->iter; ++i) {
		out << this->elem[i] << endl;
	}
	cout << "Запис у файл зроблено!"<<endl;
	cout << "\t\t----" << endl;
	out.close();
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream inp(glpath.c_str());
	ifstream inp2(glpath2.c_str());

	CustomList *lib = new CustomList[2];

	lib[0].inpFunc(inp);
	lib[1].inpFunc(inp2);

	lib[0].showLines("Рядки з файлу 1: ");
	lib[1].showLines("Рядки з файлу 2: ");

	CustomList CreatedList = ConcatX(lib[0], lib[1]);
	CreatedList.showLines("Об'єднаний список: ");

	ofstream out(glpathOut.c_str(), ios_base::trunc);
	CreatedList.outToFile(out);

	prompt();
	return 0;
}

void prompt() {
	if (_getch() == 27) {
		exit(0);
	}
	else main();
}