#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;

struct student{
	char name[10];
	char rno[5];
	char branch[5];
};


void pack(ofstream &fout)
{
	student s;
	char buffer[100];
	int l1,l2,l3;
	cout<<"Enter student's name\n";
	cin>>s.name;
	l1=strlen(s.name);
	strcpy(buffer,s.name);
	for(int i=l1;i<10;i++)
	{
		strcat(buffer,"*");
	}
	strcat(buffer,"|");
	
	
	cout<<"Enter student's roll no\n";
	cin>>s.rno;
	l2=strlen(s.rno);
	strcat(buffer,s.rno);
	for(int i=l2;i<5;i++)
	{
		strcat(buffer,"*");
	}
	strcat(buffer,"|");
	
	
	cout<<"Enter student's branch\n";
	cin>>s.branch;
	l3=strlen(s.branch);
	strcat(buffer,s.branch);
	for(int i=l3;i<5;i++)
	{
		strcat(buffer,"*");
	}
	strcat(buffer,"#");
	fout<<buffer;
	cout<<"Data written into the file\n";
}

void unpack(ifstream &fin)
{
	struct student s;
	char buffer[100];
	fin.getline(buffer,100,'\0');
	int i=0,j=0;
	
	while(buffer[i]!='*'&&buffer[i]!='|')
	{
		s.name[j++]=buffer[i++];
	}
	j=0;
	
	while(buffer[i]=='*'||buffer[i]=='|')
	{
		i++;
	}
	
	
	while(buffer[i]!='*'&&buffer[i]!='|')
	{
		s.rno[j++]=buffer[i++];
	}
	j=0;
	while(buffer[i]=='*'||buffer[i]=='|')
	{
		i++;
	}

	
	while(buffer[i]!='*'&&buffer[i]!='#')
	{
		s.branch[j++]=buffer[i++];
		
	}
	
	cout<<"Name :\t\t"<<s.name<<endl;
	cout<<"Roll no :\t"<<atoi(s.rno)<<endl;
	cout<<"Branch :\t"<<s.branch<<endl;
	
}


int main()
{
	ofstream fout;
	fout.open("flr.txt");
	pack(fout);
	fout.close();
	
	ifstream fin;
	fin.open("flr.txt");
	unpack(fin);
	fin.close();
}
