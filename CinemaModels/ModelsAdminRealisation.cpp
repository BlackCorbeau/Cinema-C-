#include "Models.h"
#include <iostream>

Admin::Admin(int id, CString password, CString name, CString surename)
{
	this->id = id;
	this->Password = password;
	this->name = name;
	this->surename = surename;
}

Admin::~Admin()
{
	Password.~CString();
}

int Admin::get_id()
{
	return id;
}

void Admin::set_id(int i)
{
	id = i;
}

CString Admin::get_password()
{
	return Password;
}

void Admin::set_password(CString str)
{
	Password = str;
}

CString Admin::get_name()
{
	return name;
}

CString Admin::get_surename()
{
	return surename;
}

void Admin::set_name(CString name)
{
	this->name = name;
}

void Admin::set_surename(CString surename)
{
	this->surename = surename;
}

Film Admin::createFilm()
{
	Film nf;
	return nf;
}

Film Admin::createFilm(CTime timeofgoes, float rate, CString name, CString type, int costforticket, CDate livebefore)
{
	Film nf(timeofgoes, rate, name, type, costforticket, livebefore);
	return nf;
}

void Admin::deleteFilm(Film& f)
{
	f.~Film();
}

Holl Admin::createHoll()
{
	Holl h;
	return h;
}

Holl Admin::createHoll(Film F, CTime starttime, CTime finishtime, int countofsits, Holl_state s)
{
	Holl h(F, starttime, finishtime, countofsits, s);
	return h;
}

void Admin::redactHole(Holl& h, int i)
{

}

void Admin::deleteHoll(Holl& h)
{
	h.~Holl();
}

