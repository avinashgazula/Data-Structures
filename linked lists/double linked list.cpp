#include<iostream>
using namespace std;
typedef struct dnode {
	struct dnode *left;
	int data;
	struct dnode *right;
}* dptr;
void addbegin(dptr &h,int d)
{
	dptr t;
	t=h;
	t->left=new dnode;
	t->left->data=d;
	t->left->left=NULL;
	t->left->right=t;
	h=t->left;
}
void addend(dptr &h,int d)
{
	dptr t,l;
	l=h;
	while(l->right!=NULL)
	{
		l=l->right;
	}
	l->right=new dnode;
	l->right->data=d;
	l->right->right=NULL;
	l->right->left=l->right;
}
void addafter(dptr &h,int after,int d)
{
	if(h==NULL)
	addbegin(h,d);
	dptr t,t1=NULL,t2=NULL;
	t=h;
	t1=new dnode;
	t1->data=d;
	t1->left=NULL;t1->right=NULL;
	while(t->right!=NULL&&t->data!=after)
	{
		t=t->right;
	}
	t2=t->right;
	t2->left=NULL;
	if(t2==NULL)
	addend(h,d);
	else
	{
		t->right=t1;
		t1->left=t;
		t1->right=t2;
		t2->left=t1;
	}
}
int delend(dptr h)
{
	dptr t,t2;
	t=h;
	while(t->right->right!=NULL)
	{
		t=t->right;
	}
	t2=t->right;
	t->right=NULL;
	int x=t2->data;
	delete t2;
	return x;
}
int delbegin(dptr &h)
{
	dptr t;
	t=h;
	h=h->right;
	h->left=NULL;
	t->right=NULL;
	int x=t->data;
	delete t;
	return x;
}
void deldata(dptr &h,int &d)
{
	dptr t,t2;
	t=h;
	if(h->data==d)
	delbegin(h);
	else
	{
		while(t->right!=NULL&&t->right->data!=d)
			t=t->right;
		t2=t->right->right;
		if(t2==NULL)
			delend(h);
		else
		{
			t->right=t2;
			t2->left=t;
		}
	}
}
void print(dptr &d)
{
	dptr t;
	t=d;
	cout<<"The list is\n";
	while(t!=NULL)
	{	
		cout<<t->data<<endl;
		t=t->right;
	}
}
int main()
{
	dptr h;
	h=new dnode;
	int d;
	cout<<"Enter data or -1 to quit\n";
	cin>>d;
	h->data=d;
	h->left=NULL;
	h->right=NULL;
	cin>>d;
	while(d!=-1)
	{
		addend(h,d);
		cin>>d;
	}
	int x,y,z;
	cout<<"1.Addend 2.Addbegin 3.Addafter 4.Delbegin 5.Delend 6.Deldata or -1.Quit\n";
	cin>>x;
	while(x!=-1)
	{
		switch(x)
		{
			case 1:
				cout<<"Which number do you want to add at the end\n";
				cin>>y;
				addend(h,y);
				print(h);
				break;
			case 2:
				cout<<"Which number do you want to add at the beginning\n";
				cin>>y;
				addbegin(h,y);
				print(h);
				break;
			case 3:
				cout<<"Which number do you want to add and after which number\n";
				cin>>y>>z;
				addafter(h,z,y);
				print(h);
				break;
			case 4:
				cout<<"Deleting the first number\n";
				delbegin(h);
				print(h);
				break;
			case 5:
				cout<<"Deleting the last number\n";
				
				delend(h);
				print(h);
				break;
			case 6:
				cout<<"Which number do you want to delete\n";
				cin>>y;
				deldata(h,y);
				print(h);
				break;
		}
		cout<<"1.Addend 2.Addbegin 3.Addafter 4.Delbegin 5.Delend 6.Deldata or -1.Quit\n";
		cin>>x;
	}
}
