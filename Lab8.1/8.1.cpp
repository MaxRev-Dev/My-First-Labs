#include <iostream>
#include <conio.h>
int main() {

	float arr[2][2];


	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3;j++) {
			std::cin >> arr[i][j];
		}

	}

	if (arr[0][0] == arr[2][2] && arr[0][1] == arr[1][2] && arr[2][0] == arr[2][0]) std::cout << "EQUAL";
	else std::cout << "NOT EQUAL"<< std::endl;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << arr[i][j];
		}std::cout << std::endl;

	}


	
	_getch();
	return 0;



	
}