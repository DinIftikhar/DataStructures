#include <iostream>
using namespace std;
struct node
{
	node* next;
	int info;
};
class LinkList
{
private:
	node* head;
	node* temp;
	node* temp1;
	int key;
public:
	LinkList();
	~LinkList() {};
	void search();
	void add();
	int recsearch(node*,int);
};
LinkList::LinkList()
{
	head = NULL;
	temp = NULL;
	temp1 = NULL;
	key = 0;
}
void LinkList::add()
{
	cout << "\nWelcome to the Insert Operation!!!\n";
	if (head == NULL)
	{
		head = new node;
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
						temp1 = new node;
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
							temp1 = new node;
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
void LinkList::search()
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
	count1 = recsearch(temp, key);
	if (count1 == 2)
		cout << "\nKey found!!!\n";
	else
		cout << "\nKey not found!!\n";
}
int LinkList::recsearch(node* temp1,int key1)
{
	if (temp1 == NULL)
		return 1;
	else if (temp1->info == key)
		return 2;
	else
		return recsearch(temp1->next, key1);
}
int main()
{
	LinkList L1;
	L1.add();
	L1.search();
	return 0;
}