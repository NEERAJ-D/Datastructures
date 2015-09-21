// SpiralMatrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	int matrix[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};


	int size = 4;
	int i=0; int j =0;
	while(size > 0 )
	{
	for(j=0;j<size;j++)
			cout<<matrix[i][j]<<" ";

	cout<<endl;
	size--;
	j--;
	for(i++;i<size+1;i++)
		cout<<matrix[i][j]<<endl;

	cout<<endl;
	
	j--;
	for(i--;j>=0;j--)
		cout<<matrix[i][j]<<" ";

	cout<<endl;
	size--;
	for(j++;i>1;i--)
		cout<<matrix[i][j]<<endl;
	}
	return 0;
}

