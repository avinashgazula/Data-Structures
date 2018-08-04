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
	while(1)
	{
		while(t!=NULL)
		{
			push(s,t);
			
			t=t->lchild;
		}
		if(s.top==-1)
		break;
		t=pop(s);
		cout<<t->data<<endl;
		t=t->rchild;		
	}

	
}


int main(){
	bstptr h;
	stack s;
	s.top=-1;
	s.size=30;
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
	print(h,h,s);
}

