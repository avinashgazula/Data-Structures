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
	strcat(buffer,"|");
	cout<<"enter branch"<<endl;
	cin>>s.branch;
	strcat(buffer,s.branch);
	strcat(buffer,"|");
	cout<<"enter roll num"<<endl;
	cin>>s.rno;
	strcat(buffer,s.rno);
	strcat(buffer,"|");
	int len=strlen(buffer);
	cout<<"the length of input given is "<<len<<endl;
	int i=0;
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
	ifstream fin;
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
