#include "classes.h"

string defdir = ".\\sources_newtr\\";
int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	//< ----INI check---- >
	//ini-keys
	long long res, icur;
	int rc = 0;
	string fname = "";
	string str1 = "InputFile";
	string str2 = "TemplateFile";
	string str3 = "OutputFile";
	string str4 = "Marker";
	//ini-keys
	connectFiles base(::defdir);
	if (base.init(::defdir) == -3) { 
		return -1; 
	}
	string g(base.c_defdir);
	string h(base.c_full1);
	if (g == h) {
		rc = base.IO(fname, str1);
	}
	else { fname = base.c_full1; }
	if (rc == -3) {
		_getch();
		return -2;
	}
	ifstream inpf(fname);
	rc = base.IO(fname, str2);
	if (rc == -3) { 
		_getch(); 
		return -3; 
	}
	ifstream sup(fname);
	rc = base.IO(fname, str3);
	if (rc == -3) {
		_getch();
		return -4;
	}
	ofstream opf(fname, ios_base::trunc);
	writer<string> ex;
	try {
			if (!inpf.is_open()) throw 1;
			if (!sup.is_open()) throw 2;
		}
	catch (int exc) {
		std::cout << "Помилка #" << exc;
		switch (exc) {
		case 1: {
			ex.answers(ex1);
			ex.answers(emergency);
			_getch();
			return 0;
		}
		case 2: {
			ex.answers(ex2);
			ex.answers(emergency);
			_getch();
			return 0;
		}
		}
	}
		//< ----endof INI check---- >
	double start = clock();
	textGen doc(::defdir);
	
	doc.nextMark(sup);
	
	doc.vecTF(opf);

		//main-panels
	while (inpf)
	{
		icur = sup.tellg();
		doc.getCartPos(icur, 1);
		//title-init
		doc.nextMark(sup);
		//title

		doc.getTitle(inpf);
		doc.nextMark(sup);
		doc.vecTF(opf);

#pragma loop(hint_parallel(4))
		for (int i = 0; i < 5; i++) {
			//ques-init
			doc.nextMark(sup);
			//ques
			doc.getQues(inpf);
			doc.vecTF(opf);
		}
		doc.nextMark(sup);
		doc.vecTF(opf);

		res = icur;
		sup.seekg(icur);
	}
	sup.seekg(res);
	
	doc.nextMark(sup);

	doc.vecTF(opf);
	doc.inTime(opf);
	
	doc.nextMark(sup);
	
	doc.vecTF(opf);
	inpf.close();
	opf.close();

	double end = clock() - start;
		
	cout << "	|						|" << endl;
	cout << "	|	Час виконнання завдання: " << end / (double)CLOCKS_PER_SEC <<" c.	|" <<endl;
	cout << "	|		  От і все!			|" << endl;
	cout << "	|		---MaxRev---			|"<<endl;
	cout << "	|_______________________________________________|";
	_getch();

	return 0;
}