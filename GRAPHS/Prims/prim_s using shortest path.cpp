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
	cout<<"Enter start vertex\n";
	cin>>a;
	cout<<endl;
	a--;
	int c=1;
	d[a]=0;
	v[a]=1;int m1=0;
	while(c<s)
	{
		int c1=0;
		for(j=0;j<s;j++)
		{
			if(v[j]==1)
			{
				for(i=0;i<s;i++)
				{
					if(AdjMatrix[j][i]!=0&&v[i]==0)
					{
						if(c1==0||AdjMatrix[j][i]<min)
						{
							min=AdjMatrix[j][i];
							m1=i;
							p[i]=j;
							c1++;
						}
					}
				}
			}
		}
		cout<<m1+1<<" "<<p[m1]+1<<endl;
		v[m1]=1;c++;
	}
}
