#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;

struct student{
	char name[10];
	char marks[5];
	char branch[5];
};

void packvl(ofstream &fout)
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

void packfl(ofstream &fout)
{
	student *s;
	s=new student;
	char buffer1[100];
	int l1,l2,l3;
	cout<<"Enter student's name\n";
	cin>>s->name;
	l1=strlen(s->name);
	strcpy(buffer1,s->name);
	for(int i=l1;i<10;i++)
	{
		strcat(buffer1,"*");
	}
	strcat(buffer1,"|");
	
	
	cout<<"Enter student's marks\n";
	cin>>s->marks;
	l2=strlen(s->marks);
	strcat(buffer1,s->marks);
	for(int i=l2;i<5;i++)
	{
		strcat(buffer1,"*");
	}
	strcat(buffer1,"|");
	
	
	cout<<"Enter student's branch\n";
	cin>>s->branch;
	l3=strlen(s->branch);
	strcat(buffer1,s->branch);
	for(int i=l3;i<5;i++)
	{
		strcat(buffer1,"*");
	}
	strcat(buffer1,"|");
	fout<<buffer1;
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
	cout<<"TEST\n";
	char buffer1[100];
	fin2.getline(buffer1,100,'\0');
	i=0,j=0;
	while(buffer1[i]!='#')
	{
		
			j=0;
			while(buffer1[i]!='*'&&buffer1[i]!='|')
			{
				s[k]->name[j++]=buffer1[i++];
			}
			s[k]->name[j]='\0';
			j=0;
			
			while(buffer1[i]=='*'||buffer1[i]=='|')
			{
				i++;
			}
			
			
			while(buffer1[i]!='*'&&buffer1[i]!='|')
			{
				s[k]->marks[j++]=buffer1[i++];
			}
			s[k]->marks[j]='\0';
			j=0;
			while(buffer1[i]=='*'||buffer1[i]=='|')
			{
				i++;
			}
			while(buffer1[i]!='*'&&buffer1[i]!='|')
			{
				s[k]->branch[j++]=buffer1[i++];
				
			}
			s[k]->branch[j]='\0';
			while(buffer1[i]=='*'||buffer1[i]=='|')
			{
				i++;
			}
			k++;
	}
	cout<<"TEST1\n";
	for(i=0;i<k;i++)
	{
		for(j=0;j<k;j++)
		{
			int a1=atoi(s[i]->marks);
			int a2=atoi(s[j]->marks);
			if(a1<a2)
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
	ofstream foutfl;
	foutfl.open("fixedlengthrecords.txt");
	cout<<"FILE1 FIXED LENGTH\n";
	int n;
	cout<<"1.Enter details -1.Quit\n";
	cin>>n;
	while(n!=-1)
	{
		
		packfl(foutfl);
		
		cout<<"1.Enter details -1.Quit\n";
		cin>>n;
	}
	foutfl<<"#";
	foutfl.close();
	
	ofstream foutvl;
	foutvl.open("variablelengthrecords.txt");
	cout<<"FILE2 VARIABLE LENGTH\n";
	cout<<"1.Enter student details. -1.Quit\n";
	cin>>n;
	while(n!=-1)
	{
		packvl(foutvl);
		cout<<"1.Enter student details. -1.Quit\n";
		cin>>n;
	}
	foutvl<<"#";
	foutvl.close();
	ifstream fin1;
	foutfl.open("fixedlengthrecords.txt");
	ifstream fin2;
	fin2.open("variablelengthrecords.txt");
	unpack(fin1,fin2);
	fin1.close();
	fin2.close();
	
}
