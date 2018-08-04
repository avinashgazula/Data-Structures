#include<iostream>
using namespace std;
void dfs(int visit[],int s,int v,int v1,int **AdjMatrix,int *num,int *parent,int &count)
{
	parent[v]=v1;
	visit[v]=1;
	num[v]=count++;
//	cout<<v<<" ";
	for(int i=0;i<s;i++)
	{
		if(i!=v&&AdjMatrix[v][i]==1&&visit[i]==0)
		{
			dfs(visit,s,i,v,AdjMatrix,num,parent,count);
		}
	}
}
int low(int x,int v,int s,int **AdjMatrix,int *num,int *parent)
{
	int nc=0;int i=0;
	for(int i=0;i<s;i++)
	{
		if(parent[i]==v)
		nc++;
	}
	//cout<<"\n nc "<<nc<<" \n";
	if(x==v)
	{
	//	cout<<"root";
		return num[v];
	}
	int tag=0,p=-1;
	for(i=0;i<s;i++)
	{
	//	cout<<endl<<"v "<<v<<endl;
		if(v!=i&&AdjMatrix[v][i]!=0&&i!=parent[v]&&v!=parent[i])
		{
		//	cout<<v<<" test "<<i<<" \n";
			p=i;
			tag++;
			break;
		}
	}
	if(p!=-1)
	return num[p];
	else
	{
		int m=s;
	//	cout<<"hello\n";
		for(i=0;i<s;i++)
		{
			if(v!=i&&AdjMatrix[v][i]!=0&&i!=parent[v]&&v==parent[i])
			{
				if(m>low(x,i,s,AdjMatrix,num,parent))
				m=low(x,i,s,AdjMatrix,num,parent);
			}
		//	return min(num[v],low(x,i,s,AdjMatrix,num,parent));
		}
		return min(num[v],m);
	}
}
int main()
{
	int **AdjMatrix,i,j,s,*num,*parent;
	cout<<"Enter the no. of vertices\n";
	cin>>s;
	AdjMatrix=new int *[s];
	num=new int[s];
	parent=new int[s];
	for(i=0;i<s;i++)
	{
		AdjMatrix[i]=new int[s];
	}
	cout<<"Enter the adjacency Matrix\n";
	for(i=0;i<s;i++)
	{
		for(j=0;j<s;j++)
		{
			cin>>AdjMatrix[i][j];
		}
	}
	int visit[s],v;
	for(i=0;i<s;i++)
	{
		visit[i]=0;
		parent[i]=-1;
	}
	cout<<"Enter the start vertex\n";
	cin>>v;
	int count=1;
	dfs(visit,s,v,v,AdjMatrix,num,parent,count);
//	for(i=0;i<s;i++)
//	cout<<num[i]<<" "<<parent[i]<<" "<<low(v,i,s,AdjMatrix,num,parent)<<endl;
	int nc=0;
	for(i=0;i<s;i++)
	{
		if(v==parent[i])
		nc++;
	}
	for(i=0;i<s;i++)
	{
		for(j=0;j<s;j++)
		{
			if(i!=j&&AdjMatrix[i][j]!=0&&low(v,j,s,AdjMatrix,num,parent)>=num[i])
			{
				if(i!=v||nc<=1)
				cout<<i<<" ";
				break;
			}
		}
	}
}
