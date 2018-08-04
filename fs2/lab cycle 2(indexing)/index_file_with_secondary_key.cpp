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
void unpack(ifstream &fin)
{
	ofstream fout1("index_file.txt");
	ofstream fout2("sec_index_file.txt");
	char key[5],rrn[3],name[15];int k=0;
	char buffer[100];
	fin.getline(buffer,100,'\0');
	int i=0,j=0;int offset=0;
	while(buffer[i]!='$')
	{
		offset=i;
		while(buffer[i]!='|')
		rrn[j++]=buffer[i++];
		rrn[j]='\0';
		i++;
		j=0;
		while(buffer[i]!='|'&&buffer[i]!='*')
		{
			name[j++]=buffer[i++];
		}
		name[j]='\0';
		j=0;
		i++;
		while(buffer[i]=='*'||buffer[i]=='|')
		i++;
		while(buffer[i]!='*'&&buffer[i]!='|')
		{
			key[j++]=buffer[i++];
		}
		key[j]='\0';
		j=0;
		while(buffer[i]!='#')
		i++;
		i++;
		cout<<"key: "<<atoi(key)<<" ";
		cout<<"name: "<<name<<" ";
		cout<<"Rrn: "<<atoi(rrn)<<endl;
		fout1<<key<<" "<<offset<<endl;
		fout2<<name<<" "<<key<<endl;
		k++;
	}
}
void search()
{
	ifstream fin;
	fin.open("fixedlengthrecords.txt");
	struct student s;int r,l;
	char namee[15],rn[5];char offset[5];char key[5],rrn[3],name[15],branch[5];
	ifstream fin1("index_file.txt");
	ifstream fin2("sec_index_file.txt");
	cout<<"Enter the name\n";
	cin>>namee;
	while(!fin2.eof())
	{
		struct student s;
		fin2>>s.name>>s.rno;
		int l1=strlen(namee);int l2=strlen(s.name);int c=0;
		if(l1==l2)
		{
			for(int i=0;i<l1;i++)
			{
				if(namee[i]==s.name[i])
				c++;
			}
			if(c==l1)
			{
				r=atoi(s.rno);
				break;
			}
		}
	}
	int r1;
	fin2.seekg(0,ios::beg);
	while(!fin1.eof())
	{
		fin1>>rn>>offset;
		r1=atoi(rn);l=atoi(offset);
		if(r1==r)
		break;
	}
	fin1.seekg(0,ios::beg);
	fin.seekg(l,ios::beg);
	char buffer[25];
	fin.getline(buffer,25);int i=0,j=0;
	cout<<buffer<<endl;
	while(buffer[i]!='|')
		rrn[j++]=buffer[i++];
		rrn[j]='\0';
		i++;
		j=0;
		while(buffer[i]!='|'&&buffer[i]!='*')
		{
			name[j++]=buffer[i++];
		}
		name[j]='\0';
		j=0;
		i++;
		while(buffer[i]=='*'||buffer[i]=='|')
		i++;
		while(buffer[i]!='*'&&buffer[i]!='|')
		{
			key[j++]=buffer[i++];
		}
		key[j]='\0';
		j=0;
		while(buffer[i]=='*'||buffer[i]=='|')
		i++;
		while(buffer[i]!='*'&&buffer[i]!='|')
		{
			branch[j++]=buffer[i++];
		}
		branch[j]='\0';
		j=0;
		while(buffer[i]!='#')
		i++;
		i++;
		cout<<"Roll No: "<<atoi(key)<<endl;
		cout<<"branch :"<<branch<<" ";
		cout<<"Rrn: "<<atoi(rrn)<<endl;
	fin.seekg(0,ios::beg);
	fin1.close();
	fin2.close();
}
int main()
{
	ifstream fin;
	fin.open("fixedlengthrecords.txt");
	unpack(fin);
	while(1)
	search();
	fin.close();
}
