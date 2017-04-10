#include "extend.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	RF file;
	structRoutine(UniFy(init(file)));
	return 0;
}


void prompt(int x) {
	if (x) main();
}

void prompt() {
	std::cout << std::endl << "Retry?? " << "ESC - exit" << std::endl;
	_getch();
	if (GetAsyncKeyState(VK_ESCAPE)) exit(0);
	else main();
}