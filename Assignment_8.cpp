#include <iostream>
using namespace std;
class rectangle
{
	float length, width;

public:
	rectangle (){ cout << "in const...\n"; length = width = 1; }
	~rectangle () {cout << "in destructor...\n"; }
	void set_length();
	void set_width();
	float get_length() const {return length;}
	float get_width() const {return width;}
	float perimeter() const;
	float area () const;
	void draw () const;
};
void rectangle::set_length()
{
	float enteredLength;
	cout << "Enter Length between 0 and 20:  ";
	cin >> enteredLength;
	while (enteredLength <= 0 || enteredLength > 20)
	{
		cout << "Invalid input, please enter a number larger than 0 but less than 20:  ";
		cin >> enteredLength;
	}
	length = enteredLength;
}
void rectangle::set_width()
{
	float enteredWidth;
	cout << "Enter Width between 0 and 20:  ";
	cin >> enteredWidth;
	while (enteredWidth <= 0 || enteredWidth > 20)
	{
		cout << "Invalid input, please enter a number larger than 0 but less than 20:  ";
		cin >> enteredWidth;
	}
	width = enteredWidth;
}
float rectangle::perimeter() const
{
	float perimeter = (2*length) + (2*width);
	return perimeter;
}
float rectangle::area() const
{
	float area = length * width;
	return area;
}
void rectangle::draw() const
{
	int counterl = 0, counterw = 0, l = (int)length, w = (int)width;
	while (counterl < l)
	{
		counterl++;
		while (counterw < w)
		{
			counterw++;
			cout << "X";
		}
		counterw = 0;
		cout << endl;
	}
}
int main()
{
	rectangle rectangle1;
	rectangle1.draw();
	rectangle1.set_length();
	rectangle1.set_width();
	cout << "Perimeter:  " << rectangle1.perimeter() << endl;
	cout << "Area:  " << rectangle1.area() << endl;
	rectangle1.draw();
	cout << endl;
	return 0;
}