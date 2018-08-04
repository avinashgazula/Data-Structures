#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;
struct student
{
	char name[10];
	int age;
};
ofstream& operator<<(ofstream& fout,student &s)
{
	fout<<s.name<<"\t";
	fout<<s.age<<endl;;
};

istream& operator>>(istream& cin,student &s)
{	
	cout<<"Name :";
	cin>>s.name;
	cout<<"Age :";
	cin>>s.age;
};

int main()
{
	
	ofstream fout("Data.txt");
	int i,n;
	cout<<"Enter no. of students :";
	cin>>n;
	struct student st[n];
	fout<<"Name\tAge\n";
	for(i=0;i<n;i++)
	{
		cout<<"Enter name and age of student "<<i+1<<endl;
		cin>>st[i];
		fout<<st[i];
		cout<<"The details have been sent into the file";
	}
	return 0;
}
