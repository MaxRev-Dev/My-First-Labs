#include <iostream> 
#include <math.h> 
#include <Windows.h> 

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double s, x, x2, dx, j, jm, f;
	cout << "¬вед≥ть значенн€ x1=";
	cin >> x;
	cout << "¬вед≥ть значенн€ dx=";
	cin >> dx;
	cout << "¬вед≥ть значенн€ j=";
	cin >> j;
	cout << "¬вед≥ть значенн€ jm=";
	cin >> jm;
	f = 1;
	s = 0;
	while (f <= j + 1) {
		x = x + dx;
		if (f == j) {
			x2 = x;
		}
		f++;
	}
	while (j <= jm) {
		s = s + (pow(fabs(x), 1.0 / 2) - pow(fabs(x2), 1.0 / 2)) / (2 * x2 + 6.25);
		j++;
	}
	cout << "—ума s=" << s << "\n\n";
	system("pause");
	return 0;
}
