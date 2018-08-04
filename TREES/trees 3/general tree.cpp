#include<iostream>
using namespace std;
typedef
struct gtnode{
	int data;
	gtnode *fc;
	gtnode *ns;
}* gtptr;
struct queue{
	gtptr elem[20];
	int size;
	int front;
	int rear;
	
};
bool not_found(int a[],int k,int n)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]==k)
		return 0;
	}
	return 1;
}
void enqueue(queue &q,gtptr &t)
{
	if((q.rear+1)%q.size==q.front)
	cout<<"queue is full\n";
	else
	{
		if(q.front==-1)
		q.front=0;
		q.rear=(q.rear+1)%q.size;
		q.elem[q.rear]=t;
		
	}
}
gtptr dequeue(queue &q)
{
	if(q.rear==-1)
	cout<<"Queue is empty\n";
	else
	{
		gtptr t=q.elem[q.front];
		if(q.front==q.rear)
		{
			q.rear=-1;
			q.front=-1;
		}
		else
		{
			q.front=(q.front+1)%q.size;
		}
		return t;
		
	}
}

void create(gtptr &t,int a)
{

	if(t==NULL)
	{
		t=new gtnode;
		t->data=a;
		t->fc=NULL;
		t->ns=NULL;
	}
	cout<<"Enter first child of "<<t->data<<endl;
	cin>>a;
	if(a!=-1)
	{
		create(t->fc,a);
	}
	cout<<"Enter next sibling of "<<t->data<<endl;
	cin>>a;
	if(a!=-1)
	{
		create(t->ns,a);
	}
}
void dft(gtptr &t)
{
	if(t==NULL)
	return;
	else
	{
		cout<<t->data<<" ";
		if(t->fc!=NULL)
		cout<<"(";
		dft(t->fc);
		if(t->ns==NULL)
		cout<<")";
		dft(t->ns);
	}
}


void bft(gtptr &h,gtptr &root,queue &q)
{
	int c=0;
	queue q1;
	q1.front=-1;
	q1.rear=-1;
	q1.size=20;
	gtptr t=h;
	if(t==NULL)
	return;
	else
	{
		if(t==root)
		cout<<t->data<<" ";
		while(t->fc!=NULL)
		{
			
			t=t->fc;
			while(t!=NULL)
			{
				enqueue(q,t);
				c++;
				t=t->ns;	
			}
			int c1=c;
			while(c!=0)
			{
				if(q.rear!=-1)
				{
					t=dequeue(q);
					cout<<t->data<<" ";
				}
				if(t->fc!=NULL)
				enqueue(q1,t);
				c--;
			}
			if(c1!=0)
			{
				if(q1.rear!=-1)
				t=dequeue(q1);
				c1--;
			}
			c=c1;
		}
	}
}

int main()
{
	int a;
	gtptr t;
	t=NULL;
	queue q;
	q.front=-1;
	q.rear=-1;
	q.size=20;
	cout<<"Enter data\n";
	cin>>a;
	create(t,a);
	cout<<"(";
	dft(t);
	cout<<endl;
	bft(t,t,q);
}

