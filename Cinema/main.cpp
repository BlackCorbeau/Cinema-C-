#include <iostream>
#include "..\CinemaModels\Models.h"

int main()
{
	CTime Time(12, 15, 10);
	Film newfilm;
	CTime c = newfilm.getTimeOfGoes();
	std::cout << c;
	newfilm.setTimeOfGoes(Time);
	c = newfilm.getTimeOfGoes();
	std::cout << c;
	return 0;
}