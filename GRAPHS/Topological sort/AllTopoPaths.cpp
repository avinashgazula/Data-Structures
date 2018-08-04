#include<iostream>
#include<cstdlib>
using namespace std;
static int  x=0;
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
void Topo(int a[],int s,int **AdjMatrix)
{
	int i,j;
	while(1)
	{
		for(i=0;i<s;i++)
		{
			if(a[i]==0)
			{
				cout<<i+1<<" ";
				for(int j=0;j<s;j++)
				{
					if(AdjMatrix[i][j])
					a[j]--;
				}
				a[i]--;
				break;
			}
		}
		if(i==s)
		break;
	}
}
void AllTopo(int a[],int visit[],int path[],int count,int s,int **AdjMatrix)
{
	int i,j;
	while(1)
	{
		for(i=0;i<s;i++)
		{
			if(a[i]==0&&visit[i]!=1)
			{
				path[count++]=i+1;
				for(int j=0;j<s;j++)
				{
					if(AdjMatrix[i][j])
					{
						a[j]--;
					}
				}
				visit[i]=1;
				AllTopo(a,visit,path,count,s,AdjMatrix);
				visit[i]=0;
				count--;
				for(int j=0;j<s;j++)
				{
					if(AdjMatrix[i][j])
					a[j]++;
				}
			}
		}
		if(i==s)
		{
			break;
		}
	}
	if(count==s)
	{
		for(int i=0;i<count;i++)
		cout<<path[i]<<" ";
		cout<<endl;
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
		//	cout<<"Enter AdjMatrix["<<i<<"]["<<j<<"]\n";
			cin>>AdjMatrix[i][j];
		}
	}
	for(i=0;i<s;i++)
	{
		a[i]=inDegree(s,AdjMatrix,i+1);
	//	cout<<endl;
	}
	int visit[s],path[s],count=0;
	for(i=0;i<s;i++)
	visit[i]=0;
	AllTopo(a,visit,path,count,s,AdjMatrix);
	for(i=0;i<s;i++)
	delete AdjMatrix[i];
	delete a;
}
