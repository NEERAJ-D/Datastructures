// CircularQueue.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <string.h>
#include <stdio.h>
#include <tchar.h>
using namespace std;

enum DATATYPE
{
	CHAR = 1,
	INTEGER,
	DOUBLE,
	FLOAT,
	CHARARRAY
};
class Node
{
public:
	void * vData;
	Node * ptr;
	DATATYPE eDataType;
	Node()
	{
		ptr = NULL;
	}
	Node(char data)
	{
		vData = new char(data);
		eDataType = CHAR;
		ptr = NULL;
	}
	Node(char * data,int nSize)
	{
		vData = new char(nSize);
		memcpy(vData,data,nSize);
		eDataType = CHARARRAY;
		ptr = NULL;
	}
	Node(int data)
	{
		vData = new int(data);
		eDataType = INTEGER;
		ptr = NULL;
	}
	Node(double data)
	{
		vData = new double(data);
		eDataType = DOUBLE;
		ptr = NULL;
	}
	Node(float data)
	{
		vData = new float(data);
		eDataType = FLOAT;
		ptr = NULL;
	}
	void SetNode(char data)
	{
		vData = new char(data);
		eDataType = CHAR;
	}
	void SetNode(int data)
	{
		vData = new int(data);
		eDataType = INTEGER;
	}
	void SetNode(double data)
	{
		vData = new double(data);
		eDataType = DOUBLE;
	}
	void SetNode(float data)
	{
		vData = new float(data);
		eDataType = FLOAT;
	}
	void SetNode(char * data,int nSize)
	{
		vData = new char(nSize);
		eDataType = CHARARRAY;
		memcpy(vData,data,nSize);
	}

};

class Queue
{
public:
	Node * front;
	Node * rear;
	Queue()
	{
		front = NULL;
		rear = NULL;
	}
	void Add(Node * element)
	{
		if(rear!=NULL)
			rear->ptr = element;
		if(element!=NULL)	
			rear = element;
		if(front==NULL)
			front = element;
		if(rear!=NULL)
			rear->ptr = front;
	}
	Node * Remove()
	{
		Node * temp = front;
		front = front->ptr;
		delete temp;
	}
	void PrintQueue()
	{
		Node * temp = front;
		if(temp==NULL)
			return;
		do
		{
			switch(temp->eDataType)
			{
			case 1: cout<<*(char *)temp->vData<<" ";
				break;
			case 2: cout<<*(int *)temp->vData<<" ";
				break;
			case 3: cout<<*(double *)temp->vData<<" ";
				break;
			case 4: cout<<*(float *) temp->vData<<" ";
			}
			temp = temp->ptr;
		}while(temp!=front);
		
	}


};

int _tmain(int argc, _TCHAR* argv[])
{


	//Variable Declarations
	int numer_of_elements = 0;
	int option = 0;
	Queue instanceQ;;
	bool continueloop = true;
	int iterator = 0;
	cout<<"Please Enter the number of elements::";
	cin>>numer_of_elements;
	Node * current = NULL;

	while(continueloop)
	{
		cout<<"\nPlease select any one datatype::"<<endl;
		cout<<"1. Character"<<endl;
		cout<<"2. Integer"<<endl;
		cout<<"3. Double"<<endl;
		cout<<"4. Float"<<endl;
		cout<<"5. PRINT QUEUE"<<endl;
		cout<<"6. EXIT"<<endl;
		cin>>option;
 
		Node * node1 =NULL;
		if(option!=5 && option !=6)
		{
			if(iterator < numer_of_elements)
			{
				iterator++;
				node1 = NULL;
				current = instanceQ.front;
			}
			else
			{
				node1 = current;
				current = current->ptr;
			}
		}
		switch(option)
		{
		case 1:	{
					char temp;
					cin>>temp;
					if(NULL == node1)
					{
						node1 = new Node(temp);
						instanceQ.Add(node1);
					}
					else
						node1->SetNode(temp);
					break;
				}
			case 2:
				{
					int temp;
					cin>>temp;
					if(NULL == node1)
					{
						node1 = new Node(temp);
						instanceQ.Add(node1);
					}
					else
						node1->SetNode(temp);
						
					break;
				}
			case 3:
				{
					double temp;
					cin>>temp;
					if(NULL == node1)
					{
						node1 = new Node(temp);
						instanceQ.Add(node1);
					}
					else
						node1->SetNode(temp);
						
					break;
				}
			case 4:
				{
					float temp;
					cin>>temp;
					if(NULL == node1)
					{
						node1 = new Node(temp);
						instanceQ.Add(node1);
					}
					else
						node1->SetNode(temp);
					break;
				}
			
			case 5: instanceQ.PrintQueue();
				break;	
			case 6: continueloop = false;
				break;
			default:
					cout<<"Message";

		}
		
	}
	
	return 0;
}

