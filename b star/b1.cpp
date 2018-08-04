#include<iostream>
using namespace std;
typedef
struct bdnode{
	int key[2];
	struct bdnode *ptr[3];
	int count;
}* bptr;
struct queue
{
	int size;
	int front;
	int rear;
	bptr elem[20];
};
void enque(struct queue &q,bptr &a)
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
bptr deque(struct queue &q)
{
	if(q.rear==-1)
	{
		cout<<"the queue is empty "<<endl;
	}
	else
	{
		bptr t=q.elem[q.front];
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
void swap(int &a,int &b)
{
	int t=a;
	a=b;
	b=t;
}
int leaf(bptr t)
{
	if(t->ptr[0]==NULL)
	return 1;
	else
	return 0;
}
bptr parent(bptr &h,bptr &t)
{
	if(t==NULL||t==h)
	return NULL;
	else
	{
		for(int i=0;i<=h->count;i++)
		{
			if(h->ptr[i]!=NULL&&h->ptr[i]==t)
			return h;
		}
		if(t->key[0]<h->key[0])
		return parent(h->ptr[0],t);
		else if(t->key[0]>h->key[t->count-1])
		return parent(h->ptr[t->count],t);
		else if(t->key[0]>h->key[0]&&t->key[0]<h->key[1])
		return parent(h->ptr[1],t);
	}
}
void print(bptr &h)
{
	if(h==NULL)
	return;
	else
	{
		for(int i=0;i<h->count;i++)
		{
			cout<<h->key[i]<<" ";
			if(h->ptr[i]!=NULL);
			print(h->ptr[i]);
		}
		if(h->ptr[h->count]!=NULL)
		print(h->ptr[h->count]);
	}
}
void levelprint(bptr &h)
{
	struct queue q;int i,j;
	q.front=-1;
	q.rear=-1;
	q.size=20;
	bptr temp;
	temp=new bdnode;
	temp->key[0]=-1;
	for(i=0;i<3;i++)
	temp->ptr[i]=NULL;
	if(h==NULL)
	{
		return;
	}
	enque(q,h);
	enque(q,temp);
	while(q.front!=-1)
	{
		bptr t=deque(q);
		if(t->key[0]==-1)
		{
			cout<<endl;
			if(q.front!=-1)
			{
				enque(q,t);
			}
		}
		else
		{
			for(i=0;i<t->count;i++)
			{
				cout<<t->key[i];
				if(i!=t->count-1)
				cout<<"|";
				else
				cout<<" ";
			}
		}
		for(i=0;i<=t->count;i++)
		{
			if(t->ptr[i]!=NULL)
			enque(q,t->ptr[i]);
		}
	}
}
void add(bptr &h,bptr &t,int k);
void insert_and_sort(bptr &h,bptr &t,int k,bptr &y);
void overflow(bptr &h,bptr &t,int k);
void nodesplit(bptr &h,bptr &t,int k,bptr &t2);
int main()
{
	int n;bptr t=NULL;
	cout<<"Enter data\n";
	cin>>n;
	while(n!=-1)
	{
		add(t,t,n);
		cout<<"Enter data\n";
		cin>>n;
	}
	print(t);
	cout<<endl;
	levelprint(t);
}
void add(bptr &h,bptr &t,int k)
{
	if(h==NULL)
	{
		t=new bdnode;
		t->count=1;
		t->key[0]=k;
		for(int i=0;i<3;i++)
		t->ptr[i]=NULL;
	}
	else
	{
		bptr y=NULL;
		if(leaf(t)&&t->count<2)
		insert_and_sort(h,t,k,y);
		else if(leaf(t)&&t->count==2)
		overflow(h,t,k);
		else
		{
			if(k<t->key[0])
			add(h,t->ptr[0],k);
			else if(k>t->key[t->count-1])
			add(h,t->ptr[t->count],k);
			else if(k>t->key[0]&&k<t->key[1])
			add(h,t->ptr[1],k);
		}
	}
}
void insert_and_sort(bptr &h,bptr &t,int k,bptr &t1)
{
	if(t->count==2)
	nodesplit(h,t,k,t1);
	else
	{
		int i=0,j=0;
		while(i<t->count)
		{
			if(t->key[i]>k)
			break;
			i++;
		}
		t->count++;
		for(j=t->count;j>i;j--)
		{
			if(j!=t->count)
			t->key[j]=t->key[j-1];
			t->ptr[j]=t->ptr[j-1];
		}
		t->key[i]=k;
		if(t->ptr[i+1]!=NULL&&t->ptr[i+1]->key[0]<k)
		t->ptr[i+1]=t1;
		else if(t->ptr[i]!=NULL&&t->ptr[i]->key[0]>k)
		t->ptr[i]=t1;
		if(t1!=NULL)
		{
			int c=t1->key[0];
			if(c<t->key[0])
			t->ptr[0]=t1;
			else if(c>t->key[t->count-1])
			t->ptr[t->count]=t1;
			else if(c>t->key[0]&&c<t->key[1])
			t->ptr[1]=t1;
		}
	}	
}
void overflow(bptr &h,bptr &t,int k)
{
	bptr p=parent(h,t);bptr t1=NULL,b=NULL,y=NULL;
	if(p==NULL)
	{
		nodesplit(h,t,k,t1);
	}
	else
	{
		b=new bdnode;
		int med[3],median,i,j;
		med[0]=t->key[0];med[1]=t->key[1];med[2]=k;
		for(i=0;i<=t->count;i++)
		b->ptr[i]=t->ptr[i];
		for(i=0;i<=t->count;i++)
		t->ptr[i]=NULL;
		for(i=0;i<3;i++)
		{
			for(j=i;j<3;j++)
			{
				if(med[i]>med[j])
				swap(med[i],med[j]);
			}
		}
		median=med[1];
		int pos=0;i=0;
		while(pos<=p->count)
		{
			if(p->ptr[pos]==t)
			break;
			pos++;
		}
		if(pos<p->count)
		{
			i=pos+1;
			while(i<=t->count)
			{
				if(p->ptr[i]!=NULL&&p->ptr[i]->count<2)
				break;i++;
			}
			if(i<=t->count)
			{
				t->key[0]=med[1];
				t->key[1]=med[2];
				for(j=i;j>pos;j--)
				{
					insert_and_sort(h,p->ptr[j],p->key[j-1],y);
					p->key[j-1]=p->ptr[j-1]->key[p->ptr[j-1]->count-1];
					p->ptr[j-1]->count--;
				}
				insert_and_sort(h,t,med[0],y);
			}
			else
			nodesplit(h,t,k,y);
		}
		else if(pos>0)
		{
			i=0;
			while(i<pos)
			{
				if(p->ptr[i]!=NULL&&p->ptr[i]->count<2)
				break;i++;
			}
			if(i!=pos)
			{
				t->key[0]=med[0];
				t->key[1]=med[1];
				for(j=i;j<pos;j++)
				{
					insert_and_sort(h,p->ptr[j],p->key[j],y);
					p->key[j]=p->ptr[j+1]->key[0];
					p->ptr[j+1]->count--;
					for(int x=0;x<p->ptr[j+1]->count;x++)
					p->ptr[j+1]->key[x]=p->ptr[j+1]->key[x+1];
				}
				insert_and_sort(h,t,med[2],y);
			}
			else
			nodesplit(h,t,k,y);
		}
	}
}
void nodesplit(bptr &h,bptr &t,int a,bptr &t2)
{
	bptr x=NULL;
	bptr p=parent(h,t);
	int med[3],pos=0,sib=-1;
	if(p==NULL||p->count==2)
	{
		int i,j;
		for(i=0;i<2;i++)
		med[i]=t->key[i];
		med[2]=a;
		for(i=0;i<3;i++)
		{
			for(j=i;j<3;j++)
			{
				if(med[i]>med[j])
				swap(med[i],med[j]);
			}
		}
		int median=med[1];
		bptr t1=NULL;
		t1=new bdnode;
		for(i=0;i<3;i++)
		t1->ptr[i]=NULL;
		t->count=1;
		t1->count=1;
		t->key[0]=med[0];
		t1->key[0]=med[2];
		bptr b;
		b=new bdnode;
		for(i=0;i<2;i++)
		{
			b->key[i]=-1;
			b->ptr[i]=t->ptr[i];
			if(i==1)
			b->ptr[2]=t->ptr[2];
		}
		for(i=0;i<3;i++)
		t->ptr[i]=NULL;
		for(i=0;i<3;i++)
		{
			if(b->ptr[i]!=NULL)
			{
				int k=b->ptr[i]->key[0];
				if(k<t->key[0])
				t->ptr[0]=b->ptr[i];
				else if(k>t->key[0]&&k<median)
				t->ptr[1]=b->ptr[i];
				else if(k>median&&k<t1->key[0])
				t1->ptr[0]=b->ptr[i];
				else if(k>t1->key[0])
				t1->ptr[1]=b->ptr[i];
			}
		}
		if(t2!=NULL)
		{
			int k=t2->key[0];
			if(k<t->key[0])
			t->ptr[0]=t2;
			else if(k>t->key[0]&&k<median)
			t->ptr[1]=t2;
			else if(k>median&&k<t1->key[0])
			t1->ptr[0]=t2;
			else if(k>t1->key[0])
			t1->ptr[1]=t2;
		}
		if(p==NULL)
		{
			p=new bdnode;
			p->key[0]=median;
			p->count=1;
			p->ptr[0]=t;
			p->ptr[1]=t1;
			p->ptr[2]=NULL;
			h=p;
		}
		else
		insert_and_sort(h,p,median,t1);
	}
	else
	{
		while(pos<=p->count)
		{
			if(p->ptr[pos]==t)
			break;
			pos++;
		}
		if(pos<p->count)
		sib=pos+1;
		else if(pos>0)
		sib=pos-1;
		p->count++;
		bptr s=p->ptr[sib];
		int i,j;
		for(i=0;i<2;i++)
		med[i]=t->key[i];
		med[2]=a;
		for(i=0;i<3;i++)
		{
			for(j=i;j<3;j++)
			{
				if(med[i]>med[j])
				swap(med[i],med[j]);
			}
		}
		int median=med[1];
		bptr t1=NULL;
		t1=new bdnode;
		for(i=0;i<3;i++)
		t1->ptr[i]=NULL;
		s->count=1;
		t->count=1;
		t1->count=2;
		if(sib<pos)
		{
			t->key[0]=p->key[pos-1];
			t1->key[0]=med[1];
			t1->key[1]=med[2];
			p->key[pos]=med[0];
			p->key[sib]=s->key[s->count];
			p->ptr[2]=t1;
		}
		else if(sib>pos)
		{
			t1->key[0]=med[2];
			t1->key[1]=p->key[pos];
			p->key[pos]=t->key[t->count];
			p->key[sib]=s->key[0];
			for(i=0;i<=s->count;i++)
			{
				if(i!=s->count)
				s->key[i]=s->key[i+1];
				s->ptr[i]=s->ptr[i+1];
			}
			p->ptr[sib]=t1;
			t1=s;
			p->ptr[2]=t1;
		}
		bptr b;
		b=new bdnode;
		for(i=0;i<2;i++)
		{
			b->key[i]=-1;
			b->ptr[i]=t->ptr[i];
			if(i==1)
			b->ptr[2]=t->ptr[2];
		}
		for(i=0;i<3;i++)
		t->ptr[i]=NULL;
		median=p->key[pos];
		for(i=0;i<3;i++)
		{
			if(b->ptr[i]!=NULL)
			{
				int k=b->ptr[i]->key[0];
				if(k<t->key[0])
				t->ptr[0]=b->ptr[i];
				else if(k>t->key[0]&&k<median)
				t->ptr[1]=b->ptr[i];
				else if(k>median&&k<t1->key[0])
				t1->ptr[0]=b->ptr[i];
				else if(k>t1->key[0]&&k<t1->key[1])
				t1->ptr[1]=b->ptr[i];
				else if(k>t1->key[1])
				t1->ptr[2]=b->ptr[i];
			}
		}
		if(t2!=NULL)
		{
			int k=b->ptr[i]->key[0];
				if(k<t->key[0])
				t->ptr[0]=t2;
				else if(k>t->key[0]&&k<median)
				t->ptr[1]=t2;
				else if(k>median&&k<t1->key[0])
				t1->ptr[0]=t2;
				else if(k>t1->key[0]&&k<t1->key[1])
				t1->ptr[1]=t2;
				else if(k>t1->key[1])
				t1->ptr[2]=t2;
		}
	}
}
