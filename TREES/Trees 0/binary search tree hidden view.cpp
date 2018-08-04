#include<iostream>
using namespace std;

typedef struct bstnode{
	int data;
	struct bstnode *lchild;
	struct bstnode *rchild;
}* bstptr;
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
		if(k<h->data)
		{
			insert(h->lchild,k);
		
		}
		if(k>h->data)
		{
			insert(h->rchild,k);
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
	//	cout<<"\nLeft child of "<<h->data<<endl;
		print(h->lchild);
		if(h->rchild!=NULL)
	//	cout<<"\nRight child of "<<h->data<<endl;
		print(h->rchild);
	}
}
void hiddenview(bstptr &h)
{
	bstptr l=h,r=h;
	while(l!=NULL)
	{
		if(l->rchild!=NULL&&l->lchild!=NULL)
		{
			l=l->lchild;
			print(l->rchild);
		}
		else
		break;
	}
	while(r!=NULL)
	{
		if(r->lchild!=NULL&&r->rchild!=NULL)
		{
			r=r->rchild;
			print(r->lchild);
		}
		else
		break;
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
	cout<<endl;
	hiddenview(h);
}


