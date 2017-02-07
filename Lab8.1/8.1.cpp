#include <iostream>
#include <conio.h>
#include <Windows.h>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int cell;
	std::cout << "Введіть розмір масиву:";
	std::cin >> cell;
	int **arr = new int *[cell];
	for (int i = 0; i < cell; i++) {
		arr[i] = new int[cell];
	}

	for (int i = 0; i < cell; i++) {
		for (int j = 0; j < cell; j++) {
			std::cin >> arr[i][j];
		} std::cout << std::endl;
	}


	std::cout << std::endl;

	for (int i = 0; i < cell; i++) {
		for (int j = 0; j < cell; j++) {
			std::cout << arr[i][j];
		} std::cout << std::endl;

	}
	for (int x1 = 0, x2 = cell - 1; x1 < cell&&x2 > 0; x1++, x2--) {
		for (int y1 = 0, y2 = cell - 1; (y1 < cell) && (y2 > 0); y1++, y2--) {
			if (arr[x1][y1] == arr[x2][y2]) {
				if (!(x1 == x2 == y1 == y2)) std::cout << "EQ! " << x1 + 1 << y1 + 1 << " = " << x2 + 1 << y2 + 1 << std::endl;

			}
			else {
				std::cout << "Масив не задовольняє умову задачі!\n Числа [" << x1 + 1 << y1 + 1 << "] = " << arr[x1][y1] << " та [" << x2 + 1 << y2 + 1 << "] = " << arr[x2][y2] << " не співспадають" << std::endl;
				_getch();
				return 0;
			}
		}
	}

	delete[] arr;


	_getch();
	return 0;




}