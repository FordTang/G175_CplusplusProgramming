#include <iostream>
using namespace std;
int main()
{
	int number = 0;
	cout << "Please Enter a Number: ";
	cin >> number;
	while (number != 0)
	{
		cout << number % 10 << " ";
		number /= 10;
	}
	cout << endl;
	return 0;
}