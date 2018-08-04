#include<iostream>
#include<cstring>
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
	htptr h=NULL;int k=0;
	int i,j=0,n=0;int z=0;
	int sum=0;
	int a[20];char b[20];
	cout<<"Enter the no of elements\n";
	cin>>n;
	int size=n;
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
	for(i=0;i<n;i++)
	{
		sum=sum+a[i];
	}
	array(t,a,b,n,k);
	i=0;
	while(i<=size)
	{
		h=new htnode;
		h->lchild=t[i];
		h->rchild=t[i+1];
		h->data='*';
		h->freq=h->lchild->freq+h->rchild->freq;
		int x=h->freq;
		if(x==sum)
		{
			break;
		}
		j=0;
		while(t[j]->freq<x)
		{
		//	cout<<"Hello\n";
			j++;
			if(j>=n)
			break;
		}
		cout<<j<<endl;
		n=n+1;
		for(k=n-1;k>j;k--)
		{
			t[k]=t[k-1];
		}
		t[j]=h;
		i=i+2;
	}
	print(h);
	char in[30];
	cout<<"Enter input or - to quit\n";
	cin>>in;
	int len=strlen(in);
	i=0;
	htptr x=h;
	while(1)
	{
		while(i<=len)
		{
			if(x->lchild==NULL&&x->rchild==NULL)
			{
				cout<<x->data<<endl;
				x=h;
				if(i==len)
				i++;
			}
			else
			if(in[i]=='0')
			{
				x=x->lchild;
				i++;
			}
			else
			{
				x=x->rchild;
				i++;
			}
		}
		cout<<"Enter input\n";
		cin>>in;
		len=strlen(in);
		i=0;
		if(in[0]=='-')
		break;
	}
}
