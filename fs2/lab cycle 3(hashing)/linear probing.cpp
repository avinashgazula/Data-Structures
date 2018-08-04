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
void add(fstream&fin,fstream &fio,int l,int a)
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
			if(t=='*'||t=='^')
			{
				fio<<key<<"|"<<offset;
			}
			else
			{
				while(t!='*'&&t!='^')
				{
					h=(hash+p)%a;p++;
					fio.seekg(h*l,ios::beg);
					fio>>t;
					fio.seekg(-1,ios::cur);
				}
				fio<<key<<"|"<<offset;
			}
	}
}
void del(fstream &fin,int l,int a,int key,int count)
{
	int i=0,pos=0;char c,t;
	int h=key%10;
	pos=((h+count)%a)*l;
	fin.seekg(pos,ios::beg);
	count++;
	char ch[l];ch[0]='\0';
	fin>>t;
	fin.seekg(-1,ios::cur);
	if(count==1&&t=='^')
	{
		cout<<"Key at the original location has already been deleted\n";
		del(fin,l,a,key,count);
	}
	
	while(1)
	{
		fin>>c;
		if(c=='^'||c=='*'||c=='#'||c=='|')
		break;
		else
		ch[i++]=c;
	}
	ch[i]='\0';
	if(key==atoi(ch))
	{
		fin.seekg(pos,ios::beg);
		for(int j=0;j<l-1;j++)
		fin<<"^";
		cout<<"key deleted\n";
		count=0;
		fin.seekg(0,ios::beg);
		exit;
	}
	else if(c=='^'||key!=atoi(ch))
	del(fin,l,a,key,count);
	else
	cout<<"Key not found\n";
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
	fstream fin("variablelengthrecords.txt");
	fstream fio("hash_file.txt");
	add(fin,fio,l,a);
	fio.seekg(0,ios::beg);
	int count=0,key;
	cout<<"ENTER KEY TO delete -1.QUIT\n";
	cin>>key;
	while(key!=-1)
	{
		del(fio,l,a,key,count);
		cout<<"ENTER KEY TO delete -1.QUIT\n";
		cin>>key;
	}
	fin.close();
	fio.close();
}
