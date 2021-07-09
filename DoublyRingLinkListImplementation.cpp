//Doubly Ring LinkList Implementation
#include <iostream>
using namespace std;
struct node
{
	int info;
	node* next;
	node* previous;
};
class DoublyRingLinkList
{
public:
	DoublyRingLinkList();
	~DoublyRingLinkList();
	void add();
	void print();
	void search();
	void remove();
private:
	node* head;
	node* temp;
	node* temp1;
	int key;
};

DoublyRingLinkList::DoublyRingLinkList()
{
	head = NULL;
	temp = NULL;
	temp1 = NULL;
	key = 0;
}

DoublyRingLinkList::~DoublyRingLinkList()
{
}
void DoublyRingLinkList::add()
{
	cout << "\nWelcome to the Insert Operation!!!\n";
	if (head == NULL)
	{
		head = new node;
		cout << "Enter the first element of the list: ";
		cin >> head->info;
		cout << endl;
		head->next = head->previous = head;
	}
	char letter = '0';
	while (letter != 'n')
	{
		cout << "\nDo you want to add another number? ";
		cout << "\nEnter 'y' for yes and 'n' for exit. ";
		cin >> letter;
		if (letter == 'y')
		{
			char x = '0';
			char z = '0';
			int count = 0;
			temp = head;
			cout << "\nEnter the key after which you want to add: ";
			cin >> key;
			while (temp->next != head)
			{
				if (temp->info == key)
				{
					if (count == 0)
					{
						temp1 = new node;
						cout << "\nEnter the number you want to add: ";
						cin >> temp1->info;
						cout << endl;
						temp1->next = temp->next;
						temp->next = temp1;
						temp1->previous = temp;
						temp1->next->previous = temp1;
					}
					else
					{
						cout << "\nAnother occurrence of the key have been found. ";
						cout << "\nDo you still want to add? Enter y for yes";
						cin >> x;
						if (x == 'y')
						{
							temp1 = new node;
							cout << "\nEnter the number you want to add: ";
							cin >> temp1->info;
							cout << endl;
							temp1->next = temp->next;
							temp->next = temp1;
							temp1->previous = temp;
							temp1->next->previous = temp1;
						}
					}
					count++;
				}
				temp = temp->next;
			}
			if (temp->info == key)
			{
				if (count == 0)
				{
					temp1 = new node;
					cout << "\nEnter the number you want to add: ";
					cin >> temp1->info;
					cout << endl;
					temp1->next = temp->next;
					temp->next = temp1;
					temp1->previous = temp;
					temp1->next->previous = temp1;
				}
				else
				{
					cout << "\nAnother occurrence of the key have been found. ";
					cout << "\nDo you still want to add? Enter y for yes";
					cin >> z;
					if (z == 'y')
					{
						temp1 = new node;
						cout << "\nEnter the number you want to add: ";
						cin >> temp1->info;
						cout << endl;
						temp1->next = temp->next;
						temp->next = temp1;
						temp1->previous = temp;
						temp1->next->previous = temp1;
					}
				}
				count++;
			}
			if (count == 0)
			{
				cout << "\nKey not found!!\n";
			}
		}
	}
}
void DoublyRingLinkList::print()
{
	cout << "\nWelcome to the Print Operation!!!\n";
	if (head == NULL)
	{
		cout << "\nYour Link List is empty. \n";
		return;
	}
	temp = head;
	cout << "\nElement of link list = {";
	while (temp->next != head)
	{
		cout << temp->info << " ,";
		temp = temp->next;
	}
	cout << temp->info << " ,";
	cout << " }\n";
}
void DoublyRingLinkList::search()
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
	while (temp->next != head)
	{
		if (temp->info == key)
		{
			count1++;
		}
		temp = temp->next;
	}
	if (temp->info == key)
	{
		count1++;
	}
	if (count1 == 0)
		cout << "\nKey Not found!!!\n";
	else
		cout << "\n" << count1 << " occurrence/s of key= '" << key << "' found in the list.\n";
}
void DoublyRingLinkList::remove()
{
	cout << "\nWelcome to the Deletion Operation!!!\n";
	if (head == NULL)
	{
		cout << "\nThere is nothing to delete from the list.\n";
		return;
	}
	int count2 = 0;
	temp = head;
	cout << "\nEnter the key you want to delete: ";
	cin >> key;
	if (head->info == key)
	{
		if (head->next == head && head->previous == head)
		{

			delete head;
			cout << "\nNumber: '" << key << "' has been deleted from the list.\n";
			head = temp = temp1 = NULL;
			return;
		}
		temp1 = temp->previous;
		temp->previous->next = temp->next;
		temp->next->previous = temp->previous;
		delete temp;
		head = temp1->next;
		temp = head;
		cout << "\nNumber: '" << key << "' has been deleted from the list.\n";
		count2++;
		return;
	}
	else
	{
		while (temp->next != head)
		{
			if (temp->info == key)
			{
				if (count2 == 0)
				{
					temp1 = temp->previous;
					temp->previous->next = temp->next;
					temp->next->previous = temp->previous;

					delete temp;
					temp = temp1;
					cout << "\nNumber: '" << key << "' has been deleted from the list.\n";
					count2++;
					return;
				}	
			}
			temp = temp->next;
		}
		if (temp->info == key)
		{
			temp1 = temp->previous;
			temp->previous->next = temp->next;
			temp->next->previous = temp->previous;
			delete temp;
			cout << "\nNumber: '" << key << "' has been deleted from the list.\n";
			temp = temp1;
			count2++;
			return;
		}
	}
	if (count2 == 0)
		cout << "\nKey not found!!!\n";
}
int main()
{
	cout << "Welcome to Doubly Ring link list implementation!!! \n";
	DoublyRingLinkList obj1;
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
				obj1.add();
				break;
			case 2:
				obj1.print();
				break;
			case 3:
				obj1.search();
				break;
			case 4:
				obj1.remove();
				break;
			default:
				cout << "\nRange out of bound!!\n";
				break;
			}
		}

	}
	return 0;
}

