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
	int evenTotal = 0, oddTotal = 0, evenCount = 0, oddCount = 0, evenStack = 0, oddStack = 0, input = 0;
	float evenAvg = 0, oddAvg = 0;
	stack odd;
	stack even;
	cout << "This program will find the averages of the odd and even values entered." << endl;
	cout << "Please enter a whole number, enter 0 to stop:  ";
	cin >> input;
	while (input != 0)
	{
		if (input%2==0)
		{
			evenTotal += input;
			even.push(input);
		}
		else
		{
			oddTotal += input;
			odd.push(input);
		}
		cout << "Please enter a whole number, enter 0 to stop:  ";
		cin >> input;
	}
	cout << endl;
	if (even.getCount() == 0)
	{
		cout << "No Even numbers entered" << endl;
	}
	else
	{
		evenStack = even.getCount();
		cout << "List of Even numbers:  ";
		//if (evenStack > 1)
		//{
			while (even.getCount()) //evenCount < evenStack)
				{
					cout << even.pop() << " ";
					evenCount++;
				}
			cout << endl;
		//}
		//else
		//{
		//	cout << even.pop() << endl;
		//}
		cout << "Even numbers Total:  ";
		cout << evenTotal << endl;
		cout << "Even numbers Average:  ";
		evenAvg = (float)evenTotal/evenStack;
		cout << evenAvg << endl;
	}
	cout << endl;
	if (odd.getCount() == 0)
	{
		cout << "No Odd numbers entered"  << endl;
	}
	else
	{
		oddStack = odd.getCount();
		cout << "List of Odd numbers:  ";
		if (oddStack > 1)
		{
			while (oddCount < oddStack)
				{
					cout << odd.pop() << " ";
					oddCount++;
				}
			cout << endl;
		}
		else
		{
			cout << odd.pop() << endl;
		}
		cout << "Odd numbers Total:  ";
		cout << oddTotal << endl;
		cout << "Odd numbers Average:  ";
		oddAvg = (float)oddTotal/oddStack;
		cout << oddAvg << endl;
	}
	cout << endl;
	return 0;
}