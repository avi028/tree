#include <iostream>
#include <queue>
#include <map>
#include <utility>
#include <climits>
#include <stack>
#include <stdlib.h>
#include <stdio.h>

#define ll long long int 
#define er(X) cout<<"error"<<X
#define mp(X,Y) make_pair(X,Y)

using namespace std;

	struct node
	{
		int data;
		struct node *left;
		struct node *right;
	};
	struct  node * head;


	int height(struct node * head )
	{
		if(head==NULL)
			return 0;
		else
		{
			int ldepth=height(head->left)+1;
			int rdepth=height(head->right)+1;
			return ldepth>rdepth?ldepth:rdepth;
		}
	}

	struct node * newNode(int data)
	{
		struct node * n=(struct node *)malloc(sizeof(struct node));
		n->data=data;
		n->left=NULL;
		n->right=NULL;
		return n;

	}

	void traverse(struct node* n)
	{
		if(n!=NULL){
			if(n->left!=NULL)
				traverse(n->left);
			cout<<n->data<<" ";
			if(n->right!=NULL)
				traverse(n->right);	
		}
	}

	void addNode(int data,struct node * head)
	{
		 if(head->data > data)
			{
				if(head->left==NULL)
					head->left=newNode(data);
				else
					addNode(data , head->left);
			}
		else if(head->data < data)
		{
			if(head->right==NULL)
				head->right=newNode(data);
			else
				addNode(data,head->right);
		}
	}


	int main()
	{
		int a[] = {2,6,5,4,7,8,13,34,1,0};
		int n =	10;
		head=NULL;
		for(int i=0;i<n;i++)
		{
			if(head==NULL)
				head=newNode(a[i]);
			else
				addNode(a[i],head);
		}	
		traverse(head);
		cout<<"\nHeight -> "<<height(head);
		return 0;
	}