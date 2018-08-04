#include<iostream>
using namespace std;
typedef struct bstnode{
	int data;
	struct bstnode *lchild;
	struct bstnode *rchild;
}* bstptr;
struct stack{
	int top;
	int size;
	bstptr elements[30];
};
void push(stack &s,bstptr &t)
{
	if(s.top==s.size-1)
	{
		cout<<"Stack is full\n";
	}
	else
	{
		s.top++;
		s.elements[s.top]=t;
	}
}
bstptr pop(stack &s)
{
	if(s.top==-1)
	{
		cout<<"Stack is empty\n";
	}
	else
	return s.elements[s.top--];
}
void del(bstptr &h,bstptr &t)
{
	if(h==NULL)
	return;
	else
	{
		if(t==h->rchild)
		{
			h->rchild=NULL;
		}
		if(t==h->lchild)
		{
			h->lchild=NULL;
		}
		else 
		{
			del(h->lchild,t);
			del(h->rchild,t);
		}
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
void print(bstptr &h,bstptr &t,stack &s)
{
	while(t!=NULL&&s.top>=0)
	{
		push(s,t);
		if(t->rchild!=NULL)
		push(s,t->rchild);
		t=t->lchild;
		{
			while(t==NULL&&s.top!=-1)
			{
				t=pop(s);
				cout<<t->data<<endl;
				del(h,t);
				if(s.top!=-1)
				{
					t=pop(s);
					if(t->lchild==NULL&&t->rchild==NULL)
					{
						cout<<t->data<<endl;
						del(h,t);
						if(s.top!=-1)
						t=pop(s);
					}
				}
			}
		}
	}
	cout<<h->data<<" ";
}
int main()
{
	bstptr h;
	stack s;
	s.top=-1;
	s.size=30;
	h=NULL;
	bstptr b;
	cout<<"Enter data or -1 to quit\n";
	int n;
	cin>>n;
	while(n!=-1)
	{
		insert(h,n);
		cout<<"Enter data or -1 to quit\n";
		cin>>n;
	}
	b=h;
	push(s,h);
	if(h->rchild!=NULL)
	push(s,h->rchild);
	h=h->lchild;
	print(b,h,s);
}
