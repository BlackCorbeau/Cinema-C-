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
Film::Film(CTime timeofgoes, float rate, CString name, CString type, int costforticket, CDate livebefore)
{
	TimeOfGoes = timeofgoes;
	Rate = rate;
	Name = name;
	this->type = type;
	CostForTicket = costforticket;
	liveBefore = livebefore;
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

float Film::getRate()
{
	return Rate;
}

void Film::setRate(float R)
{
	Rate = R;
}

CString Film::getName()
{
	return Name;
}

void Film::setName(CString str)
{
	Name = str;
}

CString Film::getType()
{
	return type;
}

void Film::setType(CString str)
{
	type = str;
}

int Film::getCostForTicket()
{
	return CostForTicket;
}

void Film::setCostForTicket(int cost)
{
	CostForTicket = cost;
}

CDate Film::getliveBefore()
{
	return liveBefore;
}

void Film::setliveBefore(CDate date)
{
	liveBefore = date;
}