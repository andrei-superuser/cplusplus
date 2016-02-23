#include <iostream>
#include <utility> //for pair
#include <map>
#include <set>

using namespace std;

int main()
{

	//maps & sets couldn't hold except unique keys 
	pair<string,string> number1("Jone","123");
    map<string,string> numbers;
    map<string,int> grades;
    set<string> words; // set stores only one occurence (Just like a mathematical set)
    multimap<string,string> nums;

    nums.insert(pair<string,string>("Jones","987"));
    nums.insert(pair<string,string>("Johny","421"));
    nums.insert(pair<string,string>("Smith","121"));
    nums.insert(pair<string,string>("Johny","121"));

    string word = "";


    do
    {
    	cout << "Enter a word: ";
    	cin >> word;
    	words.insert(word);
    }while(word != "quit");

    set<string>::iterator iter1 = words.begin();
    while(iter1 != words.end())
    {
    	cout << *iter1 << endl;
    	iter1++;
    }






    grades["Ali"] = 12;
    grades["Sam"] = 2;
    grades["Tom"] = 90;

    string name;
    cout << "Please enter a name to find it's grade: ";
    cin >> name;

    if(grades.find(name) != grades.end())
    {
    	cout << "The grade is " << grades[name] << endl;
    }
    else
    {
    	cout << name << " not found" << endl;
    }

    double sum = 0.0;
    double avg;


    map<string,int>::iterator iter = grades.begin();
    while(iter != grades.end())
    {
      sum += iter->second;
      iter++;
    }

    cout << "The average is: " << sum/grades.size() << endl;
    	
	cout << number1.first << " " << number1.second << endl;

	pair<string,string> event1("Ahmed Alkabary","Long Jump");

	cout << event1.first << " " << event1.second << endl;


	numbers["Jones"] = "365";
	numbers["Joey"] = "2121";
	numbers.insert(pair<string,string>("Kalub","1211"));


	cout << "Jones number is: " << numbers["Jones"] << endl;
	cout << "Numbers of numbers is: " << numbers.size() << endl;
	numbers.erase("Joey");
	cout << "Numbers of numbers is: " << numbers.size() << endl;





  






    return 1;
}
