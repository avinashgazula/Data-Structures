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
	fstream file("file.txt");
	fstream f1("file1.txt");
	fstream f2("file2.txt");
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
					if(f1.tellg()!=0)
					f1<<" ";
					f1<<a[i];
				}
				count=1;
			}
			else if(count==1)
			{
				for(int i=0;i<d;i++)
				{
					if(f2.tellg()!=0)
					f2<<" ";
					f2<<a[i];
				}
				count=0;
			}
		}
	}
	f1.seekg(0,ios::beg);
	f2.seekg(0,ios::beg);
	int n1=d,n2=d;int *a1,*a2,x=0;
	fstream b1("b1.txt");
	fstream b2("b2.txt");int i=0,j=0;
	while(n1!=n&&n2!=n)
	{
		if(f1.eof()&&f2.eof())
		{
			n1=n1+i;n2=n2+j;
			cout<<"n1 "<<n1<<" n2 "<<n2<<endl;
			cout<<"x "<<x<<endl;
			cout<<"HEEEELLLLpppppp\n";
			if(x==0)
			{
				cout<<"000000000000000000000\n";
				f1.close();f2.close();b1.close();b2.close();
				fstream f1("b1.txt");
				fstream f2("b2.txt");
				fstream b1("file1.txt",ios::in|ios::trunc);
				fstream b2("file2.txt",ios::in|ios::trunc);
				char ch1[100],ch2[100];
				f1.getline(ch1,100);
				f2.getline(ch2,100);
				cout<<"FILEEEE\n";
				cout<<ch1<<endl<<ch2<<endl;
				f1.seekg(0,ios::beg);
				f2.seekg(0,ios::beg);
				cout<<"pos1 "<<f1.tellp();
				cout<<"\npos2 "<<f2.tellp()<<endl;
				x=1;
			}
			else if(x==1)
			{
				cout<<"11111111111111111111\n";
				f1.close();f2.close();b1.close();b2.close();
				fstream f1("file1.txt");
				fstream f2("file2.txt");
				f1.seekg(0,ios::beg);
				f2.seekg(0,ios::beg);
				fstream b1("b1.txt",ios::trunc);
				fstream b2("b2.txt",ios::trunc);
				x=0;
			}
		}
		cout<<"Hello\n";
		a1=new int[n1];
		a2=new int[n2];
		i=0,j=0;
		cout<<"pos1 "<<f1.tellg();
		cout<<"\npos2 "<<f2.tellg()<<endl;
		if(!f1.eof()&&f1.tellg()==-1)
		f1.seekg(1,ios::cur);
		if(!f2.eof()&&f2.tellg()==-1)
		f2.seekg(1,ios::cur);
		cout<<"poos1 "<<f1.tellp()<<" "<<f1.tellg();
		cout<<"\npoos2 "<<f2.tellp()<<" "<<f2.tellg()<<endl;
		while(i!=n1)
		{
			cout<<"test1\n";
			char ch[3];
			f1>>ch;
			a1[i++]=atoi(ch);
		//	if(f1.eof())
		//	break;
		}
		while(j!=n2)
		{
			cout<<"test2\n";
			char ch[3];
			f2>>ch;
			a2[j++]=atoi(ch);
		//	if(f2.eof())
		//	break;
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
				if(b1.tellg()!=0)
				b1<<" ";
				b1<<m[k];
			}
			count=1;
		//	n1=n1+j;
		}
		
		else if(count==1)
		{
			cout<<"b2\n\n";
			for(int k=0;k<i+j;k++)
			{
				if(b2.tellg()!=0)
				b2<<" ";
				b2<<m[k];
			}
			count=0;
		//	n2=n2+i;
		cout<<"count "<<count<<" last "<<m[i+j-1]<<endl;
		}
		cout<<" b1 pos "<<b1.tellg()<<endl;
		cout<<" b2 pos "<<b2.tellg()<<endl;
		delete a1,a2;
	}
}
