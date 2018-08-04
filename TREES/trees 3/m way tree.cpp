#include<iostream>
using namespace std;

typedef
struct mstnode{
	int count;
	int m;
	int key[10];
	mstnode *ptr[10+1];
}* mstptr;

void create(mstptr &t,int a,int k)
{
	int i;int c=-1;
	if(t==NULL)
	{
		t=new mstnode;
		t->key[0]=a;
		t->count=1;
		t->m=k;
		for(i=0;i<(t->m)+1;i++)
		t->ptr[i]=NULL;	
	}
	else
	{
		
		if(t->count==t->m)
		{
			for(i=0;i<t->m;i++)
			{
				if(t->key[i]<a)
				c=i;
			}
			create(t->ptr[c+1],a,k);
		}
		else
		{
			for(i=0;i<(t->count);i++)
			{
				if(t->key[i]<a)
				c=i;
			}
			int x=t->count;
			for(i=x;i>c+1;i--)
			{
				t->key[i]=t->key[i-1];
				t->ptr[i+1]=t->ptr[i];
			}
			t->key[c+1]=a;
			t->ptr[c+2]=NULL;
			t->count=t->count+1;
		}
	}
}

void find(mstptr &h,int &a)
{
	mstptr t=h;
	if(t==NULL)
	cout<<"Key not found\n";
	else
	{
		for(int i=0;i<t->m;i++)
		{
			
			if(t->ptr[i]!=NULL)
			find(t->ptr[i],a);
			else
			if(t->key[i]==a)
			{
				a=-1;
			}
		}
		if(t->ptr[t->m]!=NULL)
		find(t->ptr[t->m],a);
	}
}
mstptr search(mstptr &h,int &a)
{
	mstptr t=h;
	if(t==NULL)
	return NULL;
	else
	{
		mstptr x;
		if(a<t->key[0])
		{
			if(t->ptr[0]!=NULL)
			x=search(t->ptr[0],a);
		}
		else
		if(a>t->key[t->count-1])
		{
			if(t->ptr[t->count]!=NULL)
			x=search(t->ptr[t->count],a);
		}
		for(int i=0;i<t->m-1;i++)
		{
			if(t->key[i]==a)
			{
				a=i;
				return t;
			}
			else
			if(a>t->key[i]&&a<t->key[i+1])
			{
				if(t->ptr[i+1]!=NULL)
				x=search(t->ptr[i+1],a);
			}
		}
		return x;
	}
	
}
mstptr max(mstptr &h)
{
	mstptr t=h;
	while(t->ptr[t->m]!=NULL)
	t=t->ptr[t->m];
	return t;
}
mstptr min(mstptr &h)
{
	mstptr t=h;
	while(t->ptr[0]!=NULL)
	{
		t=t->ptr[0];
	}
	return t;
}

mstptr del(mstptr &h,int a)
{
	mstptr s=search(h,a);
}
void print(mstptr &t)
{
	if(t==NULL)
	return;
	else
	{
		for(int i=0;i<t->m;i++)
		{
			
			if(t->ptr[i]!=NULL)
			print(t->ptr[i]);
			if(t->key[i]!=0)
			cout<<t->key[i]<<" ";
		}
		if(t->ptr[t->m]!=NULL)
		print(t->ptr[t->m]);
	}
}

int main()
{
	mstptr t;
	t=NULL;
	int a,k;int c=0;
	cout<<"Enter the no of keys\n";
	cin>>k;
	cout<<"Enter data or -1 to quit\n";
	cin>>a;
	while(a!=-1)
	{
		create(t,a,k);
		cout<<"Enter data or -1 to quit\n";
		cin>>a;
	}
	print(t);
	cout<<endl;
	int key;
	cout<<"Enter the key you want to search\n";
	cin>>key;
	while(key!=-1)
	{
		find(t,key);
		if(key!=-1)
		cout<<"key not found\n";
		else
		cout<<"Key found\n";
		cout<<"Enter the key you want to search\n";
		cin>>key;
	}  
	mstptr q;
	q=max(t);
	cout<<q->key[q->count-1]<<endl;
	q=min(t);
	cout<<q->key[0]<<endl;
/*	int l;
	cout<<"Enter data to be searched\n";
	cin>>l;
	mstptr s;
	s=NULL;
	while(l!=-1)
	{
		s=search(t,l);
		cout<<l<<endl;
		cout<<"test\n";
		cout<<s->key[l];
		cout<<"Enter data to be searched\n";
		cin>>l;
	}
	*/
	
}

