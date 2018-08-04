#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
int d=3;
int n=24;
void swap(int &a,int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}
void sort(int *a)
{
	for(int i=0;i<d;i++)
	{
		for(int j=i;j<d;j++)
		{
			if(a[i]>a[j])
			swap(a[i],a[j]);
		}
	}
}
int* merge(int a1[],int a2[],int n1,int n2)
{
//	sort(a1);sort(a2);
for(int y=0;y<n1;y++)
cout<<a1[y]<<" ";
cout<<endl;
for(int y=0;y<n2;y++)
cout<<a2[y]<<" ";
cout<<endl;
	int *m;int pos=0,i=0,j=0;
	m=new int[n1+n2];
	while(i<n1&&j<n2)
	{
		if(a1[i]<a2[j])
		{
			m[pos++]=a1[i];
			i++;
		}
		else
		{
			m[pos++]=a2[j];
			j++;
		}
	}
	if(i==n1&&j!=n2)
	{
		for(int k=j;k<n2;k++)
		m[pos++]=a2[k];
	}
	else
	{
		for(int k=i;k<n1;k++)
		m[pos++]=a1[k];
	}
	for(int y=0;y<n1+n2;y++)
	cout<<m[y]<<" ";
	return m;
}
int main()
{
	ifstream file("file.txt");
	ofstream p("file1.txt");
	ofstream q("file2.txt");
	int no=0,count=0,a[d];
	while(!file.eof())
	{
		char ch[3];
		file>>ch;
		a[no++]=atoi(ch);
		if(no==d)
		{
			sort(a);
			no=0;
			if(count==0)
			{
				for(int i=0;i<d;i++)
				{
					//if(f1.tellp()!=0
					p<<a[i]<<" ";
				}
				count=1;
			}
			else if(count==1)
			{
				for(int i=0;i<d;i++)
				{
					//if(f2.tellg()!=0)
					//f2<<" ";
					q<<a[i]<<" ";
				}
				count=0;
			}
		}
	}
	p.close();
	q.close();
	ifstream f1("file1.txt");
	ifstream f2("file2.txt");
	ofstream b1("b1.txt");
	ofstream b2("b2.txt");
	int n1=d,n2=d;int *a1,*a2,x=0;
	
	while(n1<n&&n2<n)
	{
		cout<<"Hello\n";
		a1=new int[n1];
		a2=new int[n2];
		int i=0,j=0;
		//f1.seekg(0,ios::beg);
		//f2.seekg(0,ios::beg);
		while(i!=n1)
		{
			char ch[3];
			f1>>ch;
			cout<<"ch- a:"<<ch<<" ";
			a1[i++]=atoi(ch);
		}
		while(j!=n2)
		{
			char ch[3];
			f2>>ch;
			cout<<"ch-b :"<<ch<<" ";
			a2[j++]=atoi(ch);
		}
		for(int y=0;y<n1;y++)
		cout<<a1[y]<<" ";
		cout<<endl;
		for(int y=0;y<n2;y++)
		cout<<a2[y]<<" ";
		cout<<endl;
		cout<<"i "<<i<<" j "<<j<<endl;
		int *m;
		cout<<"n1 "<<n1<<" n2 "<<n2<<endl;
		m=new int[i+j];
		m=merge(a1,a2,i,j);
		cout<<endl<<i+j<<endl;
		for(int y=0;y<i+j;y++)
		cout<<m[y]<<" ";
		cout<<"\nYelLLoooOOOO\n";
		cout<<"count "<<count<<endl;
		cout<<endl;
		if(count==0)
		{
			cout<<"b1\n\n";
			for(int k=0;k<i+j;k++)
			{
				//if(b1.tellg()!=0)
				//b1<<" ";
				b1<<m[k]<<" ";
			}
			count=1;
		//	n1=n1+j;
		}
		
		else if(count==1)
		{
			cout<<"b2\n\n";
			for(int k=0;k<i+j;k++)
			{
				//if(b2.tellg()!=0)
				//b2<<" ";
				b2<<m[k]<<" ";
			}
			count=0;
		//	n2=n2+i;
		cout<<"count "<<count<<" last "<<m[i+j-1]<<endl;
		}
		cout<<" b1 pos "<<b1.tellp()<<endl;
		cout<<" b2 pos "<<b2.tellp()<<endl;
		if(f1.eof()&&f2.eof())
		{
			n1=n1+i;n2=n2+j;
			cout<<"n1 "<<n1<<" n2 "<<n2<<endl;
			cout<<"x "<<x<<endl;
			cout<<"HEEEELLLLOOOOOOOO\n";
			if(x==0)
			{
				cout<<"BREAKKKK\n";
				f1.close();f2.close();b1.close();b2.close();
				ifstream f1("b1.txt");
				ifstream f2("b2.txt");
				ofstream b1("file1.txt");
				ofstream b2("file2.txt");
				x=1;
			}
			else if(x==1)
			{
				f1.close();f2.close();b1.close();b2.close();
				ifstream f1("file1.txt");
				ifstream f2("file2.txt");
				ofstream b1("b1.txt");
				ofstream b2("b2.txt");
				x=0;
			}
		}
	}
	f1.close();
	f2.close();
	b1.close();
	b2.close();
}
