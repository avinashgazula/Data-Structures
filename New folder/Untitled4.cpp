#include<iostream>
using namespace std;
int main()
{
	int n,i=1,j,k,x,y;
	cout<<"Enter the no of rows\n";
	cin>>n;
	int a[n][n];
	int b=n/2;
	a[b][b]=i;
	i++;

   for(x=1;x<n;)
   {
   		for(y=1;y<2*x;y++)
   	{
   		cout<<i;
   		a[b+x-1][b+x]=i;
   		i++;
   	
   		a[b+x][b+x]=i;
   		i++;
   	}
   		
   		for(y=1;y<=2*x;y++)
   		{	
   		a[b+x][b+x-y]=i;
   		i++;
		}
   
	}

	for(j=0;j<n;j++)
	{
		for(k=0;k<n;k++)
		cout<<a[j][k]<<" "<<endl;
	}
}
