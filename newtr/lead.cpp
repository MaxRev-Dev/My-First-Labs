#include "classes.h"
#include "MyLib.h"

using namespace std;

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	string fname = "";
	//ini-keys
	string str1 = "InputFile";
	string str3 = "OutputFile";
	string str2 = "TemplateFile";

	connectFiles base;
	base.IO(fname, str1);
	ifstream f(fname); //"./exp/samp1.txt"
	base.IO(fname, str2);
	ifstream sup(fname); //"res.html"
	base.IO(fname, str3);
	ofstream hit(fname, ios_base::trunc); //"index.html"

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
