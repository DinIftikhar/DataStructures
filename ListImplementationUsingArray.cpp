//List Implementation using Array
#include <iostream>
using namespace std;
void add(char*, char,char);
void del(char*, char);
int main()
{
	char array[8] = { '2','6','8','7','1','\0' };
	cout << "Array before insertion of element: " << array << endl;
	//add(given array, character after which you want to add, required char to be added)
	add(array, '7','5');
	//del(given array, character you want to delete)
	del(array, '8');
	return 0;

}
void add(char* arr, char (x),char (y)) //function to insert a number into array
{
	char* ptr1 = arr;
	char* temp = arr;
	while (*ptr1 != x)
	{
		//ptr1 pointing the number after which you want to insert another number
		ptr1++;
	}
	while (*temp != '\0')
	{
		//temp moved to the end of the array
		temp++;
	}
	while (temp != ptr1)
	{
		//shift each element of the array after 'x' to the right.
		*(temp + 1) = *temp;
		temp--;
	}
	//Insert the given number
	*(temp + 1) = y;
	cout << "\n \nArray after insertion of element: " << arr << endl;
}
void del(char* arr2, char(z)) //function to delete the element from the array
{
	char* ptr2 = arr2;
	char* temp2 = arr2;
	while (*ptr2 != z)
	{
		//ptr2 pointing to the number you want to delete
		ptr2++;
	}
	while (*ptr2 != '\0')
	{
		//shift each element after the given number to the left.
		*ptr2 = *(ptr2 + 1);
		ptr2++;
	}
	cout << "\n \nArray after deletion of required element: " << arr2 << endl;
}