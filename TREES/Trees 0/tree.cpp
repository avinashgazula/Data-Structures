#include<iostream>
using namespace std;

struct node {
	int data;
	struct node *n1;
	struct node *n2;
	struct node *n3;
	
}* mptr;

struct stack
{
  int element[6];
  int size;
  int top;	
};
void push(struct stack &s,int x)
{
	if(s.size-1==s.top)
	{
		cout<<"stack is full"<<endl;
	}
	else
	{
	  s.top++;
	  s.element[s.top]=x;	
	}	
}

int pop(struct stack &s)
{
	if(s.top==-1)
	{
	  cout<<"stack is empty"<<endl;
	}
	else
	{
	 s.top--;
	 return s.element[s.top+1];
	}
}

mptr search(mptr l,int d)
{
	mptr t1,t2,t3;
	t1=l;t2=l;t3=l;
	while(t1->n1!=NULL&&t2->n2!=NULL&&t3->n3!=NULL&&t1->data!=d&&t2->data!=d&&t3->data!=d)
	{
		t1=t1->n1;
		t2=t2->n2;
		t3=t3->n3;
	}
}

void addend(mptr l,int d,)
{
	
	mptr t,t2;
	t=l;
	t2=new node;
	t2->data=d;
	t2->n1=NULL;
	t2->n2=NULL;
	t2->n3=NULL;
	
	
}

int main()
{
	
	
}
