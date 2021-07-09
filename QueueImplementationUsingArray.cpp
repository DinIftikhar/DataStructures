//Queue Implementation Using Array
#include <iostream>
using namespace std;
class Queue
{
private:
	int rear;
	int front;
	
public:
	int array[8];
	int N = sizeof(array) / sizeof(array[0]);
	Queue() {
		rear = front = -1;
	}
	~Queue() {};
	void enqueue();
	void dequeue();
}; 
void Queue::enqueue()
{
	int num;
	cout << "\nSize of Array is: " << N << endl;
	if (front == 0 && rear == N - 1)
	{
		cout << "\nQueue is Full.\n";
		return;
	}
	if (rear == -1)
	{
		rear = front = 0;
		cout << "\nQueue is empty. Add a number.\n";
		cin >> num;
		array[rear] = num;
		rear = (rear + 1) % N;
		return; 
	}
	

	cout << "\nAdd a new number.\n";
	cin >> num;
	array[rear] = num;
	rear = (rear + 1) % N;
}
void Queue::dequeue()
{
	

}
int main()
{
	Queue Q1;
	Q1.enqueue();
	Q1.enqueue();
	Q1.enqueue();
	Q1.enqueue();
	Q1.enqueue();
	Q1.enqueue();
	Q1.enqueue();
	Q1.enqueue();
	Q1.enqueue();

	return 0;
}
