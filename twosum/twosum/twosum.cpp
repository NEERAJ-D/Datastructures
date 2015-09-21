// twosum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


 vector<int> twoSum(vector<int>& nums, int target) {

		int n1 = nums.at(0);

		vector<pair<int,int>>vecarray;
		for(int i=0;i<nums.size();i++)
		{
			pair<int,int> p;
			p.first = nums.at(i);
			p.second = i;
			vecarray.push_back(p);
		}

		
        std::sort(vecarray.begin(),vecarray.end());
        
        int startIndex = 0;
        int twosum = 0;
         vector<int> returnvector;
        int endIndex = nums.size()-1;
        bool found = false;
        while(found==false)
        {
			twosum = vecarray.at(startIndex).first + vecarray.at(endIndex).first;
          
            if(twosum < target)
            startIndex++;
            
            else if(twosum > target)
            endIndex--;
            
            else
            {
               found = true;

			   if(vecarray.at(startIndex).first < 0)
					returnvector.push_back(vecarray.at(endIndex).second+1);
			    if(vecarray.at(endIndex).first < 0)
                returnvector.push_back(vecarray.at(startIndex).second+1);


				if(vecarray.at(startIndex).first >= 0)
                returnvector.push_back(vecarray.at(startIndex).second+1);

				if(vecarray.at(endIndex).first >= 0)
				returnvector.push_back(vecarray.at(endIndex).second+1);

			  
			   

            }
        }
        return returnvector;
    }


int _tmain(int argc, _TCHAR* argv[])
{

	vector<int> inputData;
	vector<int> output;

	inputData.push_back(0);
	inputData.push_back(4);
	inputData.push_back(3);
	inputData.push_back(0);
	//inputData.push_back(-5);
	output = twoSum(inputData,0);

	for(int i=0;i<output.size();i++)
		cout<<output.at(i)<<" ";
	return 0;
}

