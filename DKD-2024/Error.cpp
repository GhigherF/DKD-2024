#include "pch.h"
#include "Header.h"

namespace Error
{
	ERROR errors[ERROR_MAX_ENTRY] =
	{
		ERROR_ENTRY(0, "������������ ��� ������"),
		ERROR_ENTRY(1, "��������� ����"),
		ERROR_ENTRY_NODEF(2), ERROR_ENTRY_NODEF(3), ERROR_ENTRY_NODEF(4), ERROR_ENTRY_NODEF(5),
		ERROR_ENTRY_NODEF(6), ERROR_ENTRY_NODEF(7), ERROR_ENTRY_NODEF(8), ERROR_ENTRY_NODEF(9),
		ERROR_ENTRY_NODEF10(10), ERROR_ENTRY_NODEF10(20), ERROR_ENTRY_NODEF10(30), ERROR_ENTRY_NODEF10(40),
		ERROR_ENTRY_NODEF10(50),
		ERROR_ENTRY_NODEF(60),
		ERROR_ENTRY_NODEF(61),
		ERROR_ENTRY_NODEF(62),
		ERROR_ENTRY_NODEF(63),
		ERROR_ENTRY_NODEF(64),
		ERROR_ENTRY_NODEF(65),
		ERROR_ENTRY_NODEF(66),
		ERROR_ENTRY_NODEF(67),
		ERROR_ENTRY_NODEF(68),
		ERROR_ENTRY(69,"���������� ������������ �������� ����� ���������� � �������� �������� �������"),
		ERROR_ENTRY_NODEF10(70), ERROR_ENTRY_NODEF10(80), ERROR_ENTRY_NODEF10(90),
		ERROR_ENTRY(100, "�������� -in ������ ���� �����"),
		ERROR_ENTRY(101, "��������� ����� �������� ���������"),
		ERROR_ENTRY(102, "������ ��� �������� ����� � �������� �����(-in)"),
		ERROR_ENTRY(103, "������ ��� �������� ����� ���������(-log)"),
		ERROR_ENTRY_NODEF(104), ERROR_ENTRY_NODEF(105), ERROR_ENTRY_NODEF(106), ERROR_ENTRY_NODEF(107), ERROR_ENTRY_NODEF(108), ERROR_ENTRY_NODEF(109),
		ERROR_ENTRY_NODEF10(110), ERROR_ENTRY_NODEF10(120), ERROR_ENTRY_NODEF10(130), ERROR_ENTRY_NODEF10(140),
		ERROR_ENTRY_NODEF10(150), ERROR_ENTRY_NODEF10(160), ERROR_ENTRY_NODEF10(170), ERROR_ENTRY_NODEF10(180), ERROR_ENTRY_NODEF10(190),
		ERROR_ENTRY(200, "LexAnaliz: ������������ ������ � �������� �����(-in)"),
		ERROR_ENTRY(201, "LexAnaliz: ����������� ������������������ ��������"),
		ERROR_ENTRY(202, "LexAnaliz: �������� ������ ������� ������"),
		ERROR_ENTRY(203, "LexAnaliz: �������� ������ ������� ���������������"),
		ERROR_ENTRY(204, "LexAnaliz: ��������� ���������� ����� ��������������"),
		ERROR_ENTRY(205,"LexAnaliz: �������� ��� ������ ����"),
		ERROR_ENTRY_NODEF(206), ERROR_ENTRY_NODEF(207), ERROR_ENTRY_NODEF(208), ERROR_ENTRY_NODEF(209),
		ERROR_ENTRY_NODEF10(210), ERROR_ENTRY_NODEF10(220), ERROR_ENTRY_NODEF10(230), ERROR_ENTRY_NODEF10(240),
		ERROR_ENTRY_NODEF10(250), ERROR_ENTRY_NODEF10(260), ERROR_ENTRY_NODEF10(270), ERROR_ENTRY_NODEF10(280), ERROR_ENTRY_NODEF10(290),
		ERROR_ENTRY(300, "Semantic:  ������������� �������������"),
		ERROR_ENTRY(301, "Semantic: ����������� ����� ����� main"),
		ERROR_ENTRY(302, "Semantic: ���������� ��������� ����� ����� main"),
		ERROR_ENTRY(303, "Semantic: � ���������� �� ������ ��� ��������������"),
		ERROR_ENTRY(304, "Semantic: � ���������� ����������� �������� ����� announce"),
		ERROR_ENTRY(305, "Semantic: ������� ��������������� ��������������"),
		ERROR_ENTRY(306, "Semantic: ��������� ������������ ���������� ���������� �������"),
		ERROR_ENTRY(307, "Semantic: ������� ����� ���������� � ������"),
		ERROR_ENTRY(308, "Semantic: ���-�� ���������� �������� � ������������ ���������� �� ���������"),
		ERROR_ENTRY(309, "Semantic: ������������ ����� ������������ ����������"),
		ERROR_ENTRY(310, "Semantic: ������������� ������� ���������� �������� �����������"),
		ERROR_ENTRY(311, "Semantic: ���������� ����������� �������"),
		ERROR_ENTRY(312, "Semantic: �������� ������ ���������� ��������"),
		ERROR_ENTRY(313, "Semantic: ������������ ������������� �������"),
		ERROR_ENTRY(314, "Semantic: ���� ������ � ��������� �� ���������"),
		ERROR_ENTRY(315, "Semantic: ��� ������� � ������������� �������� �� ���������"),
		ERROR_ENTRY(316, "Semantic: ������������ ��������� ��������� ������ �� ����� \'=\'"),
		ERROR_ENTRY(317, "Semantic: �������� �������� ���������"),
		ERROR_ENTRY(318, "Semantic: ������� �� ����"),
		ERROR_ENTRY(319, "Semantic: �������� ������������ ������ ��������"),
		ERROR_ENTRY_NODEF10(320),ERROR_ENTRY_NODEF10(330),ERROR_ENTRY_NODEF10(340),ERROR_ENTRY_NODEF10(350),
		ERROR_ENTRY_NODEF10(360),ERROR_ENTRY_NODEF10(370),ERROR_ENTRY_NODEF10(380),ERROR_ENTRY_NODEF10(390),
		ERROR_ENTRY_NODEF100(400), ERROR_ENTRY_NODEF100(500),
		ERROR_ENTRY(600, "MFST: �������� ��������� ���������"),
		ERROR_ENTRY(601, "MFST: �� ������ ������ ���������� �������"),
		ERROR_ENTRY(602, "MFST: ������ � ���� �������"),
		ERROR_ENTRY(603, "MFST: ������ � ���� ���������"),
		ERROR_ENTRY(604, "MFST: ������ � ������ ���������� �������"),
		ERROR_ENTRY(605, "MFST: ������ � ������ �������/���������"),
		ERROR_ENTRY(606, "MFST: ������ � ������ ����������� ���������� �������"),
		ERROR_ENTRY(607, "MFST: ������ ��� �������������� �����/��������� ���������"),
		ERROR_ENTRY(608, "MFST: ������ � ���� �����/��������� ���������"),
		ERROR_ENTRY(609, "MFST: ������ � ������� �����/��������� ���������"),
		ERROR_ENTRY(610, "MFST: �������� �������� ��������"),
		ERROR_ENTRY(611, "MFST: �������� �������������� ��������"),
		ERROR_ENTRY(612, "MFST: �������� ���������. ��������� ������ ��������������/��������"),
		ERROR_ENTRY(613, "MFST: ������ � �������������� ���������"),
		ERROR_ENTRY(614, "MFST: ������������ �������������� �����������"),
		ERROR_ENTRY(615, "MFST: ������������ �������������� ����������� � ���� �����/��������� ���������"),
		ERROR_ENTRY(616, "MFST: ������� ��������� �������������� �� ����� ���� ������"),
		ERROR_ENTRY_NODEF(617),ERROR_ENTRY_NODEF(618), ERROR_ENTRY_NODEF(619),
		ERROR_ENTRY_NODEF10(620), ERROR_ENTRY_NODEF10(630), ERROR_ENTRY_NODEF10(640), ERROR_ENTRY_NODEF10(650),
		ERROR_ENTRY_NODEF10(660), ERROR_ENTRY_NODEF10(670), ERROR_ENTRY_NODEF10(680), ERROR_ENTRY_NODEF10(690),
		ERROR_ENTRY_NODEF100(700), ERROR_ENTRY_NODEF100(800), ERROR_ENTRY_NODEF100(900)
	};

	ERROR GetError(int id)
	{
		if (id < 0 || id > ERROR_MAX_ENTRY)
			return errors[0];
		else
			return errors[id];
	}

	ERROR GetError(int id, int line, int col)
	{
		ERROR err = GetError(id);
		err.position.col = col;
		err.position.line = line;
		return err;
	}
};