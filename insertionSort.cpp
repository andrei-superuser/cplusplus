/* Insertion Sort:

Algorithm:

Set Current_Index to the first position in the array
Repeat until Current_Index is at the end of the array
     Set x to the element at the Current_Index
     Find the insertion location, where x should be inserted in the sorted part of the array
     Move all elements between the insertion location and the end of the sorted part down by one
     Store x at the insertion location
	


Time Complexity:
 It has O(n^2) time complexity

*/

#include <iostream>

using namespace std;

void insSort(int *array,int size)
{


	int currentIndex;
	int temp;

	for(int i = 0;i < size;i++)
	{
		currentIndex = i;
		for(int j = 0;j < currentIndex;j++)
		{
			if(array[j] > array[j+1])
			{
		           temp = array[j];
		           array[j] = array[j+1];
		           array[j+1] = temp;
				
		        }
		}

		

		
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

	insSort(array,size);


	cout << "The sorted array is: ";

	for(int i = 0;i < size;i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	return 1;
}
