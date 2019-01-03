#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

std::vector<int> v;

void search(int key)
{
	sort(v.begin(),v.end());
	int low=0;
	int high=v.size();
	int iterationCounter=0;
	bool found=false;

	while(low != high)
	{
		iterationCounter++;
		int mid = (low+high)/2;
		if(v[mid]==key)
		{
			cout <<"key found in."<<endl;
			cout<<"iteration counter: "<<iterationCounter<<endl;
			found = true;
			break;
		}
		else if(key<v[mid]) high = mid; 
		else low = mid;
	}

	if(!found) cout <<"Couldn't find item!"<<endl;
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
		v.push_back(data);
	}

	iFile.close();
	return true;
}


int main()
{
	readFromFile();
	search(101);
	return 0;
}