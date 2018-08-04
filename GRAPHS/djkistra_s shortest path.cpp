#include<iostream>
using namespace std;
int main()
{
	int **AdjMatrix,i,j,s,a,z,min=0,m=0;
	cout<<"Enter the no. of vertices\n";
	cin>>s;
	int d[s],p[s],v[s];
	AdjMatrix=new int *[s];
	for(i=0;i<s;i++)
	AdjMatrix[i]=new int[s];
	cout<<"Enter the adjacency Matrix\n";
	for(i=0;i<s;i++)
	{
		for(j=0;j<s;j++)
		cin>>AdjMatrix[i][j];
		d[i]=-1;
		p[i]=-1;
		v[i]=0;
	}
	cout<<"Enter source and goal\n";
	cin>>a>>z;
	a--;z--;
	int c=a;
	d[c]=0;
	v[c]=1;
	while(c!=z)
	{
		for(i=0;i<s;i++)
		{
			if(AdjMatrix[c][i]!=0&&v[i]==0)
			{
				if(d[i]==-1||d[c]+AdjMatrix[c][i]<d[i])
				{
					d[i]=d[c]+AdjMatrix[c][i];
					p[i]=c;
				}
			}
		}
		int count=0;
		for(i=0;i<s;i++)
		{
			if(d[i]!=0&&d[i]!=-1&&v[i]==0)
			{
				count++;
				if(count==1)
				{
					min=d[i];
					m=i;
				}
				if(min>d[i])
				{
					min=d[i];
					m=i;
				}	
			}
		}
		c=m;
		v[c]=1;
	}
	while(1)
	{
		cout<<c+1<<" ";
		c=p[c];
		if(c==a)
		{
			cout<<a+1;
			break;
		}
	}
}
