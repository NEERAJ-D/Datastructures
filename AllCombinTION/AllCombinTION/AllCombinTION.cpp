// AllCombinTION.cpp : Defines the entry point for the console application.
//Anagrams

#include "stdafx.h"
#include <iostream>
#include<string>
using namespace std;
int cnt=0;
void allcombi(string a,int i,int n)
{
     int j;
     char temp; 
     if (i == n)
     {
        cout<<a<<endl;
        cnt++;
     } 
     else
     {
          for (j = i; j <= n; j++)
         {
            //swap((a+i), (a+j));
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            allcombi(a, i+1, n);
            //swap((a+i), (a+j)); //backtrack
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
         }
      }
      //return cnt;
}
int _tmain(int argc, _TCHAR* argv[])
{

	string mystring("hello");
	allcombi(mystring,0,mystring.length()   );
	cout<<"count::"<<cnt;
	return 0;
}
