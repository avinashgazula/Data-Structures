#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
char A[5]={'A','B','C',' '};
typedef struct leafnode{
	char *key;
}* lptr;
typedef struct trienode{
	int tag;
	union u{
		struct leafnode *ptr0;
		struct trienode *ptr1;
	}u1[4];
}* tptr;
void print(tptr &t)
{
	if(t==NULL)
	return;
	else
	{
		cout<<t->tag<<" ";
		char c[10];
		if(t->tag==1)
		{
			for(int i=0;i<4;i++)
			{
				if(t->u1[i].ptr1!=NULL)
				print(t->u1[i].ptr1);
			}
		}
		else if(t->tag==0)
		{
			int len=strlen(t->u1[3].ptr0->key);
			cout<<t->u1[3].ptr0->key<<" ";
		}
	}
}
void add(tptr &t,tptr &t1,int p,char data[],int len,int c)
{
	int p1,p2;
	
	for(p2=0;p2<4;p2++)
	{
		if(t1->u1[3].ptr0->key[c]==A[p2])
		break;		
	}
/*	tptr temp=new trienode;
	temp->tag=1;
	for(int i=0;i<4;i++)
	temp->u1[i].ptr1=NULL;
	t->u1[p].ptr1=temp;*/
	for(p1=0;p1<4;p1++)
	{
		if(data[c]==A[p1])
		break;
	}
	if(c!=len&&p1==p2)
	{
		tptr temp=new trienode;
		temp->tag=1;
		for(int i=0;i<4;i++)
		temp->u1[i].ptr1=NULL;
		t->u1[p].ptr1=temp;
		add(t->u1[p].ptr1,t1,p1,data,len,c+1);
	}
	else
	{
		tptr temp=t;
		tptr t2=new trienode;
		t2->tag=0;
		for(int j=0;j<4;j++)
		t2->u1[j].ptr0=NULL;
		t2->u1[3].ptr0=new leafnode;
		t2->u1[3].ptr0->key=new char[len];
		strcpy(t2->u1[3].ptr0->key,data);
		if(c==len)
		t->u1[3].ptr1=t2;
		else
		temp->u1[p1].ptr1=t2;
		if(c==strlen(t1->u1[3].ptr0->key))
		temp->u1[3].ptr1=t1;
		else
		temp->u1[p2].ptr1=t1;
	}
}
void insert(tptr &t,char data[],int c,int len,int c1)
{
	if(t==NULL)
	{
		int i;tptr t1=NULL;
		if(c1==0)
		{
			t=new trienode;
			t->tag=1;
			for(i=0;i<4;i++)
			t->u1[i].ptr1=NULL;
			for(i=0;i<3;i++)
			{
				if(data[c]==A[i])
				break;
			}
			t->u1[i].ptr1=new trienode;
			t1=new trienode;
			t1=t->u1[i].ptr1;
		}
		else if(c1==1)
		t1=new trienode;
		t1->tag=0;
		for(int k=0;k<4;k++)
		t1->u1[k].ptr0=NULL;
		t1->u1[3].ptr0=new leafnode;
		t1->u1[3].ptr0->key=new char[len];
		strcpy(t1->u1[3].ptr0->key,data);
		if(c1==1)
		t=t1;
		else
		t->u1[i].ptr1=t1;
	}
	else
	{
		int i=0,j=0,p=0,p1=-1,p2=-1;
		if(c==len)
		insert(t->u1[3].ptr1,data,c+1,len,1);
		else if(t->tag==1)
		{
			for(p=0;p<4;p++)
			{
				if(c1==0)
				{
					if(data[c]==A[p])
					break;
				}
				else if(c1==1)
				{
					if(data[c+1]==A[p])
					break;
				}
			}
			tptr t1=t->u1[p].ptr1;
			if(t1==NULL||t1->tag==1)
			insert(t->u1[p].ptr1,data,c,len,1);
			else if(t1->tag==0)
			{
				c++;
				for(p2=0;p2<4;p2++)
				{
					if(t1->u1[3].ptr0->key[c]==A[p2])
					break;
				}
				tptr temp=new trienode;
				temp->tag=1;
				for(int i=0;i<4;i++)
				temp->u1[i].ptr1=NULL;
				t->u1[p].ptr1=temp;
				for(p1=0;p1<3;p1++)
				{
					if(data[c]==A[p1])
					break;
				}
				if(p1==p2)
				{
					add(t->u1[p].ptr1,t1,p,data,len,c+1);
				}
				else
				{
					tptr t2=new trienode;
					t2->tag=0;
					for(j=0;j<4;j++)
					t2->u1[j].ptr0=NULL;
					t2->u1[3].ptr0=new leafnode;
					t2->u1[3].ptr0->key=new char[len];
					strcpy(t2->u1[3].ptr0->key,data);
					temp->u1[p1].ptr1=t2;
					temp->u1[p2].ptr1=t1;
				}
			}
		}
	}
}
void del(tptr &h,tptr &t,char data[],int len,int c)
{
	int n=0,pos=-1;
	if(t==NULL)
	return;
	else if(t->tag==1)
	{
		for(int i=0;i<4;i++)
		{
			if(t->u1[i].ptr1!=NULL)
			{
				pos=i;
				n++;
			}
		}
	//	cout<<"n"<<n<<endl;
		if(n==1&&pos!=3)
		{
			if(t==h)
			{
	//			cout<<"EQUAL\n";
				h=t->u1[pos].ptr1;
				del(h,h,data,len,c+1);
			}
			else
			{
				t=NULL;
			/*	t=t->u1[pos].ptr1;
				del(h,t,data,len,c+1);*/
			}
		}
		else if(n==2)
		{
			int p=-1,pos=-1;
			for(p=0;p<4;p++)
			{
				if(data[c]==A[p])
				break;
			}
			for(int i=0;i<4;i++)
			{
				if(t->u1[i].ptr1!=NULL)
				{
					if(i!=p)
					pos=i;
				}
			}
		//	cout<<"\np "<<p<<" pos "<<pos<<endl;
			if(t->u1[p].ptr1->tag==0)
			t=t->u1[pos].ptr1;
			else
			del(h,t->u1[p].ptr1,data,len,c+1);
		}
		else
		{
			char ch[10];int p=-1;
			if(t->u1[3].ptr1!=NULL)
			{
				strcpy(ch,t->u1[3].ptr1->u1[3].ptr0->key);
				if(!strcmp(ch,data))
				{
					t->u1[3].ptr1=NULL;
					return;
				}
			}
			for(p=0;p<4;p++)
			{
				if(data[c]==A[p])
				break;
			}
			cout<<"hello\n"<<c<<" P "<<p<<endl;
			del(h,t->u1[p].ptr1,data,len,c+1);
		}
		
	}
	else if(t->tag==0)
	{
		t=NULL;
	}
}
int main()
{
	char data[10];tptr t=NULL;int c=0;
	while(1)
	{
		cout<<"Enter data to add\n";
		cin>>data;
		if(atoi(data)==-1)
		break;
		int len=strlen(data);
		insert(t,data,0,len,0);
	}
	print(t);
	while(1)
	{
		cout<<"\nEnter data to delete\n";
		cin>>data;
		if(atoi(data)==-1)
		break;
		int len=strlen(data);
		del(t,t,data,len,0);
		cout<<"test\n";
		print(t);
		cout<<endl;
	}
	print(t);
}
