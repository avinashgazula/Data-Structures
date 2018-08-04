#include<iostream>
using namespace std;
typedef struct treap{
	struct treap *lchild;
	int k;
	int p;
	struct treap *rchild;
}* tptr;
void print(tptr &t)
{
	if(t==NULL)
	return;
	else
	{
		cout<<t->k<<" "<<t->p<<endl;
		if(t->lchild!=NULL)
		print(t->lchild);
		if(t->rchild!=NULL)
		print(t->rchild);
	}
}
tptr search(tptr t,int &a)
{
	if(t==NULL)
	return t;
	else
	{
		if(t->k==a)
		return t;
		else
		{
			if(a>t->k)
			return search(t->rchild,a);
			else
			return search(t->lchild,a);
		}
	}
}
tptr parent(tptr &t,int a)
{
	if(t==NULL||t->k==a)
	return NULL;
	
	else
	{
		if(t->lchild!=NULL&&t->rchild!=NULL)
		{
			if(t->lchild->k==a||t->rchild->k==a)
			{
				return t;
			}
			else
			{
				if(a<t->k)
				return parent(t->lchild,a);
				if(a>t->k)
				return parent(t->rchild,a);
			}
		}
		else if(t->lchild!=NULL&&t->rchild==NULL)
		{
			if(t->lchild->k==a)
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
			if(t->rchild->k==a)
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
void single_right(tptr &t,tptr &temp)
{
	tptr p1=parent(t,temp->k);
	tptr p2=parent(t,p1->k);
	if(p2!=NULL&&p1==p2->lchild)
	{
		tptr x=NULL;
		if(temp->rchild!=NULL)
		x=temp->rchild;
		p2->lchild=temp;
		temp->rchild=p1;
		p1->lchild=x;
	}
	else if(p2!=NULL&&p1==p2->rchild)
	{
		tptr x=NULL;
		if(temp->rchild!=NULL)
		temp->rchild=x;
		p2->rchild=temp;
		temp->rchild=p1;
		p1->lchild=x;
	}
	else if(p1!=NULL)
	{
		tptr x=NULL;
		if(temp->rchild!=NULL)
		x=temp->rchild;
		temp->rchild=p1;
		p1->lchild=x;
		t=temp;
	}
}
void single_left(tptr &t,tptr &temp)
{
	tptr p1=parent(t,temp->k);
	tptr p2=parent(t,p1->k);
	if(p2!=NULL&&p1==p2->lchild)
	{
		tptr x=NULL;
		if(temp->lchild!=NULL)
		x=temp->lchild;
		p2->lchild=temp;
		temp->lchild=p1;
		p1->rchild=x;
	}
	else if(p2!=NULL&&p1==p2->rchild)
	{
		tptr x=NULL;
		if(temp->lchild!=NULL)
		x=temp->lchild;
		p2->rchild=temp;
		temp->lchild=p1;
		p1->rchild=x;
	}
	else if(p1!=NULL)
	{
		tptr x=NULL;
		if(temp->lchild!=NULL)
		x=temp->lchild;
		temp->lchild=p1;
		p1->rchild=x;
		t=temp;
	}
}
void check(tptr &t,tptr &t1)
{
	tptr p1=parent(t,t1->k);
	if(p1!=NULL&&p1->p>t1->p&&t1==p1->lchild)
	{
		single_right(t,t1);
	}
	else if(p1!=NULL&&p1->p>t1->p&&t1==p1->rchild)
	{
		single_left(t,t1);
	}
	tptr p2=parent(t,t1->k);
	if(p2!=NULL&&p2->p>t1->p)
	check(t,t1);
	else
	{
		cout<<endl;
		print(t);
		cout<<endl;
	}
	
}
void insert(tptr &h,tptr &t,int key,int pri)
{
	if(t==NULL)
	{
		t=new treap;
		t->k=key;
		t->p=pri;
		t->lchild=NULL;
		t->rchild=NULL;
		tptr temp=t;
		tptr p1=parent(h,temp->k);
		if(p1!=NULL&&p1->p>temp->p)
		check(h,temp);
	}
	else if(key<t->k)
	insert(h,t->lchild,key,pri);
	else
	insert(h,t->rchild,key,pri);
}
void del(tptr &h,int &key)
{
	tptr t=search(h,key);
	if(t==NULL)
	cout<<"key not found\n";
	else
	{
		if(t->rchild!=NULL&&t->lchild!=NULL)
		{
			if(t->rchild->p<t->lchild->p)
			{
				
				single_left(h,t->rchild);
				if(t==h)
				h=t->rchild;
				del(h,key);
			}
			else if(t->rchild->p>t->lchild->p)
			{
				single_right(h,t->lchild);
				if(t==h)
				h=t->lchild;
				del(h,key);
			}
		}
		else if(t->rchild==NULL&&t->lchild!=NULL)
		{
			single_right(h,t->lchild);
			if(t==h)
			h=t->lchild;
			del(h,key);
		}
		else if(t->lchild==NULL&&t->rchild!=NULL)
		{
			single_left(h,t->rchild);
			if(t==h)
			h=t->lchild;
			del(h,key);
		}
		else if(t->lchild==NULL&&t->rchild==NULL)
		{
			tptr y=parent(h,key);
			if(y!=NULL)
			{
				if(t==y->lchild)
				y->lchild=NULL;
				else if(t==y->rchild)
				y->rchild=NULL;
			}
		}
	}
}
int main()
{
	tptr t=NULL;
	tptr h=NULL;
	int k,p;
	cout<<"Enter data(key and priority) or -1 to quit\n";
	cin>>k>>p;
	insert(h,t,k,p);
	h=t;
	cout<<"Enter data(key and priority) or -1 to quit\n";
	cin>>k>>p;
	while(k!=-1||p!=-1)
	{
		insert(h,t,k,p);
		cout<<"Enter data or -1 to quit\n";
		cin>>k>>p;
	}
	print(h);
	cout<<endl<<"Enter key to delete\n";
	cin>>k;
	while(k!=-1||p!=-1)
	{
		del(h,k);
		print(h);
		cout<<endl<<"Enter key to delete\n";
		cin>>k; 
	}
}
