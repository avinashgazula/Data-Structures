#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>

using namespace std;

struct student{
	char name[20];
	char rno[5];
	char branch[10];
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
				s[k].branch[j++]=buffer[i++];
			}
			s[k].branch[j]='\0';
			i++;
			cout<<"Name :"<<s[k].name<<endl;
			cout<<"R.No :"<<atoi(s[k].rno)<<endl;
			cout<<"Branch :"<<s[k].branch<<endl;
			k++;
	}

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
