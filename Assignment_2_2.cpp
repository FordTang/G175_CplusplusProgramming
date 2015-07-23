#include <iostream>
#include <string>
using namespace std;
int main()
{
	string firstname, lastname;
	cout << "What is your first name?" << endl;
	getline(cin, firstname);
	cout << "What is your last name?" << endl;
	getline(cin, lastname);
	cout << "Hello " << firstname << " " << lastname << "." << endl;
	return 0;
}