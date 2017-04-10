#include "extend.h"

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	linker::createLists();
	linker::writeFiles();
	linker::copier();

	_getch();
}
