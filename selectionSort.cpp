/* Selection Sort:

Algorithm:

Set Current_Element to the start of the array
Repeat until Current_Element at the end of the array
     Linear search from Current_Element to the end of the array for the Largest_Element
     If the Largest_Element is not the Current_Element swap them
     Move Current_Element to next element

Time Complexity:
 It has O(n^2) time complexity

*/

#include <iostream>

using namespace std;

void selSort(int *array,int size)
{


	int smallestIndex;

	for(int i = 0;i < size;i++)
	{
		int minIndex = i;
		for(int j = i;j < size;j++)
		{
			if(array[j] < array[minIndex])
			{
				minIndex = j;
			}
		}

		int temp;
		temp = array[i];
		array[i] = array[minIndex];
		array[minIndex] = temp;

		
	}
}
	

int main()
{
	//int array[10] = {10,2,3,7,8,4,5,9,1,6};


	int size;
	
	cout << "Enter the size of the array: ";
	cin >> size;

	int *array = new int[size];

	cout << "Enter the elements of the array: ";
	for(int i = 0;i < size;i++)
	{
		cin >> array[i];
	}

	selSort(array,size);


	cout << "The sorted array is: ";

	for(int i = 0;i < size;i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	return 1;
}
