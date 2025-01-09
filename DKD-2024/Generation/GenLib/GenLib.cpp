#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime> 

extern "C"
{



	int __stdcall ston(char* buffer, char* ptr)
	{
		int n = 0;
		while (*ptr >= '0' && *ptr <= '9') {
			n *= 10;
			n += *ptr++;
			n -= '0';
		}
		return n;
		
	}

	void _stdcall date()
	{
		time_t Time = time(NULL);
		struct tm* now = localtime(&Time);

		std::cout << "Date: "
			<< now->tm_mday << "-"
			<< (now->tm_mon + 1) << "-"
			<< (now->tm_year + 1900) << std::endl;

		std::cout << "Time: "
			<< now->tm_hour << ":"
			<< now->tm_min << ":"
			<< now->tm_sec << std::endl;
	}

	int __stdcall outnum(int value)
	{
		std::cout << value;
		return 0;
	}

	int __stdcall outstr(char* ptr)
	{
		if (ptr == nullptr)
		{
			std::cout << std::endl;
		}
		for (int i = 0; ptr[i] != '\0'; i++)
			std::cout << ptr[i];
		return 0;
	}
}
