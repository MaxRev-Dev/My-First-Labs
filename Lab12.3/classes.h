#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <Windows.h>
#include <functional>
#include <string>
#include <map>
#include <exception>
//#include "D:\important!labs_path\filecfg.h"
using namespace std;
//
//class files {
//public:
//	files();
//	void createBIN();
//	void showTable();
//	void newSheet();
//    void deleteInfo();
//	void editInfo();
//	void newInfo();
//	
//	~files();
//private:
//	void put(string);
//	string& get(string&);
//	void chose();
//	bool openDay(string);
//	void makeDate();	
//};

class Discover {
private:
	struct Base
	{
		ifstream data,crd;
		ofstream data_out,crd_out;
		string str,_rw_str,path;
		string*files;

		int capacity,iter;
	};
	string get(istream&);
	void put(string);
public: 
	Discover();
	Base file;
	void Select();
	void readDate();
	void ReadAll();
	void CreateNew();
	~Discover();
};
class Sheet {
private:	
	int capacity=0,size=2;
	struct Students {
		string name;
		bool WasOn[4];
	};
	Students *st;
	string path;
	enum subj { OS, Matan, Alg, Prog };
	Students* expandStud(Students*,int);
	void removeLine(Students*, int);
public:	
	friend void Discover::readDate();
	Sheet();
	Sheet(string);
	Sheet(int);
	void addLine(Students*);
	string date;
	void SaveAs(Students*);
	string SavedIn();
	~Sheet();
};

