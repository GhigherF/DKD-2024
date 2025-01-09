#include "pch.h"
#include "Log.h"
#include "Error.h"
#include "Parm.h"
#include "FlexAnaliz.h"
#include "In.h"
#include "IT.h"
#include "LT.h"
#include "PolishNotation.h"
#include "Semantic.h"
#include "MFST.h"
#include "Generator.h"
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	char LEXERROR[] = "����������� ������ �������� � �������� ";
	char SYNTERROR[] = "�������������� ������ �������� � �������� ";
	char SEMERROR[] = "���������� ������������� ������ ";
	char POLISHERROR[] = "������ ��� ������� �������������� ��������� ";
	char LEXGOOD[] = "����������� ������ �������� ��� ������ ";
	char SYNTGOOD[] = "�������������� ������ �������� ��� ������ ";
	char SEMGOOD[] = "������������� ������ �������� ��� ������ ";
	char POLISHGOOD[] = "�������������� ��������� ��������� ��� ������ ";
	char STOP[] = "���������� ��������� �����������";
	char ALLGOOD[] = "��������� ������� ���������!";
	setlocale(LC_ALL, "Russian");
	Log::LOG log;

	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);                            //�������� ���������
		log = Log::getstream(parm.log);
		Log::writeLog(log);														//�������� ��������� �������
		Log::writeParm(log, parm);												//�������� � ������ ���������
		In::IN in = In::getin(parm.in, log.stream);
		Log::writeIn(log.stream, in);


		in.words = In::getWordsTable(log.stream, in.text, in.code, in.size);
		In::printTable(in.words);

		Lexer::LEX tables;
		bool lex_ok = Lexer::analyze(tables, in, log, parm);
		if (parm.is_print_tables) {
			IT::writeIdTable(&std::cout, tables.idtable);							//�������� � ��������� ������ ����� ������� ������ � ��������������� 
			LT::writeLexTable(&std::cout, tables.lextable);							//� ����� ������������ ������� � ������
			LT::writeLexemsOnLines(&std::cout, tables.lextable);
		}
		LT::writeLexTable(log.stream, tables.lextable);							//�������� � ������ ������� ������ � ��������������� 
		IT::writeIdTable(log.stream, tables.idtable);							//� ����� ������������ ������� � ������
		LT::writeLexemsOnLines(log.stream, tables.lextable);
		if (!lex_ok)
		{
			Log::writeLine(log.stream, LEXERROR, "");
			Log::writeLine(&std::cout, LEXERROR, STOP, "");
			return 0;
		}
		else
		{
			Log::writeLine(&std::cout, LEXGOOD, "");
		}
		MFST_TRACE_START(log.stream);
		MFST::Mfst mfst(tables, GRB::getGreibach());							//��������� �������������� ������
		bool synt_ok = mfst.start(log);
		mfst.savededucation();
		mfst.printrules(log);			//������� ������ �������
		if (!synt_ok)
		{
			Log::writeLine(log.stream, SYNTERROR, "");
			Log::writeLine(&std::cout, SYNTERROR, STOP, "");
			exit(69);

		}
		else Log::writeLine(&std::cout, SYNTGOOD, "");




		bool sem_ok = Semantic::semanticsCheck(tables, log);					//��������� ������������� ������
		if (!sem_ok)
		{
			Log::writeLine(log.stream, SEMERROR, "");
			Log::writeLine(&std::cout, SEMERROR, STOP, "");
			exit(69);

		}
		else Log::writeLine(&std::cout, SEMGOOD, "");
		bool polish_ok = Polish::PolishNotation(tables, log);					//��������� �������������� ��������� � �����
		if (!polish_ok)
		{
			Log::writeLine(log.stream, POLISHERROR, "");
			Log::writeLine(&std::cout, POLISHERROR, STOP, "");
			exit(69);

		}
		else Log::writeLine(&std::cout, POLISHGOOD, "");
		LT::writeLexTable(log.stream, tables.lextable);							//�������� � ������ ����� ������� ������ � ���������������
		IT::writeIdTable(log.stream, tables.idtable);
		LT::writeLexemsOnLines(log.stream, tables.lextable);					//� ����� ������������ ������� � ������
		if (parm.is_print_tables) {
			IT::writeIdTable(&std::cout, tables.idtable);							//�������� � ��������� ������ ����� ������� ������ � ��������������� 
			LT::writeLexTable(&std::cout, tables.lextable);							//� ����� ������������ ������� � ������
			LT::writeLexemsOnLines(&std::cout, tables.lextable);
		}


		Gener::CodeGeneration(tables, parm, log);								//��������� ��������� ����
		Log::writeLine(log.stream, ALLGOOD, "");									//���� ������ ���������
		Log::writeLine(&std::cout, ALLGOOD, "");
		Log::Close(log);													    //������� ������
		//system("C:\\DKD-2024\\DKD-2024\\my.bat");
	}
	catch (Error::ERROR e)
	{
		Log::writeError(log.stream, e);
		exit(69);
	}

}


