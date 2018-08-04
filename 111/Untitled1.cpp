#include<iostream>
using namespace std;
typedef
struct node{
	int data;
	struct node *lchild;
	struct node *rchild;
}* bstptr;
bstptr search(bstptr &t,int a)
{
	if(t==NULL)
	return NULL;
	if(t->data==a)
	return t;
	else if(t->data>a)
	return search(t->lchild,a);
	else
	return search(t->rchild,a);
}
bstptr parent(bstptr &h,bstptr &t,int a)
{
	if(t==NULL||h->data==a||(t->lchild==NULL&&t->rchild==NULL))
	return NULL;
	if(t->lchild!=NULL&&t->rchild!=NULL&&(t->lchild->data==a||t->rchild->data==a))
	return t;
	else if(t->rchild==NULL&&t->lchild!=NULL&&t->lchild->data==a)
	return t;
	else if(t->lchild==NULL&&t->rchild!=NULL&&t->rchild->data==a)
	return t;
	else if(t->data>a)
	return parent(h,t->lchild,a);
	else
	return parent(h,t->rchild,a);
	
}
void insert(bstptr &t,int a)
{
	if(t==NULL)
	{
		t=new node;
		t->data=a;
		t->lchild=NULL;
		t->rchild=NULL;
	}
	else if(t->data>a)
	insert(t->lchild,a);
	else
	insert(t->rchild,a);
}
void del(bstptr &h,bstptr &t,int a)
{
	if(t->lchild==NULL&&t->rchild==NULL&&t->data==a)
	{
		bstptr p=parent(t);
		if(p->lchild==t)
		p->lchild=NULL;
		if(p->rchild==t)
		p->rchild=NULL;
	}
	else if(t->)
}
void print(bstptr &t)
{
	cout<<t->data<<" ";
	if(t->lchild!=NULL)
	print(t->lchild);
	if(t->rchild!=NULL)
	print(t->rchild);
}
int main()
{
	int n;
	bstptr t=NULL;
	cout<<"Enter data\n";
	cin>>n;
	while(n!=-1)
	{
		insert(t,n);
		cout<<"Enter data\n";
		cin>>n;
	}
	print(t);
}
