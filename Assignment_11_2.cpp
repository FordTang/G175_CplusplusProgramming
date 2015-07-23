#include <iostream>
using namespace std;

class Vector
{
private:
	double x;				// horizontal value
	double y;				// vertical value
	double z;
public:
	Vector(void);
	Vector(double h, double v, double z);		// set x, y, z values
	~Vector(void);
	void show_vector(void) const ;	// show rectangular values
	Vector operator+(const Vector &b) const;
	Vector operator-(const Vector &b) const;
	Vector operator-() const;
	Vector operator*(double n) const;

friend Vector operator*(double n, const Vector &a);  //non member friend function. See explanations in text below this example.
};

// public methods
Vector::Vector(void)	// default constructor
{
	x = y = z = 0.0;
}

// constructs a Vector from rectangular coordinates
Vector::Vector(double h, double v, double o)
{
	x = h;
	y = v;
	z = o;
}
Vector::~Vector(void)	// destructor
{
}
void Vector::show_vector(void) const
{
	cout << "(" << x << ", " << y << ", " << z << ")\n";
}
Vector Vector::operator+(const Vector & b) const // binary +
{
	double sx, sy, sz;
	sx = x + b.x;
	sy = y + b.y;
	sz = z + b.z;
	Vector sum = Vector(sx, sy, sz);
	return sum;
}
Vector Vector::operator-(const Vector & b) const // binary -
{
	double sx, sy, sz;
	sx = x - b.x;
	sy = y - b.y;
	sz = z - b.z;
	Vector diff = Vector(sx, sy, sz);
	return diff;
}
Vector Vector::operator-() const // unary -
{
	double nx, ny, nz;
	nx = -x;
	ny = -y;
	nz = -z;
	Vector neg = Vector(nx, ny, nz);
	return neg;
}
Vector Vector::operator*(double n) const // binary *
{
	double mx, my, mz;
	mx = n * x;
	my = n * y;
	mz = n * z;
	Vector mult = Vector(mx, my, mz);
	return mult;
}
//// Non member function:
Vector operator*(double n, const Vector &a) // overloaded function. See explanations in text below this example.
{
	Vector mult = Vector(n*a.x, n*a.y, n*a.z);
	return mult;
}

int main(void)
{
	Vector first(1, 2, 3);
	Vector second(4, 5, 6);
	Vector result;
	
	cout << "First: ";
	first.show_vector();		// display first
	cout << "Second: ";
	second.show_vector();		// display second
	cout << "Result = first + second: ";
	result = first + second;	// adding objects!
	result.show_vector();
	cout << "Negate result: ";
	Vector negate = - result;		// negate signs
	negate.show_vector();
	cout << "Result - second: ";
	result = result - second;		// subtracting objects
	result.show_vector();
	cout << "Doubled result: Vector * 2.0 ";
	Vector twotimes = result * 2.0;	// member function
	twotimes.show_vector();
	cout << "Doubled result: 2.0 * Vector ";
	Vector timestwo = 2.0 * result;	// member function
	twotimes.show_vector();

	result = 0.5 * result;		// overloaded or friend function needed. See explanations in text below this example.
	cout << "Halved result: ";
	result.show_vector();
   
	return 0;
}