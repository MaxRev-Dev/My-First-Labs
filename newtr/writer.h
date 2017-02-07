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
		ex1, ex2, helper, emergency
	};
	template <typename type>
	class writer
	{
	private:
		size_t *fullsz = new size_t;
	public:
		writer();
		void answers(int);
		void cpstr(type *, const type *);
		void w(const type &);
	};

	template<typename type>
	inline writer<type>::writer()
	{
	}

	template <typename type>
	void writer<type>::cpstr(type *dest, const type *src) {
		*fullsz = strlen(dest) + 2 + strlen(src);
		for (size_t i = strlen(dest), z = 0; i < *fullsz; i++) {
			dest[i] = src[z++];
		}
	}

	template <typename type>
	void writer<type>::answers(int e) {
		switch (e)
		{
		case confInit: {
			w("	|						|");
			w("	|	������ ������ �� ��������(		|");
			w("	|	�� �� ��������, ����� ���� �����)	|");
			w("	|						|");
			w("		--->Making default config...");
			w("");
			w("		    ����� ���� �����: ");
			w("		   ���� �� ��� ��������");
			w("	    ���� �� �� ������Ͳ, �� �������� \"Enter\"");
			w("");
			std::cout << "			";
			break;
		}
		case confErrFileExists: {
			w("		������ ����� �� ���� ���� ��������. ");
			w("			������� ���� ��� ����.");
			w("			� ���� ������������.");
			break;
		}
		case genFile: {
			w("");
			w("		��� ������� ������ �����. ��� ����������");
			w("");
			w("		���� ���� ����� ������������� �����: ");
			w("			�������� �� INDEX");
			w("	    ���� �� �� ������Ͳ, �� �������� \"Enter\"");
			w("");
			std::cout << "			";
			break;
		}
		case tmplFile: {
			w("");
			w("			����� �����-���������: ");
			w("		�� ����-������. � ����� ��� ����������");
			w("		  ���� ������ ����� ���� ������������");
			w(" WARNING!!!������� �� ��������� ������� �� ��������!!!WARNING");
			w("	    ���� �� �� ������Ͳ, �� �������� \"Enter\"");
			w("");
			std::cout << "			";
			break;
		}
		case plsPutFile: {
			w("	  � ����� ������ �������� �������� ���� � �������� �����");
			w("		  �� �� ���� ����������� TXT ����");
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
			w("		�������..�� ����� ��� �������� �� ����������� ����� �����) ");
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
			w("! ��������� ������� ����-������");
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
		std::cout << str << endl;
	}
