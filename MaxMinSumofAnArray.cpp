#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
void print(int *a,int n,int count,int &min,int &max,int &sum)
{
	if(count==n)
	{
		cout<<"Max "<<max<<" Min "<<min<<" Sum "<<sum;
		return;
	}
	if(a[count]<min)
	min=a[count];
	if(a[count]>max)
	max=a[count];
	sum+=a[count];
	count++;
	print(a,n,count,min,max,sum);
}
int main()
{
	int n,*a;
	cout<<"Enter size of the array\n";
	cin>>n;
	a=new int[n];
	cout<<"Enter the array\n";
	for(int i=0;i<n;i++)
	cin>>a[i];
	int count =1,min=a[0],max=a[0],sum=a[0];
	print(a,n,count,min,max,sum);
}
