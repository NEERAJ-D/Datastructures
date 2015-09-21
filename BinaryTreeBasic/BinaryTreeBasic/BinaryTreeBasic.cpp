// BinaryTreeBasic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
	int data;
	Node * left;
	Node * right;

	Node(int ndata)
	{
		data = ndata;
		left = NULL;
		right = NULL;
	}

};

void dfs(Node * root)
{

}

void bfs(queue<Node *> BFSQ)
{
	if(BFSQ.empty())
		return;

	Node * front = BFSQ.front();
	
	if(front)
	{
		BFSQ.pop();
	cout<<front->data<<" ";
	if(front->left)
	BFSQ.push(front->left);
	if(front->right)
	BFSQ.push(front->right);
	}
	else
		return;

	bfs(BFSQ);
}

void preorder(Node * root)
{
	if(root == NULL)
		return;

	cout<<root->data<<endl;
	preorder(root->left);
	preorder(root->right);

}

void postorder(Node * root)
{
if(root == NULL)
		return;

	
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<endl;
}
void inorder(Node * root)
{
if(root == NULL)
		return;

	
	inorder(root->left);
	cout<<root->data<<endl;
	inorder(root->right);

}

int _tmain(int argc, _TCHAR* argv[])
{

	Node * head = new Node(10);
	head->left = new Node(20);
	head->right = new Node(30);

	head->left->left = new Node(4);
	head->left->right = new Node(5);

	preorder(head);

	cout<<endl;
	postorder(head);

	cout<<endl;
	inorder(head);
	cout<<endl;
	queue<Node *> q;
	q.push(head);
	bfs(q);


	return 0;
}

