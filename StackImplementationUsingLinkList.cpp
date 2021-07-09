//Stack Implementation using LinkList
#include <iostream>
using namespace std;

struct node
{
	int info;
	node* next;
};
class StackOperation
{
private:
	node* top;
	node* temp;
	int limit;
	int count;
public:
	StackOperation();
	~StackOperation() {};
	void setlimit();
	void push();
	void pop();

};
StackOperation::StackOperation()
{
	top = NULL;
	temp = NULL;
	limit = 0;
	count = 0;
}
void StackOperation::setlimit()
{
	cout << "\nPlease set your stack limit first.\n";
	cin >> limit;
}
void StackOperation::push()
{
	if (limit == count)
	{
		cout << "\n\nStack full. You cant push more entities to the stack\n";
		return;
	}
	
	if (top == NULL)
	{
		top = new node;
		cout << "\nPlease enter number you want to push into the stack.";
		cin >> top->info;
		top->next = NULL;
		count++;
		return;
	}
	temp = new node;
	cout << "\nPlease enter number you want to push into the stack.";
	cin >> temp->info;
	temp->next = top;
	top = temp;
	count++;
}
void StackOperation::pop()
{
	if (top == NULL)
	{
		cout << "\n\nStack Underflowed.There is nothing to delete.\n\n";
		return;
	}
	top = top->next;
	cout << "\nNumber: " << temp->info << " has been popped out from the stack.\n";
	delete temp;
	temp = top;
	count--;

}
int main()
{
	StackOperation S1;
	int num = 0;;
	cout << "Welcome to the Stack Operations.\n\n";
	S1.setlimit();
	while (num !=3)
	{
		cout << "\n\nWhat operation do you want to perform?\n";
		cout << "Press 1 for Push. 2 for pop. 3 for exit\n\n";
		cin >> num;
		switch (num)
		{
		case 1:
			S1.push();
			break;
		case 2:
			S1.pop();
			break;
		default:
			break;
		}
	}

	return 0;
}