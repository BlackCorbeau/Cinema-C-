#include "Models.h"

Film::Film()
{
	CDate lb;
	CTime T;
	CString str;
	TimeOfGoes = T;
	Rate = 0.0;
	Name = str;
	type = str;
	CostForTicket = 0;
	liveBefore = lb;
	str.~CString();
}

Film::Film(Film& f)
{
	TimeOfGoes = f.TimeOfGoes;
	Rate = f.Rate;
	Name = f.Name;
	type = f.type;
	CostForTicket = f.CostForTicket;
	liveBefore = f.liveBefore;
}

Film::~Film()
{
	Name.~CString();
	type.~CString();
}

CTime Film::getTimeOfGoes()
{
	return TimeOfGoes;
}

void Film::setTimeOfGoes(CTime T)
{
	TimeOfGoes = T;
}