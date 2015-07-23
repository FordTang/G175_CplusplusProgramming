#include <iostream>
using namespace std;

const int STACK_SIZE = 100;

class stack
{
	private:
		int count;			// number of items in the stack
		int data[STACK_SIZE];
	public:
		stack();
		~stack();
		void push(const int item);	// push an item on the stack
		int pop();			// pop item off the stack
		int getCount() const;			// return count
};

stack::stack()	// constructor
{
	count = 0;	// zero the stack
}

stack::~stack() {}	// default destructor

void stack::push(const int item)
{
	if (count < STACK_SIZE)
	{
		data[count] = item;
		++count;
	}
	else cout << "Overflow!\n";
}

int stack::pop()
{
	if (count >0)
	{
		--count;
		return (data[count]);
	}
	else
	{
		cout << "Underflow!\n";
		return 0;
	}
}

int stack::getCount() const
{
	return count;
}

int main ()
{
	unsigned short int menu = 0;
	int number = 0, intBuffer = 0;

	stack store;

	cout << "This program will convert a number into Binary, Hexadecimal or Octal." << endl << "Please enter a number:  ";
	cin >> number;
	cout << endl;
	
	cout << "Convert the number from Decimal into:  " << endl;
	cout << "1 - Binary" << endl;
	cout << "2 - Hexadecimal" << endl;
	cout << "3 - Octal" << endl;
	cin >> menu;
	switch (menu)
	{
	case 1:
		while (number != 0)
		{
		store.push(number % 2);
		number /= 2;
		}
		cout << endl << "The number converted to Binary is:  ";
		while (store.getCount() != 0)
		{
		cout << store.pop() << " ";
		}
		cout << endl;
		break;
	case 2:
		while (number != 0)
		{
		store.push(number % 16);
		number /= 16;
		}
		cout << endl << "The number converted to Hexadecimal is:  ";
		while (store.getCount() != 0)
		{
			intBuffer = store.pop();
			if (intBuffer > 9)
				cout << char('A' + intBuffer - 10);
			else
				cout << intBuffer;
		}
		cout << endl;
		break;
		break;
	case 3:
		while (number != 0)
		{
		store.push(number % 8);
		number /= 8;
		}
		cout << endl << "The number converted to Octal is:  ";
		while (store.getCount() != 0)
		{
		cout << store.pop() << " ";
		}
		cout << endl;
		break;
		break;
	default:
		cout << endl << "No conversion, the number stays as " << number << endl;
		break;
	}
	cout << endl;

	return 0;
}