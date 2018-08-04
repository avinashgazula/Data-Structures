#include<iostream>
using namespace std;
typedef struct node{
	struct node *lc;
	int data;
	struct node *rc;
}* tptr;
void create(tptr &t,int a)
{
	if(t==NULL)
	{
		t=new node;
		t->data=a;
		t->lc=NULL;
		t->rc=NULL;
	}
	int l,r;
	cout<<"Enter data left of "<<a<<" : ";
	cin>>l;
	if(l!=-1)
	create(t->lc,l);
	cout<<"Enter data right of "<<a<<" : ";
	cin>>r;
	if(r!=-1)
	create(t->rc,r);
}
void inorder(tptr t)
{
	if(t==NULL)
	return;
	inorder(t->lc);
	cout<<t->data<<" ";
	inorder(t->rc);
}
void AllPaths(tptr &t,int a[],int count)
{
	if(t==NULL)
	return;
	if(t!=NULL)
	a[count++]=t->data;
	if(t->lc==NULL&&t->rc==NULL)
	{
		for(int i=0;i<count;i++)
		cout<<a[i]<<" ";
		cout<<endl;
	}
	else
	{
		AllPaths(t->lc,a,count);
		AllPaths(t->rc,a,count);
	}
	
}
int main()
{
	tptr t=NULL;
	int k,a[30],count=0;
	cout<<"Enter root node : ";
	cin>>k;
	create(t,k);
	inorder(t);
	cout<<endl;
	AllPaths(t,a,count);
}
