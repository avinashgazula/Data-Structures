#include<iostream>
using namespace std;

struct stack{
	int size;
	int top;
	int elements[50];
};

typedef struct bstnode{
	int data;
	struct bstnode *lchild;
	struct bstnode *rchild;
}* bstptr;

void push(struct stack &s,int data)
{
	if(s.top==s.size-1)
	{
		cout<<"Stack is full\n";
	}
	else
	{
		s.top++;
		s.elements[s.top]=data;
	}
}

int pop(struct stack &s)
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

void print(bstptr h,stack s)
{
	
	if(h==NULL)
	{
	
		return;
	}
	else
	{
		push(s,h->data);
		
		print(h->lchild,s);
		
		print(h->rchild,s);
	}
}

int main(){
	bstptr h;
	h=NULL;
	struct stack s;
	cout<<"Enter data or -1 to quit\n";
	int n;int i=0;
	cin>>n;
	while(n!=-1)
	{
		insert(h,n);
		cout<<"Enter data or -1 to quit\n";
		cin>>n;
		i++;
	}
	print(h,s);
	for(int j=0;j<i;j++)
	pop(s);
	
}


