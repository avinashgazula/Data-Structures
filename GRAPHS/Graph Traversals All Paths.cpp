#include<iostream>
using namespace std;
struct queue
{
	int size;
	int front;
	int rear;
	int elem[20];
};
struct stack{
	int top;
	int size;
	int elements[30];
};

void push(stack &s,int &t)
{
	if(s.top==s.size-1)
	{
		cout<<"Stack is full\n";
	}
	else
	{
		s.top++;
		s.elements[s.top]=t;
	}
}
int pop(stack &s)
{
	if(s.top==-1)
	{
		cout<<"Stack is empty\n";
	}
	
	else
	return s.elements[s.top--];
}
void enqueue(struct queue &q,int &a)
{
	if((q.rear+1)%q.size==q.front)
	cout<<"the queue is full"<<endl;
	else
	{
		if(q.front==-1)
		q.front=0;
		q.rear=(q.rear+1)%q.size;
		q.elem[q.rear]=a;
	}
}
int dequeue(struct queue &q)
{
	if(q.rear==-1)
	cout<<"the queue is empty "<<endl;
	else
	{
		int t=q.elem[q.front];
		if(q.front==q.rear)
		{
			q.rear=-1;
			q.front=-1;
		}
		else
		q.front=(q.front+1)%q.size;
		return t;
	}
}
int present(int v,int a[],int count)
{
	for(int i=0;i<count;i++)
	{
		if(a[i]==v)
		return 1;
	}
	return 0;
}
void dfs(int visit[],int s,int v,int **AdjMatrix)
{
	visit[v]=1;
	cout<<v<<" ";
	for(int i=0;i<s;i++)
	{
		if(i!=v&&AdjMatrix[v][i]==1&&visit[i]==0)
		dfs(visit,s,i,AdjMatrix);
	}
	for(int i=0;i<s;i++)
	{
		if(visit[i]==0)
		{
			dfs(visit,s,i,AdjMatrix);
			break;
		}
	}
}
void dfsall(int count,int l,int a[],int visit[],int s,int v,int **AdjMatrix)
{
	visit[v]=1;
	a[count++]=v;
	if(count==s)
	{
		for(int i=0;i<s;i++)
		cout<<a[i]<<" ";
		cout<<endl;
		for(int i=4;i>=l;i--)
		a[i]=-1;
	}
	for(int i=0;i<s;i++)
	{
		l++;
		if(i!=v&&AdjMatrix[v][i]==1&&present(i,a,count)==0)
		dfsall(count,l,a,visit,s,i,AdjMatrix);
	}
	for(int i=0;i<s;i++)
	{
		if(visit[i]==0)
		{
			dfsall(count,l,a,visit,s,i,AdjMatrix);
			break;
		}
	}
}
void bfs(int z,queue &q1,queue &q,int visit[],int s,int v,int **AdjMatrix)
{ 
	if(z==0)
	enqueue(q,v);int c1=0;z++;
	visit[v]=1;
	while(q.front!=-1)
	{
		v=dequeue(q);
		cout<<v<<" ";
		for(int i=s-1;i>=0;i--)
		{
			if(i!=v&&AdjMatrix[v][i]==1&&visit[i]!=1)
			{
				visit[i]=1;
				enqueue(q,i);
			}
		}
	}
	for(int i=0;i<s;i++)
	{
		if(visit[i]==0)
		bfs(z,q1,q,visit,s,i,AdjMatrix);
	}
}
void bfsall(int count,int b[],int z,queue &q1,queue &q,int visit[],int s,int v,int **AdjMatrix)
{
	if(z==0)
	{
		enqueue(q,v);
		visit[v]=1;
	}
	b[count++]=v;
	int c1=0;z++;
	if(count==s)
	{
		for(int i=0;i<s;i++)
		cout<<b[i]<<" ";
		cout<<endl;
	}
	for(int i=0;i<s;i++)
	{
		if(i!=v&&AdjMatrix[v][i]==1&&present(i,b,count)==0)
		{
		//	visit[i]=1;
		//	b[count++]=i;
			enqueue(q,i);
			enqueue(q1,i);
			c1++;
		}
	}
	for(int i=0;i<c1;i++)
	{
		if(q1.front!=-1)
		{
			int t=dequeue(q1);
		//	b[count++]=t;
			bfsall(count,b,z,q1,q,visit,s,t,AdjMatrix);	
		}
		
	}
	for(int i=0;i<s;i++)
	{
		if(visit[i]==0)
		bfsall(count,b,z,q1,q,visit,s,i,AdjMatrix);
	}
}
int main()
{
	int **AdjMatrix,i,j,s,*a,*b;
	queue q,q1;
	q.front=-1;q1.front=-1;
	q.rear=-1;q1.rear=-1;
	cout<<"Enter the no. of vertices\n";
	cin>>s;
	q.size=50;q1.size=50;
	AdjMatrix=new int *[s];
	a=new int[s];
	b=new int[s];
	for(i=0;i<s;i++)
	AdjMatrix[i]=new int[s];
	cout<<"Enter the adjacency Matrix\n";
	for(i=0;i<s;i++)
	{
		for(j=0;j<s;j++)
		{
		//	cout<<"Enter AdjMatrix["<<i<<"]["<<j<<"]\n";
			cin>>AdjMatrix[i][j];
		}
	}
	int visit[s],v,count=0,l=0,z=0;;
	for(i=0;i<s;i++)
	visit[i]=0;
	cout<<"ENter the start vertex\n";
	cin>>v;int temp=v;
	cout<<"bfs all paths\n";
	bfsall(count,b,z,q1,q,visit,s,v,AdjMatrix);
/*	cout<<"dfs\n";
	dfs(visit,s,v,AdjMatrix);
	for(i=0;i<s;i++)
	visit[i]=0;v=temp;
	cout<<"\nbfs\n";
	z=0;
	bfs(z,q1,q,visit,s,v,AdjMatrix);
	for(i=0;i<s;i++)
	visit[i]=0;v=temp;
	cout<<"\ndfs all paths\n";count=0,l=0;
	dfsall(count,l,a,visit,s,v,AdjMatrix);*/
}
