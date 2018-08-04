#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

typedef struct btnode{
	int tag;
	union u1{
		int opnd;
		char optr;
	}data;
	struct btnode *lchild;
	struct btnode *rchild;
}* btptr;

struct stack{
	int top;
	int size;
	btptr elem[50];
};

void push(stack &s,btptr &t)
{
	
	if(s.top==s.size-1)
	{
		cout<<"Stack is full\n";
	}
	else
	{
		s.top++;
		s.elem[s.top]=t;
	}
}

btptr pop(stack &s)
{
	if(s.top==-1)
	{
		cout<<"Stack is empty\n";
	}
	else
	{
		return s.elem[s.top--];
	}
}

int op(int a,int b,char c)
{
	switch(c)
	{
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':
			return a/b;
	}
}

int isopnd(char ch){
	if(ch>='0'&&ch<='9')
	return 1;
	
	return 0;
}

int isoptr(char ch)
{
	if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
	return 1;
	
	return 0;
}

void createoptr(btptr &t,stack &s,int n)
{
	if(t==NULL)
	{
		t=new btnode;
		t->tag=n;
		cout<<"Enter character\n";
		if(n==0)
		{
			
		}
	}
	btptr o1=pop(s);
	btptr o2=pop(s);
	t=new btnode;
	t->tag=1;
	t->data.optr=n;
	t->rchild=o1;
	t->lchild=o2;
	push(s,t);
}

void createopnd(btptr &t,stack &s,int q)
{
	t=new btnode;
	t->tag=0;
	t->data.opnd=q;
	t->lchild=NULL;
	t->rchild=NULL;
	push(s,t);
}

int eval(btptr &t)
{
	if(t->lchild==NULL&&t->rchild==NULL)
	{
		return t->data.opnd;
	}
	else
	{
		int a=eval(t->lchild);
		int b=eval(t->rchild);
		return op(a,b,t->data.optr);
	}
}


int main()
{
	btptr t;
	int n;
	stack s;
	s.top=-1;
	s.size=30;
	char p='a';
	int q;
	cout<<"Enter the postfix expression character by character(1 & '-1' to quit)\n";
	cout<<"0.operator 1,operand 2.quit\n";
	cin>>n;

	while(n!=2)
	{
		if(n==0)
		{
			cout<<"Enter operator\n";
			cin>>n;
			createoptr(t,s,n);
		}
		
		if(n==1)
		{
			cout<<"Enter operand\n";
			cin>>p;
			createopnd(t,s,p);
		}
		createopnd(t,s,n);
		cout<<"Enter the postfix expression character by character(1 and '-1' to quit)\n";
		cout<<"0.operator 1,operand 2.quit\n";
		cin>>n;
	
	}
	cout<<"\nEvaluating the given postfix expression gives "<<eval(t);
}
