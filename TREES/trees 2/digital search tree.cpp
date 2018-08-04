#include<iostream>
using namespace std;

typedef struct bstnode{
	int data;
	struct bstnode *lchild;
	struct bstnode *rchild;
}* bstptr;

int check(int a1,int b1)
{
	int a[4],b[4];
	for(int i=0;i<4;i++)
	{
		a[i]=a1%10;
		a1=a1/10;
		b[i]=b1%10;
		b1=b1/10;
	}
	for(int j=3;j>=0;j--)
	{
		if(a[j]>b[j])
		return 1;
		if(a[j]<b[j])
		return 0;
	}
}

void insert(bstptr &h,int k)
{
	if(h==NULL)
	{
		h=new bstnode;
		h->data=k;
		h->lchild=NULL;
		h->rchild=NULL;
	}
	else
	{
		if(check(k,h->data)==1)
		{
			insert(h->rchild,k);
		
		}
		else
		{
			insert(h->lchild,k);
		}
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

int main(){
	bstptr h;
	h=NULL;
	cout<<"Enter data or -1 to quit\n";
	int n;
	cin>>n;
	while(n!=-1)
	{
		insert(h,n);
		cout<<"Enter data or -1 to quit\n";
		cin>>n;
	}
	print(h);
}


