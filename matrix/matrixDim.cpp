#include <iostream> 
#include <Windows.h>
#include <conio.h>
using namespace std;
int n = 0,resn;
long long sum = 0;
void prompt();
long long recurse(long long *A) {
	if (resn >= 1) {
		resn--;
		recurse(A);
	}
	if (resn <= n) sum += A[resn++];
	return sum;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Розмір масиву: ";
	cin >> ::n;
	resn = n--;
	long long *A = new long long[::n];

	for (int i = 0; i <= ::n; i++) {
		A[i] = i + 1;
	}
	cout << "Введений масив: ";
	for (int i = 0; i <= ::n; ++i)
		cout << A[i] << " ";

	cout << endl << "S = " << recurse(A) << endl;
	prompt();
	return 0;
}

void prompt() {
	std::cout << std::endl << "Ще раз?? " << "ESC - вихід" << std::endl;
	_getch();
	if (GetAsyncKeyState(VK_ESCAPE)) exit(0);
	else main();
}
