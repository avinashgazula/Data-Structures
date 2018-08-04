#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;
struct student
{
	char name[30];
	char rno[5];
	char branch[10];
};
void pack(ofstream &fout)
{
	student s;
	char buffer[100];
	cout<<"enter the name of student ";
	cin>>s.name;
	strcpy(buffer,s.name);
	strcat(buffer,"|");
	cout<<"enter his rno ";
	cin>>s.rno;
	strcat(buffer,s.rno);
	strcat(buffer,"|");
	cout<<"enter his branch ";
	cin>>s.branch;
	strcat(buffer,s.branch);
	strcat(buffer,"-");
	fout<<buffer<<endl;
}
void unpack(ifstream &fin,ofstream &ob,int &k)
{
	char c,c1;
	student s;char ch;
	while(!fin.eof())
	{
		char buffer[100];
		k=fin.tellg();
		cout<<"k= "<<k<<endl;
	//	fin.getline(buffer,100,'-');
		fin>>s.name>>s.rno>>s.branch;//cout<<s.name<<s.rno<<s.branch;
		//cout<<ch;
		ob<<s.rno<<" "<<k<<endl; 
	
	}
	
}
void search()
{
	char ch[5],a[5];int i=0,k=0,loc=-1,m=0;
	cout<<"Enter the key of the record you want to search\n";
	cin>>ch;
	char b[5],x[5];
	int len=strlen(ch);
	ifstream fin("index_file.txt");
	while(!fin.eof())
	{
		fin>>a>>x;
	//	cout<<a<<"-"<<x<<endl;
		int a1=atoi(a);
		int ch1=atoi(ch);
//		cout<<a1<<"-"<<ch1<<endl;
		if(a1==ch1)
		{
			cout<<"key found\n";
		//	fin.seekg(2,ios::cur);
			break;
		}
	}	
	fin.close();
	loc=atoi(x);
	cout<<"loc "<<loc<<endl;
	if(loc==-1)
	cout<<"key not found";
	else
	{
		ifstream file("the_file.txt");
		file.seekg(loc,ios::beg);
		char p[30];
		file.getline(p,30);
		cout<<p<<endl;
		file.close();
	}
	
}
int main()
{
//	ofstream obj;
/*	obj.open("the_file.txt");
	int n;
	cout<<"enter the number of student details ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		pack(obj);
	}
	obj.close();*/
	ifstream my;
	ofstream ob;
	int k=0;
	my.open("the_file.txt");
	ob.open("index_file.txt");
//	for(int i=0;i<2;i++)
	unpack(my,ob,k);
	my.close();
	ob.close();
	ifstream objl;
	char a[100];
	objl.open("the_file.txt");
	int c;
/*	while(1)
	{
		cout<<"no of pos to move\n";
		cin>>c;
		objl.seekg(c,ios::beg);
		objl.getline(a,100);
		cout<<a<<endl;
	} */
	
	while(1)
	search();
	return 0; 
}
