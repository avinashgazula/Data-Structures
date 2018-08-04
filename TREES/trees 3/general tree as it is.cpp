#include<iostream>
using namespace std;
typedef
struct gtnode{
	int data;
	int x;
	int y;
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

int ht(gtptr &h)
{
	gtptr t=h;
	if(t->fc==NULL)
	return 0;
	else
	{
		int i;
		if(t->fc!=NULL)
		{
			t=t->fc;
			if(t->ns==NULL)
			{
				if(t->fc!=NULL)
				i=ht(t->fc)+1;
				else
				i=0;
			}
			while(t->ns!=NULL)
			{
				if(ht(t)>ht(t->ns))
				i=ht(t);
				else
				i=ht(t->ns);
				t=t->ns;
			}
			return i+1;
		}
		
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
void dft(gtptr &t,int i)
{
	if(t==NULL)
	return;
	else
	{
		dft(t->fc,i);
		t->x=i;
		t->y=ht(t);
		dft(t->ns,i);
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
		{
			for(int i=0;i<t->x;i++)
			cout<<" ";
			cout<<t->data<<endl;
		}
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
					if(c==c1)
					{
						for(int i=0;i<h->x;i++)
						cout<<" ";
					}
					t=dequeue(q);
					gtptr temp=t;
					for(int i=0;i<((h->x)-(temp->x));i++)
					cout<<t->data;
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
	int x;
	dft(t,0);
	cout<<endl;
	bft(t,t,q);
}

