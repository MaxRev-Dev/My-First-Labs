#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>
#include <string>
#include <SimpleIni.h>
#include <dirent.h>
#include <time.h>

using namespace std;

class connectFiles
{
private:
	char buffer[256] = "";
	string str = "";
	DIR *dir;
	struct dirent *ent;
	

public:
	connectFiles();
	void IO(string&, string);
	void init();
	void defaultConf();
	string der();
	~connectFiles();
	char c_defconf[20];
	const string defconf = "config.ini";
};

class textGen {
private:
	vector<char>vcr;
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
	textGen();
	void nextChr(vector<char> &);
	void nextMark(ifstream &);
	void vecTF(ofstream &);
	void getTitle(ifstream &);
	void getQues(ifstream &);
	void textGen::getCartPos(long long&, int);
};