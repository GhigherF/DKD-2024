#include "pch.h"
#include "Header.h"

namespace Error
{
	ERROR errors[ERROR_MAX_ENTRY] =
	{
		ERROR_ENTRY(0, "Недопустимый код ошибки"),
		ERROR_ENTRY(1, "Системный сбой"),
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
		ERROR_ENTRY(69,"Невозможно использовать ключевое слово ассемблера в качестве названия функции"),
		ERROR_ENTRY_NODEF10(70), ERROR_ENTRY_NODEF10(80), ERROR_ENTRY_NODEF10(90),
		ERROR_ENTRY(100, "Параметр -in должен быть задан"),
		ERROR_ENTRY(101, "Превышена длина входного параметра"),
		ERROR_ENTRY(102, "Ошибка при открытии файла с исходным кодом(-in)"),
		ERROR_ENTRY(103, "Ошибка при создании файла протокола(-log)"),
		ERROR_ENTRY_NODEF(104), ERROR_ENTRY_NODEF(105), ERROR_ENTRY_NODEF(106), ERROR_ENTRY_NODEF(107), ERROR_ENTRY_NODEF(108), ERROR_ENTRY_NODEF(109),
		ERROR_ENTRY_NODEF10(110), ERROR_ENTRY_NODEF10(120), ERROR_ENTRY_NODEF10(130), ERROR_ENTRY_NODEF10(140),
		ERROR_ENTRY_NODEF10(150), ERROR_ENTRY_NODEF10(160), ERROR_ENTRY_NODEF10(170), ERROR_ENTRY_NODEF10(180), ERROR_ENTRY_NODEF10(190),
		ERROR_ENTRY(200, "LexAnaliz: Недопустимый символ в исходном файле(-in)"),
		ERROR_ENTRY(201, "LexAnaliz: Неизвестная последовательность символов"),
		ERROR_ENTRY(202, "LexAnaliz: Превышен размер таблицы лексем"),
		ERROR_ENTRY(203, "LexAnaliz: Превышен размер таблицы идентификаторов"),
		ERROR_ENTRY(204, "LexAnaliz: Превышена допустимая длина идентификатора"),
		ERROR_ENTRY(205,"LexAnaliz: Значение вне границ типа"),
		ERROR_ENTRY_NODEF(206), ERROR_ENTRY_NODEF(207), ERROR_ENTRY_NODEF(208), ERROR_ENTRY_NODEF(209),
		ERROR_ENTRY_NODEF10(210), ERROR_ENTRY_NODEF10(220), ERROR_ENTRY_NODEF10(230), ERROR_ENTRY_NODEF10(240),
		ERROR_ENTRY_NODEF10(250), ERROR_ENTRY_NODEF10(260), ERROR_ENTRY_NODEF10(270), ERROR_ENTRY_NODEF10(280), ERROR_ENTRY_NODEF10(290),
		ERROR_ENTRY(300, "Semantic:  Необъявленный идентификатор"),
		ERROR_ENTRY(301, "Semantic: Отсутствует точка входа main"),
		ERROR_ENTRY(302, "Semantic: Обнаружено несколько точек входа main"),
		ERROR_ENTRY(303, "Semantic: В объявлении не указан тип идентификатора"),
		ERROR_ENTRY(304, "Semantic: В объявлении отсутствует ключевое слово announce"),
		ERROR_ENTRY(305, "Semantic: Попытка переопределения идентификатора"),
		ERROR_ENTRY(306, "Semantic: Превышено максимальное количество параметров функции"),
		ERROR_ENTRY(307, "Semantic: Слишком много параметров в вызове"),
		ERROR_ENTRY(308, "Semantic: Кол-во ожидаемыех функцией и передаваемых параметров не совпадают"),
		ERROR_ENTRY(309, "Semantic: Несовпадение типов передаваемых параметров"),
		ERROR_ENTRY(310, "Semantic: Использование пустого строкового литерала недопустимо"),
		ERROR_ENTRY(311, "Semantic: Отсутствие закрывающих кавычек"),
		ERROR_ENTRY(312, "Semantic: Превышен размер строкового литерала"),
		ERROR_ENTRY(313, "Semantic: Недопустимый целочисленный литерал"),
		ERROR_ENTRY(314, "Semantic: Типы данных в выражении не совпадают"),
		ERROR_ENTRY(315, "Semantic: Тип функции и возвращаемого значения не совпадают"),
		ERROR_ENTRY(316, "Semantic: Недопустимое строковое выражение справа от знака \'=\'"),
		ERROR_ENTRY(317, "Semantic: Неверное условное выражение"),
		ERROR_ENTRY(318, "Semantic: Деление на ноль"),
		ERROR_ENTRY(319, "Semantic: Превышен максимальный размер Толкиена"),
		ERROR_ENTRY_NODEF10(320),ERROR_ENTRY_NODEF10(330),ERROR_ENTRY_NODEF10(340),ERROR_ENTRY_NODEF10(350),
		ERROR_ENTRY_NODEF10(360),ERROR_ENTRY_NODEF10(370),ERROR_ENTRY_NODEF10(380),ERROR_ENTRY_NODEF10(390),
		ERROR_ENTRY_NODEF100(400), ERROR_ENTRY_NODEF100(500),
		ERROR_ENTRY(600, "MFST: Неверная структура программы"),
		ERROR_ENTRY(601, "MFST: Не найден список параметров функции"),
		ERROR_ENTRY(602, "MFST: Ошибка в теле функции"),
		ERROR_ENTRY(603, "MFST: Ошибка в теле процедуры"),
		ERROR_ENTRY(604, "MFST: Ошибка в списке параметров функции"),
		ERROR_ENTRY(605, "MFST: Ошибка в вызове функции/выражении"),
		ERROR_ENTRY(606, "MFST: Ошибка в списке фактических параметров функции"),
		ERROR_ENTRY(607, "MFST: Ошибка при констуировании цикла/условного выражения"),
		ERROR_ENTRY(608, "MFST: Ошибка в теле цикла/условного выражения"),
		ERROR_ENTRY(609, "MFST: Ошибка в условии цикла/условного выражения"),
		ERROR_ENTRY(610, "MFST: Неверный условный оператор"),
		ERROR_ENTRY(611, "MFST: Неверный арифметический оператор"),
		ERROR_ENTRY(612, "MFST: Неверное выражение. Ожидаются только идентификаторы/литералы"),
		ERROR_ENTRY(613, "MFST: Ошибка в арифметическом выражении"),
		ERROR_ENTRY(614, "MFST: Недопустимая синтаксическая конструкция"),
		ERROR_ENTRY(615, "MFST: Недопустимая синтаксическая конструкция в теле цикла/условного выражения"),
		ERROR_ENTRY(616, "MFST: Область видимости идентификатора не может быть пустой"),
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