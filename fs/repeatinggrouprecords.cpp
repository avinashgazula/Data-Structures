#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;

struct child{

	char cname[10];
	char age[5];
};

struct employee{
	char name[30];
	char id[5];
	
	char n[2];
	child s[10];
};

void pack(ofstream &fout)
{
	char buffer[100];
	struct employee e;
	cout<<"Enter the employee's name\n";
	cin>>e.name;
	strcpy(buffer,e.name);
	strcat(buffer,"|");
	cout<<"Enter the id no\n";
	cin>>e.id;
	strcat(buffer,e.id);
	strcat(buffer,"|");
	cout<<"Enter the no of children\n";
	cin>>e.n;
	strcat(buffer,e.n);
	strcat(buffer,"|");
	int x=atoi(e.n);
	for(int i=0;i<x;i++)
	{
		cout<<"Enter the name of child "<<i+1<<endl;
		cin>>e.s[i].cname;
		strcat(buffer,e.s[i].cname);
		strcat(buffer,"|");
		cout<<"Enter age\n";
		cin>>e.s[i].age;
		strcat(buffer,e.s[i].age);
		strcat(buffer,"|");
	}

	fout<<buffer;
	cout<<"Data written into the file\n";
	
}

void unpack(ifstream &fin)
{
	
	char buffer[200];
	employee e[10];
	fin.getline(buffer,200,'\0');

	cout<<buffer<<endl;
	cout<<buffer[1];
	int i=0,j=0,k=0;int c=0;
	while(1)
	{
			cout<<endl<<"EMPLOYEE "<<k+1<<endl;
	        j=0;
			while(buffer[i]!='|')
			{
				e[k].name[j++]=buffer[i++];
				
			}
			
			e[k].name[j]='\0';
			
			cout<<"Name      \t:"<<e[k].name<<endl;
			
			j=0;i++;
			cout<<i<<endl;
			while(buffer[i]!='|')
			{
				e[k].id[j++]=buffer[i++];
			}
			e[k].id[j]='\0';
			j=0;i++;
			cout<<"Id.No     \t:"<<atoi(e[k].id)<<endl;
			cout<<i<<endl;
			e[k].n[0]=buffer[i++];
			e[k].n[1]='\0';
			j=0;
			i++;
			cout<<"No. of children :"<<atoi(e[k].n)<<endl;
			int x=atoi(e[k].n);
			cout<<i<<endl;
			for(c=0;c<x;c++)
			{
				while(buffer[i]!='|') 
				{
					e[k].s[c].cname[j++]=buffer[i++];
				}
				e[k].s[c].cname[j]='\0';
				cout<<"child name  \t:"<<e[k].s[c].cname<<endl;
				j=0;i++;
				cout<<i<<endl;
			
				while(buffer[i]!='|')
				{
					e[k].s[c].age[j++]==buffer[i++];
					
				}
				cout<<endl;
				e[k].s[c].age[j]='\0';
				cout<<"child age    \t:"<<atoi(e[k].s[c].age)<<endl;
				i++;
				cout<<i<<endl;
			}
			j=0;
			cout<<i<<endl;
			k++;
			if(buffer[i]=='#')
			break;
	}
	
	
}

int main()
{
	ofstream fout;
	fout.open("repeatinggrouprecords.txt");
	int n,i=0;
	cout<<"1.Enter employee details. -1.Quit\n";
	cin>>n;
	while(n!=-1)
	{
		pack(fout);
		cout<<"1.Enter employee details. -1.Quit\n";
		cin>>n;
	}
	fout<<"#";
	
	fout.close();
	
	ifstream fin;
	fin.open("repeatinggrouprecords.txt");
	unpack(fin);
	fin.close();
}
