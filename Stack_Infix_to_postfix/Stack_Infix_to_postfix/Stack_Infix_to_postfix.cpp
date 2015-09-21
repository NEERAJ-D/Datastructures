// Stack_Infix_to_postfix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class Operator_Stack
{
public:
	char * stack;
	int top;

	Operator_Stack()
	{
		top = -1;
		stack = NULL;
	}
	Operator_Stack(int size)
	{
		top = -1;
		stack = NULL;
		stack = new char(size);
	}
	void push(char * oper)
	{
		stack[++top] = *oper;
	}
	char pop()
	{
		return stack[top--];
	}

	void Infix_To_PostFix(char expression[100])
	{
		//char expression[100] = {"a+b-c*d"};
		int priority = 0,in_priority = 0,stack_priority = 0 ;
		char * cptr = expression;
		char poppedchar;
		while(*cptr != '\0')
		{
			int ascii_char = *cptr;
			if(ascii_char  >= 97 && ascii_char  <= 123)
			{
				cout<<*cptr;
			}
			else
			{
				in_priority = calc_priority(*cptr);
				stack_priority = calc_priority(stack[top]);
				if(in_priority > stack_priority)
					push(cptr);
				else
				{
					while(in_priority <= calc_priority(stack[top]) && top != -1)
					{
						poppedchar = pop();
						if(poppedchar != '(')
						cout<<poppedchar;
					}
					if(*cptr != ')')
					push(cptr);
				}
			}
			cptr++;
		}
		while(top != -1)
		{
			cout<<pop();
		}

	}
	int calc_priority(char oper)
	{
		switch(oper)
		{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '(':
		case ')':
			return 0;
		case '^':
			return 3;
		default:
			return 0;
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	
	char expression[100];

	cout<<"Enter expression:\n";
	cin>>expression;

	Operator_Stack user_stack(sizeof(expression));

	user_stack.Infix_To_PostFix(expression);


	return 0;
}

