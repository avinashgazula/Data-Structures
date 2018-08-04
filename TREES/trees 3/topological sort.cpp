#include<iostream>
using namespace std;
typedef
struct tnode{
	int key;
	int count;
	struct tnode *next;
	struct pointer *trail;
}* tptr;
typedef
struct pointer{
	struct tnode *id;
	struct pointer *next;
}* ptr;

void addend(tptr &h,int k,int c)
{
	tptr t=h;

	{
		while(t->next!=NULL)
		t=t->next;
		t->next=new tnode;
		t=t->next;
		t->key=k;
		t->count=c;
		t->next=NULL;
		t->trail=NULL;
	}
}

tptr find(tptr &h,int d)
{
	tptr t=h;
	while(t->key!=d&&t->next!=NULL)
	t=t->next;
	if(t->key==d)
	return t;
	else
	return NULL;
}

void randptr(tptr &h,ptr &t,int a)
{
	tptr temp=find(h,a);
	t->id=temp;
	t->next=NULL;
}

void rand(tptr &h,tptr &t,int a)
{
	if(a==-1)
	t->trail=NULL;
	else
	{
		t->trail=new pointer;
		t->trail->id=find(h,a);
		
		cout<<"is the next of the pointer null 1.no 2.yes\n";
		int n;
		cin>>n;
		if(n==2)
		t->trail->next=NULL;
		else
		{
			int x;
			cout<<"Enter data\n";
			cin>>x;
			ptr k;
			t->trail->next=new pointer;
			k=t->trail->next;
			randptr(h,k,x);
		}
	}
}
bool not_found(int a[],int k,int n)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]==k)
		return 0;
	}
	return 1;
}
void print(tptr &t)
{
	tptr h=t;
	while(h!=NULL)
	{
		cout<<h->key<<" ";
		h=h->next;
	}
	cout<<endl;
}
bool to_do(tptr &h,int a)
{
	tptr t=h;
	while(t->next!=NULL)
	{
		if(t->key==a&&t->count==1)
		return 1;
		t=t->next;
	}
	return 0;
}
bool search(int a[],int k)
{
	for(int i=0;a[i]!=0;i++)
	{
		if(a[i]==k)
		return 0;
	}
	return 1;
}

void path(tptr &h,int k,int a[],int i)
{
	//tptr t=h;
	if(to_do(h,k))
	return;
	else
	{
		tptr t=h;
		while(t!=NULL)
		{
			ptr temp=t->trail;
			while(temp!=NULL)
			{
				if(temp->id->key==k)
				{
				//	if(not_found(a,k,i))
					cout<<t->key<<" ";
					a[i]=t->key;
					i++;
					path(h,t->key,a,i);
				}
				temp=temp->next;
			}
			t=t->next;
		}
	}
}
int main()
{
	tptr t;
	t=NULL;
	int a=0,k,c,n;
	cout<<"Enter key and count\n";
	cin>>k>>c;
	t=new tnode;
		t->key=k;
		t->count=c;
		t->next=NULL;
		t->trail=NULL;
		cout<<"Enter key and count\n";
		cin>>k>>c;
	while(k!=-1||c!=-1)
	{
		addend(t,k,c);
		a++;
		cout<<"Enter key and count\n";
		cin>>k>>c;
	}
	print(t);
	tptr temp=t;
		for(int i=0;i<=a;i++)
	{
		cout<<"enter the data id of trail of "<<temp->key<<" points to\n";
		cin>>n;
		rand(t,temp,n);
		temp=temp->next;
	}
	int data;
	cout<<"Enter the course you want to study\n";
	cin>>data;
	int b[20];
	for(int x=0;x<20;x++)
	b[x]=0;
	int i=0;int j;
	tptr t2=t;
	while(data!=-1)
	{
		path(t,data,b,i);
		cout<<endl;
		for(j=0;b[j]!=0;j++)
		{
			cout<<b[j]<<" ";
		} 
		cout<<endl;
		cout<<"Enter the course name\n";
		cin>>data;
	}
	
}
