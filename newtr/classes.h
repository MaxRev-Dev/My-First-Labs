#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>
#include <string>
#include "SimpleIni.h"
#include "dirent.h"
#include <time.h>
#include <exception>
#include <conio.h>
#include <time.h>
#include "writer.h"
using namespace std;
class connectFiles
{
private:
	char buffer[256] = "";
	string str = "",tmp = "";
	DIR *dir;
	struct dirent *ent;
	unsigned int *fullsz = new unsigned int;
	string defdir = "";
	char chr1[15] = "tests.txt";
	char chr2[15] = "index.html";
	char chr3[15] = "res.html";
	char chr4[15] = "/*mark*/";
	void mkstr(int);
	
public:
	connectFiles(string &);
	int IO(string&, string), e;
	int init(string &);
	int hell();
	bool CreateDir(TCHAR *);
	string der();
	void cpst(char *, char *);
	
	int defaultConf(string &);
	const string defconf = "config.ini";
	char *c_full = new char[100];
	char *c_defconf = new char[50];
	char *c_defdir = new char[50];
	char *c_full1 = new char[100];
	char *c_full2 = new char[100];
	char *c_full3 = new char[100];
};

class textGen {
private:
	vector<char>vec_sup;
	vector<char>ctr;
	vector<char>mirror;
	string mark = "";
	bool clicker = false;
	string itr = "";
	int c = 1, i = 1;
	long long x = 0, tx = 0, curTP = 0;
	char cr=0;
public:
	vector<char>vcr;
	textGen(string &);
	void nextChr(vector<char> &);
	void nextMark(ifstream &);
	void vecTF(ofstream &);
	void getTitle(ifstream &);
	void getQues(ifstream &);
	void getCartPos(long long&, int);
	void inTime(ofstream&);
};
