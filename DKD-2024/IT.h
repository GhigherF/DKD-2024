#pragma once
#pragma once
#include <iostream>

#define MAXSIZE_ID	8					//���� ����� �������� ��������������
#define SCOPED_ID_MAXSIZE   MAXSIZE_ID*2 //���� ����� �������� ������������� + ������� ���������
#define MAXSIZE_TI		4096			//���� ����� ���������� ����� � ������� ���������������	
#define NUM_DEFAULT	0x00000000		//�������� �� ��������� ��� int
#define STR_DEFAULT	0x00			//�������� �� ��������� ��� sting
#define NULLIDX_TI		0xffffffff		//��� �������� ������� ���������������
#define STR_MAXSIZE	255				//������������ ����� ���������� ��������
#define NUM_MAXSIZE   127		//������������ �������� ��� ���� number
#define NUM_MINSIZE  -128		//����������� �������� ��� ���� number
#define MAX_PARAMS_COUNT 20				//������������ ���������� ���������� � �������		//���-�� ���������� � ������� concat
#define STON_PARAMS_CNT 1
#define DATE_PARAMS_CNT 0//���-�� ���������� � ������� atoii
#define DATE_TYPE NULL
#define STON_TYPE IT::IDDATATYPE::SML



namespace IT
{
	enum IDDATATYPE { SML = 1, STR = 2, VOID = 3, UNDEF };//���� ������ ���������������: ��������, ���������, ��� ����(��� ��������), ��������������
	enum IDTYPE { V = 1, F = 2, P = 3, L = 4, S = 5 };	//���� ���������������: ����������, �������, ��������, �������, ����������� �������
	enum STDFNC { F_DATE,F_STON, F_NOT_STD };	//����������� �������
	static const IDDATATYPE STON_PARAMS[] = { IT::IDDATATYPE::STR };//��������� �-��� atoi
	struct Entry
	{
		union
		{
			int	vint;            			//�������� number
			struct
			{
				int len;					//���������� ��������
				char str[STR_MAXSIZE - 1];//�������
			} vstr;							//�������� ������
			struct
			{
				int count;					// ���������� ���������� �������
				IDDATATYPE* types;			//���� ���������� �������
			} params;
		} value;						//�������� ��������������
		int			idxfirstLE;				//������ � ������� ������		
		char		id[SCOPED_ID_MAXSIZE];
		IDDATATYPE	iddatatype;				//��� ������
		IDTYPE		idtype;					//��� ��������������
		char		scope[SCOPED_ID_MAXSIZE/2];
		Entry()							//����������� ��� ����������
		{
			this->value.vint = NUM_DEFAULT;
			this->value.vstr.len = NULL;
			this->value.params.count = NULL;
		};
		Entry(char* id, int idxLT, IDDATATYPE datatype, IDTYPE idtype) //����������� � �����������
		{
			strncpy_s(this->id, id, SCOPED_ID_MAXSIZE - 1);
			this->idxfirstLE = idxLT;
			this->iddatatype = datatype;
			this->idtype = idtype;
		};
	};
	struct IdTable		//��������� ������� ���������������
	{
		int maxsize;	//������� ������� ��������������� < TI_MAXSIZE
		int size;		//������� ������ ������� ��������������� < maxsize
		Entry* table;	//������ ����� ������� ���������������
	};
	IdTable Create(int size = NULL);	//������� ������� ��������������� < TI_MAXSIZE
	void Add(					//�������� ������ � ������� ���������������
		IdTable& idtable,		//��������� ������� ���������������
		Entry entry);			//������ ������� ��������������� 
	int isId(					//�������: ����� ������(���� ����), TI_NULLIDX(���� ����)
		IdTable& idtable,		//��������� ������� ���������������
		char id[SCOPED_ID_MAXSIZE]);	//�������������
	bool SetValue(IT::Entry* entry, char* value);	//������ �������� ��������������
	bool SetValue(IT::IdTable& idtable, int index, char* value);
	void writeIdTable(std::ostream* stream, IT::IdTable& idtable); //������� ������� ���������������
};
