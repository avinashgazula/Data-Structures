#include<iostream>
using namespace std;
typedef struct node{
	int data;
	struct node *lc;
	struct node *rc;
}* tptr;
int fib(int n)
{
	if(n==0||n==1)
	return 1;
	else return fib(n-1)+fib(n-2);
}
void create(tptr &t,int n)
{
	if(t==NULL)
	{
		t=new node;
		t->data=fib(n);
		t->lc=NULL;
		t->rc=NULL;
		if(n>=2)
		{
			create(t->lc,n-1);
			create(t->rc,n-2);
		}
	}
}
void print(tptr t)
{
	if(t==NULL)
	return;
	else
	{
		cout<<t->data<<" ";
		print(t->lc);
		print(t->rc);
	}
}
int main()
{
	int n;tptr t=NULL;
	cout<<"Enter the fibonacci no ";
	cin>>n;
	create(t,n);
	print(t);
}
