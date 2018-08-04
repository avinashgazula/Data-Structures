#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;
struct student
{
	char rollno[6];
	char name[10];
	char marks[3];
};
void pack(ofstream &f,student &s)
{
	char ch[50];
    cout<<"rollno"<<endl;
	cin>>s.rollno;
	strcpy(ch,s.rollno);
    strcat(ch,"|");
	cout<<"name"<<endl;
	cin>>s.name;
	strcat(ch,s.name);
	strcat(ch,"|");
	cout<<"marks"<<endl;
	cin>>s.marks;
	strcat(ch,s.marks);
	strcat(ch,"|");
	f<<ch<<endl;
}
void unpack(ifstream &o,int j)
{
	char ch[100];
	int c=0;
	o.getline(ch,100,'#');
	for (int i=0;ch[i]!='\0';i++)
	{
		
		 if (ch[i]=='\n')
		c++;
else 
if (ch[i]=='|')
		cout<<endl;
		else
		cout<<ch[i];
			if (c==j)
		break;
	}
	cout<<"..................";
}
int main()
{
	int n,d,l;
	cout<<"How many student details?"<<endl;
	cin>>n;
	student s[n];
	ofstream f;
	f.open("f1.txt");
	for (int i=0;i<n;i++)
	pack (f,s[i]);
	f<<'#';
	f.close();
	ofstream h;
	h.open("f2.txt");
	cout<<"how many numbers in f2?"<<endl;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cout<<"number"<<endl;
		cin>>d;
	h<<d<<'|';
}
	h<<'#';
	h.close();
	ifstream g;
	g.open("f2.txt");
	char ch[3];
	g.getline(ch,3,'|');
	int j=ch[0]-'0';
    ifstream k;
    k.open("f1.txt");
    unpack(k,j);
	return 0;
}
