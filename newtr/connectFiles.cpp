#include "classes.h"
	writer<string> w;
	CSimpleIniA ini;
	connectFiles::connectFiles(string &dfdir)
	{
		defdir = dfdir;
		strcpy_s(buffer, "");
		strcpy_s(chr1, "tests.txt");
		strcpy_s(chr2, "index.html");
		strcpy_s(chr3, "template.html");
		strcpy_s(chr4, "/*mark*/");
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
			if (r == 1) w.w(" онф≥г пустий або неправильний!");
			return -3;
		}

		return 0;
	}
	int connectFiles::init(string &d) {
		w.answers(helper);
		dir = opendir("./");
		int defaultMakeCheck = 1;
		
		while ((ent = readdir(dir)) != NULL) {
			str = ent->d_name;
			if (str == defconf) {
				w.w("	|	   Config.ini знайдено!			|");
				string tmp;
				if (IO(tmp, "InputFile") == -3) return -3;
				cout << "		  ‘айл " << tmp << "	" << endl;
				w.w("		   якщо н≥ то введ≥ть ≥ншу назву	");
				cout << "		";
				cin.getline(buffer, 256);
				mkstr(-1);
				if (IO(tmp, "ThisDir") == -3) return -3;
				memcpy(c_defdir, tmp.c_str(), sizeof(defdir));
				memcpy(c_full1, c_defdir, sizeof(defdir));
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
		closedir(dir);
		if (str != defconf) {
			if (defaultConf(d) == -3) {
				_getch();
				defaultMakeCheck = 0;
				return -3;
			}
		}

		if (!opendir(defdir.c_str())) {
			w.w("’м.. ўось п≥шло не так( ўось з назвою папки");
			return -3;
		}

		d = defdir;

		if (defaultMakeCheck == 0) {
			mkstr(-1);
			mkstr(1);
		}
		mkstr(0);
		mkstr(2);
		mkstr(3);
		return 0;
	}
	int connectFiles::hell() {
		ofstream fo(c_full3, ios_base::trunc);
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
		w.answers(confInit);
		cin.getline(buffer, 256);
		if (buffer[0] == 0) {
			d = defdir;
			memcpy(c_defdir, defdir.c_str(), sizeof(defdir));
			ini.SetValue("Main", "InputFile", c_full1);
			mkstr(1);
			cpst(c_full1, ".txt");
		}
		else {
			defdir = ".\\";
			defdir += buffer;
			defdir += "\\";
			d = defdir;
		}
		mkstr(-1);
		ini.SetValue("Main", "ThisDir", c_defdir);
		mkstr(0);
		mkstr(2);
		mkstr(3);

		if (CreateDir((TCHAR*)defdir.c_str()) == false) {
			w.answers(confErrFileExists);
			w.answers(emergency);
			return -3;
		}
		w.answers(genFile);
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
		w.answers(tmplFile);

		cin.getline(buffer, 256);
		if (buffer[0] == 0) {
			ini.SetValue("Main", "TemplateFile", c_full3);
		}
		else {
			memcpy(c_full3, c_defdir, sizeof(defdir));
			cpst(c_full3, buffer);
			cpst(c_full3, ".html");
			ini.SetValue("Main", "TemplateFile", c_full3);
		}

		ini.SetValue("Main", "Marker", chr4);

		w.answers(plsPutFile);

		dir = opendir(c_defdir);
		int quiter = 0;

		while (quiter != 1) {
			Sleep(1000);
			dir = opendir(c_defdir);
			while ((ent = readdir(dir)) != NULL) {
				str = ent->d_name;
				if (strspn(".txt", str.c_str()) == 4) {
					memcpy(c_full1, c_defdir, sizeof(defdir));
					writer <char> d;
					d.cpstr(c_full1, str.c_str());
					ini.SetValue("Main", "InputFile", c_full1);
					quiter++;
					break;
				}
			}
		}
		closedir(dir);

		/*while (true) {

			if (buffer[0] == '0') {
				w.answers(exitPR);
				return -3;
			}
			cin.getline(buffer, 256);
			memcpy(c_full1, c_defdir, sizeof(defdir));
			cpst(c_full1, buffer);
			cpst(c_full1, ".txt");
			ifstream f(c_full1);
			if (!f.is_open()) {
				w.answers(NF);
			}
			else {
				ini.SetValue("Main", "InputFile", c_full1);
				break;
			}
		}*/


		w.w("");
		if (ini.SaveFile(c_full) == 0)	w.answers(confCreated);
		if (this->hell() == 0) w.answers(tmplCreated);
		w.answers(allIsOk);
		return 0;
	}
	void connectFiles::cpst(char *dest, char *src) {
		*fullsz = strlen(dest) + 2 + strlen(src);
		for (size_t i = strlen(dest), z = 0; i < *fullsz; i++) {
			dest[i] = src[z++];
		}
	}
	bool connectFiles::CreateDir(TCHAR * sPathTo)
	{
		while (CreateDirectory(sPathTo, NULL) == FALSE)
		{
			TCHAR   sTemp[MAX_PATH];

			size_t k = _tcslen(sPathTo);
			_tcscpy_s(sTemp, sPathTo);

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
	void connectFiles::mkstr(int e) {
		switch (e) {
		case -1: {
			memcpy(c_defdir, defdir.c_str(), sizeof(defdir));
			memcpy(c_defconf, defconf.c_str(), sizeof(defconf));
			break;
		}
		case 0: {
			memcpy(c_full, c_defconf, sizeof(defconf));
			break;
		}
		case 1: {
			memcpy(c_full1, c_defdir, sizeof(defdir));
			cpst(c_full1, chr1);
			break;
		}
		case 2: {
			memcpy(c_full2, c_defdir, sizeof(defdir));
			cpst(c_full2, chr2);
			break;
		}
		case 3: {
			memcpy(c_full3, c_defdir, sizeof(defdir));
			cpst(c_full3, chr3);
			break;
		}
		default: {

		}
		}
	}
