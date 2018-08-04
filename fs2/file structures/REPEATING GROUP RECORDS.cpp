#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
using namespace std;
struct child
{
	char name[50];
	char DOB[10];
};
struct employee
{
	char name[100];
	char id[10];
	child *c;
	int n;
};
void pack(ofstream &fout)
{
	char buffer[100];
	struct employee emp;
	cout<<"enter employee name ";
	cin>>emp.name;
	strcpy(buffer,emp.name);
	strcat(buffer,"|");
	cout<<"enter idno ";
	cin>>emp.id;
	strcat(buffer,emp.id);
	strcat(buffer,"|");
	cout<<"enter the num of children of "<<emp.name;
	cin>>emp.n;
	emp.c=new child[emp.n];
	char ch[2];
	itoa(emp.n,ch,10);
	strcat(buffer,ch);
	strcat(buffer,"|");
	for(int i=0;i<emp.n;i++)
	{
		cout<<"enter the name of child"<<endl;
		cin>>emp.c[i].name;
		strcat(buffer,emp.c[i].name);
		strcat(buffer,"|");
		cout<<"enter DOB"<<endl;
		cin>>emp.c[i].DOB;
		strcat(buffer,emp.c[i].DOB);
		strcat(buffer,"|");
	}
	fout<<buffer<<endl;
}
void unpack(ifstream &fin)
{
	char buffer[300];
	struct employee e;
	fin.getline(buffer,100);
	int i=0,j=0;
	while(buffer[i]!='|')
	{
		e.name[j]=buffer[i];
		j++;
		i++;
	}
	e.name[j]='\0';
	cout<<e.name<<" ";
	j=0;
	i++;
	while(buffer[i]!='|')
	{
		e.id[j]=buffer[i];
		i++;
		j++;
	}
	e.id[j]='\0';
	j=0;
	i++;
	cout<<e.id<<" ";
	char a[2];
	while(buffer[i]!='|')
	{
		a[j]=buffer[i];
		i++;
		j++;
	}
	a[j]='\0';
	j=0;
	i++;
	e.n=atoi(a);
	cout<<e.n<<" ";
	cout<<endl;
	int k=0;
	e.c=new child[e.n];
	while(k<e.n)
	{
		while(buffer[i]!='|')
		{
			e.c[k].name[j]=buffer[i];
			j++;
			i++;
		}
		e.c[k].name[j]='\0';
		cout<<e.c[k].name<<" ";
		j=0;
		i++;
		while(buffer[i]!='|')
		{
			e.c[k].DOB[j]=buffer[i];
			i++;
			j++;
		}
		e.c[k].DOB[j]='\0';
		j=0;
		i++;
		cout<<e.c[k].DOB<<" ";
		k++;
	}
}
int main()
{
	ofstream fout;
	int in;
	fout.open("myfile.txt");
	cout<<"press 1:enter details  2:stop"<<endl;
	cin>>in;
	int i=0,j=0;
	while(in==1)
	{
		pack(fout);
		cout<<"press 1:to enter details  2:to stop"<<endl;
		cin>>in;
		i++;
	}
	fout.close();
	ifstream fin;
	fin.open("myfile.txt");
	while(j<i)
	{
	   unpack(fin);
	   j++;
    }
	fin.close();
	return 0;
}
