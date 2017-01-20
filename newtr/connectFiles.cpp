#include "classes.h"
#include "writer.h"
writer<string> w;
CSimpleIniA ini;
connectFiles::connectFiles()
{
}
void connectFiles::IO(string&str, string key) {
	strcpy_s(c_defconf, defconf.c_str());
	ini.LoadFile(c_defconf);
	str = ini.GetValue("Main",key.c_str(), NULL);
}
void connectFiles::defaultConf() {
	
	strcpy_s(c_defconf, defconf.c_str());
	ini.LoadFile(c_defconf);
	w.w("Making default config...\n");
	
	w.w("File with tests (press Enter for default): ");
	cin.getline(buffer, 256);
	if (buffer[0] == 0) {
		ini.SetValue("Main", "InputFile", "./tests.txt");
	}
	else ini.SetValue("Main", "InputFile", buffer);

	w.w("Name of generated file (press Enter for default): ");
	cin.getline(buffer, 256);
	if (buffer[0] == 0) {
		ini.SetValue("Main", "OutputFile", "./index.html");
	}
	else  ini.SetValue("Main", "OutputFile", buffer);

	w.w("Marker in Sample file (press Enter for default): ");
	cin.getline(buffer, 256);
	if (buffer[0] == 0) {
		ini.SetValue("Main", "Marker", "/*mark*/");
	}
	else  ini.SetValue("Main", "Marker", buffer);
	
	ini.SetValue("Main", "TemplateFile", "./res.html");
	ini.SaveFile(c_defconf);
	w.w("Config created!");
}
void connectFiles::init() {
	
	dir = opendir("./");
	while ((ent = readdir(dir)) != NULL) {
		str = ent->d_name;
		if (str == defconf) {
			w.w("Config.ini found!\n");
			break;
		}
	}
	if (str != defconf) {
		ofstream d;
		d.open(defconf, std::fstream::in | std::fstream::out | std::fstream::app);
		d << "\n";
		d.close();
		defaultConf();
		}
	
	closedir(dir);
}
string connectFiles::der() {
	return defconf;
}
connectFiles::~connectFiles()
{
}
