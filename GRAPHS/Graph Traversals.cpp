#include<iostream>
using namespace std;
struct queue
{
	int size;
	int front;
	int rear;
	int elem[20];
};
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
		dfs(visit,s,i,AdjMatrix);
	}
}
void bfs(int z,queue &q1,queue &q,int visit[],int s,int v,int **AdjMatrix)
{ 
	if(z==0)
	enqueue(q,v);int c1=0;z++;
	visit[v]=1;
	for(int i=0;i<s;i++)
	{
		if(i!=v&&AdjMatrix[v][i]==1&&visit[i]!=1)
		{
			visit[i]=1;
			enqueue(q,i);
			enqueue(q1,i);
			c1++;
		}
	}
	for(int i=0;i<c1;i++)
	{
		bfs(z,q1,q,visit,s,dequeue(q1),AdjMatrix);	
	}
	for(int i=0;i<s;i++)
	{
		if(visit[i]==0)
		bfs(z,q1,q,visit,s,i,AdjMatrix);
	}
}
int main()
{
	int **AdjMatrix,i,j,s,*a;
	queue q,q1;
	q.front=-1;q1.front=-1;
	q.rear=-1;q1.rear=-1;
	cout<<"Enter the no. of vertices\n";
	cin>>s;
	q.size=50;q1.size=50;
	AdjMatrix=new int *[s];
	a=new int[s];
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
	int visit[s],v;
	for(i=0;i<s;i++)
	visit[i]=0;
	cout<<"ENter the start vertex\n";
	cin>>v;
	cout<<"dfs\n";
	dfs(visit,s,v,AdjMatrix);
	for(i=0;i<s;i++)
	visit[i]=0;
	cout<<"\nbfs\n";
	int z=0;
	bfs(z,q1,q,visit,s,v,AdjMatrix);
	while(q.front!=-1)
	{
		int k=dequeue(q);
		cout<<k<<" ";
	}
}
