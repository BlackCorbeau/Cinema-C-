#include "Models.h"

Holl::Holl()
{
	CTime _time;
	Film fl;
	f = fl;
	StartTime = _time;
	FinishTime = _time;
	CountOfSits = 0;
	s = Empty;
}

Holl::Holl(Holl& h)
{
	f = h.f;
	StartTime = h.StartTime;
	FinishTime = h.FinishTime;
	CountOfSits = h.CountOfSits;
	s = h.s;
}

Holl::Holl(Film F, CTime starttime, CTime finishtime, int countofsits, Holl_state s)
{
	f = F;
	StartTime = starttime;
	FinishTime = finishtime;
	CountOfSits = countofsits;
	this->s = s;
}

Holl::~Holl()
{
	f.~Film();
}

Film Holl::getFilm()
{
	return f;
}

CTime Holl::getStartTime()
{
	return StartTime;
}

CTime Holl::getFinishTime()
{
	return FinishTime;
}

int Holl::getCountOfSits()
{
	return CountOfSits;
}

Holl_state Holl::getstates()
{
	return s;
}

void Holl::setFilm(Film f)
{
	this->f = f;
}

void Holl::setStartTime(CTime ST)
{
	StartTime = ST;
}

void Holl::setFinishTime(CTime FT)
{
	FinishTime = FT;
}

void Holl::setCountOfSits(int count)
{
	CountOfSits = count;
}

void Holl::setstates(Holl_state _s)
{
	s = _s;
}
