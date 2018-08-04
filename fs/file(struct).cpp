#include<iostream>
#include<fstream>
using namespace std;
struct student
{
	string name;
	int age;
};
int main()
{
	ofstream files("student.txt");
	int b,n;char a;
	cout<<"Enter no. of students in the class\n";
	cin>>n;
	student s[n+10];
	files<<"Name    Age"<<endl;
	for(b=0;b<n;b++)
			{
					cout<<"Enter the name and age of student "<<b+1<<endl;
					cout<<"Name: ";
					cin>>s[b].name;
					cout<<"Age: ";
					cin>>s[b].age;
					files<<s[b].name<<"  "<<s[b].age<<endl;
			}

	cout<<"Do uou want to add more students? or n to quit\n";
	cin>>a;
	if(a=='y'||a=='Y')
		{		n;
				cout<<"Enter the name and age of student "<<b+1;
				cin>>s[n].name>>s[n].age;
				files<<s[n].name<<"  "<<s[n].age<<endl;
		}
	else
	cout<<"The file has all the student details";
	files.close();
	return 0;
	
}
