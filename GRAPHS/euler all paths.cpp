#include<iostream>
using namespace std;
typedef struct node{
	int data;
	struct node *next;
}* lptr;
void addll(lptr &l,int d)
{
	if(l==NULL)
	{
		l=new node;
		l->data=d;
		l->next=NULL;
	}
	else
	{
		addll(l->next,d);
	}
}
int complete(lptr l,int s)
{
	lptr t=l;
	int count=0,visit[s];
	for(int i=0;i<s;i++)
	visit[i]=0;
	while(t!=NULL)
	{
		visit[t->data]=1;
		t=t->next;
	}
	for(int i=0;i<s;i++)
	{
		if(visit[i]==1)
		count++;
	}
	if(count==s)
	return 1;
	return 0;
}
int Degree(int s,int **AdjMatrix,int x)
{
	int count=0;
	for(int i=0;i<s;i++)
	{
		if(AdjMatrix[x][i]==1)
		count++;
	}
	return count;
}
int present(lptr l2,int v1,int v2)
{
	lptr t=l2;
	while(t->next!=NULL)
	{
		if((t->data==v1&&t->next->data==v2)||(t->data==v2&&t->next->data==v1))
		return 1;
		t=t->next;
	}
	return 0;
}
void printll(lptr l,lptr l2,int a,int **AdjMatrix)
{
	if(l==NULL)
	return;
	else
	{
		cout<<l->data<<"  ";
		if(a!=-1&&present(l2,a,l->data)==0)
		{
			AdjMatrix[a][l->data]=1;
			AdjMatrix[l->data][a]=1;
		}
		printll(l->next,l2,l->data,AdjMatrix);
	}
}
void euler(lptr &t,lptr l1,lptr l2,int s,int v,int **AdjMatrix,int &c)
{
	lptr l=NULL;
	if(c==0)
	addll(t,v);
	else
	addll(l1,v);
	if(complete(t,s))
	{
		if(l2!=NULL)
		printll(t,l2,-1,AdjMatrix);
		cout<<endl;
	}
	l=t;
	if(Degree(s,AdjMatrix,v)==0)
	{
		c=1;
		if(l1!=NULL)
		{
			while(l->data!=l1->data)
			{
				l=l->next;
			}
			lptr temp=l->next;
			l->next=l1->next;
			lptr t1=l;
			while(1)
			{
				if(t1->next==NULL)
				{
					t1->next=temp;
					break;
				}
				t1=t1->next;
			}
			l1=NULL;
			t=l;
		}
		lptr t2=t;
		while(t2!=NULL)
		{
			if(Degree(s,AdjMatrix,t2->data)!=0)
			{
				euler(t,l1,l2,s,t2->data,AdjMatrix,c);
				break;
			}
			t2=t2->next;
		}
	}
	else
	{
		for(int i=0;i<s;i++)
		{
			
			if(i!=v&&AdjMatrix[v][i]==1)
			{
				AdjMatrix[v][i]=0;
				AdjMatrix[i][v]=0;
				addll(l2,i);
				euler(l,l1,l2,s,i,AdjMatrix,c);
			}	
		}
		return;
	}
}
int main()
{
	int **AdjMatrix,i,j,s,*a;
	cout<<"Enter the no. of vertices\n";
	cin>>s;
	AdjMatrix=new int *[s];
	a=new int[s];
	for(i=0;i<s;i++)
	AdjMatrix[i]=new int[s];
	cout<<"Enter the adjacency Matrix\n";
	for(i=0;i<s;i++)
	{
		for(j=0;j<s;j++)
		{
			cin>>AdjMatrix[i][j];
		}
	}
	int count=0;
	for(i=0;i<s;i++)
	{
		if(Degree(s,AdjMatrix,i)%2==1)
		{
			count++;
		}
	}
	int v,c=0;
	cout<<"count "<<count<<endl;
	cout<<"Enter Start Vertex\n";
	cin>>v;
	lptr l=NULL,l1=NULL,l2=NULL;
	if(count==0||count==2)
	euler(l,l1,l2,s,v,AdjMatrix,c);
	else
	cout<<"Not possible\n";
	//printll(l,-1,AdjMatrix);
}
