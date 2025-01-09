#pragma once
#pragma once
#include "LT.h"
#include "In.h"
#include "Log.h"
#include "FST.h"

#define TYPE_SMALL		"small"
#define TYPE_STRING		"string"
#define TYPE_VOID		 "void"
#define TYPE_TRUE       "true"
#define TYPE_FALSE       "false"
#define DATE			"date"
#define STON			"ston"
#define MAIN			"main"


#define ISTYPE(str) ( !strcmp(str, TYPE_SMALL) || !strcmp(str, TYPE_STRING) )

namespace Lexer
{
	struct LEX
	{
		LT::LexTable lextable;
		IT::IdTable	idtable;
		LEX() {}
	};
	struct Graph
	{
		char lexema;
		FST::FST graph;
	};



	IT::Entry* getEntry		// ��������� � ���������� ������ ��
	(
		Lexer::LEX& tables,						// �� + ��
		char lex,								// �������
		char* id,								// �������������
		char* idtype,							// ���������� (���)
		bool isParam,							// ������� ��������� �������
		bool isFunc,							// ������� �������
		Log::LOG log,							// ��������
		int line,								// ������ � �������� ������
		bool& rc_err							// ���� ������(�� ������)
	);

	struct ERROR_S									// ��� ���������� ��� throw ERROR_THROW | ERROR_THROW_IN
	{
		int id;
		char message[ERROR_MAXSIZE_MESSAGE];			// ���������			
		struct
		{
			short line = -1;						//����� ������ (0, 1, 2, ...)
			short col = -1;						//����� ������� � ������(0, 1, 2, ...)
		} position;
	};
	bool analyze(LEX& tables, In::IN& in, Log::LOG& log, Parm::PARM& parm);
	int	getIndexInLT(LT::LexTable& lextable, int itTableIndex);					// ������ ������ ������� � ������� ������
};

