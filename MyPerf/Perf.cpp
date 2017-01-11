#include "HR.h"
#include <iostream>
#include <windows.h>


int main() 
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	HR now(0);
	while (true) {
		if (now.addEl() == 0) break;
		now.addEl();
	} now.outputArray();

	system("pause");
	return 0;

}