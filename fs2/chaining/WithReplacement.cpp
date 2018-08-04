#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;
struct student{
	char name[20];
	char rno[5];
	char branch[10];
};
void add(fstream&fin,fstream &fio,int l,int a,int chain)
{
	char buffer1[100];
	struct student s[a];
	fin.getline(buffer1,100,'\0');
	cout<<buffer1<<endl;int p=1;
	int i=0,j=0,k=0;int offset=0;
	while(buffer1[i]!='#')
	{
		offset=i;
	    j=0;
		while(buffer1[i]!='|')
		s[k].name[j++]=buffer1[i++];
		s[k].name[j]='\0';
		j=0;i++;
		while(buffer1[i]!='|')
		s[k].rno[j++]=buffer1[i++];
		s[k].rno[j]='\0';
		j=0;i++;
		int key=atoi(s[k].rno);
		while(buffer1[i]!='|')
		s[k].branch[j++]=buffer1[i++];
		s[k].branch[j]='\0';
		i++;
		k++;
		int hash=key%a;
		int h=hash;
		fio.seekg(h*l,ios::beg);
		char t;
		fio>>t;
		fio.seekg(-1,ios::cur);
		cout<<"KEY "<<key<<" OFFSET "<<offset<<endl;
		if(t=='*'||t=='^')
		{
			fio<<key<<"|"<<offset<<"|-1";
		}
		else
		{
			cout<<"hello";
			char c,cn[l];int v=0;char nos[5];int x=0;
			fio.seekg(h*l,ios::beg);
			while(1)
			{
				fio>>c;
				if(c=='|'||c=='#')
				break;
				nos[v++]=c;
			}
			nos[v]='\0';
			int no=atoi(nos);
			cout<<"NO "<<h<<" "<<nos;
			if(no%a==h)
			{
				cout<<"BOOOO"<<h<<endl;
				fio.seekg(h*l,ios::beg);
				fio>>t;
				fio.seekg(-1,ios::cur);
				while(t!='*'&&t!='^')
				{
					h=(hash+p)%a;p++;
					fio.seekg(h*l,ios::beg);
					chain=h;
					fio>>t;
					fio.seekg(-1,ios::cur);
				}
				cout<<"CHAIN"<<chain;
				fio<<key<<"|"<<offset<<"|-1";
				fio.seekg(key%a*l,ios::beg);
				fio>>c;
				while(c!='|')
				fio>>c;
				fio>>c;
				while(c!='|')
		    	fio>>c;
				int len=fio.tellg();
				while(c!='*'&&c!='#')
				{
					fio>>c;
					cn[v++]=c;
				}
				while(atoi(cn)!=-1)
				{
					v=0;
					int r=atoi(cn);
					for(int x=0;x<5;x++)
					cn[x]='\0';
					fio.seekg(r*l,ios::beg);
					while(c!='|')
					fio>>c;
					fio>>c;
					while(c!='|')
					fio>>c;
					len=fio.tellg();
					while(c!='*'&&c!='#')
					{
						fio>>c;
						cn[v++]=c;
					}
				}
				fio.seekg(len,ios::beg);
				fio<<chain;
				fio>>c;
				fio.seekg(-1,ios::cur);
				while(c!='#')
				{
					fio<<"*";
			    	fio>>c;
					fio.seekg(-1,ios::cur);
				}
			}
			else
			{
				cout<<"no "<<no<<" test\n";p=1;
				char buffer[l];
				fio.seekg(h*l,ios::beg);int z=0,len=0;
				while(1)
				{
					fio>>c;
					if(c=='#')
					break;
					buffer[z++]=c;
				}
				fio.seekg(h*l,ios::beg);
				//cout<<key<<"|"<<offset<<"|-1";
				fio<<key<<"|"<<offset<<"|-1";
				hash=no%a;
				h=hash;
				fio.seekg(h*l,ios::beg);
				fio>>t;
				fio.seekg(-1,ios::cur);
				while(t!='*'&&t!='^')
				{
					h=(hash+p)%a;p++;
					fio.seekg(h*l,ios::beg);
					chain=h;
					fio>>t;
					fio.seekg(-1,ios::cur);
				}
				fio<<buffer;
				fio.seekg(no%a*l,ios::beg);
	  	    	/*char print[100];
				fio.getline(print,100);
				cout<<chain<<"print "<<print;*/
				//cout<<"ret "<<no%a;
				fio>>c;
				while(c!='|')
				fio>>c;
				fio>>c;
				while(c!='|')
		    	fio>>c;
		    	len=fio.tellg();
		    	int loon=len;
				int g=0;
				while(c!='*'&&c!='#')
				{
					cout<<"c"<<c;
					fio>>c;
					cn[g++]=c;
				}
				cout<<"cn "<<atoi(cn)<<"chain "<<chain;
				while(atoi(cn)!=-1)
				{
				//	cout<<"hellooo"<<atoi(cn)*l<<endl;
					char rec[l],cn2[l];
					v=0;
					int r=atoi(cn);
					for(int x=0;x<5;x++)
					cn[x]='\0';
					fio.seekg(r*l,ios::beg);
					cout<<"r*l "<<r*l<<" ";
					fio>>c;
					while(c!='|')
					fio>>c;
					fio>>c;
					while(c!='|')
					fio>>c;
					len=fio.tellg();
					cout<<"len1 "<<len;
					while(c!='*'&&c!='#')
					{
						fio>>c;
						cn[v++]=c;
					}
					fio.seekg(r*l,ios::beg);
					while(1)
					{
						fio>>c;
						if(c=='|')
						break;
						rec[v++]=c;
					}
					int rool=atoi(rec);
					if(atoi(cn)!=-1&&rool%a==no%a)
					len=atoi(cn);
					else if(atoi(cn)==-1)
					{
						len=loon;
					}
					cout<<"len"<<len;
				//	cout<<"\n cn2 "<<atoi(cn);
					if(atoi(cn)!=-1)
					{
						r=atoi(cn);v=0;
						fio.seekg(r*l,ios::beg);
						while(1)
						{
							fio>>c;
							if(c=='|')
							break;
							rec[v++]=c;
						}
						fio>>c;
						while(c!='|')
						fio>>c;
						for(int x=0;x<5;x++)
						cn2[x]='\0';v=0;
						while(c!='*'&&c!='#')
						{
							fio>>c;
							cn2[v++]=c;
						}
						if((atoi(rec))%a==no)
						{
							fio.seekg(atoi(rec)*l,ios::beg);
							len=fio.tellg();
							fio>>c;
							while(c!='|')
							fio>>c;
							fio>>c;
							while(c!='|')
							fio>>c;
							len=fio.tellg();
							while(c!='*'&&c!='#')
							{
								fio>>c;
								cn[v++]=c;
							}
						}
					}
					
				}
				fio.seekg(len,ios::beg);
				fio<<chain;
				fio>>c;
				fio.seekg(-1,ios::cur);
				while(c!='#')
				{
					fio<<"*";
			    	fio>>c;
					fio.seekg(-1,ios::cur);
				}
			}
		}
	}
}
int main()
{
	ofstream fout("chain_file.txt");
	int l,a,chain=-1;
	cout<<"Enter the length of the record\n";
	cin>>l;
	cout<<"Enter the address space\n";
	cin>>a;
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<l-1;j++)
		fout<<"*";
		fout<<"#";
	}
	fout.close();
	fstream fin("variablelengthrecords1.txt");
	fstream fio("chain_file.txt");
	add(fin,fio,l,a,chain);
	fio.seekg(0,ios::beg);
	fin.close();
	fio.close();
}
