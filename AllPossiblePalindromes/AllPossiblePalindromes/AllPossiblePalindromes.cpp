// AllPossiblePalindromes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string.h>
#include <iostream>
#include <set>
#include<map>
#include <cctype> 
#include <algorithm>
#include <utility>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	map<string,int>palidromes;

//	palidromes.insert(std::pair<string,int>("David D.",1923));

	map<string,int>::iterator myiterator;
	//map<string,string>mymap;
	string str1("addascfrffd");
	string temp("");
	string currentstring("");
	int left=0,right = 0;
	for(int i=2;i <= str1.length();i++)
	{
		for(int j=0;j<str1.length();j++)
		{
			
			if((j+i)<=str1.length())
			{
				currentstring = str1.substr(j,i);
				//cout<<str1;
				//Within bounds


				//Apply whether palindrome logic
				if(i%2==0)
				{
					//even palindrome
					left = i/2 - 1;
					right = i/2;
				}
				else
				{
					//odd palindrome
					left = i/2 - 1;
					right = i/2 + 1;
				}

				while(left >= 0 && right < currentstring.length())
				{
					if(currentstring[left] == currentstring[right])
					{
						//Substring exists from left,right
						//cout<<currentstring.substr(left,right-left+1);
						temp = currentstring.substr(left,right-left+1);
						if(temp.compare(""))
						printf("%s\n",temp.c_str());
						//palidromes[temp] = 1;
						//Employees.insert(std::pair<string,int>("David D.",1923));
					}
					else
						break;
					left--;
					right++;
				}
		
			}
		}
	}


	int totalcount = 0;
    char temporary[2] = {'\0'};
    for(int i=0;str1[i]!='\0';i++)
    {
        temporary[0] = str1[i];
    //    palidromes[temporary] = 1; 
		cout<<temporary<<endl;
    }
	for(myiterator = palidromes.begin();myiterator != palidromes.end();myiterator++)
		totalcount++;
	if(str1.size() == 0)
	{
		return 0;
	}

	
	cout<<totalcount;


	return 0;
}

