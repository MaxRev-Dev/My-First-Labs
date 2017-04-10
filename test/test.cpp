#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
using namespace std;
void prompt();
double a1, a10, sum;
double recur(double x) {
	if (x == a1) return a1;
	sum += pow(recur(--x),2);
	return ++x;
}
int main() {
	sum = 0;
	cin >> a1;
	cin >> a10;
	recur(a10+1);
	cout << sum;
	_getch();
	prompt();
	return 0;
}

void prompt() {
	std::cout	<< std::endl;
	std::cout	<< std::endl;
	_getch();
	if (GetAsyncKeyState(VK_ESCAPE)) exit(0);
	else main();
}
