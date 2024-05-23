#pragma once

class CDate
{
private:
	int day;
	int month;
	int year;
public:
	CDate();
	CDate(int _day, int _month, int _year);
	~CDate();
	void initialize_day(int _day);
	void initialize_month(int _month);
	void initialize_year(int _year);
	int get_day();
	int get_month();
	int get_year();
	void print_parametrs();

	friend std::istream& operator>>(std::istream& input, CDate& obj) {
		char c = ' ';
		std::cin >> obj.day >> c >> obj.month >> c >> obj.year;
		return input;
	}

	friend std::ostream& operator<<(std::ostream& output, CDate& obj) {
		std::cout << obj.day << ':' << obj.month << ':' << obj.year;
		return output;
	}
};