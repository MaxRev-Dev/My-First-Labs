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
			w("	|	Нажаль конфіг не знайдено(		|");
			w("	|	Це не проблема, зараз буде новий)	|");
			w("	|						|");
			w("		--->Making default config...");
			w("");
			w("		    Назва нової ПАПКИ: ");
			w("		   Сюди ми все помістимо");
			w("	    ЯКЩО ВИ НЕ ВПЕВНЕНІ, то натисніть \"Enter\"");
			w("");
			std::cout << "			";
			break;
		}
		case confErrFileExists: {
			w("		Нажаль папка не може бути створена. ");
			w("			Можливо вона вже існує.");
			w("			І немає конфігурації.");
			break;
		}
		case genFile: {
			w("");
			w("		Далі вводимо просто назву. БЕЗ розширення");
			w("");
			w("		Якою буде НАЗВА ЗГЕНЕРОВАНОГО ФАЙЛУ: ");
			w("			Зазвичай це INDEX");
			w("	    ЯКЩО ВИ НЕ ВПЕВНЕНІ, то натисніть \"Enter\"");
			w("");
			std::cout << "			";
			break;
		}
		case tmplFile: {
			w("");
			w("			НАЗВА ФАЙЛУ-ЗАГОТОВКИ: ");
			w("		Це файл-шаблон. З нього все починається");
			w("		  Його дизайн можна потім відредагувати");
			w(" WARNING!!!Порядок та розміщення маркерів не змінювати!!!WARNING");
			w("	    ЯКЩО ВИ НЕ ВПЕВНЕНІ, то натисніть \"Enter\"");
			w("");
			std::cout << "			";
			break;
		}
		case plsPutFile: {
			w("	  а тепер просто закиньте потрібний файл в СТВОРЕНУ папку");
			w("		  Це має бути спеціальний TXT файл");
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
			w("		Секунду..Ну тепер усе залежить від можливостей цього заліза) ");
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
			w("! Неможливо відкрити файл-шаблон");
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
		std::cout << str << endl;
	}
