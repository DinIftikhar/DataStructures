//Stack Implentation Using Array
#include <iostream>
using namespace std;

class StackOperation
{
private:
	int top;
public:
	int array[100];
	StackOperation();
	~StackOperation() {};
	void peek();
	void push();
	void pop();
};
StackOperation::StackOperation()
{
	top = -1;
}
void StackOperation:: peek()
{
	if (top < 0)
		cout << "\nStack is empty\n";
	else
		cout << "\nThe top element is " << array[top] << endl;	
}
void StackOperation::push()
{
	if (top > 99)
	{
		cout << "\nStack Overflowed\n";
		return;
	}
	int key = 0;
	cout << "\nEnter the number you want to insert in the stack.\n";
	cin >> key;
	top++;
	array[top] = key;
	
}
void StackOperation::pop()
{
	if (top == -1)
	{
		cout << "\nStack Underflowed\n";
		return;
	}
	cout << array[top] << " has been pooped out from the stack.\n";
	top--;

}
int main()
{
	StackOperation S1;
	int num = 0;;
	cout << "Welcome to the Stack Operations.\n\n";
	while (num != 4)
	{
		cout << "\n\nWhat operation do you want to perform?\n";
		cout << "Press 1 for Push. 2 for pop. 3 for peek. 4 for exit\n\n";
		cin >> num;
		switch (num)
		{
		case 1:
			S1.push();
			break;
		case 2:
			S1.pop();
			break;
		case 3:
			S1.peek();
		default:
			break;
		}
	}

	return 0;
}