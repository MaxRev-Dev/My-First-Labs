#pragma once

enum ENU : int {
	confInit,
	confErrFileExists,
	genFile,
	tmplFile,
	plsPutFile,
	NF,
	allIsOk,
	confCreated,
	tmplCreated,
	exitPR,
	ex1, ex2,helper,emergency
};
template <typename type>
class writer
{
public:
	writer();
	void answers(int);
	void w(const type &);
};

template<typename type>
inline writer<type>::writer()
{
}

template <typename type>
void writer<type>::answers(int e) {
	switch ( e)
	{
	case confInit: {
		w("	|						|");
		w("	|	������ ������ �� ��������(		|");
		w("	|	�� �� ��������, ����� ���� �����)	|");
		w("	|						|");
		w("		--->Making default config...");
		w("		����� � ��������� (press \"Enter\" for default): ");
		w("");
		std::cout << "			";
		break;
	}
	case confErrFileExists: {
		w("		������ ����� �� ���� ���� ��������. ");
		w("		������� ���� ��� ����.");
		w("		� ���� ������������.");
		break;
	}
	case genFile: {
		w("");
		w("		������� ������ �����. ��� ����������");
		w("		����� ������������� ����� (press \"Enter\" for default): ");
		w("");
		std::cout << "			";
		break;
	}
	case tmplFile: {
		w("");
		w("		����� �����-��������� (press \"Enter\" for default): ");
		w("");
		std::cout << "			";
		break;
	}
	case plsPutFile: {
		w("		�������� �������� ���� � �������� ����� � ������ ���� ����� ���");
		w("			�� �� ���� TXT ����");
		w("");
		std::cout << "			";
		break;
	}
	case NF: {
		w("		���� �� ��������! ������ ���� �� ��� ��� 0 ��� ������");
		w("");
		std::cout << "			";
		break;
	}
	case allIsOk: {
		w("		--->������� ����� ��������!");
		w("		����� ����������...");
		w("		�������..� ���� � ��)...");
		w("");
		break;
	} 
	case confCreated: {
		w("		--->������ ������ ��������!");
		break;
	}
	case tmplCreated: {
		w("		--->����-������ ������ ��������!");
		break; 
	}
	case exitPR: {
		w("--->��������?");
		break;
	}
	case ex1: {
		w("! ��������� ������� ���� � �������");
		w("�������� ���� ������������");
		break;
	}
	case ex2: {
		w("! ��������� ������� ����-���������");
		w("�������� ���� ������������");
		break;
	}
	case helper: {
		w("	|		---MaxRev---			|");
		w("	|						|");
		w("	|		 ---Info---			|");
		w("	|	���� ���� �� ���, ��������� ������	|");
		w("	|	   ����� ����������� �����		|");
		w("	|		  ����������� �������		|");
		w("	|						|");
		break;
	}
	case emergency: {
		w("");
		w("	��� ��� �� �����������, �� � �� �����. �������� �����(");
		break;
	}
	default:break;
	}
}

template <typename type>
void writer<type>::w(const type& str) {
	std::cout<<  str << endl;
}