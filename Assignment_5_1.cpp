#include <iostream>
using namespace std;
int main()
{
	int number=0, counter=1,total=0;
	cout << "Please Enter a Number: ";
	cin >> number;
	cout << "1";
	while (counter <= number)
	{
		cout << " + " << counter << "*" << counter;
		total += counter * counter;
		counter++;
	}
	cout << " = " << total << endl;
	return 0;
}