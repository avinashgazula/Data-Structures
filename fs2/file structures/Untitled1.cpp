#include<iostream>
using namespace std;
void insert(int h[],int &s,int d)
{
	if(s==-1)
	{
		h[0]=d;
		s++;
	}
	else
	{
		s++;
		j=s;
		h[j]=d;
		while(j!=1)
		{
			
		}
	}
}
int main()
{
	int h[100];
	int size=-1;
	int d;
	cout<<"enter the data to be inserted in the heap ";
	cin>>d;
	while(d!=-1)
	{
		insert(h,size,d);
		cout<<"enter the data to be inserted in the heap ";
		cin>>d;
	}
}
