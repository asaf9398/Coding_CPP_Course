#pragma once
#include <iostream>
enum month{January=1,February,March,April,May,June,July,August,September,October,November,December};
using namespace std;
const int DEFAULT_DAY=1;
const int DEFAULT_MONTH=1;
const int DEFAULT_YEAR=2000;
class Date
{
	int day, month, year;
	
public:
	//Deafualt cto'r
	Date()
	{
		day = DEFAULT_DAY;
		month = DEFAULT_MONTH;
		year = DEFAULT_YEAR;
	}
	
	//Full cto'r
	Date(int day, int month, int year)
	{
		Date();
		setDay(day);
		setMonth(month);
		setYear(year);
	}
	
	//Getters & Setters
	void setDay(int day)
	{
		if (day >= 1 && day <= 31)
		{
			this->day = day;
		}
		else
		{
			this->day = DEFAULT_DAY;
			cout << "The input is unvalid, the day will have default value and will be " << DEFAULT_DAY << endl;
		}
	}
	void setMonth(int month)
	{
		if (month >= 1 && month <= 12)
		{
			this->month = month;
		}
		else
		{
			this->month = DEFAULT_MONTH;
			cout << "The input is unvalid, the month will have default value and will be " << DEFAULT_MONTH << endl;
		}
	}
	void setYear(int year)
	{
		if (year >= 1900 && year <= 2022)
		{
			this->year = year;
		}
		else
		{
			this->year = DEFAULT_YEAR;
			cout << "The input is unvalid, the year will have default value and will be " << DEFAULT_YEAR << endl;
		}
	}
	int getDay()
	{
		return day;
	}
	int getMonth()
	{
		return month;
	}
	int getYear()
	{
		return year;
	}
};

