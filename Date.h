// Program name: Date Class Exceptions
// Author: Daniel Jackson
// Date last updated: 4/21/2018
// Purpose: Validate user input for a date class

#pragma once
#include <string>

class Date
{
	// array for the days in each month
	int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int month; // stores the month
	int day; // stores the day
	int year; // stores the year

	void validateMonth(int month); // validates the month
	void validateDay(int day); // validates the day
	void validateYear(int year); // validates the year

	// mutator methods
	void setMonth(int month); // sets the month
	void setDay(int day); // sets the day
	void setYear(int year); // sets the year
public:
	Date(int month, int day, int year); // three parameter Date constructor
	std::string toString(); // returns a string with the month, day and year
};

