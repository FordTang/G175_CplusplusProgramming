#include <iostream>
#include <string>
using namespace std;
int main()
{
	string MonthName [12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	int MonthDays [12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int Day=0, Month=0, Elapse=0;
	cout << "This program calculates the number of days from January 1st, 2011 to a date in the year 2011 that you specify." << endl;
	cout << endl;
	cout << "Please enter a month (1-12):  ";
	cin >> Month;
	while (Month > 12 || Month < 1)
	{
		cout << "Month value is invalid, please enter 1-12:  ";
		cin >> Month;
	}
	Month--;
	cout << endl;
	cout << "Please enter a day of the month:  ";
	cin >> Day;
	while (Day < 1 || Day > MonthDays[Month])
	{
		cout << "Day value is invalid, please enter 1-" << MonthDays[Month] << " for the month of " << MonthName[Month] << ":  ";
		cin >> Day;
	}
	cout << endl;

	int counter = 0;
	while (counter < Month)
	{
		Elapse += MonthDays[counter];
		counter++;
	}
	Elapse += Day;
	cout << Elapse << " days elapse between January 1, 2011 and " << MonthName[Month] << " " << Day << ", 2011." << endl << endl;
	return 0;
}
