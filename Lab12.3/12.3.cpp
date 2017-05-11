#include "classes.h"

void GR();
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	GR();
	_getch();
	return 0;
}


void prompt(int x) {
	if (x) main();
	else {
		cout << "<<<<< EXIT! >>>>>";
		_getch();
		exit(0);
	}
}