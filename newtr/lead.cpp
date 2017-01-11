#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>
#include "extend.h"


void next_cr(vector<char> &);
void forClass(vector<char> &, vector<char> &);
void nextMark(vector<char> &, long long &, const string &, vector<char> &);
void getTitle(vector<char> &, long long &);
void getQues(vector<char> &, long long &);
void vtf(vector<char>& );

using namespace std;

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ifstream f("./exp/samp1.txt");
	ifstream sup("res.html");
	ofstream hit("index.html", ios_base::trunc);
	
	vector<char>vec_main;
	vector<char>vec_sup;
	vector<char>ctr;
	ctr.push_back(64);
	vector<char>mirror = ctr;
	string itr;

	int c = 1, i = 1;
	long long icur,tsx,res2;
	string marker = "/*mark*/";
	
	//init header
	icur = sup.tellg();
	nextMark(vec_main, icur, marker,ctr);
	vtf(vec_main);

	//main-panels
	while (f) 
	{	
		long long res = icur;
		//title-init
		nextMark(vec_main, icur, marker, ctr);
		vtf(vec_main);
		//title
		
		tsx = f.tellg();
		getTitle(vec_main, tsx);
		vtf(vec_main);
		nextMark(vec_main, icur, marker, mirror);
		vtf(vec_main);
	
		for (int i = 0; i < 5; i++){
			//ques-init
			nextMark(vec_main, icur, marker, ctr);
			vtf(vec_main);
			//ques
			getQues(vec_main, tsx);
			vtf(vec_main);
			
		}
		nextMark(vec_main, icur, marker, ctr);
		vtf(vec_main);

		res2 = icur;
		icur = res;
		f.seekg(tsx);
	}

	nextMark(vec_main, res2, marker, ctr);
	vtf(vec_main);

	f.close();
	hit.close();
		return 0;
}
