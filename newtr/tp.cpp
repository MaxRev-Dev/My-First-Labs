#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "classes.h"

using namespace std;

fls::fls() {
	fileReq(flname);
	generateBody();
}

void fls::fileReq(char *(flname)) {
	cin.getline(flname, 256);
}
void fls::generateBody() {
	writer ob;
	string str(flname);
	ifstream sup("\"" + str + "\""); 

}

void fls::nextMark(int) {

}

fls::~fls() {
}
