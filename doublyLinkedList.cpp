#include <iostream>
#include <fstream>
using namespace std;

struct node
{
	int data;
	node *previous;
	node *next;
};


node* createNode(int data)
{
	node *temp = new node[1];
	temp[0].data = data;
	temp[0].previous = NULL;
	temp[0].next = NULL;
	return temp;
}

node *head = NULL;
node *tail = NULL;
void insertIntoList(node*temp)
{
	if(head==NULL && tail==NULL)
	{
		head = temp;
		tail = temp;
		temp->previous=NULL;
		temp->next = NULL;
	}
	else
	{
		tail->next = temp;
		temp->previous = tail;
		temp->next = NULL;
		tail = temp;
	}
}


void traverseForward()
{
	node *current = head;
	while(current != NULL)
	{
		cout<<current->data<<" ";
		current = current->next;
	}
	cout <<endl;
}

void traverseBackward()
{
	node *current = tail;
	while(current != NULL)
	{
		cout<<current->data<<" ";
		current = current->previous;
	}
	cout<< endl;
}

void searchDataInList(int data)
{
	node *current = head;
	while(current != NULL)
	{
		if(data == current->data)
		{
			cout <<"Data found."<<endl;
			return;
		}
		current = current->next;
	}
	cout <<"Data not found."<<endl;
}

void deleteDataFromList(int data)
{
	node *temp = head;
	while(temp!=NULL)
	{
	 	if(data == temp->data)
	 	{
	 		if(temp == head)
	 		{
	 			head = head->next;
	 			head->previous = NULL;
	 		}
	 		else if(temp == tail)
	 		{
	 			tail = tail->previous;
	 			tail->next = NULL;
	 		}
	 		else
	 		{
	 			temp->next->previous = temp->previous;
	 			temp->previous->next = temp->next;		
	 		}
	 	}
	 	temp = temp->next;
	}
}


void insertAfter(int key,int data)
{
	node *current = head;
	while(current != NULL)
	{
		if(key == current->data)
		{
			if(current==head)
			{
				node *temp = createNode(data);
				head->next->previous = temp;
				temp->previous = head;
				temp->next = head->next;
				head->next = temp;	
			}
			else if(current == tail)
			{
				node *temp = createNode(data);
				tail->next=temp;
				temp->previous=tail;
				temp->next=NULL;
				tail=temp;
			}
			else
			{
				node *temp = createNode(data);
				
				temp->previous = current;
				temp->next = current->next;
				temp->next->previous = temp;
				temp->previous->next = temp;
			}
		}
		
		current = current->next;
	}
}
void readFromFile()
{
	string fileName="bubble.txt";
	//cout <<"Enter your file name : ";
	//cin >> fileName;

	ifstream iFile;
	iFile.open(fileName.c_str());
	if(!iFile.is_open())
	{
		cout<<"Couldn't open file."<<endl;
		return;
	}

	int data;
	node *temp = NULL;
	while(!iFile.eof())
	{
		iFile >> data;
		temp = createNode(data);
		insertIntoList(temp);
	}
}

int main()
{

	readFromFile();
	traverseForward();
	//traverseBackward();
	//searchDataInList(10);
	//deleteDataFromList(10);
	//searchDataInList(10);
	insertAfter(10,5);
	traverseForward();
	//traverseBackward();


	return 0;
}