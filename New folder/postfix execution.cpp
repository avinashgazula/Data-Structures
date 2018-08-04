#include<iostream>
#include<cstring>
using namespace std;
struct stack
{
	int size;
	int elements[50];
	int top;
};

void push(struct stack &s,int x)
{
	if(s.size-1==s.top)
	cout<<"Stack is full\n";
	else
	{
	
	s.top++;
	s.elements[s.top]=x;}
}

int pop(struct stack &s)
{
	if(s.top==-1)
	{
		return -1;
	}
	else{
			int x= s.elements[s.top--];
			return x;
		
	}

}

int isoperator(char &a)
{
	if(a=='+'||a=='-'||a=='*'||a=='/')
	return true;
	else
	return false;
}

int isdigit(char &a)
{
	if(a>='0'&&a<='9')
	return true;
	else
	return false;
}

int operation(int x,int y,char &a)
{
	if(a=='+')
	return x+y;
	if(a=='-')
	return y-x;
	if(a=='*')
	return x*y;
	if(a=='/')
	return y/x;
}

int main()
{
	char ch[10];
	struct stack postfix;
	postfix.size=10;
	postfix.top=-1;

	char temp[10];
	int len,a=0,i,j,o1,o2,o,count=0;
	cout<<"Enter the postfix expression\n";
	cin.get(ch,10);
	len=strlen(ch);
	for(i=0;i<len;i++)
	{
		if(isdigit(ch[i]))
		push(postfix,ch[i]-'0');
		if(isoperator(ch[i]))
		{
			o1=pop(postfix);
			o2=pop(postfix);
			o=operation(o1,o2,ch[i]);
			push(postfix,o);
		} 
	}
	cout<<pop(postfix);
	return 0;
}
