#include <iostream>
#include "class.h"
#include "CDate.h"
#include "functions.h"


	CTime::CTime()
	{
		second = 0;
		minute = 0;
		hour = 0;
	}
	CTime::CTime(int _second, int _minute, int _hour)
	{
		second = _second;
		minute = _minute;
		hour = _hour;
	}
	CTime::~CTime()
	{

	}
	void CTime::initialize_seconds(int _second)
	{
		second = _second;
	}
	void CTime::initialize_minutes(int _minutes)
	{
		minute = _minutes;
	}
	void CTime::initialize_hours(int _hours)
	{
		hour = _hours;
	}
	int CTime::get_seconds()
	{
		return second;
	}
	int CTime::get_minutes()
	{
		return minute;
	}
	int CTime::get_hours()
	{
		return hour;
	}
	void CTime::print_parametrs()
	{
		std::cout << hour << ":" << minute << ":" << second << "\n";
	}

	CTime CTime::operator+(const CTime& T1)
	{
		CTime Res(*this);
		Res.second += T1.second;
		Res.minute += T1.minute;
		Res.hour += T1.hour;
		return Res;
	}
