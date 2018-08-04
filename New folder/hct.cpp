#include<iostream>
using namespace std;
typedef
struct htnode{
	struct htnode *lchild;
	char data;
	int freq;
	struct htnode *rchild;
}* htptr;

void swap(int &a,int &b)
{
	int t=a;
	a=b;
	b=t;
}

void swap(char &a,char &b)
{
	char t=a;
	a=b;
	b=t;
}

void array(htptr t[],int a[],char b[],int &size,int &i)
{
	
	while(i!=size)
	{
		t[i]=new htnode;
		t[i]->data=b[i];
		t[i]->freq=a[i];
		t[i]->lchild=NULL;
		t[i]->rchild=NULL;
		i++;
		array(t,a,b,size,i);
	}
}


void addd(htptr &h,htptr t[],int &size,int &i)
{
	cout<<"fhfghhg\n";
	int x=h->freq;
	cout<<x<<endl;
	int j=0;
	while(t[j]->freq<x)
	{
		j++;
	}
	cout<<j<<endl;
	size=size+1;
	for(int k=size-1;k>j;k--)
	{
		t[k]=t[k-1];
	}
	t[j]=h;

	
	i=i+2;
}

void create(htptr &h,htptr t[],int &size,int &i)
{
	
	while(i<=size)
	{
		cout<<"test1\n";
		h=new htnode;
		
		h->lchild=t[i];
		cout<<"test4\n";
		h->rchild=t[i+1];
		cout<<"test5\n";
		h->data='*';
		cout<<h->lchild->freq;
		h->freq=h->lchild->freq+h->rchild->freq;
		
		
		cout<<"test2\n";
		addd(h,t,size,i);
		cout<<"test3\n";
		
	}
	
}

void print(htptr h)
{
	if(h==NULL)
	{
	
		return;
	}
	else
	{
		cout<<h->data<<" "<<h->freq<<endl;
		if(h->lchild!=NULL)
		cout<<"\nLeft child of "<<h->data<<" "<<h->freq<<endl;
		print(h->lchild);
		if(h->rchild!=NULL)
		cout<<"\nRight child of "<<h->data<<" "<<h->freq<<endl;
		print(h->rchild);
	}
}


int main()
{
	htptr t[20];
	for(int q=0;q<20;q++)
	t[q]=NULL;
	htptr h=NULL;
	int i,j,n=0;int k=0;
	int a[20];char b[20];
	cout<<"Enter the no of elements\n";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter data and freq\n";
		cin>>b[i];
		cin>>a[i];
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i]<a[j])
			{
				swap(a[i],a[j]);
				swap(b[i],b[j]);
			}
		}
	}
	array(t,a,b,n,k);
	cout<<t[0]->data;
/*	for(i=0;i<n;i++)
	cout<<t[i]->data<<" "<<t[i]->freq<<endl;*/
	cout<<"test\n";
	create(h,t,n,k);
	
	print(t[n-1]);
	
	
}
