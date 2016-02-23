#include <iostream>
#include <vector>
#include <list>
#include <deque>


using namespace std;

int main()
{

    vector<int> numbers;
	list<string> names;
	deque<string> line;
	
	line.push_back("Customer 1");
	line.push_front("Customer 2");
	line.push_back("Customer 3");
	
	for(int i =0;i < line.size();i++)
	{
		cout << line[i] << endl;
	}
	
	line.pop_back();

	names.push_back("Ahmed");
	names.push_back("Sayed");
	names.push_back("Alkabary");

	list<string>::iterator iter = names.begin();
	while(iter != names.end())
	{
		cout << *iter << " ";
	    iter++;
	}


	cout << endl;

	cout << names.front() << " " << names.back();
	names.reverse();
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.pop_back();

    for(int i =0;i < numbers.size();i++)
    {
        cout << numbers[i] << endl;
    }








    return 1;
}
