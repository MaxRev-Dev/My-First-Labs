#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>

using namespace std;

void next_cr(vector<char> &ctrl)
{
	char lc = 'Z';
	char &a = ctrl.at(ctrl.size() - 1);
	if (a == lc)
	{
		ctrl.push_back('A');
	}
	else
	{
		a++;
	}
}
void vtf(vector<char> &vcr)
{
	ofstream fl("index.html", ios_base::app);
	int s = vcr.size();
	for (int i = 0; i < s; ++i)
	{
		fl << vcr[i];
	} vcr.clear();
	fl.close();
}
void nextMark(vector<char> &vcr, long long &x, const string &mark, vector<char> &ctrl)
{
	ifstream tmp("res.html");
	string itr;
	char cr;
	tmp.seekg(x);
	while (true)
	{
		int j = 0;
		int t = mark.size();
		for (int i = 0; i < t; ++i)
		{
			tmp.get(cr);
			itr.push_back(cr);
			// '\n' - fix
			if (cr == '\n') {
				j++;
			}
		}
		if (itr == mark) break;
		itr.clear();
		x = tmp.tellg();
		tmp.seekg(x - mark.size() - j);

		tmp.get(cr);
		if (cr == 'X')
		{
			next_cr(ctrl);
			int s = ctrl.size();
			for (int i = 0; i < s; ++i)
				vcr.push_back(ctrl[i]);
			tmp.get(cr);
		}
		vcr.push_back(cr);
	}
	tmp.seekg(x + 1);
	x = tmp.tellg();
	tmp.close();
}
void forClass(vector<char> &vcr, vector<char> &counter)
{
	//init class counter
	next_cr(counter);
	//put class counter to vec
	int s = counter.size();
	for (int i = 0; i < s; ++i) vcr.push_back(counter.at(i));
}
void getTitle(vector<char> &vcr, long long &tx)
{
	ifstream arch("./exp/samp1.txt");
	arch.seekg(tx);
	char sym = 0, pr = 0, symb = 0;

	while (sym != '{')
	{
		vcr.push_back(sym);
		if (sym == '/')
		{
			arch.get(sym);
			if (sym == '/')
			{
				vcr.pop_back();
				vcr.pop_back();
			} else vcr.push_back(sym);
		}
		arch.get(sym);
	} arch.get(sym);
	tx = arch.tellg();
	arch.close();
}
void getQues(vector<char> &vcr, long long &tx) {
	ifstream arch("./exp/samp1.txt");
	string sg = "<strong>";
	string sgx = "</strong>";
	arch.seekg(tx);
	char sym = 0, pr = 0;
	int j = 1;
	while (true)
	{
		arch.get(sym);
		if (sym == '~' || sym == '%' || sym == '}' || sym == '-') break;
	}
	if (sym == '%' || sym == '~')
	{
		if (sym == '%') {
			int s = sg.size();
			for (int i = 0; i < s; ++i) vcr.push_back(sg.at(i));
			j = 0;
		}
		while (true)
		{
			arch.get(sym);
			if (sym == '\\')
			{
				arch.get(sym);
				vcr.push_back(sym);
			}
			if (sym == '~' || sym == '%' || sym == '}')
			{
				vcr.pop_back();
				break;
			}
			vcr.push_back(sym);
		}
		if (j == 0) {
			int s = sgx.size();
			for (int i = 0; i < s; ++i) vcr.push_back(sgx.at(i));
			j = 1;
		}
	}

	if (sym == '}')
	{
		tx = arch.tellg();
		arch.seekg(tx - 3);
		arch.get(sym);
		vcr.push_back(sym);

		arch.seekg(tx);
		int j = 0;
		while (j<5){
			arch.get(sym);
			if (!arch){
				arch.close();
				break;
			} j++;
		}
		if (arch){
			tx = arch.tellg();
			tx -= j;
			arch.seekg(tx);
		}
	}
	tx = arch.tellg();
	tx -= 1;

	arch.close();
}