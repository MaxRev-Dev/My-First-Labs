#include <iostream>
#include <conio.h>
#include <Windows.h>

void sort(int*, int);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int coll, row, chk(NULL);
	std::cout << "---->> Введіть розмір масиву" << std::endl;
	std::cout << "Кількість стовпців: ";
	std::cin >> coll;
	std::cout << "Кількість рядків: ";
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
			std::cout << arr[i][j] << " ";
		} std::cout << std::endl << std::endl;
	}
	std::cout << std::endl;

	int sorted[100], k = 0;
	for (int i = 0; i < 100; i++) sorted[i] = 0;
	for (int x1 = 0; x1 < coll; x1++) {
		for (int y1 = row - 1; y1 > x1; y1--) {
			sorted[k++] = arr[x1][y1];
		}
	}
	sort(sorted, k);

	for (int x1 = 0, k = 0; x1 < coll; x1++) {
		for (int y1 = 0; y1 < x1; y1++, k++) {
			arr[x1][y1] = sorted[k];
		}
	}

	for (int i = 0; i < coll; i++) arr[i][i] = 0; // diagonal = 0 ))))

	for (int i = 0; i < coll; i++) {
		for (int j = 0; j < row; j++) {
			std::cout << arr[i][j] << " ";
		} std::cout << std::endl << std::endl;

	}
	for (int i = 0; i < coll; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	_getch();
	return 0;

}
void sort(int *arr, int k) {
	int tmp;

	for (int i = 0; i < k - 1; i++) {
		for (int j = 0; j < k - i - 1; j++) {
			if (*(arr + j) > *(arr + j + 1)) {
				tmp = *(arr + j + 1);
				*(arr + j + 1) = *(arr + j);
				*(arr + j) = tmp;
			}
		}
	}
}
