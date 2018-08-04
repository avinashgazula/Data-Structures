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
	
	char buffer[100];

	struct student s;
	
		cout<<"Enter student's name\n";
		cin>>s.name;
		strcpy(buffer,s.name);
		strcat(buffer,"|");
		cout<<"Enter student's roll no\n";
		cin>>s.rno;
		strcat(buffer,s.rno);
		strcat(buffer,"|");
		cout<<"Enter student's branch\n";
		cin>>s.branch;
		strcat(buffer,s.branch);
		strcat(buffer,"#");
		fout<<buffer;
		cout<<"Data written into the file\n";
}

void unpack(ifstream &fin)
{
	char buffer[100];
	struct student s;
	fin.getline(buffer,100,'#');
	
	int i=0,j=0;
	while(buffer[i]!='|')
	{
		s.name[j++]=buffer[i++];
		
	}
	
	j=0;i++;
	while(buffer[i]!='|')
	{
		s.rno[j++]=buffer[i++];
	}
	j=0;i++;
	while(buffer[i]!='\0')
	{
		s.branch[j++]=buffer[i++];
	}
	cout<<"Name :"<<s.name<<endl;
	cout<<"R.No :"<<atoi(s.rno)<<endl;
	cout<<"Branch :"<<s.branch<<endl;
}

int main()
{
	ofstream fout;
	fout.open("variablelengthrecords.txt");
	pack(fout);
	fout.close();
	
	ifstream fin;
	fin.open("variablelengthrecords.txt");
	unpack(fin);
	fin.close();
}
