#include<iostream>
using namespace std;
typedef
struct bdnode{
	int count;
	int key[4];
	struct bdnode *ptr[5];
}* bptr;
void swap(int &a,int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}
int leaf(bptr t)
{
	int k=-1;
	for(int i=0;i<=t->count;i++)
	{
		if(t->ptr[i]==NULL)
		k++;
	}
	if(k==t->count)
	return 1;
	else
	return 0;
}
bptr search(bptr &h,int &a)
{
	bptr t=h;
	if(t==NULL)
	return NULL;
	else
	{
		bptr x;
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
		for(int i=0;i<4;i++)
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
bptr parent(bptr &t,bptr &k)
{
	if(t==NULL||k==t)
	return NULL;
	else
	{
		bptr x=NULL;
		for(int i=0;i<=t->count;i++)
		{
			if(t->ptr[i]!=NULL&&t->ptr[i]==k)
			return t;
		}
		if(k->key[0]<t->key[0])
		{
			if(t->ptr[0]!=NULL)
			x=parent(t->ptr[0],k);
		}
		else
		if(k->key[0]>t->key[t->count-1])
		{
			if(t->ptr[t->count]!=NULL)
			x=parent(t->ptr[t->count],k);
		}
		for(int i=0;i<4;i++)
		{
			if(k->key[0]>t->key[i]&&k->key[k->count-1]<t->key[i+1])
			{
				if(t->ptr[i+1]!=NULL)
				x=parent(t->ptr[i+1],k);
			}
		}
		return x;
	}
}
void insert_and_sort(bptr &h,bptr &t,int a,bptr &t1);
void overflow(bptr &h,bptr &t,int a,bptr &t2);
void add(bptr &h,bptr &t,int a);
void print(bptr &t)
{
	if(t==NULL)
	return;
	else
	{
		for(int i=0;i<=t->count;i++)
		{
			if(i!=t->count)
			cout<<t->key[i]<<" ";
			if(t->ptr[i]!=NULL)
			print(t->ptr[i]);
		}
	}
}
int main()
{
	bptr t=NULL;
	cout<<"Enter data\n";
	int n;
	cin>>n;
	while(n!=-1)
	{
		add(t,t,n);
		cout<<endl;
		print(t);
		cout<<endl;
		cout<<"Enter data\n";
		cin>>n;
	}
	print(t);
}
void KeyRedirect(bptr &h,bptr &t,int a)
{
	bptr p=parent(h,t);bptr t1=NULL,b=NULL;int i,j,k;
	int med[5];
	if(p==NULL)
	{
		overflow(h,t,a,t1);
	}
	else
	{
		for(k=0;k<=p->count;k++)
		{
			if(p->ptr[k]==t)
			break;
		}
		if((k+1<=p->count)&&p->ptr[k+1]->count!=4)
		{
			if(p->ptr[k+1]->count<4)
			insert_and_sort(h,p->ptr[k+1],p->key[k+1],t1);
			for(i=0;i<4;i++)
			med[i]=t->key[i];
			med[5]=a;
			for(i=0;i<5;i++)
			{
				for(j=i;j<5;j++)
				{
					if(med[i]>med[j])
					swap(med[i],med[j]);
				}
			}
			b=new bdnode;
			for(i=0;i<4;i++)
			{
				b->key[i]=-1;
				b->ptr[i]=t->ptr[i];
				if(i==3)
				b->ptr[4]=t->ptr[4];
			}
			for(i=0;i<4;i++)
			t->key[i]=med[i];
			p->key[k+1]=med[5];
			for(i=0;i<5;i++)
			{
				if(b->ptr[i]!=NULL)
				{
					int k=b->ptr[i]->key[0];
					if(k<t->key[0])
					t->ptr[0]=b->ptr[i];
					else if(k>t->key[3]&&k<p->key[k])
					t->ptr[4]=b->ptr[i];
					else if(k>p->key[k]&&k<p->ptr[k+1]->key[0])
					p->ptr[k+1]->ptr[0]=b->ptr[i];
					for(j=0;j<t->count;j++)
					{
						if(k>t->key[j]&&k<t->key[j+1])
						t->ptr[j+1]=b->ptr[i];
					}
				}
			}
		}
		else if((k-1>=0)&&p->ptr[k-1]->count!=4)
		{
			
			for(i=0;i<4;i++)
			med[i]=t->key[i];
			med[4]=a;
			for(i=0;i<5;i++)
			{
				for(j=i;j<5;j++)
				{
					if(med[i]>med[j])
					swap(med[i],med[j]);
				}
			}
			cout<<"test1"<<endl;
			b=new bdnode;
			for(i=0;i<4;i++)
			{
				b->key[i]=-1;
				b->ptr[i]=t->ptr[i];
				if(i==3)
				b->ptr[4]=t->ptr[4];
			}
			cout<<"test2\n";
			if(p->ptr[k-1]->count<4)
			{
				insert_and_sort(h,p->ptr[k-1],p->key[k-1],t1);
				p->key[k-1]=med[0];
			cout<<"test201\n";
			}
			else if(p->ptr[k-1]->count==4)
			{
				p->key[k]=med[0];
				p->ptr[k+1]=p->ptr[k];
				p->ptr[k]=NULL;
			}
			cout<<"test202\n";
			for(i=1;i<=4;i++)
			t->key[i-1]=med[i];
			cout<<"test3\n";
			for(i=0;i<5;i++)
			{
				if(b->ptr[i]!=NULL)
				{
					int k=b->ptr[i]->key[0];
					if(k<t->key[0])
					t->ptr[0]=b->ptr[i];
					else if(k>t->key[3]&&k<p->key[k])
					t->ptr[4]=b->ptr[i];
					else if(k>p->key[k]&&k<p->ptr[k+1]->key[0])
					p->ptr[k+1]->ptr[0]=b->ptr[i];
					for(j=0;j<t->count;j++)
					{
						if(k>t->key[j]&&k<t->key[j+1])
						t->ptr[j+1]=b->ptr[i];
					}
				}
			}
			cout<<"test4\n";
		}
		else 
		overflow(h,t,a,t1);
	}
}
void overflow(bptr &h,bptr &t,int a,bptr &t2)
{
	bptr x=NULL;
	bptr p=parent(h,t);
	int med[5];
	int i,j;
	for(i=0;i<4;i++)
	med[i]=t->key[i];
	med[4]=a;
	for(i=0;i<5;i++)
	{
		for(j=i;j<5;j++)
		{
			if(med[i]>med[j])
			swap(med[i],med[j]);
		}
	}
	int median=med[2];
	bptr t1=NULL;
	t1=new bdnode;
	for(i=0;i<5;i++)
	t1->ptr[i]=NULL;
	t->count=2;
	t1->count=2;
	t->key[0]=med[0];
	t->key[1]=med[1];
	t1->key[0]=med[3];
	t1->key[1]=med[4];
	bptr b;
	b=new bdnode;
	for(i=0;i<4;i++)
	{
		b->key[i]=-1;
		b->ptr[i]=t->ptr[i];
		if(i==3)
		b->ptr[4]=t->ptr[4];
	}
	for(i=0;i<5;i++)
	t->ptr[i]=NULL;
	for(i=0;i<5;i++)
	{
		if(b->ptr[i]!=NULL)
		{
			int k=b->ptr[i]->key[0];
			if(k<t->key[0])
			t->ptr[0]=b->ptr[i];
			else if(k>t->key[0]&&k<t->key[1])
			t->ptr[1]=b->ptr[i];
			else if(k>t->key[1]&&k<median)
			t->ptr[2]=b->ptr[i];
			else if(k>median&&k<t1->key[0])
			t1->ptr[0]=b->ptr[i];
			else if(k>t1->key[0]&&k<t1->key[1])
			t1->ptr[1]=b->ptr[i];
			else if(k>t1->key[2])
			t1->ptr[2]=b->ptr[i];
		}
	}
	if(t2!=NULL)
	{
		int k=t2->key[0];
		if(k<t->key[0])
		t->ptr[0]=t2;
		else if(k>t->key[0]&&k<t->key[1])
		t->ptr[1]=t2;
		else if(k>t->key[1]&&k<median)
		t->ptr[2]=t2;
		else if(k>median&&k<t1->key[0])
		t1->ptr[0]=t2;
		else if(k>t1->key[0]&&k<t1->key[1])
		t1->ptr[1]=t2;
		else if(k>t1->key[2])
		t1->ptr[2]=t2;
	}
	if(p==NULL)
	{
		p=new bdnode;
		p->key[0]=median;
		p->count=1;
		p->ptr[0]=t;
		p->ptr[1]=t1;
		for(i=2;i<5;i++)
		p->ptr[i]=NULL;
		h=p;
	}
	else
	insert_and_sort(h,p,median,t1);
}
void add(bptr &h,bptr &t,int a)
{
	if(t==NULL)
	{
		t=new bdnode;
		t->count=1;
		t->key[0]=a;
		for(int i=0;i<=4;i++)
		t->ptr[i]=NULL;
	}
	else
	{
		bptr y=NULL;
		if(t->count<4&&leaf(t))
		insert_and_sort(h,t,a,y);
		else if(t->count==4&&leaf(t))
		{
			KeyRedirect(h,t,a);
			cout<<endl;
			print(h);
			cout<<endl;
		}
		else
		{
			if(a<t->key[0])
			add(h,t->ptr[0],a);
			else if(a>t->key[(t->count)-1])
			add(h,t->ptr[t->count],a);
			else
			{
				for(int i=0;i<t->count;i++)
				{
					if(a>t->key[i]&&a<t->key[i+1])
					add(h,t->ptr[i+1],a);
				}
			}
		}
	}
}
void insert_and_sort(bptr &h,bptr &t,int a,bptr &t1)
{
	if(t->count==4)
	overflow(h,t,a,t1);
	else
	{
		int i=0,j=0;
		for(i=0;i<t->count;i++)
		{
			if(t->key[i]>a)
			break;
		}
		t->count++;
		for(j=t->count;j>i;j--)
		{
			if(j!=t->count)
			t->key[j]=t->key[j-1];
			t->ptr[j]=t->ptr[j-1];
		}
		t->key[i]=a;
		if(t->ptr[i+1]!=NULL&&t->ptr[i+1]->key[0]<a)
		t->ptr[i+1]=t1;
		else if(t->ptr[i]!=NULL&&t->ptr[i]->key[0]>a)
		t->ptr[i]=t1;
	}
}
