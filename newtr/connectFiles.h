#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <SimpleIni.h>
#include <dirent.h>

using namespace std;

class connectFiles
{
private:
	char buffer[256] = "";
	string str = "";
	DIR *dir;
	struct dirent *ent;
	string defconf = "config.ini";
	char c_defconf[50];
	
public:
	connectFiles();
	void IO(string&,string);
	void init();
	void defaulConf();
	~connectFiles();
};

