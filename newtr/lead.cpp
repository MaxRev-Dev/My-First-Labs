#include "classes.h"
using namespace std;

string defdir = ".\\TextGen_sources\\";
int rounder = 0;
typedef BOOL(WINAPI *SETCONSOLEFONT)(HANDLE, DWORD);
SETCONSOLEFONT SetConsoleFont;
extern writer<string> w;
extern CSimpleIniA ini;
void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO structCursorInfo;

void prompt();
void font() {
	cout << "\t\t\t\tHi. \n\tFor the first launch we need to set up console font." << endl;
	
	string key = "ConsoleFont",str;
	int i;
	connectFiles s(::defdir);
	SI_Error rc = ini.LoadFile(s.defconf.c_str());
	CONSOLE_FONT_INFO CFI;
		CONSOLE_FONT_INFO* pCFI = &CFI;
		GetCurrentConsoleFont(GetStdHandle(STD_OUTPUT_HANDLE), false, pCFI);
		HMODULE hmod = GetModuleHandleA("KERNEL32.DLL");
		SetConsoleFont = (SETCONSOLEFONT)GetProcAddress(hmod, "SetConsoleFont");
	if (rc == 0) {	
		try {
			if (!ini.GetValue("Main", key.c_str(), NULL)) throw 1;
			str = ini.GetValue("Main", key.c_str(), NULL);
			i = atoi(str.c_str());
			system("cls");
		}
		catch (int r) {
			if (r == 1) w.w("\t\t!!!Config is invalid! Delete it and try again!!!");
			_getch();
			exit(-1);
		}

		SetConsoleFont(GetStdHandle(STD_OUTPUT_HANDLE), i);
		GetCurrentConsoleFont(GetStdHandle(STD_OUTPUT_HANDLE), false, pCFI);
	}
	else {
		cout << "\t\tPress ESCAPE when all is OK" << endl;
		
		for (i = 11; i > 0; --i) {
			SetConsoleFont(GetStdHandle(STD_OUTPUT_HANDLE), i);
			GetCurrentConsoleFont(GetStdHandle(STD_OUTPUT_HANDLE), false, pCFI);
			cout << "\t\tПеревірка тексту" << endl;
			if (_getch() == 27) break;
		} system("cls");
		char s[4];
		_itoa_s(i, s, 10);
		ini.SetValue("Main", key.c_str(), s);
	}
	
}
void osinfo() {
	SetConsoleTitle("TextGen");
	OSVERSIONINFO OS;
	ZeroMemory(&OS, sizeof(OSVERSIONINFO));
	OS.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetVersionEx(&OS);
	cout << "Version: " << OS.dwMajorVersion << "." << OS.dwMinorVersion << "." << OS.dwBuildNumber<<endl;
	font();
	/*switch (OS.dwMajorVersion) {
	case 5: {
		switch (OS.dwMinorVersion)
		{
		case 1: { 
			cout << "[System]: ";
			cout << "Windows XP" << endl;
			cout << "Trying to setup font"<<endl;
			font();
			break;
		}
		default: break;
		} break;
	}
	case 6: {
		switch (OS.dwMinorVersion)
		{
		case 0: {
			cout << "[System]: ";
			cout << "Windows Vista"<<endl;
			cout << "Trying to setup font"<<endl;
			font();
			break;
		}
		case 1: {
			cout << "[System]: ";
			cout << "Windows 7" << endl;
			cout << "Trying to setup font"<<endl;
			font();
			break;
		}
		case 3: {
			cout << "[System]: ";
			cout << "Windows 8" << endl;
			break;
		}
		default:
			break;
		}
		break;
	}
	case 10: cout << "[System]: "; cout << "Windows 10" << endl; break;
	default: break;
	}*/
}
bool animation() {
	string key = "AnimateThis", val;
	textGen d(::defdir);
	connectFiles s(::defdir);
	s.mkstr(-1);
	s.mkstr(0);
	ini.LoadFile(s.c_defconf);
	try {
		if (!ini.GetValue("Main", key.c_str(), NULL)) throw 1;
		else {
			if (ini.GetBoolValue("Main", key.c_str(), NULL)) d.animateThis = true;
			else d.animateThis =false;
		}
	}
	catch (int) {
		cout << "\t\tВикористовувати анімацію?\n\t\t\t[Enter][Esc]"<<endl;
		bool ds;
		if (_getch() == 27) { ds = false; }
		else ds = true;
		d.animateThis = ds;
		ini.SetBoolValue("Main", key.c_str(),ds);
		ini.SaveFile(s.c_full);
	}
	return d.animateThis;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	if (::rounder==0)osinfo();
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
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);
	textGen doc(::defdir);
	doc.animateThis = animation();
	double start = clock();
	
	
	if (doc.animateThis) doc.startThreadAnim();
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

	if (doc.animateThis) doc.stopThreadAnim();
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
	
	prompt();
	return 0;
}

void prompt() {
	std::cout << std::endl << "\t\t\tЩе раз?? " << "ESC - вихід" << std::endl;
	int inp = _getch();
	if (inp == 27) exit(0); 
	else if (inp == 13 || inp == 32) { ++::rounder; main(); }
	else prompt(); 
}