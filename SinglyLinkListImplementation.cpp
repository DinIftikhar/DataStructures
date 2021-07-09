//Singly LinkList Implementation
#include <iostream>
using namespace std;
struct Node
{
	int info;
	Node* next;
}; //END OF STRUCTURE DEFINITION
class LinkList
{
public:
	LinkList();
	~LinkList();
	void add();
	void print();
	void search();
	void remove();
private:
	Node* head;
	Node* temp;
	Node* temp1;
	int key;
}; //END OF CLASS DEFINITION

LinkList::LinkList() //CONSTRUCTOR
{
	//INITIALIZATION OF POINTERS
	head = NULL;
	temp = NULL;
	temp1 = NULL;
	key = 0;
}

LinkList::~LinkList()
{
	//DESTRUCTOR DEFINITION
}
void LinkList::add() //FUNCTION CALL TO ADD A NUMBER TO THE LIST
{
	cout << "\nWelcome to the Insert Operation!!!\n";
	if (head == NULL)
	{
		head = new Node;
		cout << "Enter the first element of the list: ";
		cin >> head->info;
		cout << endl;
		head->next = NULL;
	}
	char letter = '0';
	while (letter != 'n')
	{
		int count = 0;
		char x = '0';
		cout << "\nDo you want to add another number? \n";
		cout << "Enter 'y' for Yes and 'n' for No. ";
		cin >> letter;
		if (letter == 'y')
		{
			temp = head;
			cout << "\nEnter the key after which you want to add: ";
			cin >> key;
			while (temp != NULL)
			{
				if (temp->info == key)
				{
					if (count == 0)
					{
						temp1 = new Node;
						cout << "\nEnter the number you want to add: ";
						cin >> temp1->info;
						temp1->next = temp->next;
						temp->next = temp1;
					}
					else 
					{
						cout << "\nAnother occurence of the Key have been found!!\n";
						cout << "Enter 'y' if you still want to add or any key to exit.";
						cin >> x;
						if (x == 'y')
						{
							temp1 = new Node;
							cout << "\nEnter the number you want to add: ";
							cin >> temp1->info;
							temp1->next = temp->next;
							temp->next = temp1;
						} 
					}
					count++;

				}
				temp = temp->next;
			}
			if (count == 0)
			{
				cout << "\nKey not found!!\n";
			}
			
		}
	}
}
void LinkList::print() //FUNCTION DEFINITION TO PRINT THE ELEMENTS OF THE LIST
{
	cout << "\nWelcome to the Print Operation!!!\n";
	if (head == NULL)
	{
		cout << "\nYour Link List is empty. \n";
		return;
	}
	temp = head;
	cout << "\nElement of link list = {";
	while (temp != NULL)
	{
		cout << temp->info << " ,";
		temp = temp->next;
	}
	cout << " }\n";
}
void LinkList::search() //FUNCTION DEFINITION TO SEARCH THE GIVEN ELEMENT IN THE LIST
{
	cout << "\nWelcome to the Search Operation!!!\n";
	if (head == NULL)
	{
		cout << "\nLink List is empty.\n";
		return;
	}
	int count1 = 0;
	temp = head;
	cout << "\nEnter the key you want to search: ";
	cin >> key;
	while (temp != NULL)
	{
		if (temp->info == key)
		{
			count1++;
		}
		temp = temp->next;
	}
	if (count1 == 0)
		cout << "\nKey Not found!!!\n";
	else
		cout << "\n" << count1 << " occurrence/s of key= '" << key << "' found in the list.\n";
}
void LinkList::remove() //FUNCTION DEFINITION TO REMOVE THE ELEMENT FROM THE LIST
{
	cout << "\nWelcome to the Deletion Operation!!!\n";
	if (head == NULL)
	{
		cout << "\nThere is nothing to delete from the list.\n";
		return;
	}
	if (head->next == NULL)
	{
		cout << "\nThis is the only element left in the Link List.\n";
		cout << "Key: " << head->info << " has been deleted from the list.\n";
		delete head;
		head = temp = temp1 = NULL;
		return;
	}
	int count2 = 0;
	char letter1 = '\0';
	char x = '\0';
	temp = head;
	cout << "\nEnter the number you want to delete: ";
	cin >> key;
	if (head->info == key)
	{
		temp1 = head;
		head = head->next;
		delete temp1;
		temp = head;
		cout << "\nThis is the first number of the list.\n";
		cout << "\nNumber: '" << key << "' has been deleted from the list.\n";
		count2++;
	}
	while (temp != NULL)
	{
		if (temp->next != NULL)
		{
			if (temp->next->info == key)
			{
				if (count2 == 0)
				{
					temp1 = temp->next;
					temp->next = temp1->next;
					delete temp1;
					cout << "\nNumber: '" << key << "' has been deleted from the list.\n";
				}
				else
				{
					cout << "\nAnother occurence of the number has been found.\n";
					cout << "\n Do you want to delete it again? 'y' for Yes and 'n' for No.\n";
					cin >> x;
					if (x == 'y')
					{
						temp1 = temp->next;
						temp->next = temp1->next;
						delete temp1;
						cout << "\nNumber: '" << key << "' has been deleted from the list again.\n";
					}
				}
				count2++;
			}
		}
			temp = temp->next;
	}
	if (count2 == 0)
		cout << "\nKey not found!!!\n";
}
void firstcall(LinkList);
int main()
{
	cout << "Welcome to link list implementation!!! \n";
	LinkList obj1;
	firstcall(obj1);
	return 0;
}
void firstcall(LinkList obj2)
{
	char c = '0';
	int num1;
	while (c != 'n')
	{
		cout << "\nDo you want to perform list operation\s?\n";
		cout << "Enter 'y' for Yes and 'n' for No: ";
		cin >> c;
		if (c == 'y')
		{
			cout << "\nWhat operation do you want to perform?\n";
			cout << "Enter:\n'1' for Insertion of elements in the list.\n";
			cout << "'2' for printing of elements of the list.\n";
			cout << "'3' for searching the elements in the list.\n";
			cout << "'4' for deleting the elements in the list.\n";
			cin >> num1;
			switch (num1)
			{
			case 1:
				obj2.add();
				break;
			case 2:
				obj2.print();
				break;
			case 3:
				obj2.search();
				break;
			case 4:
				obj2.remove();
				break;
			default:
				cout << "\nRange out of bound!!\n";
				break;
			}
		}

	}
}
