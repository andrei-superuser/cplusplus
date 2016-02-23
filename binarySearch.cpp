/* Binary Search:

Assume the array is sorted:

Algorithm:

The binary search algorithm begins by comparing the target value to the value of the middle element of the sorted array. If the target value is equal to the middle element's value, then the position is returned and the search is finished. If the target value is less than the middle element's value, then the search continues on the lower half of the array; or if the target value is greater than the middle element's value, then the search continues on the upper half of the array. This process continues, eliminating half of the elements, and comparing the target value to the value of the middle element of the remaining elements - until the target value is either found (and its associated element position is returned), or until the entire array has been searched (and "not found" is returned).

Time Complexity:
 It has O(log n) time complexity

*/

#include <iostream>

using namespace std;

int binSearch(int array[],int element,int high,int low)
{
	int mid = (low + high) /2;
	if(element == array[mid])
	{
		return mid;
	}
	else if(element > array[mid])
	{

		if(low <= high)
		{
			binSearch(array,element,high,mid+1);
		}
		else { return -1;}
	}
	else if(element < array[mid])
	{
		if(low <= high)
		{
			binSearch(array,element,mid-1,low);	
		}
		else {return -1;}

	}
		
}
	

int main()
{
	int array[10] = {1,2,3,4,5,6,7,8,9,10};

	int element;
	cout << "Enter the element that you are searching for: ";
	cin >> element;	

	cout << "The index is: " << binSearch(array,element,10,0) << endl;

	


	

	return 1;
}
