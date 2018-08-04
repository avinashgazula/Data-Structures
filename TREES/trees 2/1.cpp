#include<iostream>
using namespace std;

typedef
struct btnode
{
	btnode* lchild;
	int data;
	btnode* rchild;
}*btptr;
void DeleteItem (btnode *&tree, int item);
void deletenode(btnode *&tree);
struct queue
{
	int size;
	int front;
	int rear;
	btptr elem[100];
};
void enque(struct queue &q,btptr &a)
{
	if((q.rear+1)%q.size==q.front)
	{
		cout<<"the queue is full"<<endl;
	}
	else
	{
		if(q.front==-1)
		q.front=0;
		q.rear=(q.rear+1)%q.size;
		q.elem[q.rear]=a;
	}
}
btptr deque(struct queue &q)
{
	if(q.rear==-1)
	{
		cout<<"the queue is empty "<<endl;
	}
	else
	{
		btptr t=q.elem[q.front];
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
void create(btptr &h,int ch)
{
	int c;
	if(h==NULL)
	{
		h=new btnode;
		h->lchild=NULL;
		h->rchild=NULL;
		h->data=ch;
	}
	cout<<"enter the data left of "<<h->data<<" ";
	cin>>c;
	if(c!=-1)
	{
		create(h->lchild,c);
	}
	cout<<"enter data right of "<<h->data<<" ";
	cin>>c;
	if(c!=-1)
	{
		create(h->rchild,c);
	}
}
void levelprint(btptr h)
{
	struct queue q;
	q.front=-1;
	q.rear=-1;
	q.size=100;
	if(h==NULL)
	{
		return;
	}
	enque(q,h);
	while(q.front!=-1)
	{
		btptr t=deque(q);
		cout<<t->data<<" ";
		if(t->lchild!=NULL)
		{
			enque(q,t->lchild);
		}
		if(t->rchild!=NULL)
		{
			enque(q,t->rchild);
		}
	}
}

btptr find(btptr &t,int d)
{
	if(t=NULL)
	return NULL;
	if(t->data==d)
	return t;
	find(t->lchild,d);
	find(t->rchild,d);
}

btptr max(btptr &t,btptr &x)
{
	if(x==NULL)
	{
		x=new btnode;
		x->data=0;
		x->lchild=NULL;
		x->rchild=NULL;
	}
	if(t==NULL)
	exit;
	
	if(t->data>x->data)
	x=t;
	max(t->lchild,x);
	max(t->rchild,x);
	return x;
	
}


int main()
{
	btptr root;
	root=NULL;
	int ch;
	cout<<"enter the root data -1 to end ";
	cin>>ch;
	if(ch!=-1)
	{
		create(root,ch);
	}
	cout<<"Enter node to delete\n";
	int n;
	cin>>n;
	deletenode(root,n);
	levelprint(root);
	return 0;
}

void DeleteItem (btnode *&tree, int item)
{
   if (tree == NULL) 	// empty tree or not in the tree
	return;

   if (item < tree->data)          // Go Left
     DeleteItem (tree->lchild, item);
   else if (item > tree->data)     // Go Right
     DeleteItem (tree->rchild, item);
   else                            // This is It
     DeleteNode (tree);
}
void deletenode(btnode *&tree)
{
  btnode *temp;
  
  temp = tree;
  if (tree->lchild == NULL)		// no left child is easy
    {
	tree = tree->rchild;
	delete temp;
    }
  else if (tree->rchild == NULL)	// no right is also easy
    {
	tree = tree->rchild;
	delete temp;
    }
  else                           // both left & right exist
    {
     temp = tree->lchild;          // find right-most node of left sub-tree
     while (temp->rchild!= NULL)
       temp = temp->rchild;
     tree->data = temp->data;    // move just that value to root
     DeleteItem (tree->lchild, temp->data);   // delete duplicate data
    }
}
