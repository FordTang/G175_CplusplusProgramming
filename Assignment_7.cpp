#include <iostream>
using namespace std;
void sort (float *a, float *b, float *c);
int main()
{
	float a=0, b=0, c=0;
	cout << "This program will sort three numbers from largest to smallest" << endl;
	cout << "Please enter the first number:  ";
	cin >> a;
	cout << "Please enter the second number:  ";
	cin >> b;
	cout << "Please enter the third number:  ";
	cin >> c;
	sort (&a, &b, &c);
	cout << "Sorting Done!" << endl;
	cout << a << " > " << b << " > " << c << endl;
	return 0;
}

void sort (float *a, float *b, float *c)
{
	float x = 0;
	if (*b > *a)
	{
		x = *a;
		*a = *b;
		*b = x;
	}
	if (*c > *b)
	{
		x = *b;
		*b = *c;
		*c = x;
		if (*b > *a)
		{
			x = *a;
			*a = *b;
			*b = x;
		}
	}
}
