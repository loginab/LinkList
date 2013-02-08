#include<map>
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
	node *temp=NULL;
	while( p->next !=NULL)
	{
		p=p->next;
	}
	temp=getnode();
	p->next=temp;
	temp->key=value;
	
}


void print(node *p)
{
	cout<<"\n";
	while (p->next !=NULL)
	{
		cout<<p->key<<"->";p=p->next;	
	}
	cout<<endl;
}

void loop(node *pt)
{

	map<node *, int> dupli;
	pair<map<node *,int>::iterator,bool>ret;
	int count =0;
	while (pt->next !=NULL)
	{


			ret=dupli.insert(make_pair(pt,pt->key));
		if(ret.second)
		{

		}
		else
		{
			cout<<"\n There is loop at key value "<<pt->next->key;
			break;
		}
		pt=pt->next;
	}
	
	cout<<"\n";
}


int main()
{
	node *pt=NULL,*temp;
	pt=getnode();
	pt->key=0;
	for(int i=1;i<=21;i++)
	{
		create_node(pt,i);	
	}
	print(pt);
	for (int i=1;i<=20;i++)
	{
		pt=pt->next;
		if(i==10)
			temp=pt;
	}
	pt->next=temp;
	
	loop(pt);

	return 0;
}
