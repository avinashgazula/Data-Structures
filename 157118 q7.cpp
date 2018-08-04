//R.No 157118 Name. G.Avinash
//Q7.Linked list to each level of a binary search tree

#include<iostream>
using namespace std;

typedef
struct bstnode{
	struct bstnode *lchild;
	int data;
	struct bstnode *rchild;
}* bstptr;

struct queue{
	int size;
	int front;
	int rear;
	bstptr elem[20];
	
};

typedef
struct node{
	
	bstptr key;
	struct node *next;
}* nptr;

void enqueue(queue &q,bstptr &t)
{
	if((q.rear+1)%q.size==q.front)
	cout<<"Queue is full\n";
	else
	{
		if(q.front==-1)
		{
			q.front=0;
			
		}
		q.rear=(q.rear+1)%q.size;
		
			q.elem[q.rear]=t;
		
	}
}

bstptr dequeue(queue &q)
{
	if(q.front==-1)
	{
		cout<<"Queue is empty\n";
	}
	else
	{
		bstptr t=q.elem[q.front];
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

int ht(bstptr &t)
{
	if(t==NULL)
	return -1;
	else
	return(max(ht(t->lchild),ht(t->rchild))+1);
}
void addend(nptr &l,bstptr &d)
{
	nptr t=l;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next=new node;
	t=t->next;
	t->key=d;
	t->next=NULL;
}

void printll(nptr &l)
{
	if(l==NULL)
	return;
	nptr t=l;
	while(t!=NULL)
	{
		cout<<t->key->data<<" ";
		t=t->next;
	}
	cout<<endl;
}

void create(bstptr &t,int &a)
{
	if(t==NULL)
	{
		t=new bstnode;
		t->data=a;
		t->lchild=NULL;
		t->rchild=NULL;
	}
	else
	{
		if(a<t->data)
		create(t->lchild,a);
		else
		create(t->rchild,a);
	}
}


void levelorderll(bstptr &t)
{
	int x=t->data;
	int h=ht(t);
	cout<<"height :"<<h<<endl;
	nptr n;
	n=NULL;
	int i;

	int c=0;
	
	queue q;
	q.front=-1;
	q.rear=-1;
	q.size=20;
	bstptr temp;
	temp=new bstnode;
	temp->data=-1;
	temp->lchild=NULL;
	temp->rchild=NULL;
	enqueue(q,t);
	enqueue(q,temp);
	n=NULL;
	while(q.front!=-1)
	{
		t=dequeue(q);
		if(t->data==-1)
		{
			cout<<"Linked list at level "<<c++<<endl;
			printll(n);
			n=NULL;
			if(q.front!=-1)
			enqueue(q,t);
		}
		else
		{
			if(n==NULL)
			{
				n=new node;
				n->key=t;
				n->next=NULL;
			}
			else
			{
				addend(n,t);
			}
			if(t->lchild!=NULL)
			enqueue(q,t->lchild);
			if(t->rchild!=NULL)
			enqueue(q,t->rchild);
		}
	}

}

int main()
{
	bstptr t;
	t=NULL;
	int a;
	cout<<"Enter data or -1 to quit\n";
	cin>>a;
	
	while(a!=-1)
	{
		create(t,a);
		cout<<"Enter data or -1 to quit\n";
		cin>>a;
	}

	cout<<endl;
	levelorderll(t);
}
