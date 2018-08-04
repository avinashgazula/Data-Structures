#include<iostream>
using namespace std;
typedef
struct tnode
{
	int data;
	struct tnode *lchild;
	struct tnode *rchild;
	
}* tptr;

struct queue{
	tptr elem[20];
	int size;
	int front;
	int rear;
	
};

void enqueue(queue &q,tptr &t)
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
tptr dequeue(queue &q)
{
	if(q.rear==-1)
	cout<<"Queue is empty\n";
	else
	{
		tptr t=q.elem[q.front];
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

tptr create(queue &q)
{
	while(q.front!=q.rear)
	{
		tptr t=NULL;
		t=new tnode;
		tptr t1=dequeue(q);
		tptr t2=dequeue(q);
		t->data=0;
		t->lchild=t1;
		t->rchild=t2;
		enqueue(q,t);
	}
		if(q.front==q.rear)
	return dequeue(q);
}

void del(tptr &h,int a)
{
	tptr t=h;
	if(t==NULL)
	return;
	else
	{
		while(t->lchild!=NULL&&t->rchild!=NULL)
		{
			if(t->lchild->data==t->data)
			t=t->lchild;
			else
			t=t->rchild;
		}
		t->data=-1;
	}
}

int win(tptr &t)
{
	if(t->lchild==NULL&&t->rchild==NULL)
	return t->data;
	else
	{
		if(t->lchild!=NULL&&t->rchild!=NULL)
		t->data=(max(win(t->lchild),win(t->rchild)));
		if(t->lchild==NULL&&t->rchild!=NULL)
		t->data=(win(t->rchild));
		if(t->rchild==NULL&&t->lchild!=NULL)
		t->data=(win(t->lchild));
		return t->data;
	}
}

int main()
{
	tptr t;
	t=NULL;
	queue q;
	q.front=-1;
	q.rear=-1;
	q.size=20;
	int i=1;
	cout<<"Enter data or -1 to quit\n";
	int a;
	cin>>a;
	t=new tnode;
	t->data=a;
	t->lchild=NULL;
	t->rchild=NULL;
	enqueue(q,t);
	cout<<"Enter data or -1 to quit\n";
	cin>>a;
	while(a!=-1)
	{
		t=new tnode;
		t->data=a;
		t->lchild=NULL;
		t->rchild=NULL;
		enqueue(q,t);
		cout<<"Enter data or -1 to quit\n";
		cin>>a;
	}
	t=create(q);
	tptr h=t;
	while(1)
	{
		int x=win(t);
		if(x==-1)
		break;
		cout<<x<<" ";
		del(h,x);
	}
}
