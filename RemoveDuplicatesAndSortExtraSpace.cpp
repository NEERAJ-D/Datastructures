// RemoveDuplicatesAndSortExtraSpace.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <map>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{

	int arr[] = {1,1,1,2,3,2,1,5,3,4,6,3,4,2,3,1};
	map<int,int> extraSpace;
	map<int,int>::iterator mapIterator;
	int size_n = sizeof(arr)/sizeof(int);

	for(int i=0;i<size_n;i++)
	{
		mapIterator = extraSpace.find(arr[i]);
		if(mapIterator == extraSpace.end())
			extraSpace[arr[i]] = 1;
		else
			mapIterator->second++;
	}
	




	return 0;
}

