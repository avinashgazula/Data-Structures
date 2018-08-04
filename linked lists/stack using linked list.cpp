#include<iostream>
using namespace std;
typedef struct node{
	int data;
	struct node *next;
}* lptr;

void addend(lptr l,int d)
{
	lptr t=l;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next=new node;
	t=t->next;
	t->data=d;
	t->next=NULL;
}

int delend(lptr h)
{

    lptr t = h;lptr t2=new node;
    while(t->next->next != NULL)
        t = t->next;
    t2->data=t->next->data;
	t->next=NULL;
	return t2->data;    

}
void push(lptr h,int d)
{	

	addend(h,d);
}
int pop(lptr h)
{
	if(h==NULL)
	cout<<"Stack is empty";
	delend(h);
}

void print (lptr l)
{
	lptr t=l;
	while(t!=NULL)
	{
		cout<<t->data<<" ";
		t=t->next;
	}
	cout<<endl;
	
}


int main()
{
	lptr stack=new node;int i,count=0,n,d;
	stack->data=1;
	stack->next=NULL;
	cout<<"Enter the elements you want to push into the stack or -1 to quit\n";
	cin>>d;
	stack->data=d;
	stack->next=NULL;
	cin>>d;
	while(d!=-1)
	{	
		addend(stack,d);
		cin>>d;
	}
	cout<<endl;
	cout<<"No of elements do you want to pop\n";
	cin>>n;
	cout<<"Popped elements are \n";
	for(i=0;i<n;i++)
	{
	cout<<pop(stack)<<endl;
	}
		
	cout<<"Remaining stack is \n";
	print(stack);
	return 0;
}
