#include<iostream>
using namespace std;

typedef struct btnode{
	struct btnode *lchild;
	int data;
	struct btnode *rchild;
}* btptr;

int between(int a,int b,int c)
{
	if(a>b)
	{
		if(c>b&&c<a)
		return 1;
	}
	if(b>a)
	{
		if(c>a&&c<b)
		return 1;
	}
	return 0;
}

/*btptr find(btptr &t,int k)
{
	btptr t1,t2;
	t1=NULL;
	t2=NULL;
	if(t==NULL)
	return;
	if(t->data==k)
	return t;
	else
	{
		t1=find(t->lchild,k);
		t2=find(t->rchild,k);
		if(t1!=NULL)
		return t1;
		if(t2!=NULL)
		return t2;
	}
}*/

int ht(btptr &t)
{
	if(t==NULL)
	return -1;
	else return max(ht(t->lchild),ht(t->rchild))+1;
}

btptr unbal(btptr &t)
{
	
	btptr t1,t2;
	t1=NULL;t2=NULL;
	if(t==NULL)
	return NULL;
	else
	{
		
		if(ht(t->lchild)-ht(t->rchild)>1||ht(t->rchild)-ht(t->lchild)>1)
		return t;
		else
		{
			while(t->lchild!=NULL)
			{
				t1=unbal(t->lchild);
				if(t1!=NULL)
				return t1;			
			}
			while(t->rchild!=NULL)
			{
				t2=unbal(t->rchild);
				if(t2!=NULL)
				return t2;			
			}
			
		}
	}
	return NULL;
	
}

void create(btptr &t,int k)
{
	btptr k1,k2,k3;
	k1=NULL;
	k2=NULL;
	k3=NULL;
	if(t==NULL)
	{
		t=new btnode;
		t->data=k;
		t->lchild=NULL;
		t->rchild=NULL;
	}
	else
	{
		if(k<t->data)
		create(t->lchild,k);
		else
		create(t->rchild,k);
	}
}

void leftrotate(btptr &k1,btptr &k2,btptr &k3)
{
	k1->rchild=k3->lchild;
	k3->lchild=k1;
}

void rightrotate(btptr &k1,btptr &k2,btptr &k3)
{
	k1->lchild=k3->rchild;
	k3->rchild=k1;
}

void doublerotate(btptr &k1,btptr &k2,btptr &k3)
{
	
}

void check(btptr &t,int k)
{
	if(t->data!=k)
	{
		cout<<"test\n";
		btptr t1=unbal(t);
		cout<<"test\n";
		btptr k1,k2,k3;
		
		if(t1!=NULL)
		{
			k1=t1;
			
			if(ht(k1->lchild)>ht(k1->rchild))
			k3=k1->lchild;
			if(ht(k1->lchild)<ht(k1->rchild))
			k3=k1->rchild;	

			if(ht(k3->lchild)>ht(k3->rchild))
			k2=k3->lchild;
			if(ht(k1->lchild)>ht(k1->rchild))
			k2=k3->lchild;								
		}
		if(between(k1->data,k2->data,k))
		doublerotate(k1,k2,k3);
		else
		{
			if(k3==k1->lchild&&k2==k3->lchild)
			rightrotate(k1,k2,k3);
			if(k3==k1->rchild&&k2==k3->rchild)
			leftrotate(k1,k2,k3);
		}
	}
}

void print(btptr h)
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

int main()
{
	btptr t;
	t=NULL;
	int n;
	cout<<"Enter data or -1 to quit\n";
	cin>>n;
	while(n!=-1)
	{
		create(t,n);
		
		check(t,n);
		cout<<"Enter data or -1 to quit\n";
		cin>>n;
	}
}


