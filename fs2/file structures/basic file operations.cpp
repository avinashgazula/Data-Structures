#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
int line(ifstream &fin)
{
	int aNumOfLines = 0;

string aLineStr;
while (getline(fin, aLineStr))
{
    if (!aLineStr.empty())
        aNumOfLines++;
}
}

int main()
{
	ofstream fout;
	fout.open("file.txt");
	char ch[300];
	cout<<"Enter data to be written into the file\n";
	cin.getline(ch,300);
	fout<<ch;
	fout.close();
	ifstream fin("file.txt",ios::in);
	char a[300];
	fin.getline(a,50,'\0');
	int len=strlen(a);
	cout<<"No of characters in the file is "<<len<<endl;
	int i=0,s=0;
	while(a[i]!='\0')
	{
		if(a[i]==' ')
		s++;
		i++;
	}
	cout<<"No of words in the file is "<<s+1<<endl;
	cout<<"no of lines "<<line(fin)<<endl;
	fin.close();
	
	ifstream read("file.txt");
	char str[30],b[50];
	read.getline(b,50,'\0');
	read.close();
	int l1=strlen(b);
	cout<<"Enter string to be searched \n";
	cin>>str;
	int l2=strlen(str);
	int x=0;
	int j,count=0;
	i=0;
	for(i=0;i<l1;i++)
	{
		for(j=0;j<l2;j++)
		{
			if(str[j]==b[i+j])
			{
				count++;
				if(count==l2)
				{
					x=i;
					cout<<"String found\n";
					break;
				}
			}
		}
	}
	int k=x-l2+1;
	cout<<" i & k "<<x<<" "<<k<<endl;
	char x1[k+1],x2[l1-k+1];
	for(i=0;i<k;i++)
	x1[i]=b[i];
	for(i=j;i<l1;i++)
	x2[i-j]=b[i];
	char r[20];
	cout<<"Enter the string it should be replaced with\n";
	cin>>r;
	ofstream write("file1.txt",ios::trunc);
	write<<x1;
	write<<r;
	write<<x2;
	write.close();
	remove("file.txt");
	rename("file1.txt","file.txt");
	ifstream print("file1.txt");
	print.getline(b,30,'\0');
	cout<<b;
}
