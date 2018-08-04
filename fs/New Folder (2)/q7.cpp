#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>

using namespace std;

struct student{
	char name[20];
	char rno[5];
	char marks[10];
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
		cout<<"Enter student's marks\n";
		cin>>s.marks;
		strcat(buffer,s.marks);
		strcat(buffer,"|");
		fout<<buffer;
		cout<<"Data written into the file\n";
}

void unpack(ifstream &fin)
{
	char buffer[100];
	struct student s[10];
	fin.getline(buffer,100,'\0');
	
	int i=0,j=0,k=0;
	while(buffer[i]!='#')
	{
			
	        j=0;
			while(buffer[i]!='|')
			{
				s[k].name[j++]=buffer[i++];
				
			}
			s[k].name[j]='\0';
			
			j=0;i++;
			while(buffer[i]!='|')
			{
				s[k].rno[j++]=buffer[i++];
			}
			j=0;i++;
			while(buffer[i]!='|')
			{
				s[k].marks[j++]=buffer[i++];
			}
			s[k].marks[j]='\0';
			i++;
		/*	cout<<"Name :"<<s[k].name<<endl;
			cout<<"R.No :"<<atoi(s[k].rno)<<endl;
			cout<<"Branch :"<<atoi(s[k].branch)<<endl; */
			k++;
	}
	int c=0,c1=0;
	ofstream fout1("file.txt");
	for(i=0;i<k;i++)
	{
		for(j=i+1;j<k;j++)
		{
			string s1=s[i].name;
			string s2=s[j].name;
			int r1=atoi(s[i].rno);
			int r2=atoi(s[j].rno);
			if(r1==r2&&s1==s2)
			{
				fout1<<s[i].marks<<"|"<<s[j].marks<<"|"<<s[i].name<<"|"<<s[i].rno<<endl;
			}
		}
	}
	fout1.close();
}

int main()
{
	ofstream fout;
	fout.open("variablelengthrecords.txt");
	int n,i=0;
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
	
	ifstream fin;
	fin.open("variablelengthrecords.txt");
	unpack(fin);
	fin.close();
}
