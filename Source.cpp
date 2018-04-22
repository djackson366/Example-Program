// Program name: Date Class Exceptions
// Author: Daniel Jackson
// Date last updated: 4/21/2018
// Purpose: Validate user input for a date class

#include "Date.h"
#include <iostream>
#include <limits>

using namespace std;
int main()
{
	// month day year
	int month = 0;
	int day = 0;
	int year = 0;
	
	// gets the input from the user
	bool valid = false;
	do
	{
		cin.exceptions(ios_base::failbit); // adds an exception to check for
		try {
			cout << "Enter in the month: ";
			cin >> month;
			cout << "Enter in the day: ";
			cin >> day;
			cout << "Enter in the year: ";
			cin >> year;
			valid = true;
		}
		catch (const ios_base::failure &failure) { // catches that exception
			cerr << std::endl << failure.what() << endl; // prints the exception
			cin.clear(); // clears failbit
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // resets the stream
		}
	} while (!valid);
	
	try
	{
		Date d(month, day, year); // creates Date object
		cout << d.toString(); // prints the contents of that object
	}
	catch (std::invalid_argument &e) // catches the arguments pushed up the stack
	{
		std::cerr << e.what() << std::endl; // prints the error
		std::cout << "Press enter to end program."; // ends the program in response
	}

	cin.get();
	cin.ignore();
	return 0;
}