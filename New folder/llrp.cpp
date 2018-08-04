#include<iostream>
using namespace std;

typedef
struct node
{
	char data;
	struct node *rand;
	struct node *next;
}* lptr;

lptr search(lptr l,char d)
{
	lptr t;
	t=l;
	while(t->next!=NULL &&t->data!=d)
	{
		t=t->next;
	}
	return t;
}


void randprint(lptr l)
{
	lptr t;
	t=l;
	cout<<t->data;
	while(t!=NULL)
	{
		cout<<t->data;
		if(t->rand==NULL)
		{
			t=t->next;
		}
		else
		{
			t=t->rand;
		}
		
	}
}

void print(lptr l)
{
	lptr t;
	t=l;
	while(t!=NULL)
	{
		cout<<t->data;
		t=t->next;
	}
}

int main()
{
	lptr l;
	l=new node;
	int i,j=1,k=0,count;
	char d1,d2,ch;
	char r[10];
	cout<<"Enter the character in the first node\n";
	cin>>d1;
	r[k++]=d1;
	l->data=d1;
	l->next=NULL;
	lptr t,t1,t2,t3,t4;
	t=l;
	while(j)
	{
		count=0;
		cout<<"Does '"<<d1<<"' have a random pointer?\ny. YES n. NO\n";
		cin>>ch;
		if(ch=='n')
		{
			t->rand=NULL;
		}
		else
		{
			cout<<"Enter the character it points to\n";
			cin>>d2;
			r[k++]=d2;
			for(i=0;i<k;i++)
			{
			
				if(d2==r[i])
				count++;
			}
			cout<<"count is "<<count<<endl;
			if(count==1)
			{
				t1=new node;
				t1->data=d2;
				t1->next=NULL;
				t->rand=t1;
			}
			else
			{
				t2=search(l,d2);
				cout<<d2<< "is "<<t2->data<<endl;
				t->rand=t2;
			}
		}
		
		count=0;
		cout<<"Does '"<< d1 <<"' have a next pointer?\ny. YES n. NO\n";
		cin>>ch;
		if(ch=='n')
		{
			t->next=NULL;
			break;
		}
		if(ch=='y')
		{
			cout<<"Enter the character it points to\n";
			cin>>d1;
			r[k++]=d1;
			for(i=0;i<k;i++)
			{
				if(d1==r[i])
				count++;
			}
			cout<<"count is "<<count<<endl;
			if(count==1)
			{
				t3=new node;
				t3->data=d1;
				t3->next=NULL;
				t->next=t3;
			}
			else
			{
				t4=search(l,d1);
				cout<<d1<< "is "<<t4->data<<endl;
				t->next=t4;
			}
		}
		if(t->next==NULL)
		j=0;
		else
		t=t->next;
		
		
	}
	int a;
	cout<<"\n1. Random print 2. Normal print -1. Quit\n";
	cin>>a;
	while(a!=-1)
	{
		if(a==1)
		randprint(l);
		if(a==2)
		print(l);
		cout<<"\n1. Random print 2. Normal print -1. Quit\n";
		cin>>a;
	}
	
	
}
