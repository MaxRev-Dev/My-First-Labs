#include <iostream>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <limits>
using namespace std;
long long req(long long);
void prompt();
long count = 1;
long long X, repeater=0;
long long degree(long long x) {
	if (x / 5 != 1 && x % 5 == 0) ::count++;
	if (x>1) x = degree(x/5);
	return x;
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "\n";
	cout << "\t¬вед≥ть число: ";
	::count = 1;
	
	cin >> ::X;
	long long i = 1;
	/*	while (true) {
			i *= 5;
			if (i == ::X) {
				degree(::X);
			}
			else if (i > ::X) break;
		}*/
	req(::X);
	if (repeater == 0) cout<<"\tƒ≥льник≥в нема"<<endl;
	else repeater = 0;
	_getch();
	prompt();
	return 0;
}
long long req(long long i) {
	if (((::X / i) != 0) && (::X%i == 0)) { 
		if ((::X != i) && (i != 1)) {
			cout <<"\t"<< i << endl;
			::repeater++;
		}
	}
	if (i>1) i = req(--i);
	return i;
}
void prompt() {
	std::cout << std::endl << "ўе раз? " << "ESC - вих≥д" << std::endl;
	_getch();
	if (GetAsyncKeyState(VK_ESCAPE)) exit(0);
	else main();
}