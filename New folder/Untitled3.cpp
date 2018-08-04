#include<iostream>
using namespace std;
struct student
{
	char name[30];
	int ht;
};
int main()
{

	 int h,a,b,z,i,c=0;
	 cout<<"Enter the no. of students : ";
	 cin>>a;
	 student s[a];
	 for(b=0;b<a;b++)
	 {
	 
		 cout<<"Enter the name and height of student"<<b+1<<endl<<"Name: ";
		 cin>>s[b].name;
		 cout<<"Height(in cm): ";
		 cin>>s[b].ht;
	 
	}
	
	cout<<"enter the no. of student whose details you want to know "<<endl;
	cin>>z;
	for(i=0;i<a;i++)
	{
		
		if(s[z-1].ht<s[i].ht)
		c++;
	}
	cout<<"Name: "<<s[z-1].name<<" Height: "<<s[z-1].ht<<endl<<" and he is shorter than "<<c<<" student(s)";
	return 0;
	 
}
