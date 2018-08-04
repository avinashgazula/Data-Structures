#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef struct node
{
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

void print (lptr l)
{
	lptr t=l;
	while(t!=NULL)
	{
		cout<<t->data<<endl;
		t=t->next;
	}
	cout<<endl;
}


int main()
{
	lptr l1,l2,l3;
	lptr t1,t2,t3;
	l1=new node;
	l2=new node;
	l3=new node;
	l1->data=3;
	l1->next=NULL;
	addend(l1,8);
	addend(l1,4);
	l2->data=2;
	l2->next=NULL;
	addend(l2,5);
	l3->data=9;
	l3->next=NULL;
	addend(l3,6);
	cout<<"List 1 is \n";
	print(l1);
	cout<<"List 2 is \n";
	print(l2);
	cout<<"List 3 is \n";
	print(l3);	
	
	cout<<"\nAfter linking list 1 to list 3 amd list 2 to list 3 the lists are \n";
	
	t1=l1;
	t2=l2;
	t3=l3;
	while(t1->next!=NULL)
	t1=t1->next;
	t1->next=t3;
	while(t2->next!=NULL)
	t2=t2->next;
	t2->next=t3;
	cout<<"List 1 is \n";
	print(l1);
	cout<<"List 2 is \n";
	print(l2);
	cout<<"List 3 is \n";
	print(l3);	
	
	cout<<"\nAfter splitting l2 and l3\n";
	while(t2->next!=NULL&& t2->data!=5)
	{
		t2=t2->next;
	}
	t2->next=NULL;
	cout<<"List 1 is \n";
	print(l1);
	cout<<"List 2 is \n";
	print(l2);
	cout<<"List 3 is \n";
	print(l3);	
	
	
	
	
}
