// Trie.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

class trie_node
{
public:
	char c_data;
	trie_node * alpha_links[26];
	trie_node()
	{
		for(int i=0;i<26;i++)
		{
			alpha_links[i] = NULL;
		}
		c_data = '\0';
	}
	trie_node(char c)
	{
		/*for(int i=0;i<26;i++)
		{
			alpha_links[i] = NULL;
		}*/
		c_data = c;
	}
};
class trie
{
public:
	trie_node * root;
	int count;

	trie()
	{
		root = new trie_node();
		count = 0;
	}
	
};

int _tmain(int argc, _TCHAR* argv[])
{
	
	trie T;
	int no_of_elements = 0;
	cout<<"Enter the number of elements";
	cin>>no_of_elements;

	int i=0;
	char key[100][100];
	trie_node * parent;
	while(i < no_of_elements)
	{
		cout<<"Enter key";
		cin>>key[i];
		
		int len = strlen(key[i]);

		int j=0;
		while(j < len)
		{
			cout<<key[i][j];	
			int ascii_char = key[i][j];
			//if(T.root)
			//{
				parent = T.root;
				if(parent != NULL)
				{
					if(parent->alpha_links[ascii_char- 97])
					{
						parent = parent->alpha_links[ascii_char- 97];
					}
				}
				int index = (ascii_char- 97);
				parent->alpha_links[index] = new trie_node(key[i][j]);
			//}	
			j++;
		}
		i++;

	}


	return 0;
}

