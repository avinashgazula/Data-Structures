#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>

using namespace std;
struct dob{
	int day;
	int month;
	int year;
};
struct person{
	string name;
	dob date;
	int id;
};
void bifercate(ifstream &fin,char ch[])
{
//	cout<<ch<<endl;
	char buffer[100];
	struct person *s[10];
	for(int x=0;x<10;x++)
	{
		s[x]=NULL;
	}
	fin.getline(buffer,100,'\0');
	
	int i=0,j=0,k=0;
	while(buffer[i]!='#')
	{
			s[k]=new person;
	        j=0;
			while(buffer[i]!='|')
			{
				s[k]->name[j++]=buffer[i++];
				
			}
			s[k]->name[j]='\0';
			
			j=0;i++;
			char di[5];
			while(buffer[i]!='|')
			{
				di[j++]=buffer[i++];
			}
			di[j]='\0';
			s[k]->id==atoi(di);
			j=0;i++;
			char dd[3],mm[3],yy[5];
			while(buffer[i]!='/')
			{
				dd[j++]=buffer[i++];
			}
			dd[j]='\0';
			s[k]->date.day=atoi(dd);
			i++;j=0;
			while(buffer[i]!='/')
			{
				mm[j++]=buffer[i++];
			}
			mm[j]='\0';
			s[k]->date.month=atoi(mm);
			i++;j=0;
			while(buffer[i]!='|')
			{
				yy[j++]=buffer[i++];
			}
			yy[j]='\0';
			s[k]->date.year==atoi(yy);
			k++;i++;
			cout<<"test\n";
	}
	
	char dd[3],mm[3],yy[5];
	dd[0]=ch[0];
	dd[1]=ch[1];
	dd[2]='\0';
	int d=atoi(dd);
	mm[0]=ch[3];
	mm[1]=ch[4];
	mm[2]='\0';
	int m=atoi(mm);
	yy[0]=ch[6];
	yy[1]=ch[7];
	yy[2]=ch[8];
	yy[3]=ch[9];
	yy[4]='\0';
	int y=atoi(yy);
	ofstream f1("file2.txt");
	ofstream f2("file3.txt");
	for(i=0;i<k;i++)
	{
		if(y>s[i]->date.year||(y==s[i]->date.year&&m>s[i]->date.month)||(y==s[i]->date.year&&m==s[i]->date.month&&d>s[i]->date.day))
		{
			f1<<s[i]->name;
			f1<<"|";
			f1<<s[i]->id;
			f1<<"|";
			f1<<s[i]->date.day;
			f1<<"/";
			f1<<s[i]->date.month;
			f1<<"/";
			f1<<s[i]->date.year;
			f1<<"|";
		}
		else
		if(y<s[i]->date.year||(y==s[i]->date.year&&m<s[i]->date.month)||(y==s[i]->date.year&&m==s[i]->date.month&&d<s[i]->date.day))
		{
			f2<<s[i]->name;
			f2<<"|";
			f2<<s[i]->id;
			f2<<"|";
			f2<<s[i]->date.day;
			f2<<"/";
			f2<<s[i]->date.month;
			f2<<"/";
			f2<<s[i]->date.year;
			f2<<"|";
		}
	}
	cout<<"output 1 created\n";
	cout<<"output 2 created\n";
	f1.close();
	f2.close();
}
int main()
{
	int n;
	cout<<"Enter the no of persons\n";
	cin>>n;
	person p[n];
	char d[3],m[3],year[5];
	ofstream fout("file1.txt");
	for(int i=0;i<n;i++)
	{
		cout<<"Enter name :";
		cin>>p[i].name;
		fout<<p[i].name;
		fout<<"|";
		cout<<"Enter id :";
		cin>>p[i].id;
		fout<<p[i].id;
		fout<<"|";
		cout<<"enter day :";
		cin>>p[i].date.day;
		fout<<p[i].date.day;
		fout<<"/";
		cout<<"enter month :";
		cin>>p[i].date.month;
		fout<<p[i].date.month;
		fout<<"/";
		cout<<"enter year :";
		cin>>p[i].date.year;
		fout<<p[i].date.year;
		fout<<"|";
		cout<<endl;
	}
	fout.close();
	ifstream fin("file1.txt");
	char ch[12];
	cout<<"Enter the date\n";
	cin>>ch;
	bifercate(fin,ch);
	fin.close();
}
