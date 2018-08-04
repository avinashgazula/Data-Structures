#include<iostream>
using namespace std;
int count=1;
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
void dfsprint(int no[],int visit[],int s,int v,int **AdjMatrix1)
{
	visit[v]=1;int temp=0;
	cout<<v<<" ";
	for(int i=0;i<s;i++)
	{
		if(i!=v&&AdjMatrix1[v][i]==1&&visit[i]==0)
		{
			temp++;
			dfsprint(no,visit,s,i,AdjMatrix1);
		}
	}
	if(temp==0)
	cout<<endl;
	int maxi=0;
	for(int i=0;i<s;i++)
	{
		for(int j=0;j<s;j++)
		{
			{
				if(visit[i]==0&&visit[j]==0&&no[i]<no[j])
				maxi=j;
				else if(visit[i]==0&&visit[j]==0)
				maxi=i;
			}
		}
	}
	if(maxi!=-1&&visit[maxi]==0)
	dfsprint(no,visit,s,maxi,AdjMatrix1);
}
void dfs(int *no,stack &s1,int visit[],int s,int v,int **AdjMatrix)
{
	visit[v]=1;int i=0,j,k=0;
	push(s1,v);
	for(i=0;i<s;i++)
	{
		if(AdjMatrix[v][i]==1&&visit[i]==0)
		{
			dfs(no,s1,visit,s,i,AdjMatrix);
		}
	}
	int b=0;
	for(int j=0;j<s1.top;j++)
	{
		int n=s1.elements[j];
		for(i=0;i<s;i++)
		{
			if(AdjMatrix[n][i]==1&&visit[i]==0)
			{
				b++;
			}
		}
	}
	if(b==0)
	{
		while(s1.top!=-1)
		{
			int p=pop(s1);
			no[p]=count++;
		}
	}
	for(int i=0;i<s;i++)
	{
		if(visit[i]==0)
		dfs(no,s1,visit,s,i,AdjMatrix);
	}
}
int main()
{
	int **AdjMatrix,i,j,s,*a,*no;
	stack s1;
	s1.top=-1;
	s1.size=30;
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
		//	cout<<"Enter AdjMatrix["<<i<<"]["<<j<<"]\n";
			cin>>AdjMatrix[i][j];
		}
	}
	int visit[s],v;
	for(i=0;i<s;i++)
	visit[i]=0;
	cout<<"Enter the start vertex\n";
	cin>>v;
	cout<<"dfs\n";
	no=new int[s];
	dfs(no,s1,visit,s,v,AdjMatrix);
	cout<<endl;
	for(i=0;i<s;i++)
	cout<<no[i]<<" ";
	int **AdjMatrix1;
	AdjMatrix1=new int *[s];
	for(i=0;i<s;i++)
	AdjMatrix1[i]=new int[s];
	for(i=0;i<s;i++)
	{
		for(j=0;j<s;j++)
		AdjMatrix1[j][i]=AdjMatrix[i][j];
	}
	for(i=0;i<s;i++)
	visit[i]=0;
	int max=0;
	max=6;
	cout<<endl;
	dfsprint(no,visit,s,max,AdjMatrix1);
}
