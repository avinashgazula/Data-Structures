#include<iostream>
#include<cstring>
using namespace std;
struct info
{
	int freq;
	char alph;
};
typedef
struct node
{
	node* lchild;
	struct info data;
	node* rchild;
}*nptr;
nptr min(nptr s[],int n)
{
	nptr min;
	min=s[0];
	for(int i=1;i<n;i++)
	{
		if(s[i]->data.freq<min->data.freq)
		{
			min=s[i];
		}
	}
	int i;
	for(i=0;i<n;i++)
	{
		if(min->data.freq==s[i]->data.freq&&min->data.alph==s[i]->data.alph)
		{
			break;
		}
	}
	for(int k=i;k<n-1;k++)
	{
		s[i]=s[i+1];
	}
	return min;
}
void inorder(nptr h)
{
	if(h!=NULL)
	{
		inorder(h->lchild);
		cout<<h->data.alph<<" ";
		inorder(h->rchild);
	}
}
int main()
{
	nptr s[26];
	int n;
	cout<<"enter  number of alphabets ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		s[i]=NULL;
	}
	for(int i=0;i<n;i++)
	{
		s[i]=new node;
		cout<<"enter alphabet ";
		cin>>s[i]->data.alph;
		cout<<"enter its freq ";
		cin>>s[i]->data.freq;
		s[i]->lchild=NULL;
		s[i]->rchild=NULL;
	}
	nptr m1,m2;
	nptr root;
	root=NULL;
	while(n!=1)
	{
		m1=min(s,n);
		n--;
		m2=min(s,n);
		root=new node;
		root->data.alph='*';
		root->data.freq=m1->data.freq+m2->data.freq;
		root->lchild=m1;
		root->rchild=m2;
		s[n-1]=root;
	}
	inorder(root);
	char in[30];
	root=s[0];
	nptr h=root;
	cout<<"enter input ";
	cin>>in;
	int c=0;
	while(c!=-1)
	{
		int len=strlen(in);
		int i=0;
		while(i<=len)
		{
		
			if(in[i]=='1')
			{
				h=h->rchild;
				i++;
			}
			else
			{
				h=h->lchild;
				i++;
			}
			if(h->lchild==NULL&&h->rchild==NULL)
			{
				cout<<h->data.alph<<" ";
				h=root;
				i++;
			}
	    }
	    cout<<"enter in ";
	    cin>>in;
    }
	return 0;
}
