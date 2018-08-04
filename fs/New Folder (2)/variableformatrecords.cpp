#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;

union salary{
	char month[10];
	char hour[3][10];
};

struct employee{
	char name[30];
	char id[5];
	char tag[2];
	salary s;
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
	cout<<"Does he get paid 1.monthly or 2.hourly?\n";
	cin>>e.tag;
	strcat(buffer,e.tag);
	strcat(buffer,"|");

	if(e.tag[0]=='1')
	{
		cout<<"Enter the salary\n";
		cin>>e.s.month;
		strcat(buffer,e.s.month);
		strcat(buffer,"|");
	}
	if(e.tag[0]=='2')
	{
		cout<<"Enter the no. of hours worked\n";
		cin>>e.s.hour[1];
		strcat(buffer,e.s.hour[1]);
		strcat(buffer,"|");
		cout<<"Enter salary per hour\n";
		cin>>e.s.hour[2];
		strcat(buffer,e.s.hour[2]);
		strcat(buffer,"|");		
		int x1=atoi(e.s.hour[1]);
		int x2=atoi(e.s.hour[2]);
		int x= x1*x2;
	/*	itoa(x,e.s.hour[3],10);
		cout<<x<<endl;
		cout<<e.s.hour[3]<<endl;
		strcat(buffer,e.s.hour[3]);
		strcat(buffer,"|"); */
	}
	fout<<buffer;
	cout<<"Data written into the file\n";
	
}

void unpack(ifstream &fin)
{
	
	char buffer[100];
	employee e[10];
	fin.getline(buffer,100,'#');
	int l=strlen(buffer);
	buffer[l]='#';
	cout<<buffer<<endl;
	int i=0,j=0,k=0;
	while(1)
	{
			cout<<endl<<"EMPLOYEE "<<k+1<<endl;
	        j=0;
			while(buffer[i]!='|')
			{
				e[k].name[j++]=buffer[i++];
				
			}
			e[k].name[j]='\0';
			
			cout<<"Name   :\t"<<e[k].name<<endl;
			
			j=0;i++;
			while(buffer[i]!='|')
			{
				e[k].id[j++]=buffer[i++];
			}
			e[k].id[j]='\0';
			j=0;i++;
	
			e[k].tag[0]=buffer[i++];
			e[k].tag[1]='\0';
			j=0;
			i++;
			
			cout<<"Id.No  :\t"<<atoi(e[k].id)<<endl;
		
			int x=atoi(e[k].tag);
			
			if(x==1)
			{
				while(buffer[i]!='|')
				{
					e[k].s.month[j++]=buffer[i++];
				}
				cout<<"Type   :\t"<<"Monthly\n";
				cout<<"Salary :\t"<<atoi(e[k].s.month)<<endl;
			}
			j=0;i++;
			if(x==2)
			{
				j=0;i--;
				while(buffer[i]!='|')
				{
					e[k].s.hour[1][j++]=buffer[i++];
				}
				j=0;i++;
				while(buffer[i]!='|')
				{
					e[k].s.hour[2][j++]=buffer[i++];
				}
				j=0;i++;
			/*	while(buffer[i]!='|')
				{
					e[k].s.hour[3][j]=buffer[i++];
				}
				j=0;	*/	
				cout<<"Type   :\t"<<"Hourly\n";
				cout<<"Hours  :\t"<<atoi(e[k].s.hour[1])<<endl;
				cout<<"Sal/hr :\t"<<atoi(e[k].s.hour[2])<<endl;
			//	cout<<"Total Salary :"<<atoi(e[k].s.hour[3])<<endl<<endl;										
			}
			
			
			k++;
			if(buffer[i]=='#')
			break;
	}
	
	
}

int main()
{
	ofstream fout;
	fout.open("variableformatrecords.txt");
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
	fin.open("variableformatrecords.txt");
	unpack(fin);
	fin.close();
}
