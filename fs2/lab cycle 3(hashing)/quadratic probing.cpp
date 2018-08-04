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
void add(ifstream&fin,fstream &fio,int l,int a)
{
	char buffer[100];
	struct student s[a];
	fin.getline(buffer,100,'\0');
	cout<<buffer<<endl;int p=1;
	int i=0,j=0,k=0;int offset=0;
	while(buffer[i]!='#')
	{
			offset=i;
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
			s[k].rno[j]='\0';
			j=0;i++;
			int key=atoi(s[k].rno);
			while(buffer[i]!='|')
			{
				s[k].branch[j++]=buffer[i++];
			}
			s[k].branch[j]='\0';
			i++;
			k++;
			int hash=key%10;
			int h=hash;
			fio.seekg(h*l,ios::beg);
			char t;
			fio>>t;
			fio.seekg(-1,ios::cur);
			if(t=='*')
			{
				fio<<key<<"|"<<offset;
			}
			else
			{
				while(t!='*')
				{
					h=(hash+(p*p))%a;p++;
					fio.seekg(h*l,ios::beg);
					fio>>t;
					fio.seekg(-1,ios::cur);
				}
				fio<<key<<"|"<<offset;
			}
	}
}

int main()
{
	ofstream fout("hash_file.txt");
	int l,a;
	cout<<"Enter the length of the record\n";
	cin>>l;
	cout<<"Enter the address space\n";
	cin>>a;
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<l-1;j++)
		fout<<"*";
		fout<<"#";
	}
	fout.close();
	ifstream fin("variablelengthrecords.txt");
	fstream fio("hash_file.txt");
	add(fin,fio,l,a);
	fin.close();
	fio.close();
}
