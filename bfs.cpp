#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <queue>
#include <limits>
#include <limits.h>
using namespace std;

int numberOfElement;
int timer=0;
int **arr;
int *dist;
bool *isVisited;
int *predecessor;
string *color;
int root=0;

//initialize all the arrays.
bool initializeValue()
{
	for(int i=0;i<numberOfElement;i++)
	{
		color[i] = "white";
		dist[i] = INT_MAX;
		predecessor[i] = -1;
		isVisited[i] = false;
	}

	return true;
}

// create arrays to contain associated info.
bool createSpace(int elementSize)
{
	numberOfElement = elementSize;
	
	arr = new int *[elementSize];
	for(int i=0;i<elementSize;i++)
	{
		arr[i] = new int [elementSize];
	} 
	dist = new int [elementSize];
	color = new string [elementSize];
	predecessor = new int [elementSize];
	isVisited = new bool [elementSize];
		
	if(initializeValue()) return true;
	else return false;
}

//shows the input matrix.
void showInput()
{
	for(int i=0;i<numberOfElement;i++)
	{
		for(int j=0;j<numberOfElement;j++) cout << arr[i][j]<<" ";
		cout << endl;
	}
}


// read input matrix from file.
bool readFromFile(string iFileName)
{
	ifstream iFile;
	iFile.open(iFileName.c_str());
	if(!iFile.is_open()) return false;
	
	int input;
	iFile >> input;
	if(!createSpace(input)) return false;
	
	for(int i=0;i<numberOfElement;i++)
	{ 
		for(int j=0;j<numberOfElement;j++)
		{
			iFile >> input;
			arr[i][j] = input;
		}
	}

	return true;
}

// shows the result of breadth first search
void showResult()
{
	cout << "node" << "  " << "distance" << "  " << "predecessor" << " 	 " << "color" << "  " << endl;
	for(int i=0;i<numberOfElement;i++) 
	{
		cout <<i<<"  	"<< dist[i]<<"    	"<<predecessor[i]<<" 		 "<<color[i]<<endl;
	}
}


// runs the breadth first search across the input matrix.
void bfs()
{
	string iFileName;
	cout <<"Enter input file name: ";
	cin >> iFileName;
	readFromFile(iFileName);

	queue <int> q;
	int i=root;
	q.push(root);

	color[root] = "grey";
	dist[root] = 0;
	predecessor[root] = -1;
	isVisited[root] = true;
	
	while(!q.empty())
	{
	
		i = q.front();
		for(int j=0;j<numberOfElement;j++)
		{
			if(arr[i][j]==1 && color[j] == "white"	&& isVisited[j]==false)
			{
				color[j] = "grey";
				predecessor[j] = i;
				isVisited[i] = true;
				dist[j] = dist[i] + 1;
				q.push(j);
			}		
		}

		color[i] = "black";
		q.pop();
	}

	showResult();
}

// main function that calls bfs function.
int main()
{
	bfs();
	return 0;
}
