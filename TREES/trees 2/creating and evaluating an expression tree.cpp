#include<iostream>
#include<cstring>
using namespace std;

typedef struct btnode{
	int tag;
	union u1{
		int opnd;
		struct st{
			struct btnode *lchild;
			char optr;
			struct btnode *rchild;
		}s;
		
	}data;
}* btptr;

struct stack{
	int top;
	int size;
	btptr elem[50];
};

void push(stack &s,btptr t)
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
			return b-a;
		case '*':
			return a*b;
		case '/':
			return b/a;
	}
}

bool isopnd(char ch){
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

btptr create()
{
	btptr t=NULL;
	stack s;
	s.top=-1;
	s.size=30;
	char p[30];
	cout<<"Enter the postfix expression\n";
	cin>>p;
	int len=strlen(p);
	int i;
	for(i=0;i<len;i++)
	{
		if(isopnd(p[i]))
		{
			t= new btnode;
			t->tag=0;
			t->data.opnd=p[i]-'0';
			push(s,t);
		}
		else
		{
			btptr o1=pop(s);
			btptr o2=pop(s);
			t=new btnode;
			t->tag=1;
			t->data.s.optr=p[i];
			t->data.s.lchild=o1;
			t->data.s.rchild=o2;
			push(s,t);
			
		}
	}
	btptr h=pop(s);
	return h;
}


int eval(btptr &t)
{
	if(t->tag==0)
	{
		return t->data.opnd;
	}
	else
	{
		
		int a=eval(t->data.s.lchild);
		int b=eval(t->data.s.rchild);
		return op(a,b,t->data.s.optr);
	}
}

void print(btptr t)
{
	if(t==NULL)
	return;
	
	if(t->tag==0)
	{
		cout<<t->data.opnd;
		
	}
	else
	{
		cout<<t->data.s.optr;
		print(t->data.s.lchild);
		print(t->data.s.rchild);
	}
}

int main()
{
	btptr t=NULL;
	t=create();
	cout<<"hello ";
//	print(t);
	cout<<"Value is "<<eval(t);
}
