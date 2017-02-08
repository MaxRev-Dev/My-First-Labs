#include <iostream>
#include <conio.h>
#include <Windows.h>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int coll, row, chk(NULL);
	std::cout << "---->> Введіть розмір масиву" << std::endl;
	std::cout << "Кількість рядків : ";
	std::cin >> coll;
	std::cout << "Кількість стовпців: ";
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

	std::cout << std::endl << "Обчислюємо... " << std::endl;

	for (int i = 0; i < coll; i++) {
		for (int j = 0; j < row; j++) {
			if (chk < arr[i][j]) chk = arr[i][j];
		} std::cout << "Стовчик " << i << "  максимум->  " << chk << std::endl;
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