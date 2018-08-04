#include<iostream>
#include<cstring>
using namespace std;
union generic
{
	int n;
	char ch;
	float f;
};

struct stack
{
	int tag;
	int top;
	int size;
	union generic u[15];
};

void push(struct stack &s,int n)
{
	if(s.size-1==s.top)
	cout<<"Stack is full\n";
	else
	{
		s.top++;
		s.u[s.top++]=n;
	}
	
}
void push(struct stack &s,char &c)
{
	if(s.size-1==s.top)
	cout<<"Stack is full\n";
	else
	s.u[s.top++]=c;
}
void push(struct stack &s,float &f)
{
	if(s.size-1==s.top)
	cout<<"Stack is full\n";
	else
	s.u[s.top++]=f;
}

int pop(struct stack &s)
{
	if(s.top==-1)
	{
		return -1;
	}
	else
	return s.elements[s.top--];
}
int main()
{
	struct stack stk;
	stk.size=15;
	stk.top=-1;
1:	cout<<"What kind of input do you want to enter into the stack\n1.Int 2.Char 3.Float\n";
	cin>>stk.tag;
	switch(stk.tag)
	{
		case 1:
			int n;
			cin>>n;
			push(stk,n);
		case 2:
			char ch;
			cin>>ch;
			push(stk,ch);
		case 3:
			float f;
			cin>>f;
			push(stk,f);
		default:
			cout<<"Wrong input";
	}
	char c;	
	cout<<"Do you want to add more details?";
	cin>>c;
	if(c=='y')
	goto(1);
	if(c=='n')
	cout<<stk.u.n<<endl<<stk.u.ch<<stk.u.f;
	return 0;
	
}

