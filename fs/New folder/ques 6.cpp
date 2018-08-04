#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
struct student
{
	char rno[5];
	char name[100];
	char branch[10];
};
int main()
{
	ofstream fout;
	ifstream fin;
	int n;
	fout.open("myfile.txt");
	cout<<"enter the number of records ";
	cin>>n;
	student s;
	for(int i=0;i<n;i++)
	{
		cout<<"enter student name ";
		cin>>s.name;
		fout<<s.name<<"|";
		cout<<"enter rno ";
		cin>>s.rno;
		fout<<s.rno<<"|";
		cout<<"enter branch ";
		cin>>s.branch;
		fout<<s.branch<<"|";
		fout<<endl;
	}
	fout.close();
	fin.open("myfile.txt");
	int i;
	cout<<"enter rec num ";
	cin>>i;
	int count=0;
	int ch,ch2;
	while(count!=i-1)
	{
		fin>>ch;
		if(ch=='\n')
		count++;
	}
	int p=0,q=0;
	fin>>ch2;
	while(ch2!='|')
	{
		s.name[i]=ch2;
		i++;
		fin>>ch2;
	}
	i=0;
	fin>>ch2;
	while(ch2!='|')
	{
		s.rno[i]=ch2;
		i++;
		fin>>ch2;
	}
	fin>>ch2;
	while(ch2!='|')
	{
		s.branch[i]=ch2;
		i++;
		fin>>ch2;
	}
	fin>>ch2;
	cout<<s.name<<" "<<s.rno<<" "<<s.branch<<endl;
	fin.close();
	return 0;
}
