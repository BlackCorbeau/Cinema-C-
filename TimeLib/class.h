#pragma once

class CTime
{
private:
	int second;
	int minute;
	int hour;
public:
	CTime();
	CTime(int _second, int _minute, int _hour);
	~CTime();
	void initialize_seconds(int _second);
	void initialize_minutes(int _minutes);
	void initialize_hours(int _hours);
	int get_seconds();
	int get_minutes();
	int get_hours();
	void print_parametrs();
	CTime operator+(const CTime& T1);

	CTime& operator=(const CTime& T1)
	{
		hour = T1.hour;
		minute = T1.minute;
		second = T1.second;
		return *this;
	}

    friend std::istream& operator>>(std::istream& input, CTime& obj) {
		char c = ' ';
		std::cin >> obj.hour >> c >> obj.minute >> c >> obj.second;
        return input;
    }

    friend std::ostream& operator<<(std::ostream& output, CTime& obj) {
		std::cout << obj.hour << ':' << obj.minute << ':' << obj.second;
        return output;
    }
};

