#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>

using namespace std;

struct student{
	char name[20];
	char marks[5];
	char branch[10];
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

void unpack(ifstream &fin1,ifstream &fin2)
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
	
	char buffer1[100];
	fin2.getline(buffer1,100,'\0');
	
	i=0,j=0;
	while(buffer1[i]!='#')
	{
			
	        j=0;
			while(buffer1[i]!='|')
			{
				s[k]->name[j++]=buffer1[i++];
				
			}
			s[k]->name[j]='\0';
			
			j=0;i++;
			while(buffer1[i]!='|')
			{
				s[k]->marks[j++]=buffer1[i++];
			}
			s[k]->marks[j]='\0';
			j=0;i++;
			while(buffer1[i]!='|')
			{
				s[k]->branch[j++]=buffer1[i++];
			}
			s[k]->branch[j]='\0';
			i++;
			k++;
	}
	
	for(i=0;i<k;i++)
	{
		for(j=0;j<k;j++)
		{
			int a1=atoi(s[i]->marks);
			int a2=atoi(s[j]->marks);
			if(a1>a2)
			{
				student *temp;
				temp=s[i];
				s[i]=s[j];
				s[j]=temp;
				
			}
		}
	}
	ofstream write("file3.txt");
	for(i=0;i<k;i++)
	{
		write<<s[i]->name;
		write<<"|";
		write<<s[i]->marks;
		write<<"|";
		write<<s[i]->branch;
		if(i==k-1)
		write<<"#";
		else
		write<<"|";
	}
	write.close();

}

int main()
{
	ofstream fout;
	fout.open("file1.txt");
	int n,i=0;
	cout<<"FILE1\n";
	cout<<"1.Enter student details. -1.Quit\n";
	cin>>n;
	while(n!=-1)
	{
		pack(fout);
		cout<<"1.Enter student details. -1.Quit\n";
		cin>>n;
	}
	fout<<"#";
	
	fout.close();
	
	ofstream fout1;
	fout1.open("file2.txt");
	i=0;
	cout<<"FILE2\n";
	cout<<"1.Enter student details. -1.Quit\n";
	cin>>n;
	while(n!=-1)
	{
		pack(fout1);
		cout<<"1.Enter student details. -1.Quit\n";
		cin>>n;
	}
	fout1<<"#";
	
	fout1.close();
	
	ifstream fin1;
	fin1.open("file1.txt");
	ifstream fin2;
	fin2.open("file2.txt");
	unpack(fin1,fin2);
	fin1.close();
	fin2.close();
}
