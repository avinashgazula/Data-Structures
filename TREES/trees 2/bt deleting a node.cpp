#include<iostream>
using namespace std;
typedef
struct btnode
{
	btnode* lchild;
	int data;
	btnode* rchild;
}*btptr;
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

btptr min(btptr node)
{
    btptr current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}


struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL) return root;
 
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = min(root->right);
 
        // Copy the inorder successor's content to this node
        root->key = temp->key;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
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
