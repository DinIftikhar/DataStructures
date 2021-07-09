//PostFix Evaluation Using Stack
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
	int peek();
	void push(float);
	void pop();
};
StackOperation::StackOperation()
{
	top = -1;
}
int StackOperation::peek()
{
	if (top < 0)
		cout << "\nStack is empty\n";
	else
		return array[top];
}
void StackOperation::push(float key)
{
	if (top > 99)
	{
		cout << "\nStack Overflowed\n";
		return;
	}
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
	top--;

}
float scanNum(char ch) //function to convert char into float
{
	int value;
	value = ch;
	return float(value - '0'); //return float from character
}
int isOperator(char ch) //function to check whether given char is an operator
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
		return 1; // yes operator
	return -1; // not operator
}
int isOperand(char ch) //function to check whether given char is operand
{
	if (ch >= '0' && ch <= '9')
		return 1; //yes its a decimalnumber
	return -1; //not a decimal number
}
float operations(int a, int b, char op)
{
	if (op == '+')
		return b + a;
	else if (op == '-')
		return b - a;
	else if (op == '*')
		return b * a;
	else if (op == '/')
		return b / a;
	else if (op == '^')
		return b ^ a;
	else
		return INT_MIN;
}

int main()
{
	StackOperation stk;
	int num = 0;
	string postfix = "53+62/*35*+";
	cout << "Welcome to the Stack Operations.\n\n";
	int a, b;
	string::iterator it;
	for (it = postfix.begin(); it != postfix.end(); it++) {
		//read elements and perform postfix evaluation
		if (isOperator(*it) != -1) {
			a = stk.peek();
			stk.pop();
			b = stk.peek();
			stk.pop();
			stk.push(operations(a, b, *it));
		}
		else if (isOperand(*it) > 0) {
			stk.push(scanNum(*it));
		}
	}
	cout << "\nThe answer is: " << stk.peek();
	

	return 0;
}