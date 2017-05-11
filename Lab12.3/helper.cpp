#include "classes.h"
#define subject  Sheet 
#define  named ::
string glpath = "D:\\MaxRev\\Desktop\\SHORTCUTS\\Lab12_3_generic\\";

string* expand(string*,int,int);
void GR() {
	Discover *ex = new Discover();
	if (!ex->file.data.is_open()) {
		ex->file.data_out.open(glpath + "data.txt");
		ex->CreateNew();
		cout << "[IS_BIN_CREATED -> OK]" << endl;
		
		while (true) {
			cin.ignore();
			cout << "Дата: ";
			string tmp;
			getline(cin, tmp);
			Sheet *x = new Sheet(tmp);				
			ex->file.data_out << glpath + tmp + ".txt"<<endl;
			cout <<endl<< "[Головне меню]" << endl;
			cout << "Додати дату?[enter]"<<endl;
			if (_getch() != 13) break;
		} ex->file.data.open(glpath + "data.txt");
	}
	else {
		while (true) {
			ex->ReadAll();
			ex->Select();
			ex->readDate();
			cout <<endl<< "[Головне меню]" << endl;
			cout << "Додати дату?[enter]" << endl;
			
			if (_getch() == 13) {
				cin.ignore();
				cout << "Дата: ";
				string tmp;
				getline(cin, tmp);
				Sheet *x = new Sheet(tmp);
				ex->file.data_out.open(glpath + "data.txt",ios_base::app);
				ex->file.data_out << glpath + tmp + ".txt" << endl;
				ex->file.data_out.close();
			}
			cout << "Вийти?[esc]"<<endl;

			if (_getch() == 27) break;
		}
	} 

	cout << "ВИХІД!";
 }

void Discover::readDate() {
	string str, tem="01";
	Sheet *ls = new Sheet(1);
	ls->st = new Sheet::Students[2];
	int iter=0;
	
	while (file.crd) {
		getline(file.crd, str);
		if (!str.empty() && str.length() > 2) {
			size_t name_len1 = str.find_first_of(tem);
			string sub_str = str.substr(0, name_len1);
			cout <<"  ["<< ++iter<<"] " << sub_str << "\t\t|\t";
			ls->st[ls->capacity].name = sub_str;
			for (int i = 0; name_len1 < str.length(); name_len1 += 2, ++i) {
				cout << ((bool)atoi(str.substr(name_len1, 1).c_str()) ? "Б" : "Н");
				ls->st[ls->capacity].WasOn[i] = (bool)atoi(str.substr(name_len1, 1).c_str());
				cout << "\t|\t";
			} cout << endl;	  ++ls->capacity; ls->st = ls->expandStud(ls->st, 2);
		}
	}file.crd.close();

	//Lines Editor 
	while (true) {
		cout << endl << "Додати запис?[enter][esc]" << endl;
		if (_getch() == 13) {
			ls->date = file.path.substr(0, file.path.find_last_of("."));
			ls->addLine(ls->st);
		}
		cout << "Видалити запис?[enter][esc]" << endl;
		if (_getch() == 13) {
			cout << "Введіть номер запису: ";
			int line;
			cin >> line;
			ls->removeLine(ls->st, line);
			ls->date = file.path.substr(0, file.path.find_last_of("."));
			ls->SaveAs(ls->st);
			cout<<endl << "Готово!" << endl;
		}
		cout << "В головне меню?[enter][esc]" << endl;
		if (_getch() == 13)break;
	}
	
}

void Discover::Select() {
	cout <<endl <<"Виберіть дату: ";
	int sel;
	cin >> sel;
	--sel;
	string name = file.files[sel].substr(file.files[sel].find_last_of("\\")+1);
	cout << endl << "Дата: " << name.substr(0,name.find_last_of(".")) <<endl << endl;
	cout << "\tПрізвище\t|\tOS\t|\tMatan\t|\tAlg\t|\tProg\t"<<endl;
	file.path = file.files[sel];
	file.crd.open(file.path);
}

Discover::Discover() {
	file.data.open(glpath + "data.txt");
}
Discover::~Discover() {
	
}

inline void Discover::CreateNew() {
	file.data.open(glpath+"data.txt", ios_base::trunc);
}
void Discover::ReadAll() {
	if (file.data.is_open()) {
		file.data.close();
		file.data.open(glpath + "data.txt");
		cout << "Наявні такі дати: " << endl << endl;
		string x; int cur, lst; file.iter = 0;
		file.files = new string[file.capacity = 1];
		while (!file.data.eof()) {
			getline(file.data, file.str);
			x = file.str;
			if (x.length() > 0) {
				file.files[file.iter] = x;
				file.files = expand(file.files, file.capacity, 1);
				cur = x.find_last_of("\\") + 1;
				x = x.substr(cur);
				lst = x.find_last_of(".");
				cout << "  [" << (++file.iter) << "] " << x.substr(0, lst) << endl;
				++file.capacity;
			}
		
		}
	}
}
inline void Discover::put(string str) {
	file.data_out << str << endl;
}

inline string Discover::get(istream& x) {
	getline(x, file.str);
	return file.str;
}

string* expand(string *x, int size, int add) {
	string*tmp = new string[size + add];

	for (int i = 0; i < size; ++i) {
		if (!x[i].empty()) tmp[i] = x[i];
	}

	return tmp;
}


Sheet::Sheet(int) {

}
Sheet::Sheet() {
	st = new Students[size];
	addLine(st);
}
Sheet::Sheet(string dater){
	this->date = glpath;
	this->date += dater;
	st = new Students[size]; 
	addLine(st);
	
}
void Sheet::addLine(Students* st) {
	while (true) {
		cout << "Введіть ім'я студента: ";
		cin >> st[capacity].name;
		cout << "Присутність[1][0]:\n\tOS:";
		cin >> st[capacity].WasOn[subject named OS]; cin.ignore();
		cout << "\tПрограмування:";
		cin >> st[capacity].WasOn[subject named Prog]; cin.ignore();
		cout << "\tМатаналіз:";
		cin >> st[capacity].WasOn[subject named Matan]; cin.ignore();
		cout << "\tАлгебра:";
		cin >> st[capacity].WasOn[subject named Alg]; cin.ignore();
		cout << "Додати ще один запис?[enter][esc]\n";
		if (_getch() != 13) break;
		capacity++;
		st = expandStud(st, 2);
	}
	for (int i = 0; i <=capacity; ++i) {
		cout << "  [" << i + 1 << "] " << st[i].name << "\t\t|\t";
		for (int j = 0; j < 4; ++j) {
			cout << ((st[i].WasOn[j]) ? "Б" : "Н") << "\t|\t";
		}cout << endl;
	}
	SaveAs(st);

}
void Sheet::removeLine(Students* x, int line) {
	--line;
	for (int i = 0; i < capacity; ++i) {
		if (line<capacity)x[line] = x[line + 1];
	} capacity--;
	for (int i = 0; i < capacity; ++i) {
		cout << "  [" << i + 1 << "] " << x[i].name<<"\t\t|\t";
		for (int j = 0; j < 4; ++j) {
			cout << ((x[i].WasOn[j]) ? "Б" : "Н")<<"\t|\t";
		}cout << endl;
	}
}
string Sheet::SavedIn() {
	if (!path.empty()) return path;
	else return nullptr;
}
Sheet::Students* Sheet::expandStud(Students* x, int add) {
	Students *tmp = new Students[this->capacity-1 + add];
	for (int i = 0; i < capacity; ++i) {
		if (!x[i].name.empty()) tmp[i].name = x[i].name;
		tmp[i].WasOn[subject named OS] = x[i].WasOn[subject named OS];
		tmp[i].WasOn[subject named Prog] = x[i].WasOn[subject named Prog];
		tmp[i].WasOn[subject named Matan] = x[i].WasOn[subject named Matan];
		tmp[i].WasOn[subject named Alg] = x[i].WasOn[subject named Alg];
	} 
	return tmp;
}
void Sheet::SaveAs(Students* x) {
	path = this->date + ".txt";
	ofstream out(path,ios::trunc);
	for (int j = 0; j <= capacity; ++j) {
		out << x[j].name << " ";
		out << x[j].WasOn[subject named OS] << " ";
		out << x[j].WasOn[subject named Matan] << " ";
		out << x[j].WasOn[subject named Alg] << " ";
		out << x[j].WasOn[subject named Prog] << endl;

	}
}

Sheet::~Sheet(){
	if (this->st) delete this->st;
}