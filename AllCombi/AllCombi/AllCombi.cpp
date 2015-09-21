// AllCombi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

	#include <iostream>
#include<string.h>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{



	// your code goes here
	
	char samplestring[100] = "thisisdone";

	cout<<samplestring<<endl;
	//samplestring = samplestring<<1;

	cout<<samplestring<<endl;

	int length = strlen(samplestring);
	/*
	for(int len = 0;len < length;len++)
	{
		cout<<endl;
		for(int i = 0;i <= len;i++)
		{
			cout<<samplestring[i];
		}
	}
	*/
		for(int len = 1;len <= length;len++)
	{
		//cout<<endl<<len<<endl;
		for(int k = 0 ; k < length; k++)
		{
		//cout<<endl;
		if((k+len)<length)
		{
			cout<<endl;
			for(int i = k;i < (k+len);i++)
			{
			//int j=0;
			//cout<<endl;
		//	while(j < (i+len))
		//	{
				cout<<samplestring[i];
		//		j++;
		//	}
		}
		}
		}
	}
	
	return 0;
}


void combination()
{
	char samplestring[100] = "thisisdone";
	int length = strlen(samplestring);

	for(int len = 1;len <= length;len++)
	{
		for(int k = 0 ; k < length; k++)
		{
			if((k+len)<length)
			{
				cout<<endl;
				for(int i = k;i < (k+len);i++)
					cout<<samplestring[i];
			}
		}
	}
}


void permutation()
{

}