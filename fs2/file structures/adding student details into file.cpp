#include<iostream>
#include<fstream>
using namespace std;
struct student
{
	char name[100];
	char section;
	int rno;
};
int main()
{
	ofstream fout;
	fout.open("students.txt");
	student s[10];
	int n;
	cout<<"enter the num of students ";
	cin>>n;
	int i;
	for(i=0;i<n;i++)
	{
		cout<<"enter the name of student"<<endl;
		cin>>s[i].name;
		cout<<"enter section"<<endl;
		cin>>s[i].section;
		cout<<"enter the rno of student"<<endl;
		cin>>s[i].rno;
		fout<<s[i].name<<" "<<s[i].section<<" "<<s[i].rno<<endl;
	}
	cout<<"add a student detail ";
	cout<<"enter the name of student"<<endl;
	cin>>s[i].name;
	cout<<"enter section"<<endl;
	cin>>s[i].section;
	cout<<"enter the rno of student"<<endl;
	cin>>s[i].rno;
	fout<<s[i].name<<" "<<s[i].section<<" "<<s[i].rno<<endl;
	fout.close();
	return 0;
}
