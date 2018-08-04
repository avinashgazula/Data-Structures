#include<iostream>
using namespace std;
typedef
struct kdnode{
	struct kdnode *lchild;
	int d;
	int key[10];
	struct kdnode *rchild;
}* kdptr;

void create(kdptr &t,int a[],int n,int i)
{
	if(t==NULL)
	{
		t=new kdnode;
		t->d=n;
		for(int k=0;k<n;k++)
		{
			t->key[k]=a[k];
		}
		t->lchild=NULL;
		t->rchild=NULL;
	}
	else
	{
		int j=i;
		i++;
		if(t->key[j]>a[j])
		create(t->lchild,a,n,i%n);
		else
		create(t->rchild,a,n,i%n);
	}
}

void print(kdptr &t)
{
	if(t==NULL)
	return;
	else
	{
		int x=t->d;
		for(int i=0;i<x;i++)
		cout<<t->key[i]<<" ";
		cout<<endl;
		print(t->lchild);
		print(t->rchild);
	}
}
int main()
{
	kdptr t;
	t=NULL;
	int n;int k=0;
	int tag;
	cout<<"Enter the number of keys\n";
	cin>>n;
	cout<<"1.Enter data\t-1.Quit\n";
	cin>>tag;
	int a[n];
	while(tag!=-1)
	{
		for(int i=0;i<n;i++)
		{
			cout<<"Enter key "<<i+1<<endl;
			cin>>a[i];
		}
		create(t,a,n,k);
		cout<<"1.Enter data\t-1.Quit\n";
		cin>>tag;		
		
	}	
	print(t);
}
