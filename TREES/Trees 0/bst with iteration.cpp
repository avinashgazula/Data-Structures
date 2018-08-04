#include<iostream>
using namespace std;

typedef
struct bstnode{
	struct bstnode *lchild;
	int data;
	struct bstnode *rchild;
}* bstptr;

void insert(bstptr &t,int k)
{
	if(t==NULL)
	{
		t=new bstnode;
		t->data=k;
		t->lchild=NULL;
		t->rchild=NULL;
	}
	else
	{
		if(t->data>k)
		{
			t=t->lchild;
		}
		else
		{
			t=t->rchild;
		}
		t=new bstnode;
		t->data=k;
		t->lchild=NULL;
		t->rchild=NULL;
	}
}

void print(bstptr h)
{
	if(h==NULL)
	{
		return;
	}
	else
	{
		cout<<h->data<<" ";
		if(h->lchild!=NULL)
		cout<<"\nLeft child of "<<h->data<<endl;
		print(h->lchild);
		if(h->rchild!=NULL)
		cout<<"\nRight child of "<<h->data<<endl;
		print(h->rchild);
	}
}

int main()
{
	bstptr t;
	t=NULL;
	int n;
	cout<<"Enter data or -1 to quit\n";
	cin>>n;
	while(n!=-1)
	{
		insert(t,n);
		cout<<"Enter data or -1 to quit\n";
		cin>>n;
	}
	
	print(t);
}
