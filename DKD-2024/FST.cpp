#include "pch.h"
#include "Header.h"
#include <iostream>

namespace FST
{
	RELATION::RELATION(char c = NULL, short ns = NULL)
	{
		this->symbol = c;
		this->nnode = ns;
	};

	NODE::NODE()
	{
		this->n_relation = NULL;
		this->relations = NULL;
	};

	NODE::NODE(short n, RELATION rel, ...)
	{
		RELATION* temp = &rel;
		this->relations = new RELATION[n];
		this->n_relation = n;
		for (short i = 0; i < n; i++)
			this->relations[i] = *(temp + i);
	};

	FST::FST(short ns, NODE n, ...)
	{
		this->node = new NODE[ns];
		NODE* temp = &n;
		this->nstates = ns;
		this->rstates = new short[ns];
		for (short i = 0; i < ns; i++)
			this->node[i] = *(temp + i);
		rstates[0] = 0;
		position = -1;
	}

	FST::FST(char* s, FST& fst)
	{
		this->node = new NODE[fst.nstates];
		NODE* temp = fst.node;
		this->string = s;
		this->nstates = fst.nstates;
		this->rstates = new short[this->nstates];
		for (short i = 0; i < this->nstates; i++)
			this->node[i] = *(temp + i);
		rstates[0] = 0;
		position = -1;

	}
	bool step(FST& fst, short*& rstates)           //��� ��������� ��������
	{
		bool rc = false;                                //���� - ��������� ����
		std::swap(rstates, fst.rstates);                        //������ ������� ��� ������� ��������� ���������
		for (short i = 0; i < fst.nstates; i++)                      //������ �� ���� ������� (�������)
		{
			if (rstates[i] == fst.position)                        //���� ������� i ������� ����� ������� ������� � �����(���� ���������� ��� �� �������� - �����)
			{
				for (short j = 0; j < fst.node[i].n_relation; j++)            //������������ ��������
				{
					if (fst.node[i].relations[j].symbol == fst.string[fst.position])  //����������� ����� ����� ������� �������
					{
						fst.rstates[fst.node[i].relations[j].nnode] = fst.position + 1;//������� � ��++
						rc = true;                            //��� �������� �������
					};
				};
			}

		};
		return rc;
	};
	bool execute(FST& fst)                      //���������� ��
	{
		short* rstates = new short[fst.nstates];          //��������� ��������� �����
		memset(rstates, 0xff, sizeof(short) * fst.nstates);      //���������� ������� ������ ��������� 255 (��������� �����. - ���-�� ����)
		short lstring = strlen(fst.string);            //����� ������� (������ �� strlen??????)
		bool rc = true;                        //����, ����������� �� ������������ ���������� ������� ����
		for (short i = 0; i < lstring && rc; i++)          //������ �� �������. ����� ����� �������, ���� ����. ��� �������� �����������
		{
			fst.position++;                      //������� � �������
			rc = step(fst, rstates);                //��� � �������
		};
		delete[] rstates;                      //�������� ������� �������
		return (rc ? (fst.rstates[fst.nstates - 1] == lstring) : rc);//���� false - ������� false ����� ������� ���������(��������� ������� � ������� ����� ����� ����� �������)
	};
}