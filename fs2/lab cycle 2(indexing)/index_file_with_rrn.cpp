#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;
struct student{
	char name[10];
	char rno[5];
	char branch[5];
};
void unpack(ifstream &fin,int index[][2],int &k)
{
	struct student s;
	char key[5],rrn[3];
	char buffer[100];
	fin.getline(buffer,100,'\0');
	int i=0,j=0;
	while(buffer[i]!='$')
	{
			while(buffer[i]!='|')
			rrn[j++]=buffer[i++];
			rrn[j]='\0';
			i++;
			j=0;
			while(buffer[i]!='|')
			i++;
			i++;
			while(buffer[i]!='*'&&buffer[i]!='|')
			{
				key[j++]=buffer[i++];
			}
			key[j]='\0';
			j=0;
			while(buffer[i]!='#')
			i++;
			i++;
			cout<<"key: "<<atoi(key)<<" ";
			cout<<"Rrn: "<<atoi(rrn)<<endl;
			index[k][0]=atoi(key);
			index[k][1]=atoi(rrn);
			k++;
	}
	int temp[2];
	for(i=0;i<k;i++)
	{
		for(j=0;j<k;j++)
		{
			if(index[i][0]<index[j][0])
			{
				temp[0]=index[j][0];
				temp[1]=index[j][1];
				index[j][0]=index[i][0];
				index[j][1]=index[i][1];
				index[i][0]=temp[0];
				index[i][1]=temp[1];
			}
		}
	}
}
void search(ifstream &fin,int index[][2],int k)
{
	int a;student s;
	cout<<"enter the key for which you want records\n";
	cin>>a;
	int i=0,j=0,rrn=-1,count=0;
	while(1)
	{
		if(index[(j+k)/2][0]==a)
		{
			rrn=index[(j+k)/2][1];
			break;
		}
		else if(index[(j+k)/2][0]>a)
		k=k/2;
		else
		{
			if(j==k/2)
			break;
			j=k/2;
		}
		if(j==k)
		break;
	}
	if(rrn==-1)
	cout<<"key not found\n";
	else
	{
		cout<<"key found\n";
		fin.seekg(rrn*25,ios::beg);
		char buffer[26];
		fin.getline(buffer,26,'#');
		i=2;
		while(buffer[i]!='\0')
		{
			j=0;
			
			while(buffer[i]!='*'&&buffer[i]!='|')
			{
				s.name[j++]=buffer[i++];
			}
			s.name[j]='\0';
			j=0;
			while(buffer[i]=='*'||buffer[i]=='|')
			{
				i++;
			}
			while(buffer[i]!='*'&&buffer[i]!='|')
			{
				s.rno[j++]=buffer[i++];
			}
			j=0;
			while(buffer[i]=='*'||buffer[i]=='|')
			{
				i++;
			}
			while(buffer[i]!='*'&&buffer[i]!='|')
			{
				s.branch[j++]=buffer[i++];
				
			}
			s.branch[j]='\0';
			while(buffer[i]=='*'||buffer[i]=='|')
			{
				i++;
			}
			cout<<"Name :\t\t"<<s.name<<endl;
			cout<<"Roll no :\t"<<atoi(s.rno)<<endl;
			cout<<"Branch :\t"<<s.branch<<endl;
		}
	}
}
int main()
{
	int k=0;
	ifstream fin;int index[10][2];
	fin.open("fixedlengthrecords.txt");
	unpack(fin,index,k);
	for(int i=0;i<k;i++)
	cout<<index[i][0]<<" "<<index[i][1]<<endl;
	while(1)
	search(fin,index,k);
	fin.close();
}
