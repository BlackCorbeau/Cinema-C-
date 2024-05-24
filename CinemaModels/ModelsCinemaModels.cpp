#include "Models.h"

Cinema::Cinema()
{
	CString adr;
	adress = adr;
	Holl h;
	hols = h;
}

Cinema::Cinema(CString adress, Holl holls)
{
	this->adress = adress;
	this->hols = holls;
}

Cinema::~Cinema()
{
	adress.~CString();
	hols.~TArchive();
}

CString Cinema::getadress()
{
	return adress;
}

Holls Cinema::getHolls()
{
	return hols;
}

void Cinema::setAdress(CString adress)
{
	this->adress = adress;
}

void Cinema::setHolls(Holls holls)
{
	this->hols = holls;
}