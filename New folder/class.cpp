#include<iostream>
using namespace std;
class stu
{
 public:	int a,m;
};
int main()
{	
	int x=0,y,z;
	cout<<"Enter no. of students in the class";
	cin>>y;
	stu s[y];
	for(x=0;x<y;x++)
	{

		cout<<"Enter age of student "<<x+1<<endl;
		cin>>s[x].a;
		cout<<"Enter marks of student "<<x+1<<endl;
		cin>>s[x].m;
	
	}
	cout<<"enter the no. of student whose details you want to know "<<endl;
	cin>>z;
	cout<<"Age: "<<s[z-1].a<<" Marks: "<<s[z-1].m;
	return 0;
}
