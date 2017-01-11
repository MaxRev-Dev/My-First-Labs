#pragma once

class HR
{
private:
	int i = 0, n = 0, j = 0;
	double* arr;
	double	number, x, num;

public:
	HR(int);
	void createArray(int);
	double addEl();
	void outputArray();
	~HR();
};

