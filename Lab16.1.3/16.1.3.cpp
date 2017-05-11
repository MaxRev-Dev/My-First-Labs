#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <Windows.h>
#include "D:\important!labs_path\filecfg.h"

using namespace std;
extern string glpath;
void prompt();

struct CustomList {
	string *elem;
	int size;
}List;

string*expand(string* x, int size) {
	string *tmp = new string[List.size+size];
	for (int i = 0; i < List.size; ++i) {
		if (!x[i].empty()) tmp[i] = x[i];
	} List.size++; return tmp;
}
/*
void delLine(string *x,int i) {
	for (int iter = i; iter < List.size-1; ++iter) {
		List.elem[iter] = List.elem[iter + 1];
	}List.size--;
}*/
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int iter = 0, des;
	ifstream inp(glpath+"Lab16.1.3.txt");
	string tmp;

	List.elem = new string[List.size=0];
	
	while (inp) {
		getline(inp, tmp);
		if (!tmp.empty() || tmp.length() > 3) {
			List.elem = expand(List.elem,1);
			List.elem[iter++] = tmp;
		}

	} inp.close();

	cout << "\t\t----"<<endl;
	cout << "–€дки з файлу: " << endl;
	for (int i = 0; i < List.size; ++i) {
		cout << "["<<i+1<<"]"<< List.elem[i] << endl;
	}
	cout << "\t\t----"<<endl;
	
	cout << "¬вед≥ть номер р€дка: ";
	cin >> des; --des;

	List.elem = expand(List.elem, 2);
	for (int i = List.size; i > des; --i) {
		if (!List.elem[i-1].empty()) {
			List.elem[i] = List.elem[i-1];
		}
	}
	cout << "¬вед≥ть значенн€: ";
	cin.ignore();
	getline(cin,List.elem[des]);

	/*
	for (int i = 0; i < VR.size;++i) {
		if (VR.x[i] == VR.x[des] && i != des) {
			delLine(VR.x, i),--i;
			if (des > i) --des;
		} 
	}
	*/

	ofstream out(glpath + "Lab16.1.3.txt",ios_base::trunc);

	cout << "\t\t----" << endl;
	for (int i = 0; i < List.size; ++i) {
		out << List.elem[i] << endl;
		cout << "[" << i + 1 << "]" << List.elem[i] << endl;
	}
	cout << "\t\t----" << endl;
	prompt();
	return 0;
}

void prompt() {
	if (_getch() == 27) {
		exit(0);
	}
	else main();
}