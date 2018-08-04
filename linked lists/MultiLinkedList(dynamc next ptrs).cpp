#include<iostream>
using namespace std;
typedef
struct node{
	int data;
	int count;
	struct node **next;
}* mptr;
void create(mptr &t)
{
	if(t==NULL)
	{
		cout<<"Enter data\n";
		int a;
		cin>>a;
		t=new node;
		t->data=a;
	}
	cout<<"Enter the no of next pointers "<<t->data<<" has\n";
	cin>>t->count;
	t->next=new mptr[t->count];
	for(int i=0;i<t->count;i++)
	{
		t->next[i]=NULL;
	}
	for(int i=0;i<t->count;i++)
	{
		cout<<"current node : "<<t->data<<endl;
		create(t->next[i]);
	}
}
void print(mptr h)
{
	mptr t=h;
	if(t==NULL)
	return;
	cout<<t->data<<" ";
	for(int i=0;i<t->count;i++)
	print(h->next[i]);
} 
void AllPaths(mptr t,int a[],int count)
{
	if(t==NULL)
	return;
	else
	a[count++]=t->data;
	if(t->count==0)
	{
		for(int i=0;i<count;i++)
		cout<<a[i]<<" ";
		cout<<endl;
	}
	else
	{
		for(int i=0;i<t->count;i++)
		AllPaths(t->next[i],a,count);
	}
}
int main()
{
	mptr h=NULL;int a[30],count=0;
	create(h);
	print(h);
	cout<<endl;
	AllPaths(h,a,count);
}
