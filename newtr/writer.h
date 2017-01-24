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
		w("	|	Нажаль конфіг не знайдено(		|");
		w("	|	Це не проблема, зараз буде новий)	|");
		w("	|						|");
		w("		--->Making default config...");
		w("		Папка з завданням (press \"Enter\" for default): ");
		w("");
		std::cout << "			";
		break;
	}
	case confErrFileExists: {
		w("		Нажаль папка не може бути створена. ");
		w("		Можливо вона вже існує.");
		w("		І немає конфігурації.");
		break;
	}
	case genFile: {
		w("");
		w("		Вводимо просто назву. Без розширення");
		w("		Назва згенерованого файлу (press \"Enter\" for default): ");
		w("");
		std::cout << "			";
		break;
	}
	case tmplFile: {
		w("");
		w("		Назва файлу-заготовки (press \"Enter\" for default): ");
		w("");
		std::cout << "			";
		break;
	}
	case plsPutFile: {
		w("		Закиньте потрібний файл в СТВОРЕНУ папку і введіть його назву тут");
		w("			Це має бути TXT файл");
		w("");
		std::cout << "			";
		break;
	}
	case NF: {
		w("		Файл не знайдено! Введіть шлях ще раз або 0 для виходу");
		w("");
		std::cout << "			";
		break;
	}
	case allIsOk: {
		w("		--->Допоміжні файли створено!");
		w("		Пекло закінчилось...");
		w("		Секунду..А може і дві)...");
		w("");
		break;
	} 
	case confCreated: {
		w("		--->Конфіг успішно створено!");
		break;
	}
	case tmplCreated: {
		w("		--->Файл-шаблон успішно створено!");
		break; 
	}
	case exitPR: {
		w("--->Виходимо?");
		break;
	}
	case ex1: {
		w("! Неможливо відкрити файл з тестами");
		w("Перевірте файл конфігурації");
		break;
	}
	case ex2: {
		w("! Неможливо відкрити файл-заготовку");
		w("Перевірте файл конфігурації");
		break;
	}
	case helper: {
		w("	|		---MaxRev---			|");
		w("	|						|");
		w("	|		 ---Info---			|");
		w("	|	Якщо щось не так, видаляємо конфіг	|");
		w("	|	   Назви записуються тільки		|");
		w("	|		  латинськими літерами		|");
		w("	|						|");
		break;
	}
	case emergency: {
		w("");
		w("	Цей світ не бездоганний, як і ця прога. Аварійний вихід(");
		break;
	}
	default:break;
	}
}

template <typename type>
void writer<type>::w(const type& str) {
	std::cout<<  str << endl;
}