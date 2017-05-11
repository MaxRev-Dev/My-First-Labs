#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <string>
#include <map>
#include "D:\important!labs_path\filecfg.h"

#define MIN_WORDS_IN_FILE 15
#define MAX_WORDS_IN_FILE 20
using namespace std;
extern string glpath;

bool isUint(const std::string& s) {
	return s.find_first_not_of("0123456789") == std::string::npos;
}

namespace linker {

	string** expand(int);

	struct FL {
		string path = (glpath += "Lab12.1[generic].txt");
		string **list;
		int files_qnt, frst, scnd, _qnt;
		string * files;
	};
	FL ex;

	string** dynamInitAr3(int fst) {
		string **ar = new string*[fst];
		for (int i = 0; i < fst; ++i) {
			ar[i] = new string[MIN_WORDS_IN_FILE];
		}
		ex.files = new string[20];
		return ar;
	}

	typedef multimap <int, string> mapType;
	mapType mp;

	string** expand(int add) {
		string**tmp = new string*[ex.files_qnt + add];
		for (int i = 0; i < ex.files_qnt + add; ++i) {
			tmp[i] = new string[MAX_WORDS_IN_FILE];
		}

		for (int i = 0; i < ex.files_qnt - add; ++i) {
			for (int j = 0; j < ex.scnd; ++j) {
				tmp[i][j] = ex.list[i][j];
			}
		}

		delete ex.list;
		return tmp;
	}

	void createLists() {
		ex.files_qnt = 1;
		ex.scnd = MIN_WORDS_IN_FILE;
		ex.list = dynamInitAr3(ex.files_qnt);

		while (true) {
			cout << "Файл #" << ex.files_qnt << endl;
			cout << "Кількість слів:";
			string tst;
			getline(cin, tst);
			while (true) {
				if (isUint(tst)) {
					ex.scnd = stoi(tst);
					break;
				}
				else {
					cout << "Це не число! Ще раз: ";
					getline(cin, tst);
				}
			}
			cin.ignore();
			for (int i = 0; i < ex.scnd; ++i) {
				getline(cin, ex.list[ex.files_qnt - 1][i]);
				mp.insert(mapType::value_type(ex.files_qnt - 1, ex.list[ex.files_qnt - 1][i]));
			}
			cout << "Записати новий файл? [enter]" << endl;
			_getch();
			if (GetKeyState(VK_RETURN) < 0) {
				++ex.files_qnt;
				ex.list = expand(1);
				continue;
			}
			else {
				break;
			}
		}

	}
	void writeFiles() {
		for (int i = 0; i < ex.files_qnt; ++i) {
			string cer = "[";
			cer += std::to_string(i + 1);
			cer += "]";
			size_t rev = ex.path.find_last_of(".");
			string atm = ex.path;
			atm.insert(rev, cer);
			
			ex.files[i] = atm;
			ofstream s(atm, ios_base::trunc);
			if (s.is_open()) {
				for (auto j = mp.equal_range(i).first; j != mp.equal_range(i).second; ++j) {
					s << " " << j->second << " ";
				} s << endl;
				cout << "Файл #"<<i+1<<" збережено в \"" << ex.files[i]<< "\""<<endl;
			}
			else {
				cout << "Файл [" << i + 1 << "] неможливо створити!";
			}
			s.close();
		}
	}
	void copier() {
		int end, start;
		cout << "\n\nКопіювати файл: ";
		cin >> start;
		cout << "В файл: ";
		cin >> end;
		--start, --end;
		if (end > ex.files_qnt || start > ex.files_qnt) end = start = ex.files_qnt;

		ifstream fin(ex.files[start]);
		ofstream fout(ex.files[end], ios_base::app);
		
		if (fin.is_open()) {
			if (fout.is_open()) {
				string buffer;
				while (fin) {
					getline(fin, buffer);
					fout << buffer;
				}
				cout << "Готово!";
			}
			else {
				cout << "Файл виводу не готовий"<<endl;
			}
		}
		else {
			cout << "Файл вводу не готовий"<<endl;
		}
	}
}
