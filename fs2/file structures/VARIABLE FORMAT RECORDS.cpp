#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;

struct employee
{
	char name[20];
	char id[5];
	union salary
	{
		int monthly;
		int hourly[3];
	}s;
	char tg[3];
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
	cout<<"enter the tag 1:monthly 2:hourly ";
	cin>>emp.tg;
	strcat(buffer,emp.tg);
	strcat(buffer,"|");
	if(emp.tg[0]=='1')
	{
		cout<<"enter the monthly salary ";
		cin>>emp.s.monthly;
		char r[10];
		itoa(emp.s.monthly,r,10);
		strcat(buffer,r);
		strcat(buffer,"|");
	}
	else
	{
		cout<<"enter the no of hrs ";
		cin>>emp.s.hourly[0];
		cout<<"enter hourly salary ";
		cin>>emp.s.hourly[1];
		emp.s.hourly[2]=(emp.s.hourly[0])*(emp.s.hourly[1]);
		emp.s.hourly[2]=emp.s.hourly[2]*30;
		char r[10];
		strcat(buffer,r);
		strcat(buffer,"|");
	}
	fout<<buffer<<endl;
}
void unpack(ifstream &fin)
{
	char buffer[100];
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
	while(buffer[i]!='|')
	{
		e.tg[j]=buffer[i];
		i++;
		j++;
	}
	e.tg[j]='\0';
	j=0;
	i++;
	cout<<e.tg<<" ";
	char a[10];
	while(buffer[i]!='|')
	{
		a[j]=buffer[i];
		i++;
		j++;
	}
	//cout<<e.name<<"  "<<e.id<<"  "<<e.tg<<" ";
	if(e.tg[0]=='1')
	{
		e.s.monthly=atoi(a);
		cout<<e.s.monthly<<endl;
    }
	else
	{
		e.s.hourly[2]=atoi(a);
		cout<<e.s.hourly[2]<<" ";
    }
	//cout<<e.name<<"  "<<e.id<<"  "<<e.tg<<" ";
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
