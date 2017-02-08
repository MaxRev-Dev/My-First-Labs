#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

int main() {
	int i, j, e;
	cout << "input height>>width" << endl;
	float x, y, k, S;
	cin >> x >> y;

	int **A = new int *[x];
	for (int i = 0; i < x; i++) {
		A[i] = new int[y];
	}


	for (i = 0; i<x; ++i) {
		for (j = 0; j<y; ++j) {
			cout << "input " << "A[" << i + 1 << "]" << "[" << j + 1 << "]:";
			cin >> A[i][j];
			cout << " " << endl;
		}
	}


	for (i = 0; i < x; ++i) {
		for (j = 0; j < y; ++j) {
			cout << A[i][j]<< " ";
		} cout << endl;
	}
	int *Su = new int [j];
	for (j = 0; j < y; ++j) {
		S = 0;
		for (i = 0; i < x; ++i) {
			S += A[i][j];
			
		}
		Su[j] = S;
		cout << "Sum[" << Su[j] << "]" << endl;
	}

	system("pause");
	return 0;
}
