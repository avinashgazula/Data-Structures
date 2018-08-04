#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
int partition(int *a,int low,int high)
{
	int l=low+1,h=high;
	int p=a[low];
	while(l<=h)
	{
		while(a[l]<p)
		l++;
		while(a[h]>p)
		h--;
		if(h>l)
		swap(a[h],a[l]);
	}
	if(low!=h)
	swap(a[low],a[h]);
	return h;
}
void quick_sort(int *a,int low,int high)
{
	int j;
	if(low<high)
	{
		j=partition(a,low,high);
	//	cout<<"j "<<j<<endl;
	//	if(low<j-1)
		quick_sort(a,low,j-1);
	//	if(j+1<high)
		quick_sort(a,j+1,high);
	}
}
int main()
{
	int n,*a;
	cout<<"Enter the no of elements\n";
	cin>>n;
	a=new int[n];
	cout<<"Enter the elements\n";
	for(int i=0;i<n;i++)
	cin>>a[i];
	int low=0,high=n-1;
	quick_sort(a,low,high);
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
}
