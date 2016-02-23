#include <iostream>
#include <stdexcept>

using namespace std;

class DivideByZero: public runtime_error
{
	public:
		DivideByZero():runtime_error("Divide by zero exception! \n") {}


};


double quotient(double numer,double denom)
{
		if(denom == 0)
		{
			throw DivideByZero();
		}
	     else
	     {
	     	return numer/denom;
	     }
}
const int DIVIDEBYZERO = 1;
int main()
{

	     double ratio, numer =2,denom = 0;

	     try{

	 
	     ratio = quotient(numer,denom);
	     }
	     catch(DivideByZero &except)
	     {
	     	cout << except.what() << endl;
	     }


	     //catch(....) for all exceptions 


	    

/*

  try{
  		int numer = 12;
  		int denom = 0;

  		if(denom == 0)
  		{
  			throw DIVIDEBYZERO;
  		}
  		else
  		{
  			cout << "Result is: " << double(numer) /denom << endl;
  		}
 }
	catch(int e)
	{
	  if(e = DIVIDEBYZERO)
	  {
	  	cerr << "Can't divide by zero!\n";
	  }
	}

*/


	return 0;
}