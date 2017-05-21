#include <iostream>
#include <conio.h> //  дл€ getch()
#include <string> // getline()
#include <Windows.h> // кирилиц€
#include <fstream>

using namespace std;

int main()
{
	SetConsoleOutputCP(1251); // кирилиц€
	ifstream inp("D:\\MaxRev\\Desktop\\SHORTCUTS\\Labs\\test[12.1].txt"); //в≥дкриваЇмо файл
	
	string char_num;
	int *num_arr = new int[15], //дл€ чисел
		*A = new int[15], //дл€ виводу
		iter=0,
		iter_of_A=0;

	while (inp) {
		getline(inp, char_num); //читаЇмо р€док
		if (char_num != "") num_arr[iter++]  = atoi(char_num.c_str()); // читаЇмо усе кр≥м останнього р€дка(в≥н пустий)
	}


	for (int i = 0; i < iter; i++) {
		int tmp = num_arr[i];
		while (true) {
			tmp = tmp - 3; //в≥дн≥маЇмо три поки не буде нуль
			if (tmp < 3 && tmp != 0) {
				cout << num_arr[i] << " - „исло Ќ≈ Ї д≥льником" << endl;
				break; //перев≥р€Їмо дал≥
			}
			else if (tmp == 0) { //"остача =0"
				cout << num_arr[i] << " - „исло Ї д≥льником" << endl;
				A[iter_of_A++] = num_arr[i]; // записуЇмо д≥льники
				break;
			}
		}
	}
	cout << endl;
	cout << "„исла €к≥ д≥л€тьс€ на три: "<<endl;
	for (int i = 0; i < iter_of_A; i++) {//вив≥д 2го масиву
		cout << A[i]<<endl;
	}

	_getch();

	return 0;
}
