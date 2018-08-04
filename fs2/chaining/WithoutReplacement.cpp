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
void add(fstream&fin,fstream &fio,int l,int a,int chain)
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
		s[k].name[j++]=buffer[i++];
		s[k].name[j]='\0';
		j=0;i++;
		while(buffer[i]!='|')
		s[k].rno[j++]=buffer[i++];
		s[k].rno[j]='\0';
		j=0;i++;
		int key=atoi(s[k].rno);
		while(buffer[i]!='|')
		s[k].branch[j++]=buffer[i++];
		s[k].branch[j]='\0';
		i++;
		k++;
		int hash=key%a;
		int h=hash;
		fio.seekg(h*l,ios::beg);
		char t;
		fio>>t;
		fio.seekg(-1,ios::cur);
		if(t=='*'||t=='^')
		{
			fio<<key<<"|"<<offset<<"|-1";
		}
		else
		{
			char c,cn[l];int i=0;
			while(t!='*'&&t!='^')
			{
				h=(hash+p)%a;p++;
				fio.seekg(h*l,ios::beg);
				chain=h;
				fio>>t;
				fio.seekg(-1,ios::cur);
			}
			fio<<key<<"|"<<offset<<"|-1";
			fio.seekg(key%a*l,ios::beg);
			fio>>c;
			while(c!='|')
			fio>>c;
			fio>>c;
			while(c!='|')
	    	fio>>c;
			int len=fio.tellg();
			while(c!='*'&&c!='#')
			{
				fio>>c;
				cn[i++]=c;
			}
			while(atoi(cn)!=-1)
			{
				i=0;
				int r=atoi(cn);
				for(int x=0;x<5;x++)
				cn[x]='\0';
				fio.seekg(r*l,ios::beg);
				while(c!='|')
				fio>>c;
				fio>>c;
				while(c!='|')
				fio>>c;
				len=fio.tellg();
				while(c!='*'&&c!='#')
				{
					fio>>c;
					cn[i++]=c;
				}
			}
			fio.seekg(len,ios::beg);
			fio<<chain;
			fio>>c;
			fio.seekg(-1,ios::cur);
			while(c!='#')
			{
				fio<<"*";
		    	fio>>c;
				fio.seekg(-1,ios::cur);
			}
		}
	}
}
void del(fstream &fin,int l,int a,int key,int count,int radix)
{
	cout<<"deleting\n";
	int i=0,pos=0,z=0;char c,t;
	int h=key%10;
	pos=((h+count)%a)*l;
	if(count==0||radix==-1)
	{
		fin.seekg(pos,ios::beg);
		z=pos%a;
	}
	else 
	{
		fin.seekg(l*radix,ios::beg);
		z=radix;
	}
	count++;
	char ch[l];ch[0]='\0';
	fin>>t;
	fin.seekg(-1,ios::cur);
	if(t=='^')
	{
		cout<<"z "<<z<<endl;
		cout<<"Key at the original location has already been deleted\n";
		del(fin,l,a,key,count,(z+1));
	}
	while(1)
	{
		fin>>c;
		if(c=='^'||c=='*'||c=='#'||c=='|')
		break;
		else
		ch[i++]=c;
	}
	ch[i]='\0';char p[l];int q=0,loc=0;
	fin>>c;
	while(c!='|')
	fin>>c;
	while(c!='*'&&c!='#')
	{
		fin>>c;
		p[q++]=c;
	}
	loc=atoi(p);
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
	else if(loc==-1)
	del(fin,l,a,key,(loc+1)%a,loc);
	else if(c=='^'||key!=atoi(ch))
	del(fin,l,a,key,count,loc);
	else
	cout<<"Key not found\n";
}
int main()
{
	ofstream fout("chain_file.txt");
	int l,a,chain=-1;
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
	fstream fio("chain_file.txt");
	add(fin,fio,l,a,chain);
	fio.seekg(0,ios::beg);
	int count=0,key;
	cout<<"ENTER KEY TO delete -1.QUIT\n";
	cin>>key;int radix=-1;
	while(key!=-1)
	{
		del(fio,l,a,key,count,radix);
		cout<<"ENTER KEY TO delete -1.QUIT\n";
		cin>>key;
	}
	fin.close();
	fio.close();
}
