#include "classes.h"
#include "MyLib.h"

using namespace std;

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double start = clock();
	string fname = "";

	//< ----INI check---- >
	//ini-keys
	string str1 = "InputFile";
	string str2 = "TemplateFile";
	string str3 = "OutputFile";
	string str4 = "Marker";
	//ini-keys
	connectFiles base;
	base.init();
	base.IO(fname, str1);
	ifstream inpf(fname);

	base.IO(fname, str2);
	ifstream sup(fname); 

	base.IO(fname, str3);
	ofstream opf(fname, ios_base::trunc); 
	
	//< ----endof INI check---- >
	textGen doc;
	doc.nextMark(sup);
	doc.vecTF(opf);
	long long res, icur;
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

	inpf.close();
	opf.close();
	
	double end = clock() - start;
	printf("Время выполнения программы с использованием распараллеливания: %f\n", end / (double)CLOCKS_PER_SEC);
	system("pause");
	return 0;
}