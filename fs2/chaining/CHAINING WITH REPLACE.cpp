#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;
int hash(int in,int sp)
{
	return (in%sp);
}
bool is_emp(int **arr,int h)
{
	return arr[h][0]==-2;
}
char unpack(int **arr,int sp,ifstream& fin)
{
	int offset,key;
	offset=fin.tellg();
	char buffer[100];
	int p=0;
	while(1)
	{
		fin>>buffer[p];
		if(buffer[p]=='#')
		break;
		if(buffer[p]=='$')
		return '$';
		else
		p++;
	}
	buffer[p+1]='\0';
	int i=0;int j=0;
	char num[10];
	while(buffer[i]!='|')
	{
		i++;
	}
	i++;
	while(buffer[i]!='|')
	{
		num[j]=buffer[i];
		i++;j++;
	}
	num[j]='\0';
	key=atoi(num);
	int h=hash(key,sp);
	int t=h;
	int c=1;
	int temp;
	while(c!=0)
	{
		if(is_emp(arr,h))
		{
			arr[h][0]=key;
			arr[h][1]=offset;
			arr[h][2]=-1;
			c=0;
		}
		else
		{	
			if(c==1&&arr[h][0]%sp!=h)
			{
				temp=arr[h][0];
				arr[h][0]=key;
				key=temp;
				c=1;
				h=key%sp;
				t=h;
			}
			else
			{
				if(hash(key,sp)==hash(arr[h][0],sp))
				t=h;
				h=(h+1)%sp;
				c++;
			}
		}
	}
	if(h!=t&&(hash(arr[h][0],sp)==hash(arr[t][0],sp)))
	arr[t][2]=h;
	cout<<"key "<<key<<" h: "<<h<<" t: "<<t<<endl;
	return '*';
}
int main()
{
	ifstream fin;
	int **arr;
	fin.open("data2.txt");
	int sp;
	cout<<"enter the address space ";
	cin>>sp;
	arr=new int*[sp];
	for(int i=0;i<sp;i++)
	{
		arr[i]=new int[3];
	}
	for(int i=0;i<sp;i++)
	{
		for(int j=0;j<3;j++)
		{
			arr[i][j]=-2;
		}
	}
	char ch='*';
	while(ch=='*')
	{
		ch=unpack(arr,sp,fin);
	}
	for(int i=0;i<sp;i++)
	{
			cout<<arr[i][0]<<" "<<arr[i][1]<<" "<<arr[i][2]<<endl;
	}
	return 0;
}
