#include <iostream>
#include <conio.h>
#include <Windows.h>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int coll, row, chk(NULL);
	std::cout << "---->> ������ ����� ������" << std::endl;
	std::cout << "ʳ������ ����� : ";
	std::cin >> coll;
	std::cout << "ʳ������ ��������: ";
	std::cin >> row;
	int **arr = new int *[coll];
	for (int i = 0; i < coll; i++) {
		arr[i] = new int[row];
	}

	for (int i = 0; i < coll; i++) {
		for (int j = 0; j < row; j++) {
			std::cin >> arr[i][j];
		} std::cout << std::endl;
	}

	std::cout << std::endl << "����������... " << std::endl;

	for (int i = 0; i < coll; i++) {
		for (int j = 0; j < row; j++) {
			if (chk < arr[i][j]) chk = arr[i][j];
		} std::cout << "������� " << i << "  ��������->  " << chk << std::endl;
		chk = -999999;
	}
	for (int i = 0; i < coll; i++) {
		for (int j = 0; j < row; j++) {
			std::cout << arr[i][j];
	}std::cout  << std::endl;
	}


	_getch();
	return 0;

}