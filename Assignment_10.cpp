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


class number
{
protected:
	//int count;
	//int data[100];
	int input;
	stack st;
public:
	number () {}
	~number () {}
	virtual void print_it() = 0;
};

class binary : public number
{
public:
	binary (int);
	~binary (){};
	void print_it();
};

class hexadecimal : public number
{
private:
	int intBuffer;
public:
	hexadecimal (int);
	~hexadecimal (){};
	void print_it();
};

class octal : public number
{

public:
	octal (int);
	~octal (){};
	void print_it();
};

binary::binary(int intInput)
{
	input = intInput;
	//count = 0;
	while (input != 0)
	{
		st.push(input % 2);
		//++count;
		input /= 2;
	}
}

void binary::print_it()
{
	cout << "Binary: \t";
	while (st.getCount() > 0)
	{
		//--count;
		cout << st.pop() << " ";
	}
	cout << endl;
}

hexadecimal::hexadecimal(int intInput)
{
	input = intInput;
	//count = 0;
	while (input != 0)
	{
		st.push(input % 16);
		//++count;
		input /= 16;
	}
}

void hexadecimal::print_it()
{
	cout << "Hexadecimal:\t";
	while (st.getCount() > 0)
	{
		//--count;
		intBuffer = st.pop();
		if (intBuffer > 9)
			cout << char('A' + intBuffer - 10) << " ";
		else
			cout << intBuffer << " ";
	}
	cout << endl;
}

octal::octal(int intInput)
{
	input = intInput;
	//count = 0;
	while (input != 0)
	{
		st.push(input % 8);
		//++count;
		input /= 8;
	}
}

void octal::print_it()
{
	cout << "Octal:  \t";
	while (st.getCount() > 0)
	{
		//--count;
		cout << st.pop() << " ";
	}
	cout << endl;
}

int main ()
{
	int intInput = 0;
	cout << "Please enter a number to be converted into Binary, Hexadecimal, and Octal:  ";
	cin >> intInput;
	number *Example;
	Example = new binary(intInput);
	Example->print_it();
	delete Example;
	Example = new hexadecimal(intInput);
	Example->print_it();
	delete Example;
	Example = new octal(intInput);
	Example->print_it();
	delete Example;
	return 0;
}
