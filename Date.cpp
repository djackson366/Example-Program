// Program name: Date Class Exceptions
// Author: Daniel Jackson
// Date last updated: 4/21/2018
// Purpose: Validate user input for a date class

#include <iostream>
#include "Date.h"
#include <stdexcept>




void Date::setMonth(int month) // sets the month
{
	try
	{
		validateMonth(month); // validates the month
		this->month = month;
	}
	catch (std::invalid_argument &e) // catches the exception
	{
		throw; // throws it up the stack
	}
}

void Date::setDay(int day) // sets the day
{
	try
	{
		validateDay(day); // validates the day
		this->day = day;
	}
	catch (std::invalid_argument &e) // catches an exception
	{
		throw; // throws the exception further up the stack
	}
}

void Date::setYear(int year) // sets the year
{
	try
	{
		validateYear(year); // validates the year
		this->year = year;
	}
	catch (std::invalid_argument &e) // catches the exception
	{
		throw; // throws the exception further up the stack
	}
}

void Date::validateMonth(int month) // validates the month
{
	if (month < 1 || month > 12) // if the month is not a valid month (between 1 and 12)
		throw std::invalid_argument("The month must be a valid month (1-12)"); // throw an invalid argument exception
}

void Date::validateDay(int day) // validates the day
{
	if (day < 1 || day > daysInMonth[month - 1]) // if the number of days are not valid (between 1 and the number of days in that month)
		throw std::invalid_argument("The day must be in the appropriate range for that month(do not worry about leap years)"); // throws an invalid argument exception
}

void Date::validateYear(int year) // validates the year
{
	if (year < 1950 || year > 2020) // if the year is not a valid year (less than 1950 or greater than 2020)
		throw std::invalid_argument("The year must be between 1950 and 2020"); // throws an invalid argument exception
}

Date::Date(int month, int day, int year) // parameterized Date constructor
{
	try
	{
		// sets the months
		setMonth(month);
		setDay(day);
		setYear(year);
	}
	catch (std::invalid_argument &e) // catches any errors
	{
		throw; // throws them up the stack
	}
	catch (...) // catch all
	{
		std::cerr << "Unknown Error";
		std::cin.get();
		std::cin.ignore();
	}
}

std::string Date::toString() // returns a string, month, day year
{
	std::string str_month = "";
	// converts month into a string
	switch (month)
	{
	case 1: str_month = "January";
		break;
	case 2: str_month = "February";
		break;
	case 3: str_month = "March";
		break;
	case 4: str_month = "April";
		break;
	case 5: str_month = "May";
		break;
	case 6: str_month = "June";
		break;
	case 7: str_month = "July";
		break;
	case 8: str_month = "August";
		break;
	case 9: str_month = "September";
		break;
	case 10: str_month = "October";
		break;
	case 11: str_month = "November";
		break;
	case 12: str_month = "December";
		break;
	}
	
	return str_month + " " + std::to_string(day) + ", " + std::to_string(year); // returns the string
}