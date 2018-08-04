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
int inDegree(int s,int **AdjMatrix,int x)
{
	int count;
	for(int i=0;i<s;i++)
	{
		if(AdjMatrix[i][x-1])
		count++;
	}
	return count;
}
void Topo(queue &q,int a[],int s,int **AdjMatrix)
{
	int i,j,x;
	for(i=0;i<s;i++)
	{
		if(a[i]==0)
		enqueue(q,i);
	}
	do{
		x=dequeue(q);
		cout<<x+1<<" ";
		a[x]--;
		for(int j=0;j<s;j++)
		{
			if(AdjMatrix[x][j])
			{
				a[j]--;
				if(a[j]==0)
				enqueue(q,j);
			}
		}
	}while(q.front!=-1);
}
int main()
{
	int **AdjMatrix,i,j,s,*a;
	queue q;
	q.front=-1;
	q.rear=-1;
	cout<<"Enter the no. of vertices\n";
	cin>>s;
	q.size=s;
	AdjMatrix=new int *[s];
	a=new int[s];
	for(i=0;i<s;i++)
	AdjMatrix[i]=new int[s];
	cout<<"Enter the adjacency Matrix\n";
	for(i=0;i<s;i++)
	{
		for(j=0;j<s;j++)
		{
			cout<<"Enter AdjMatrix["<<i<<"]["<<j<<"]\n";
			cin>>AdjMatrix[i][j];
		}
	}
	for(i=0;i<s;i++)
	{
		a[i]=inDegree(s,AdjMatrix,i+1);
		cout<<endl<<a[i]<<endl;
	}
	cout<<"Hello\n";
	Topo(q,a,s,AdjMatrix);
}
