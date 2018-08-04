#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;
void add(fstream &fio,int l,int key)
{
	int hash=key%10;
	int h=hash;int i=1;char ch[l];
	fio.seekg(h*l,ios::beg);
	fio<<key;
	itoa(key,ch,l);
	int len=strlen(ch);
	for(i=len;i<l-1;i++)
	fio<<"*";
}
void search(fstream &fin,int l,int a,int key)
{
	int i=0;char c;
	int h=key%10;
	fin.seekg(h*l,ios::beg);
	//fin<<key;
	char ch[l];
	while(1)
	{
		fin>>c;
		if(c=='*'||c=='#')
		break;
		else
		ch[i++]=c;
	}
	ch[i]='\0';
	if(key==atoi(ch))
	cout<<"Key found\n";
	else
	cout<<"Key not found\n";
}
void del(fstream &fin,int l,int a,int key)
{
	int i=0;char c;
	int h=key%10;
	fin.seekg(h*l,ios::beg);
	//fin<<key;
	char ch[l];
	while(1)
	{
		fin>>c;
		if(c=='*'||c=='#')
		break;
		else
		ch[i++]=c;
	}
	ch[i]='\0';
	if(key==atoi(ch))
	{
		fin.seekg(h*l,ios::beg);
		for(int j=0;j<l-1;j++)
		fin<<"*";
		cout<<"key deleted\n";
	}
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
	fstream fio("hash_file.txt");
	int tag;
	cout<<"ENTER KEY -1.QUIT\n";
	cin>>tag;
	while(tag!=-1)
	{
		add(fio,l,tag);
		cout<<"ENTER KEY -1.QUIT\n";
		cin>>tag;
	}
	cout<<"ENTER KEY TO delete -1.QUIT\n";
	cin>>tag;
	while(tag!=-1)
	{
		del(fio,l,a,tag);
		cout<<"ENTER KEY TO delete -1.QUIT\n";
		cin>>tag;
	}
}
