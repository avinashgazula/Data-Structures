#include<iostream>
#include<cstring>
using namespace std;
struct stack
{
	int size;
	char elements[50];
	int top;
};

void push(struct stack &s,char x)
{
	if(s.size-1==s.top)
	cout<<"Stack is full\n";
	else
	{
		s.top++;
		s.elements[s.top]=x;
	}

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

int precedence(char &a)
{
	switch(a)
	{
		case '+':
		case '-':
			return 1;
		case '*':
			return 2;
		case '/':
			return 3;
	}
}
int main()
{
	struct stack postfix;
	postfix.size=10;
	postfix.top=-1;
	char infix[10];
	char temp[10];
	int len,a=0,i,j,o1,o2,count=0;
	cout<<"Enter the infix expression\n";
	cin.get(infix,10);
	len=strlen(infix);

	for(i=0;i<len;i++)
	{
		if(isdigit(infix[i]));
		cout<<infix[i]<<" ";
		
		if(isoperator(infix[i]))
		{
			if(postfix.top==-1)
			push(postfix,infix[i]);
			temp[i]=pop(postfix);
			push(postfix,temp[i]);
			if(precedence(infix[i])>precedence(temp[i]))
			{
				push(postfix,infix[i]);
			count++;
			}
			else
			{
				
					temp[i]=pop(postfix);
					push(postfix,temp[i]);
					while(precedence(infix[i])<=precedence(temp[i]))
					{
					
						temp[i]=pop(postfix);
						push(postfix,temp[i]);
						cout<<pop(postfix)<<" ";
						
					}

			}
		}
	}
	for(j=0;j<count;j++)
	pop(postfix);
	return 0;
}

