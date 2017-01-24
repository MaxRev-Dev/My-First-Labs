#include "classes.h"

writer<string> w;
CSimpleIniA ini;
connectFiles::connectFiles(string &dfdir)
{
	defdir = dfdir;
}
int connectFiles::IO(string&str, string key) {
	memcpy(c_defconf, defconf.c_str(), sizeof(defconf));

	SI_Error rc = ini.LoadFile(this->c_defconf);
	if (rc < 0) return -3;
	try {
		 if (!ini.GetValue("Main", key.c_str(), NULL)) throw 1;
		 str = ini.GetValue("Main", key.c_str(), NULL);
	}
	catch (int r) {
		if (r == 1) w.w("Конфіг пустий або неправильний!");
		return -3;
	}
	
	return 0;
}
int connectFiles::init(string &d) {
	this->helper();
	dir = opendir("./");
	while ((ent = readdir(dir)) != NULL) {
		str = ent->d_name;
		if (str == defconf) {
			w.w("	|	   Config.ini знайдено!			|");
			string tmp;
			IO(tmp, "InputFile");
			cout<<"	|		  Файл "<<tmp<<"		|"<<endl;
			w.w("	|	   Якщо ні то введіть іншу назву	|");
			cout << "		";
			cin.getline(buffer, 256);
			memcpy(c_defdir, defdir.c_str(), sizeof(defdir));
			memcpy(c_defconf, defconf.c_str(), sizeof(defconf));
			IO(tmp, "ThisDir");
			memcpy(c_defdir, tmp.c_str(), sizeof(defdir));
			memcpy(c_full1,c_defdir, sizeof(defdir));
			if (buffer[0] == 0) {
				break;
			}
			else {
				cpst(this->c_full1, buffer);
				cpst(this->c_full1, ".txt");
				ini.SetValue("Main", "InputFile", c_full1);
				ini.SaveFile(c_defconf);
			}

			closedir(dir);
			return 0;
		}
	}

	if (str != defconf) {
		if (defaultConf(d) == -3) {
			_getch(); return -3;
		}
	}
	closedir(dir);
	if (!opendir(defdir.c_str())) {
			w.w("Хм.. Щось пішло не так( Щось з назвою папки");
			/*char buff[30];
			cin.getline(buff, 30);
			if (buff[0] != 0)
			{
				if (!this->CreateDir(buff)) {
					w.w("Нажаль неможливо створити файли конфігурації(");
					_getch();
					return -3;
				}
				defdir = buff;
				defdir = ".\\" + defdir +"\\";
			}
			memcpy(c_defdir, defdir.c_str(), sizeof(defdir));
			if (buff[0]==0) this->CreateDir(this->c_defdir);*/
		}
	d = defdir;
	memcpy(c_defdir, defdir.c_str(), sizeof(defdir));
	memcpy(c_defconf, defconf.c_str(), sizeof(defconf));
	memcpy(c_full, c_defconf, sizeof(defconf));
	if (strspn(buffer,c_full1) == 0) {
		memcpy(c_full1, c_defdir, sizeof(defdir));
		cpst(c_full1, chr1);
	}
	memcpy(c_full2, c_defdir, sizeof(defdir));
	cpst(c_full2, chr2);
	memcpy(c_full3, c_defdir, sizeof(defdir));
	cpst(c_full3, chr3);
	return 0;
}
int connectFiles::hell() {
	ofstream fo(c_full3,ios_base::trunc);
		writer<string> w;
		fo << "<!doctype html>\n";
		fo << "\n";
		fo << "<html>\n";
		fo << "<head>\n";
		fo << "	<meta charset = \"windows-1251\">\n";
		fo << "	<meta name = \"viewport\" content = \"width=device-width, initial-scale=1\">\n";
		fo << "	<link rel = \"stylesheet\" href = \"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css\">\n";
		fo << "	<script src = \"https://ajax.googleapis.com/ajax/libs/jquery/3.1.1/jquery.min.js\"></script>\n";
		fo << "	<script src = \"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js\"></script>\n";
		fo << "\n";
		fo << "	<style type = \"text/css\">\n";
		fo << "		.col-sm-2 {\n";
		fo << "			overflow: auto;\n";
		fo << "			margin: 5px;\n";
		fo << "			border: #adadae;\n";
		fo << "			border-width: 2px;\n";
		fo << "			border-style: solid;\n";
		fo << "		}\n";
		fo << "\n";
		fo << "		a:focus {\n";
		fo << "			text-decoration: none;\n";
		fo << "		}\n";
		fo << "		.center{\n";
		fo << "			text-align: center;\n";
		fo << "		}\n";
		fo << "\n";
		fo << "	</style>\n";
		fo << "\n";
		fo << "<title>TESTS</title>\n";
		fo << "</head>\n";
		fo << "<body>\n";
		fo << "\n";
		fo << "<div class = \"container-fluid\">\n";
		fo << "	<div class = \"row\">\n";
		fo << "		<div class = \"container\">\n";		
		fo << "				<div class = \"container\">\n";
		fo << "			<h2 class=\"center\">TESTS</h2>\n";
		fo << "					<div class = \"panel-group\" id = \"accordion\">\n";
		fo << "/*mark*/\n";
		fo << "						<div class = \"panel panel-default\">\n";
		fo << "							<div class = \"panel-heading\">\n";
		fo << "								<h4 class = \"panel-title\">\n";
		fo << "									<a data-toggle = \"collapse\" data-parent = \"#accordion\" href = \"#collapseX\">/*mark*/</a>\n";
		fo << "								</h4>\n";
		fo << "							</div>\n";
		fo << "\n";
		fo << "						<div id = \"collapseX\" class = \"panel-collapse collapse\">\n";
		fo << "							<div class = \"panel-body\">\n";
		fo << "/*mark*/\n";
		fo << "								<div class = \"col-sm-2\">/*mark*/</div>\n";
		fo << "								<div class = \"col-sm-2\">/*mark*/</div>\n";
		fo << "								<div class = \"col-sm-2\">/*mark*/</div>\n";
		fo << "								<div class = \"col-sm-2\">/*mark*/</div>\n";
		fo << "								<div class = \"col-sm-2\">/*mark*/</div>\n";
		fo << "							</div>\n";
		fo << "						</div>\n";
		fo << "					</div>\n";
		fo << "/*mark*/\n";
		fo << "				</div>\n";
		fo << "/*mark*/\n";
		fo << "			</div>\n";
		fo << "		</div>\n";
		fo << "	</div>\n";
		fo << "</div>\n";
		fo << "</body>\n";
		fo << "</html>\n";
		fo << "/*mark*/\n";
		fo.close();
		return 0;

}
int connectFiles::defaultConf(string &d) {
	w.w("	|						|");
	w.w("	|	Нажаль конфіг не знайдено(		|");
	w.w("	|	Це не проблема, зараз буде новий)	|");
	w.w("	|						|");
	w.w("		--->Making default config...");
	
	w.w("		Папка з завданням (press \"Enter\" for default): ");
	w.w("");
	std::cout << "			";
	cin.getline(buffer, 256);
	if (buffer[0] == 0) {
		ini.SetValue("Main", "InputFile", c_full1 );
		memcpy(c_full1, c_defdir, sizeof(defdir));
		cpst(c_full1, chr1);
		cpst(c_full1, ".txt");
	}
	else {
		defdir = ".\\";
		defdir += buffer;
		defdir += "\\";
		d = defdir;
	}
	memcpy(c_defdir, defdir.c_str(), sizeof(defdir));
	memcpy(c_defconf, defconf.c_str(), sizeof(defconf));
	ini.SetValue("Main", "ThisDir", c_defdir);
	memcpy(c_full, c_defconf, sizeof(defconf));
	memcpy(c_full2, c_defdir, sizeof(defdir));
	cpst(c_full2, chr2);
	memcpy(c_full3, c_defdir, sizeof(defdir));
	cpst(c_full3, chr3);
	if (CreateDir(this->c_defdir) == false) { 
		w.w("Нажаль папка не може бути створена. "); 
		w.w("Можливо вона вже існує"); 
		return -3;
	}
	w.w("");
	w.w("		Вводимо просто назву. Без розширення");
	w.w("		Назва згенерованого файлу (press \"Enter\" for default): ");
	w.w("");
	std::cout << "			";
	cin.getline(buffer, 256);
	if (buffer[0] == 0) {
		ini.SetValue("Main", "OutputFile", c_full2);
	}
	else {
		memcpy(c_full2, c_defdir, sizeof(defdir));
		cpst(c_full2, buffer);
		cpst(c_full2, ".html");
		ini.SetValue("Main", "OutputFile", c_full2);
	}
	w.w("");
	w.w("		Назва файлу-заготовки (press \"Enter\" for default): ");
	w.w("");
	std::cout << "			";
	cin.getline(buffer, 256);
	if (buffer[0] == 0) {
		ini.SetValue("Main", "TemplateFile", c_full3);
	}
	else {
		memcpy(c_full3, c_defdir, sizeof(defdir));
		cpst(c_full3, buffer);
		cpst(c_full3, ".html");
		ini.SetValue("Main", "TemplateFile",c_full3);
	}

	ini.SetValue("Main", "Marker", chr4);
		
	w.w("		Закиньте потрібний файл в СТВОРЕНУ папку і введіть його назву тут");
	w.w("			Це має бути TXT файл");
	w.w("");
	std::cout << "			";
	while (true) {
		if (buffer[0] == '0') {
			w.w("--->Виходимо?");
			return -3;
		}		
		cin.getline(buffer, 256);
		memcpy(c_full1, c_defdir, sizeof(defdir));
		cpst(c_full1, buffer);
		cpst(c_full1, ".txt");
		ifstream f(c_full1);
		if (!f.is_open()) {
			w.w("		Файл не знайдено! Введіть шлях ще раз або 0 для виходу");
			w.w("");
			std::cout << "			";
		}
		else {
			ini.SetValue("Main", "InputFile", c_full1);
			break;
		}
	}
	w.w("");
	if (ini.SaveFile(c_full) == 0)	w.w("		--->Конфіг успішно створено!");
	if (this->hell() == 0) w.w("		--->Файл-шаблон успішно створено!");
	w.w("		--->Допоміжні файли створено!");
	w.w("		Пекло закінчилось...");
	w.w("		Секунду..А може і дві)...");
	w.w("");
	return 0;
}
void connectFiles::helper() {
	w.w("	|		---MaxRev---			|");
	w.w("	|						|");
	w.w("	|		 ---Info---			|");
	w.w("	|	Якщо щось не так, видаляємо конфіг	|");
	w.w("	|	   Назви записуються тільки		|");
	w.w("	|		  латинськими літерами		|");
	w.w("	|						|");
}
void connectFiles::cpst(char *dest, char *src) {
	*fullsz = strlen(dest) + 2 + strlen(src);
	for (unsigned int i = strlen(dest), z = 0; i < *fullsz; i++) {
		dest[i] = src[z++];
	}
}
bool connectFiles::CreateDir(TCHAR * sPathTo)
{
	while (CreateDirectory(sPathTo, NULL) == FALSE)
	{
		TCHAR   sTemp[MAX_PATH];
		int k = strlen(sPathTo);
		strcpy_s(sTemp, sPathTo);

		while (CreateDirectory(sTemp, NULL) != TRUE)
		{
			while (sTemp[--k] != '\\')
			{
				if (k <= 1)
					return FALSE;
			}
		}
		return TRUE;
	} return true;
}
string connectFiles::der() {
	return defconf;
}
