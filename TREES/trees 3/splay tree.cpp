#include<iostream>
using namespace std;
typedef
struct bstnode{
	struct bstnode *lchild;
	int data;
	struct bstnode *rchild;
}* bstptr;

void create(bstptr &t,int a)
{
	if(t==NULL)
	{
		t=new bstnode;
		t->data=a;
		t->lchild=NULL;
		t->rchild=NULL;
	}
	else
	{
		if(a<t->data)
		create(t->lchild,a);
		else
		create(t->rchild,a);
	}
}
bstptr searchk1(bstptr t,int &a)
{
	if(t==NULL)
	return t;
	else
	{
		if(t->data==a)
		return t;
		else
		{
			bstptr x=NULL;
			if(a>t->data)
			{
				x=searchk1(t->rchild,a);
			}
			else
			x=searchk1(t->lchild,a);
			if(x!=NULL)
			return x;
		}
	}
}
bstptr parent(bstptr &t,int a)
{
	if(t==NULL)
	return t;
	else
	{
		if(t->lchild!=NULL&&t->rchild!=NULL)
		{
			if(t->lchild->data==a||t->rchild->data==a)
			{
				return t;
			}
			else
			{
				if(a<t->data)
				return parent(t->lchild,a);
				if(a>t->data)
				return parent(t->rchild,a);
			}
		}
		else if(t->lchild!=NULL&&t->rchild==NULL)
		{
			if(t->lchild->data==a)
			{
				return t;
			}
			else
			{
				return parent(t->lchild,a);
			}
		}
		else
		if(t->rchild!=NULL&&t->lchild==NULL)
		{
			if(t->rchild->data==a)
			{
				return t;
			}
			else
			{
				return parent(t->rchild,a);
			}
		}
		
	}
}
bstptr searchk2(bstptr &t,int a)
{
	if(t==NULL)
	return t;
	else
	{
		
		if(t->lchild!=NULL&&t->rchild!=NULL)
		{
			if(t->lchild->data==a||t->rchild->data==a)
			{
				return t;
			}
			else
			{
				bstptr x=NULL;
				if(a<t->data)
				x=searchk2(t->lchild,a);
				if(a>t->data)
				x=searchk2(t->rchild,a);
				if(x!=NULL)
				return x;
			}
		}
		else
		if(t->lchild!=NULL&&t->rchild==NULL)
		{
			if(t->lchild->data==a)
			{
				return t;
			}
			else
			{
				bstptr x=NULL;
				
				x=searchk2(t->lchild,a);
				
				if(x!=NULL)
				return x;
			}
		}
		else
		if(t->rchild!=NULL&&t->lchild==NULL)
		{
			if(t->rchild->data==a)
			{
				return t;
			}
			else
			{
				bstptr x=NULL;
				x=searchk2(t->rchild,a);
				if(x!=NULL)
				return x;
			}
		}
		
	}
}
void singleright(bstptr &k1,bstptr &k2)
{
	k2->lchild=k1->rchild;
	k1->rchild=k2;
}
void singleleft(bstptr &k1,bstptr &k2)
{
	k2->rchild=k1->lchild;
	k1->lchild=k2;
}
void lzigzag(bstptr &h,bstptr &k1,bstptr &k2,bstptr &k3)
{
	
	bstptr k4=searchk2(h,k3->data);
	int a;
	if(k3!=h)
	{
		if(k3==k4->lchild)
		a=-1;
		if(k3==k4->rchild)
		a==1;
	}
	k2->rchild=k1->lchild;
	k3->lchild=k1->rchild;
	k1->lchild=k2;
	k1->rchild=k3;
	if(k3!=h)
	{
		if(a==-1)
		k4->lchild=k1;
		if(a==1)
		k4->rchild=k1;
	}
}
void rzigzag(bstptr &h,bstptr &k1,bstptr &k2,bstptr &k3)
{
	
	bstptr k4=searchk2(h,k3->data);
	int a;
	if(k3!=h)
	{
		if(k3==k4->lchild)
		a=-1;
		if(k3==k4->rchild)
		a==1;
	}
	k3->rchild=k1->lchild;
	k2->lchild=k1->rchild;
	k1->lchild=k3;
	k1->rchild=k2;
	if(k3!=h)
	{
		if(a==-1)
		k4->lchild=k1;
		if(a==1)
		k4->rchild=k1;
	}
}
void splay(bstptr &h,int a)
{
	bstptr t=h;
	bstptr k1=searchk1(t,a);
	bstptr k2=searchk2(t,k1->data);
	if(k2==h&&k1==k2->lchild)
	singleright(k1,k2);
	if(k2==h&&k1==k2->rchild)
	singleleft(k1,k2);
	bstptr k3=searchk2(t,k2->data);
	if(k2==k3->rchild&&k1==k2->rchild)
//	lzigzig(h,k1,k2,k3);
	if(k2==k3->lchild&&k1==k2->lchild)
//	rzigzig(h,k1,k2,k3);
	if(k2==k3->lchild&&k1==k2->rchild)
	lzigzag(h,k1,k2,k3);
	if(k2==k3->rchild&&k1==k2->lchild)
	rzigzag(h,k1,k2,k3);
}

void print(bstptr &t)
{
	if(t==NULL)
	return;
	else;
	cout<<t->data<<" ";
	print(t->lchild);
	print(t->rchild);
}

int main()
{
	bstptr t;
	t=NULL;
	int a;
	cout<<"Enter data or -1 to quit\n";
	cin>>a;
	while(a!=-1)
	{
		create(t,a);
		cout<<"Enter data or -1 to quit\n";
		cin>>a;
	}
	print(t);
	
	cout<<endl<<"Enter the data to be splayed\n";
	int k;
	cin>>k;
/*	while(t->data!=k)
	{
		splay(t,k);
	} */
	bstptr temp1=searchk1(t,k),temp2=parent(t,k);
	cout<<"k1"<<temp1->data<<" k2 "<<temp2->data;
	
	
	
}
