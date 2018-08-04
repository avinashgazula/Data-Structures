#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
struct student
{
	char name[50];
	char rno[5];
	char branch[10];
};
void pack(ofstream &fout)
{
	char buffer[100];
	struct student s;
	cout<<"enter name"<<endl;
	cin>>s.name;
	strcpy(buffer,s.name);
	int i;
	char a[2]={'*','\0'};
	for(i=strlen(buffer);i<49;i++)
	strcat(buffer,a);
	cout<<strlen(buffer)<<endl;
	strcat(buffer,"|");
	cout<<"enter branch"<<endl;
	cin>>s.branch;
	strcat(buffer,s.branch);
	for(int i=strlen(buffer);i<60;i++)
	strcat(buffer,a);
	cout<<strlen(buffer)<<endl;
	strcat(buffer,"|");
	cout<<"enter roll num"<<endl;
	cin>>s.rno;
	strcat(buffer,s.rno);
	for(int i=strlen(buffer);i<65;i++)
	strcat(buffer,a);
	strcat(buffer,"|");
	cout<<strlen(buffer)<<endl;
	int len=strlen(buffer);
	cout<<"the length of input given is "<<len<<endl;
	fout<<buffer<<endl;
}
void unpack(ifstream &fin)
{
	char buffer[100];
	struct student s;
	fin.getline(buffer,100);
	int i=0,j=0;
	while(buffer[i]!='|')
	{
		s.name[j]=buffer[i];
		j++;i++;
	}
	s.name[j]='\0';
	j=0;
	i++;
	while(buffer[i]!='|')
	{
		s.branch[j]=buffer[i];
		i++;j++;
	}
	s.branch[j]='\0';
	j=0;i++;
	while(buffer[i]!='|')
	{
		s.rno[j]=buffer[i];
		i++;j++;
	}
	s.rno[j]='\0';
	cout<<s.name<<"  "<<s.branch<<"  "<<s.rno<<endl;
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
	ifstream obj;
	obj.open("myfile.txt");
	while(j<i)
	{
	   unpack(obj);
	   j++;
    }
	obj.close();
	return 0;
}
