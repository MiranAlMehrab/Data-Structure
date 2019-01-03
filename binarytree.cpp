#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node
{
	int data;
	node *parent;
	node *leftChild;
	node *rightChild;
};
node *root=NULL;

node * createNode(int data)
{
	node *temp = new node[1];
	temp->data = data;
	temp->parent = NULL;
	temp->rightChild = NULL;
	temp->leftChild = NULL;
	
	return temp;
}

void insertAtTree(node *temp)
{
	if(root==NULL) root = temp;
	else
	{
		node *current = root;
		while(1)
		{
			if(temp->data < current->data)
			{
				if(current->leftChild==NULL)
				{
					current->leftChild = temp;
					temp->parent = current;
					//cout<<"inserted in left "<<temp->data<<endl;
					break;
				}
				else current = current->leftChild; 
			}
			else
			{
				if(current->rightChild==NULL)
				{
					current->rightChild = temp;
					temp->parent = current;
					//cout<<"inserted in right "<<temp->data<<endl;
					break;
				}
				else current = current->rightChild; 
			}
		}
	}
}

void showTree(node *current)
{
	cout<<current->data<<"  ";
	if(current->leftChild != NULL) showTree(current->leftChild);
	if(current->rightChild != NULL) showTree(current->rightChild);
	cout << endl;
} 


void sortTree(node *current)
{
	if(current->leftChild != NULL) sortTree(current->leftChild);
	if(current->rightChild != NULL) sortTree(current->rightChild);
	if(current->parent != NULL && current->data > current->parent->data)
	{
		int data = current->parent->data;
		current->parent->data = current->data;
		current->data = data;
	}

}


bool readFromFile()
{
	string fileName;
	cin >> fileName;

	ifstream iFile;
	iFile.open(fileName.c_str());
	if(!iFile.is_open()) return false;

	int data=0;
	while(!iFile.eof())
	{
		iFile >> data;
		insertAtTree(createNode(data)); 
	}

	iFile.close();
	return true;
}

int main()
{
	if(!readFromFile()) return -1; //abnormal termination
	showTree(root);
	
	return 0;
}