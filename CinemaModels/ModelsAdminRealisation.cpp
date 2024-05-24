#include "Models.h"
#include <iostream>

Admin::Admin(int id, CString password)
{
	this->id = id;
	this->Password = password;
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

void Admin::redactFilm(Film& f, int i)
{
	
}

void Admin::deleteFilm(Film& f)
{
	f.~Film();
}