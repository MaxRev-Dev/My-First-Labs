#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <fstream>
#include <stack>
#include <vector>
#include <algorithm>
#include "D:\important!labs_path\filecfg.h"
using namespace std;
bool accen(long i, long  j) { return (i<j); }
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector<long >mainVect;
	stack<long > z;
	int iter = -1;
	string tmp;
	ifstream inp(glpath + "Lab16.2.2.txt");

	while (inp) {
		++iter;
		getline(inp, tmp);
		z.push(atoi(tmp.c_str()));
	}
	while (!z.empty()) {
		mainVect.push_back(z.top()); z.pop();
	}
	cout << "\t\t---" << endl;
	cout << "Стек:" << endl;
	for (auto r = mainVect.begin() + 1; r != mainVect.end();++r) {
		cout << *r<< endl;
	}cout << endl;
	vector<long >cr=mainVect;
		
	std::sort(mainVect.begin(), mainVect.end(), accen);
	cout << "\t\t---" << endl;
	cout << "Відсортовані числа: " << endl;

	for (auto r = mainVect.begin() + 1; r != mainVect.end(); ++r) {
		cout << *r << endl;
	}

	cout << "\t\t---" << endl;
	cout << "Нумерація в стеку: " << endl;
	for(int z=0;z<=iter;++z){
		for (int i = iter; i !=0; --i) {
			if ( cr.at(z)==mainVect[i]) cout << "[" << i << "]" << mainVect[i] << endl;
		}
	}
	_getch();
	return 0;
}

