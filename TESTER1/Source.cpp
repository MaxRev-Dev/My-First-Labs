#include <iostream>
#include <conio.h> //  ��� getch()
#include <string> // getline()
#include <Windows.h> // ��������
#include <fstream>

using namespace std;

int main()
{
	SetConsoleOutputCP(1251); // ��������
	ifstream inp("D:\\MaxRev\\Desktop\\SHORTCUTS\\Labs\\test[12.1].txt"); //��������� ����
	
	string char_num;
	int *num_arr = new int[15], //��� �����
		*A = new int[15], //��� ������
		iter=0,
		iter_of_A=0;

	while (inp) {
		getline(inp, char_num); //������ �����
		if (char_num != "") num_arr[iter++]  = atoi(char_num.c_str()); // ������ ��� ��� ���������� �����(�� ������)
	}


	for (int i = 0; i < iter; i++) {
		int tmp = num_arr[i];
		while (true) {
			tmp = tmp - 3; //������� ��� ���� �� ���� ����
			if (tmp < 3 && tmp != 0) {
				cout << num_arr[i] << " - ����� �� � ��������" << endl;
				break; //���������� ���
			}
			else if (tmp == 0) { //"������ =0"
				cout << num_arr[i] << " - ����� � ��������" << endl;
				A[iter_of_A++] = num_arr[i]; // �������� �������
				break;
			}
		}
	}
	cout << endl;
	cout << "����� �� ������� �� ���: "<<endl;
	for (int i = 0; i < iter_of_A; i++) {//���� 2�� ������
		cout << A[i]<<endl;
	}

	_getch();

	return 0;
}
