#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

typedef struct node {

	int key;
	int value;
	struct node * next;
};

node* getnode()
{
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->next=NULL;
	temp->key=0;
	temp->value=0;
	return temp;
}

void create_node(node *p,int value)
{
	node *temp;
	while( p->next !=NULL)
	{
		p=p->next;
	}
	temp=getnode();
	p->next=temp;
	temp->key=value;
	
}

node* reverse(node *p)
{
	node *prev,*temp;
	prev=NULL;
	while(p !=NULL)
	{
		temp=p;
		p=p->next;
		temp->next=prev;
		prev=temp;
	}

	return prev;
}

node* reverse(node *p, int k, int m)
{
	node *start, *end,*prev,*temp,*X;
	int i,j,a,b,c;
	int flag=0;
	start=p;
	prev=NULL;
	while(p!=NULL)
	{	i=k;j=m;start=p;
		while( p!=NULL && i>0)
		{
			temp=p;
			p=p->next;
			temp->next=prev;
			prev=temp;i--;
		}

		if(end !=NULL)
			end->next=prev;
		if (flag==0)
		{
			X=prev;
			flag=1;
		}	
		if(p==NULL)
			return X;
		start->next=p;
		while(p !=NULL && j>0)
		{	temp=p;
			p=p->next;j--;
		}
		end=temp;
		temp->next=NULL;
		prev=NULL;
		if(p==NULL)
			return X;

	
	}

	return X;

}

void print(node *p)
{
	cout<<"\n";
	while (p->next !=NULL)
	{
		cout<<p->key<<"->";p=p->next;	
	}
}


int main()
{
	node *pt;
	pt=getnode();
	for(int i=1;i<=20;i++)
	{
		create_node(pt,i);	
	}
	print(pt);
	pt=reverse(pt,3,2);
	print(pt);

	return 0;
}
