#pragma once
namespace NewTextGenWForms {
	textGen::textGen(std::string &dfdir)
	{
		ctr.push_back(64);
		mirror = ctr;
		CSimpleIniA ini;
		connectFiles d(dfdir);
		memcpy(d.c_defconf, d.defconf.c_str(), sizeof(d.defconf));
		memcpy(d.c_full, d.c_defconf, sizeof(d.defconf));
		ini.LoadFile(d.c_full);
		mark = ini.GetValue("Main", "Marker", NULL);

	}
	void textGen::nextChr(vector<char> &ctrl)
	{
		char endOfR = 'Z';
		char &lastChr = ctrl.at(ctrl.size() - 1);
		(lastChr == endOfR) ? ctrl.push_back('A') : lastChr++;
		clicker = true;
	}
	void textGen::nextMark(std::ifstream &tmp)
	{
		string itr;
		char cr;
		tmp.seekg(x);
		while (true)
		{
			int j = 0;
			size_t t = mark.size();
			for (size_t i = 0; i < t; ++i)
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
				(clicker == false) ? nextChr(ctr) : clicker = false;
				size_t s = ctr.size();
				for (size_t i = 0; i < s; ++i)
					vcr.push_back(ctr[i]);
				tmp.get(cr);
			}
			vcr.push_back(cr);
		}
		tmp.seekg(x + 1);
		x = tmp.tellg();
	}
	void textGen::inTime(ofstream &fo) {
		fo << "			<div class=\"footer center panel panel-success\">\n";
		fo << "				<div class=\"panel-body\">";
		struct tm newtime;
		time_t now = time(0);
		char buf[80];
		localtime_s(&newtime, &now);
		strftime(buf, 80, "%A - %d/%m/%y - %X", &newtime);
		fo << "					<p>Generated on " << buf << "</p>\n";

		fo << "					<a href=\"http://maxrev.pp.ua\">Powered by MaxRev <span>©</span> 2017</a>\n";
		fo << "				</div>";
		fo << "			</div>";
	}
	void textGen::vecTF(ofstream &fl)
	{
		size_t s = vcr.size();
		for (size_t i = 0; i < s; ++i)
		{
			fl << vcr[i];
		} vcr.clear();
	}

	void textGen::getTitle(ifstream &arch)
	{
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
				}
				else vcr.push_back(sym);
			}
			arch.get(sym);
		}
	}
	void textGen::getQues(ifstream &arch) {
		string sg = "<strong>";
		string sgx = "</strong>";
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
				size_t s = sg.size();
				for (size_t i = 0; i < s; ++i) vcr.push_back(sg.at(i));
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
				size_t s = sgx.size();
				for (size_t i = 0; i < s; ++i) vcr.push_back(sgx.at(i));
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
			while (j < 5) {
				arch.get(sym);
				if (!arch) {
					arch.close();
					break;
				} j++;
			}
			if (arch) {
				tx = arch.tellg();
				tx -= j;
				arch.seekg(tx);
			}
		}
		tx = arch.tellg();
		arch.seekg(tx - 1);
	}
	void textGen::getCartPos(long long&rr, int sw) {
		switch (sw) {
		case 1: x = rr;
		case 2: tx = rr;
		}
	}
}