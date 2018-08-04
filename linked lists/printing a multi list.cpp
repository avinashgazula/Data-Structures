#include<iostream>
using namespace std;
typedef
struct node
{
	int tag;
	union u1
	{
		char ch;
		node* ptr;
	}data;
	node* next;
}*mptr;
mptr create();
void addend(mptr &m,int t);
void print(mptr &m);
int main()
{
	mptr m;
	m=create();
	cout<<"(";
	print(m);
	cout<<")";
	return 0;
}

mptr create()
{
	mptr m;
	m=NULL;
	int tg;
	char ch1;
	cout<<"0:char  1:ptr  2:exit  ";
	cin>>tg;
	if(tg==2)
	{
		return m;
	}
	if(tg==0)
	{
		m=new node;
		m->next=NULL;
		cout<<"enter character ";
		cin>>ch1;
		m->data.ch=ch1;
		m->tag=tg;
	}
	if(tg==1)
	{
		m=new node;
		m->tag=tg;
		m->next=NULL;
		cout<<"enter details of child list "<<endl;
		m->data.ptr=create();
	}
	cout<<"0:char  1:ptr  2:exit";
	cin>>tg;
	while(1)
	{
		if(tg==2)
		{
			break;
		}
		else
		{
			addend(m,tg);
		}
		cout<<"0:char  1:ptr  2:exit";
		cin>>tg;
	}
	return m;
}
void addend(mptr &m,int t)
{
	mptr temp=m;
	char d;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=new node;
	temp=temp->next;
	temp->next=NULL;
	temp->tag=t;
	if(t==0)
	{
		cout<<"enter a character  ";
		cin>>d;
		temp->data.ch=d;
	}
	if(t==1)
	{
		cout<<"enter details in child list "<<endl;
		temp->data.ptr=create();
	}
}
void print(mptr &m)
{
	mptr temp;
	temp=m;
	while(m!=NULL&&m->tag==0)
	{
		cout<<m->data.ch<<"  ";
		m=m->next;
	}
	if(m!=NULL)
	{
		if(m->tag==1)
		{
			cout<<"(";
		print(m->data.ptr);
		cout<<")";
		}
		if(m->next!=NULL)
		print(m->next);
	}
}
