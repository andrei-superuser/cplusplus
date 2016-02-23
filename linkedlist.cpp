#include <iostream>
#include <string>

using namespace std;

class Node
{
	public:
		string data;
		Node *next;
		Node(string aData,Node *aNext)
		{
			data = aData;
			next = aNext;
		}

		string getData()
		{
			return data;
		}

		Node *Next()
		{
			return next;
		}
		void setNext(Node *aNext)
		{
			next = aNext;
		}
};

class LinkedList
{
		public: 
			Node *head;
			LinkedList()
			{
				head = NULL;
			}
			void Append(string data)
			{
				Node *newNode = new Node(data, NULL);
				Node * temp = head;
				if(temp != NULL)
				{
					while(temp->Next() != NULL)
					{
						temp = temp->Next();
					}
					temp->setNext(newNode);
				}
				else
				{
					head = newNode;
				}
			}
			void Delete(string data)
			{
				Node *temp = head;
				if(temp == NULL)
				{
					return;
				}

			 	if(temp->Next() == NULL)
			 	{
			 		delete temp;
			 		head = NULL;
			 	}
			 	else
			 	{
			 		Node* prev;
			 		do
			 		{
			 			if(temp->getData() == data)
			 			{
			 				break;
			 			}

			 			prev = temp;
			 			temp = temp->Next();
			 		}while(temp != NULL);
					prev->setNext(temp->Next());
					delete temp;
				}
		}

		void Print()
		{
			Node *temp = head;
			if(temp == NULL)
			{
				cout << "Empty list" << endl;
				return;
			}
		 	else
		 	{
		 		do
		 		{
		 			cout << temp->getData() << "---->";
		 			temp = temp->Next();

		 		}while(temp != NULL);
				cout << " Null" << endl;
			}
		}




};
int main ()
{
	cout << "Linked List implementation!\n";

	LinkedList names;
	names.Append("Ahmed");
	names.Append("David");
	names.Append("John");
	names.Print();
	names.Delete("David");
	names.Print();

	
	return 0;
}


