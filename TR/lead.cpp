#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>
#define toDigit(c) (c-'0')
using namespace std;
void p1();

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ifstream tx("tests.txt");
	ifstream sup("part2.html");

	p1();
	ifstream &cr = tx;
	char sym, count_ques ='A', symb = 0, res='A', pr;
	int i = 1;
	vector<char>vec_name;
	vector<char>vec_ques;
	vector<char>vec_part;
	int c = 1;
	ofstream ht("index.html", ios_base::app);
	tx.get(sym);
	sup.get(pr);
	
	while (tx)
	{
			while (pr != 'X')
			{
				vec_part.push_back(pr);
				sup.get(pr);
			} sup.get(pr);
			vec_part.push_back(res); 
			vec_part.push_back(count_ques);
			while (pr != 'Y')
			{
				vec_part.push_back(pr);
				sup.get(pr);
			} sup.get(pr);
			for (size_t i = 0; i < vec_part.size(); ++i)
			{
				ht << vec_part[i];
			} vec_part.clear(); //to file			
			while (sym != '/') {
				tx.get(sym);
			}
			if (sym == '/') {
				
				tx.get(sym);
				tx.get(sym);
				while (sym != '{')
				{
					vec_part.push_back(sym);
					tx.get(sym);
				} tx.get(sym);
			}
			for (size_t i = 0; i < vec_part.size(); ++i)
			{
				ht << vec_part[i];
			} vec_part.clear(); //to file
			while (pr != 'X')
			{
				vec_part.push_back(pr);
				sup.get(pr);
			} sup.get(pr);
			 
			vec_part.push_back(count_ques);
			for (size_t i = 0; i < vec_part.size(); ++i)
			{
				ht << vec_part[i];
			} vec_part.clear(); //to file
			while (pr != 'A')
			{
				vec_part.push_back(pr);
				sup.get(pr);
			} sup.get(pr);
			for (size_t i = 0; i < vec_part.size(); ++i)
			{
				ht << vec_part[i];
			} vec_part.clear(); //to file
			while (sym != '~')
			{
				symb = sym;
				tx.get(sym);
			}symb = sym;
			tx.get(sym);
			while (i < 5)
			{
				while (sym != '~')
				{
					if (sym == '\\')
					{
						tx.get(sym);
						if (sym == '=' || sym == '}' || sym == '{') vec_part.push_back(sym);
					}
					else 
					{ 
						vec_part.push_back(sym); 
					}
					
					tx.get(sym);
				}tx.get(sym);

				for (size_t i = 0; i < vec_part.size(); ++i)
				{
					ht << vec_part[i];
				} vec_part.clear(); //to file
				while (pr != 'A')
				{
					vec_part.push_back(pr);
					sup.get(pr);
				} sup.get(pr);
				for (size_t i = 0; i < vec_part.size(); ++i)
				{
					ht << vec_part[i];
				} vec_part.clear(); //to file


				for (size_t i = 0; i < vec_part.size(); ++i)
				{
					ht << vec_part[i];
				} vec_part.clear(); //to file

				for (size_t i = 0; i < vec_ques.size(); ++i)
				{
					ht << vec_ques[i];
				} vec_ques.clear();

				i++;

			}	i = 1;
			while (sym != '}')
			{	
				vec_part.push_back(sym);
				tx.get(sym);
				if (sym == '\\')
				{
					tx.get(sym);
					if (sym == '=' || sym == '}' || sym == '{')	vec_part.push_back(sym);
				}
			} tx.get(sym);
			for (size_t i = 0; i < vec_part.size(); ++i)
			{
				ht << vec_part[i];
			} vec_part.clear();
			while (pr != 'S')
			{
				vec_part.push_back(pr);
				sup.get(pr);
				
			} 
			sup.get(pr);
			tx.get(sym);
			if (sym == '-') {
				vec_part.push_back(sym);
				tx.get(sym);
				if (sym == '-')	break;
			}

			for (size_t i = 0; i < vec_part.size(); ++i)
			{
				ht << vec_part[i];
			} vec_part.clear(); //to file
			sup.seekg(0);
			if (count_ques == 'Z') {
				count_ques = 'A';
				res = 'B';
			}
			count_ques++;
			
		}	
		tx.get(sym); 
			
	while (pr != 'Z')
	{	
		vec_part.push_back(pr);
		sup.get(pr);
	} sup.get(pr);

	for (size_t i = 0; i < vec_part.size(); ++i)
	{
		ht << vec_part[i];
	} vec_part.clear(); //to file
	

	ht.close();
	tx.close();
	sup.close();
	return 0;
}

void p1()
{
	char c;
	ifstream lol("part.html");
	ofstream r("index.html", ios_base::trunc);
	lol.get(c);
	while (lol){
		r << c;
		lol.get(c);
	}
	lol.putback('\n');
	lol.close();
	r.close();
}