// ExpponentialPandQ.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<map>
using namespace std;

void CheckExpo(int number)
{
	string s;
	s.c
	int numberinstance = number;
	int mincount = 0;
	bool possible = true;
	string producttillnow = "negative"; //0 - indicates positive, 1- indicates negative
	//map<int,int> factor_occurences;
	if(number <= 3)
	{
		possible = false;
	}
	for(int i=2;i<=(numberinstance/2);i++)
	{
		int count = 0;
		while(number%i ==0)
		{
			number = number/i;
			count++;
		}
		//Insert into the set the pair value of factor and count
		if(mincount == 0)
		{
			mincount = count;

		}
		if(count!=0 && count!=1)
		{
			if(count < mincount)
			{
				if(mincount%count ==0)
				{
					mincount = count;
					if(count%2==1)
						producttillnow  = "negative";
					else
						producttillnow  = "positive";
						
				}
				else
				{
					possible = false;
					break;
				}
			}
			else
			{
				if(count%mincount !=0)
				{
					possible = false;
					break;
				}

			}

			//factor_occurences[i] = count;
			
		}
		else
		{
			if(count == 1)
			{
				possible = false;
				break;
			}

		}
	}

	if(possible)
	{
		cout<<"possible\n";
	}
	else
	{
		cout<<"Not possible\n";
		
	}

	//Iterate the factor array to print all the factors
	//for(int i=0;i<factor_occurences.size();i++)
	//	if(factor_occurences[i] != 0)
	//	cout<<i<<" occurs "<<factor_occurences[i]<<" many times \n";
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 216078855228;
	CheckExpo(n);
	return 0;
}

