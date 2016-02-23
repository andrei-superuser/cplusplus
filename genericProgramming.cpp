#include <iostream>
#include <vector>


using namespace std;

const int SIZE = 10;


template <typename T>
void printArray(T array[],int size)
{
    for(int i = 0;i < size;i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

template <typename M>

M maxi(M var1, M var2)
{
    if(var1 > var2)
    return var1;
    return var2;
}

template <typename K>


class Stack{

private:
        K datastore[100];
        int top;

public:
        Stack() : top(-1) {}
        void push(int num) { top++; datastore[top] = num; }
        K pop() {int val = datastore[top]; datastore[top] = 0; top--; return val; }
        K peek() { return datastore[top]; }


};

template <>
class Stack<string> {

private:
        string datastore[100];
        int top;

public:
        Stack() : top(-1) {}
        void push(string val) { top++; datastore[top] = val; }
        string pop() {string val = datastore[top]; datastore[top] = ""; top--; return val; }
        string peek() { return datastore[top]; }



};


template <typename X,typename Y>
X maxi(X var1,Y var2)
{
    return (var1 > var2) ? var1 :var2;
}

template <class P,class O>

class Cmap
{

    private:
            vector<P> keys;
            vector<O> values;
    public:
            void insert(P key,O value)
            {
                keys.push_back(key);
                values.push_back(value);
            }

            void get(int n)
            {
            cout << keys[n] << ": " << values[n] << endl;

            }


};


int main()
{
   /* int arrayInt[SIZE] = {1,2,3,4,5,6,7,8,9,10};
    string arrayStr[SIZE] = {"ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGH","NINE","TEN"};

    printArray(arrayInt,SIZE);
    printArray(arrayStr,SIZE);

    cout << maxi(3,2) << endl;
    cout << maxi('a','b') << endl;

  Stack<string> names;
  names.push("mary");
  names.push("joe");

  cout << names.peek() << endl;
  names.pop();
  cout << names.peek() << endl;


   int x = 2;
   double y = 3.3;

   cout << maxi(y,x) << endl;
   */


   Cmap<string,int>  grades;
   grades.insert("Ahmed",100);
   grades.insert("John",999);

   grades.get(0);
   grades.get(1);


    return 0;
}
