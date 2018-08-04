#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;
struct student
{
	char name[10];
	int rno;
	char branch[5];
};
istream& operator>>(istream& cin,student &s)
{	
	cout<<"Enter name of student "<<" : ";
		cin>>s.name;
		cout<<"Enter R.No : ";
		cin>>s.rno;
		cout<<"Enter Branch : ";
		cin>>s.branch;
};
ofstream& operator<<(ofstream& file,student &s)
{
	file<<s.name<<"\t"<<s.rno<<"\t"<<s.branch<<endl;
};

int main()
{
	ofstream file("students.txt");

	cout<<"Enter the number of students : ";
	int i,j=0,n,a;char ch;
	cin>>n;
	student s[n*2];
	file<<"Name\tR.No\tbranch\n";

	for(i=0;i<n;i++)
	{
		cin>>s[i];
		file<<s[i];
	}
	file.close();	
	char fil[200];

	cout<<"1.Add 2.Delete 3.Exit\n";
		cin>>a;
		if(a==1)
		{	file.open("students.txt",ios::app);
			
					cin>>s[n];
					file<<s[n];
					file.close();
					cout<<"Student details added\n";
					n++;
		}
		if(a==2)
		{	file.open("students.txt",ios::trunc);
			cout<<"Which student record do you want to delete\n";
			int del;
			cin>>del;
			for(i=0,i!=del-1;i<n+j;i++)
			{
				file<<s[i];
			}
			cout<<"The student's records have been deleted\n";
			file.close();
			
		}
		if(a==3)
		{
			file.close();
				exit;
		}
		return 0;
	
}
