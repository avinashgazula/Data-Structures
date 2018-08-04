#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>

using namespace std;

struct student{
	char name[20];
	char marks[5];
	char branch[10];
	char *n[20];
	char *b[10];
};

void pack(ofstream &fout)
{
	
	char buffer[100];

	struct student *s;
	s=new student;
		cout<<"Enter student's name\n";
		cin>>s->name;
		strcpy(buffer,s->name);
		strcat(buffer,"|");
		cout<<"Enter student's marks\n";
		cin>>s->marks;
		strcat(buffer,s->marks);
		strcat(buffer,"|");
		cout<<"Enter student's branch\n";
		cin>>s->branch;
		strcat(buffer,s->branch);
		strcat(buffer,"|");
		fout<<buffer;
		cout<<"Data written into the file\n";
}

void unpack(ifstream &fin1)
{
	char buffer[100];
	struct student *s[10];
	for(int x=0;x<10;x++)
	{
		s[x]=NULL;
		s[x]=new student;
	}
	fin1.getline(buffer,100,'\0');
	
	int i=0,j=0,k=0;
	while(buffer[i]!='#')
	{
			
	        j=0;
			while(buffer[i]!='|')
			{
				s[k]->name[j++]=buffer[i++];
				
			}
			s[k]->name[j]='\0';
			
			j=0;i++;
			while(buffer[i]!='|')
			{
				s[k]->marks[j++]=buffer[i++];
			}
			s[k]->marks[j]='\0';
			j=0;i++;
			while(buffer[i]!='|')
			{
				s[k]->branch[j++]=buffer[i++];
			}
			s[k]->branch[j]='\0';
			i++;
			k++;
	}
	
	for(i=0;i<k;i++)
	{
		for(j=i+1;j<k;j++)
		{
			if(s[i]->marks==s[j]->marks)
			{
				s[i]->n=new ch
			}
		}
	}
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
