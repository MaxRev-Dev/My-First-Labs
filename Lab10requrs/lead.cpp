#include <iostream>
#include <conio.h>
#include <iomanip>
#include <Windows.h>

using namespace std;
int req(int);
void prompt();
int X, repeater=0;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "¬вед≥ть число: ";

	cin >> ::X;
	req(::X);
	if (repeater == 0) cout<<"ƒ≥льник≥в нема"<<endl;
	else repeater = 0;
	_getch();
	prompt();
	return 0;
}
int req(int i) {
	if (((::X / i) != 0) && (::X%i == 0)) { 
		if ((::X != i) && (i != 1)) {
			cout << i << endl;
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