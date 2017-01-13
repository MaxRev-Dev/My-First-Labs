#include "classes.h"


connectFiles::connectFiles()
{
	init();
}
void connectFiles::IO(string&str, string key) {
	CSimpleIniA ini;
	strcpy_s(c_defconf, defconf.c_str());
	ini.LoadFile(c_defconf);
	str = ini.GetValue("Main",key.c_str(), NULL);
}
void connectFiles::defaultConf() {
	CSimpleIniA ini;
	strcpy_s(c_defconf, defconf.c_str());
	ini.LoadFile(c_defconf);
	std::cout << "Making default config...\n";

	std::cout << "File with tests (press Enter for default): ";
	cin.getline(buffer, 256);
	if (buffer[0] == 0) {
		ini.SetValue("Main", "InputFile", "./tests.txt");
	}
	else ini.SetValue("Main", "InputFile", buffer);

	std::cout << "Name of generated file (press Enter for default): ";
	cin.getline(buffer, 256);
	if (buffer[0] == 0) {
		ini.SetValue("Main", "OutputFile", "./index.html");
	}
	else  ini.SetValue("Main", "OutputFile", buffer);

	ini.SetValue("Main", "TemplateFile", "./res.html");
	ini.SaveFile(c_defconf);

}
void connectFiles::init() {
	CSimpleIniA ini;
	dir = opendir("./");
	while ((ent = readdir(dir)) != NULL) {
		str = ent->d_name;
		if (str == defconf) {
			std::cout << "Config.ini found!\n";
			break;
		}
	}
	if (str != defconf) {
		ofstream d;
		d.open(defconf, std::fstream::in | std::fstream::out | std::fstream::app);
		d << "\n";
		d.close();
		defaulConf();
		}
	
	closedir(dir);
}
connectFiles::~connectFiles()
{
}
