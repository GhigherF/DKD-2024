#pragma once
#pragma once
#include <iostream>

#define MAXSIZE_ID	8					//макс число символов идентификатора
#define SCOPED_ID_MAXSIZE   MAXSIZE_ID*2 //макс число символов идентификатор + область видимости
#define MAXSIZE_TI		4096			//макс число количество строк в таблице идентификаторов	
#define NUM_DEFAULT	0x00000000		//значение по умолчанию дл€ int
#define STR_DEFAULT	0x00			//значение по умолчанию дл€ sting
#define NULLIDX_TI		0xffffffff		//нет элемента таблицы идентификаторов
#define STR_MAXSIZE	255				//максимальна€ длина строкового литерала
#define NUM_MAXSIZE   127		//максимальное значение дл€ типа number
#define NUM_MINSIZE  -128		//минимальное значение дл€ типа number
#define MAX_PARAMS_COUNT 20				//максимальное количество параметров у функции		//кол-во параметров у функции concat
#define STON_PARAMS_CNT 1
#define DATE_PARAMS_CNT 0//кол-во параметров у функции atoii
#define DATE_TYPE NULL
#define STON_TYPE IT::IDDATATYPE::SML



namespace IT
{
	enum IDDATATYPE { SML = 1, STR = 2, VOID = 3, UNDEF };//типы данных идентификаторов: числовой, строковый, без типа(дл€ процедур), неопределенный
	enum IDTYPE { V = 1, F = 2, P = 3, L = 4, S = 5 };	//типы идентификаторов: переменна€, функци€, параметр, литерал, стандартна€ функци€
	enum STDFNC { F_DATE,F_STON, F_NOT_STD };	//стандартные функции
	static const IDDATATYPE STON_PARAMS[] = { IT::IDDATATYPE::STR };//параметры ф-ции atoi
	struct Entry
	{
		union
		{
			int	vint;            			//значение number
			struct
			{
				int len;					//количество символов
				char str[STR_MAXSIZE - 1];//символы
			} vstr;							//значение строки
			struct
			{
				int count;					// количество параметров функции
				IDDATATYPE* types;			//типы параметров функции
			} params;
		} value;						//значение идентификатора
		int			idxfirstLE;				//индекс в таблице лексем		
		char		id[SCOPED_ID_MAXSIZE];
		IDDATATYPE	iddatatype;				//тип данных
		IDTYPE		idtype;					//тип идентификатора
		char		scope[SCOPED_ID_MAXSIZE/2];
		Entry()							//конструктор без параметров
		{
			this->value.vint = NUM_DEFAULT;
			this->value.vstr.len = NULL;
			this->value.params.count = NULL;
		};
		Entry(char* id, int idxLT, IDDATATYPE datatype, IDTYPE idtype) //конструктор с параметрами
		{
			strncpy_s(this->id, id, SCOPED_ID_MAXSIZE - 1);
			this->idxfirstLE = idxLT;
			this->iddatatype = datatype;
			this->idtype = idtype;
		};
	};
	struct IdTable		//экземпл€р таблицы идентификаторов
	{
		int maxsize;	//Ємкость таблицы идентификаторов < TI_MAXSIZE
		int size;		//текущий размер таблицы идентификаторов < maxsize
		Entry* table;	//массив строк таблицы идентификаторов
	};
	IdTable Create(int size = NULL);	//Ємкость таблицы идентификаторов < TI_MAXSIZE
	void Add(					//добавить строку в таблицу идентификаторов
		IdTable& idtable,		//экземпл€р таблицы идентификаторов
		Entry entry);			//строка таблицы идентификаторов 
	int isId(					//возврат: номер строки(если есть), TI_NULLIDX(если есть)
		IdTable& idtable,		//экземпл€р таблицы идентификаторов
		char id[SCOPED_ID_MAXSIZE]);	//идентификатор
	bool SetValue(IT::Entry* entry, char* value);	//задать значение идентификатора
	bool SetValue(IT::IdTable& idtable, int index, char* value);
	void writeIdTable(std::ostream* stream, IT::IdTable& idtable); //вывести таблицу идентификаторов
};
