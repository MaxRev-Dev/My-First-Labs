#include "extend.h"

int main() {

}


void prompt(int x) {
	if (x) main();
	else {
		cout << "<<<<< EXIT! >>>>>";
		_getch();
		exit(0);
	}
}