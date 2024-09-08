#pragma once
#include<iostream>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

enum class Months {
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};

class Date {
	unsigned int year, month, day;
public:
	Date();
	Date(int y, int m, int d);
	Date(string date);
	void Set(string date);
	unsigned int GetYear();
	unsigned int GetMonth();
	unsigned int GetDay();
	void dateInDays(unsigned int daysToBeRealized, unsigned int year, unsigned int month, unsigned int day);
	void DateInDaysBack(unsigned int daysToBeRealized, unsigned int year, unsigned int month, unsigned int day);
	void ConvertDateToDays(unsigned int year, unsigned int month, unsigned int day, Date date, int& days);
	bool leapYear(unsigned int year);
	bool DateComparison(Date date, unsigned int year, unsigned int month, unsigned int day, bool& flag);
	string toString();
};
void Check(char& choice);
void operations(Date date);
void start();
