// BinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

class node
{
public:
	node()
	{
	}
	node(int rdata)
	{
		data = rdata; 
	}
	int data;
	 node * left;
	 node * right;
};
class Stack
{

public:
	//int data[100];
	node * data[100];
	int top;
	Stack()
	{
		top = -1;
	}
	void push(node * formalparameter)
	{
		data[++top] = formalparameter;
	}
	node * pop()
	{
		return data[top--];
	}
	void printstack()
	{
		int i = top;
		while(i != -1)
		{
			cout<<(data[i--])->data<<endl;
		}
	}

};
class Queue
{
public:
	node * data[100];
	int front;
	int rear;
	Queue()
	{
		front = 0;
		rear = -1;
	}
	void Add(node * ndata)
	{
		data[++rear] = ndata;
	}
	node * DeleteFront()
	{
		if(rear >= front)
		{
			return data[front++];
		}
	}
	int DeleteRear()
	{
		return 0;
	}
	void printq()
	{
		int i = front;
		while(i<= rear)
		{
			cout<<(data[i++])->data<<" ";
		}
	}

};


class Tree
{

public:
	node * root;
	Tree()
	{
		root = NULL;
		nCount = 0;
		leafcount = 0;
	}

	int nArray[100];
	int nCount;
	int leafcount;
	int distancefromroot[100];

	Stack s;

	Queue q;
	Queue q_alternate;

	void AddNode(int nData);
	
	void InOrder(node *);
	void PreOrder(node *);
	void PostOrder(node *);
	bool Identical(node * root1,node * root2);
	int MaximumDepth(node *);

	void DeleteTree(node *);

	//All perform mirroring
	node * DuplicateTree(node *,node *);
	void MirrorTreePreorderPrint(node * root);
	void PreOrderStore(node *);
	void AddMirroredNode(int nData);	

	void MirrorExisting(node *);

	//http://www.geeksforgeeks.org/the-great-tree-list-recursion-problem/
	void GreatTreeListRecursion(node * root);

	void BreadthFirstSearch(node *);

	void CountLeaf(node *);

	void DoubleTree(node * root);
	int height( node* root);
	void MaxWidth(node * root);
	int SumTree(node * root);
	void HorizontalWidth(node * root);
	void LevelOrder(node * root);
	void LevelOrderTwoQueues(node * root);

	bool FullBinary(node * root);
	void ReverseBFS(node * root);

};

void Tree::BreadthFirstSearch(node * root)
{
	if(root == NULL)
		return;

	//Add element to queue
	//q.Add(root);
	if(root->left != NULL)
		q.Add(root->left);
	if(root->right != NULL)
		q.Add(root->right);
	
	if(q.front <= q.rear)
	{
		cout<<(q.DeleteFront())->data<<" ";
		BreadthFirstSearch(q.data[q.front]);
	}
	
}

void Tree::GreatTreeListRecursion(node * root)
{
	
}
int Tree::MaximumDepth(node * root)
{
	if(root == NULL)
	{
		return 0;
	}
	else
	{
		int leftheight = MaximumDepth(root->left);
		int rightheight = MaximumDepth(root->right);
		
		if(leftheight  > rightheight)
		{
			return (leftheight + 1);
		}
		else return(rightheight + 1);
	}
}


void Tree::InOrder(node * root)
{
	if(root != NULL)
	{
		InOrder(root->left);
		cout<<root->data<<" ";
		InOrder(root->right);
	}
}


void Tree::CountLeaf(node * root)
{
	if(root != NULL)
	{
		CountLeaf(root->left);
		CountLeaf(root->right);
		if(root->left == NULL && root->right == NULL)
			leafcount++;
	}
}

bool Tree::Identical(node * root1,node * root2)
{
	if(root1 != NULL && root2 != NULL)
	{
		Identical(root1->left,root2->left);
		if(root1->data != root2->data)
			return false;
		Identical(root1->right,root2->right);
	}
	else if(root1 != NULL && root2 == NULL)
	{
			return false;
	}
	else if(root1 == NULL && root2 != NULL)
	{
		return false;
	}
		
	
}

void Tree::PreOrder(node * root)
{
	if(root != NULL)
	{
		cout<<root->data<<" ";
		PreOrder(root->left);
		PreOrder(root->right);
	}
}


void Tree::PreOrderStore(node * root)
{
	if(root != NULL)
	{
		cout<<root->data<<" ";
		nArray[nCount++] = root->data;
		PreOrderStore(root->left);
		PreOrderStore(root->right);
	}
}
void Tree::MirrorTreePreorderPrint(node * root)
{
	if(root != NULL)
	{
		cout<<root->data<<" ";
		MirrorTreePreorderPrint(root->right);
		MirrorTreePreorderPrint(root->left);
	}

}
void Tree::MirrorExisting(node * root)
{
	//Post Order (After visiting both left and right branches swap the branches
	if(root == NULL)
	{
		return ;
	}
	else
	{
		MirrorExisting(root->left);
		MirrorExisting(root->right);

		//Swap
		node * temp =  root->left;
		root->left = root->right;
		root->right = temp;
	}
}

/*
void Tree::SumChild(node * root)
{
	if(root != NULL)
	{
		SumChild(root->left);
		SumChild(root->right);
		if()
			
	}
}
*/

void Tree::PostOrder(node * root)
{
	if(root != NULL)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		cout<<root->data<<" ";
	}
}

int Tree::SumTree(node * root)
{
	//int left,right;
	//if(root == NULL)
	//	return 0;
	//
	//left = root->data;
	//root->data = SumTree(root->left) + SumTree(root->right);
	//return root->data + left;

	//int lh=0,rh=0;
	//if(root == NULL)
	//	return 0;

	//if(root->left != NULL)
	//	lh = SumTree(root->left) + root->left->data;
	//if(root->right != NULL)
	//	rh = SumTree(root->right) + root->right->data;
	//
	//root->data = lh + rh;
	//return(root->data);

	if(root == NULL)
		return 0;

	int old = root->data;
	int x = SumTree(root->left) + old;
	int y = SumTree(root->right) + old;
	
	//if(x!= 0 || y!= 0)
	root->data = x + y;
	cout<<" "<<(root->data);
	return (root->data);
	

}

void Tree::DeleteTree(node * root)
{
	if(root != NULL)
	{
		DeleteTree(root->left);
		DeleteTree(root->right);
		delete root;
	}
}

node * MakeNode(int data)
{
	
	node * ptr = new node(data);
	ptr->left = NULL;
	ptr->right = NULL;
	return ptr;
}
void Tree::AddNode(int nData)
{
	node * currentNode = NULL;
	node * parent = NULL;


	//Initially check if root is NULL
	if(root == NULL)
	{
		root = MakeNode(nData);
		return;
	}

	parent = root;
	currentNode = root;
	while(true)
	{
					
		if(nData < currentNode->data)
		{
			//Left child
			if(currentNode->left == NULL)
			{
				currentNode->left = MakeNode(nData);
				break;
			}
			else
			{
				currentNode = currentNode->left;
			}
									
		}
		else
		{
			//Right child
			if(currentNode->right == NULL)
			{
				currentNode->right = MakeNode(nData);
				break;
			}
			else
			{
				currentNode = currentNode->right;
			}			

		}
	
	}

		
}
void Tree::AddMirroredNode(int nData)
{
	node * currentNode = NULL;
	node * parent = NULL;


	//Initially check if root is NULL
	if(root == NULL)
	{
		root = MakeNode(nData);
		return;
	}

	parent = root;
	currentNode = root;
	while(true)
	{
					
		if(nData > currentNode->data)
		{
			//Left child
			if(currentNode->left == NULL)
			{
				currentNode->left = MakeNode(nData);
				break;
			}
			else
			{
				currentNode = currentNode->left;
			}
									
		}
		else
		{
			//Right child
			if(currentNode->right == NULL)
			{
				currentNode->right = MakeNode(nData);
				break;
			}
			else
			{
				currentNode = currentNode->right;
			}			

		}
	
	}

		
}
//Creates a mirrored tree (need to verify on various trees)
node * Tree::DuplicateTree(node * originalroot,node * duplicateroot)
{
	if(originalroot == root)
	{
		duplicateroot = MakeNode(originalroot->data);
	}
	if(originalroot != NULL)
	{
		//Create right child
		if(originalroot->left != NULL)
			duplicateroot->right  = MakeNode(originalroot->left->data);
		DuplicateTree(originalroot->left,duplicateroot->right);
		
		//Create left child
		if(originalroot->right != NULL)
			duplicateroot->left  = MakeNode(originalroot->right->data);
		DuplicateTree(originalroot->right,duplicateroot->left);
	}
	return duplicateroot;
}


void Tree::DoubleTree(node * root)
{
	node * doublenode = NULL,* temp = NULL;
	if(root == NULL)
		return;

	if(root->left == NULL)
	{
		doublenode = MakeNode(root->data);
		root->left = doublenode;
		DoubleTree(root->right);
	}
	else
	{
		doublenode = MakeNode(root->data);
		temp = root->left;
		root->left = doublenode;
		doublenode->left = temp;
		DoubleTree(doublenode->left);
		DoubleTree(root->right);
	}

}

int Tree::height(node * root)
{
   if (root == NULL)
     return 0;
   else
   {
     /* compute the height of each subtree */
     int lHeight = height(root->left);
     int rHeight = height(root->right);
     /* use the larger one */
 
     return (lHeight > rHeight)? (lHeight+1): (rHeight+1);
   }
}
void MaxWidthRecursion(node * root,int * count ,int level)
{
	if(root == NULL)
		return;
	
	count[level]++;
	MaxWidthRecursion(root->left,count,level);
	MaxWidthRecursion(root->right,count,level);

}
void Tree::MaxWidth(node * root)
{
	int ht = height(root);

	int * count = new int(ht);

	int level = 0;

	MaxWidthRecursion(root,count,level);

	//return max from here
}

void Tree::HorizontalWidth(node * cnode)
{
	if(cnode == root)
		distancefromroot[0] = root->data;

	//Recusrive version

	//Create a hashmap and store the sum for each distance
}	




bool Tree::FullBinary(node * root)
{
	//Prerequisite that the root has already been added in the queue
	int countofnodesatlevel = 0;
	int level = 1;
	int frontdata = 0;
	node * front;
	bool complete = true;

	//Dequeue element
	//If Separator print new line (increment level count)
	
	//Add Lchild
	//Add Rchild
	
	
	//Call BFS (front queue);
	
	q.Add(root);
	q.Add(MakeNode(999));
	
	while(q.front <= q.rear)
	{
	
	if((q.data[q.rear])->data == 999 && (q.data[q.front])->data == 999 )
	{
		break;
	}
		
	front = q.DeleteFront();
	frontdata = front->data;
	if(frontdata == 999)
	{
		cout<<endl;
		if(q.data[q.rear] != q.data[q.rear - 1])
			q.Add(MakeNode(999));
		//Level change
		//Check if the (2 raised to level) = count
		

		if(countofnodesatlevel == (double)pow((double)2,(double)level) )
		{
			complete = true;
			countofnodesatlevel = 0;
		}
		else
		{
			complete = false;
			break;
		}
			level++;
	}
	else
	{
		cout<<frontdata<<" ";
		//Not a separator
		if(front->left != NULL)
		{
			q.Add(front->left);
			countofnodesatlevel++;
		}
		if(front->right != NULL)
		{
			q.Add(front->right);
			countofnodesatlevel++;
		}
		
	}
	}
	return complete;

}
void Tree::InsertatLastPosition(node * root)
{
	//Prerequisite that the root has already been added in the queue
	
	int frontdata = 0;
	node * front;

	//Dequeue element
	//If Separator print new line (increment level count)
	
	//Add Lchild
	//Add Rchild
	
	
	//Call BFS (front queue);
	
	q.Add(root);
	q.Add(MakeNode(999));
	

	while(q.front <= q.rear)
	{
	
	if((q.data[q.rear])->data == 999 && (q.data[q.front])->data == 999 )
	{
		break;
	}
	
	
	front = q.DeleteFront();
	frontdata = front->data;
	if(frontdata == 999)
	{
		cout<<endl;
		if(q.data[q.rear] != q.data[q.rear - 1])
			q.Add(MakeNode(999));
		//Level change
	}
	else
	{
		cout<<frontdata<<" ";
		//Not a separator
		if(front->left != NULL)
		q.Add(front->left);
		if(front->right != NULL)
		q.Add(front->right);
		
	}
	}

}
void Tree::LevelOrder(node * root)
{
	//Prerequisite that the root has already been added in the queue
	
	int frontdata = 0;
	node * front;

	//Dequeue element
	//If Separator print new line (increment level count)
	
	//Add Lchild
	//Add Rchild
	
	
	//Call BFS (front queue);
	
	q.Add(root);
	q.Add(MakeNode(999));
	

	while(q.front <= q.rear)
	{
	
	if((q.data[q.rear])->data == 999 && (q.data[q.front])->data == 999 )
	{
		break;
	}
	
	
	front = q.DeleteFront();
	frontdata = front->data;
	if(frontdata == 999)
	{
		cout<<endl;
		if(q.data[q.rear] != q.data[q.rear - 1])
			q.Add(MakeNode(999));
		//Level change
	}
	else
	{
		cout<<frontdata<<" ";
		//Not a separator
		if(front->left != NULL)
		q.Add(front->left);
		if(front->right != NULL)
		q.Add(front->right);
		
	}
	}
}

void Tree::VerticalPrinting()
{

}


void Tree::ReverseBFS(node * root)
{
	//Prerequisite that the root has already been added in the queue
	
	int frontdata = 0;
	node * front;

	//Dequeue element
	//If Separator print new line (increment level count)
	
	//Add Lchild
	//Add Rchild
	
	
	//Call BFS (front queue);
	
	q.Add(root);
	s.push(root);
	q.Add(MakeNode(999));
	

	while(q.front <= q.rear)
	{
	
	if((q.data[q.rear])->data == 999 && (q.data[q.front])->data == 999 )
	{
		break;
	}
	
	
	front = q.DeleteFront();
	s.push(front);
	frontdata = front->data;
	if(frontdata == 999)
	{
		cout<<endl;
		if(q.data[q.rear] != q.data[q.rear - 1])
			q.Add(MakeNode(999));
		//Level change
	}
	else
	{
		cout<<frontdata<<" ";
		//Not a separator
		if(front->left != NULL)
		q.Add(front->left);
		if(front->right != NULL)
		q.Add(front->right);
		
	}
	}
}
/*
void Tree::LevelOrderTwoQueues(node * root)
{

	node * element;
	//Level wise pr1inting using two queues

	q.Add(root);
	

	//While both queues are not empty
	while(q.front > q.rear && q_alternate.front > q_alternate.rear)
	{
		while(q.front > q.rear )
		{
			//q_alternate is not empty
			element = q_alternate.DeleteFront();
			frontdata = element->data;
			cout<<frontdata<<" ";
			//Not a separator
			if(front->left != NULL)
				q.Add(front->left);
			if(front->right != NULL)
				q.Add(front->right);

		}
		while(q_alternate.front > q_alternate.rear)
		{
			element = q.DeleteFront();
			frontdata = element->data;
			//Not a separator
			if(element->left != NULL)
				q.Add(element->left);
			if(element->right != NULL)
				q.Add(element->right);
		}

	}

}
*/
int _tmain(int argc, _TCHAR* argv[])
{

	int nData = 0;
	
	Tree t,p;
	t.AddNode(10);
	t.AddNode(20);
	t.AddNode(5);
	t.AddNode(50);
	t.AddNode(15);
	t.AddNode(25);
	t.AddNode(53);


	p.AddNode(10);
	p.AddNode(20);
	p.AddNode(51);
	p.AddNode(50);
	p.AddNode(15);
	p.AddNode(25);
	p.AddNode(53);

	Tree m;
	m.AddNode(10);
	m.AddNode(5);
	m.AddNode(20);
	m.AddNode(3);
	m.AddNode(6);
	m.AddNode(15);
	m.AddNode(36);

	//p.LevelOrder(p.root);

	
	if(m.FullBinary(m.root))
	{
		cout<<"\nFull Binary\n";
	}
	else
	{
		cout<<"\nNot full binary\n";
	}

	return 0;

	//InOrder Printing
	t.InOrder(t.root);

	cout<<endl;

	//PreOrder Printing
	t.PreOrder(t.root);

	cout<<endl;

	//Post Order Printing
	t.PostOrder(t.root);

	cout<<endl;


	if(t.Identical(t.root,p.root))
	{
		cout<<"Identical"<<endl;
	}
	else
	{
		cout<<"Not identical"<<endl;
	}

	
	cout<<"Maximum depth::"<<t.MaximumDepth(t.root)<<endl;

	
	t.PreOrder(t.root);
	cout<<endl;
	cout<<"\nMirroring preorder traversal only::\n";
	t.MirrorTreePreorderPrint(t.root);
	

	cout<<"\nMirroring tree::\n";

	Tree d;
	node * newroot = t.DuplicateTree(t.root,d.root);

	d.PreOrder(newroot);


	//Do a pre-order traversal and store nodes in  auxiliary storage
	//Then run a for loop and create tree by reversing conditions for adding node in BST
	//i.e. if node is greater insert in left else right

	//Storing in array
	cout<<"\nStoring array\n";
	t.PreOrderStore(t.root);

	Tree mirror;
	//Printing array
	cout<<"\nPrinting Array"<<endl;
	for(int i=0;i<t.nCount;i++)
		cout<<t.nArray[i]<<" ";
	for(int i=0;i<t.nCount;i++)
		mirror.AddMirroredNode(t.nArray[i]);

	//Printing mirror tree
	cout<<"\nPrinting mirror tree::\n";
	mirror.PreOrder(mirror.root);

	//Printing Pre-order traversal
	cout<<"\nPre-Order traversal::\n";
	t.PreOrder(t.root);
	//Existing tree modified
	cout<<"\nMirrored (Existing tree modified) traversal::\n";
	t.MirrorExisting(t.root);
	t.PreOrder(t.root);

/*
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	s.printstack();

	cout<<"--"<<endl;
	cout<<s.pop()<<endl;
	cout<<"--"<<endl;
	cout<<s.pop()<<endl;
	cout<<"--"<<endl;
	s.printstack();

*/
	
/*
	t.q.Add(10);
	t.q.Add(20);
	t.q.Add(30);
	t.q.Add(40);

	t.q.printq();

	t.q.DeleteFront();

	cout<<"\n----\n";

	t.q.printq();

	t.q.DeleteFront();
	t.q.DeleteFront();
	t.q.DeleteFront();
	t.q.DeleteFront();

	cout<<"\n----\n";
	t.q.printq();

*/
	//cout<<"\n-----------------\n";
	//t.q.Add(t.root);
	//t.BreadthFirstSearch(t.root);

	t.CountLeaf(t.root);
	cout<<"\nLeaf Nodes::"<<t.leafcount<<endl;

	
	cout<<"\nPreOrder Tree\n";
	t.PreOrder(t.root);

	cout<<"\nDouble Tree\n";
	t.DoubleTree(t.root);

	t.PreOrder(t.root);

	cout<<"\nDouble Tree\n";
	t.PostOrder(t.root);

	//t.Inorder(t.root);
	

	cout<<"\n-------\n";

	Tree n;
	n.AddNode(10);
	n.AddNode(5);
	n.AddNode(20);
	n.AddNode(3);
	n.AddNode(6);
	n.AddNode(15);
	n.AddNode(36);

	cout<<"\n---------Sum Tree----------\n";
	int number = n.SumTree(n.root);


	/*
	if(n.CompleteBinary(n.root))
	{
		cout<<"Complete Binary\n";
	}
	else
	{
		cout<<"Not Complete Binary\n";
		
	}
	*/
	return 0;
}
