#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
struct DOB
{
	int day;
	int month;
	int year;
};
struct person
{
	char name[20];
	int age;
	DOB Bdate;
};
void Bifercate(ifstream & fout)
{
	char b[500],ch,ch1='-';int i=0,n,m,k=0,l=0;
	ofstream fout3("output3.txt");
    while(!fout.eof())
    {
    	int c=0;
    	fout>>ch;
    	b[i]=ch;l++;
    	if(b[i]!='#')
    	{
    		i++;l++;continue;
		}
		else if(b[i]=='#')
		{
			n=1000*(b[i-4]-48)+100*(b[i-3]-48)+10*(b[i-2]-48)+b[i-1]-48;
		}
		if(k==0)
		{
			fout3<<n;m=n;
			fout3<<ch1;
			fout3<<k;
			fout3<<endl;
			k++;
		}
		if(m!=n)
        {
        	fout3<<n;
            m=n;
        	fout3<<ch1;
        	fout3<<i;
        	fout3<<endl;
		}		
		i++;
	}
	
}
int main()
{
	char a[20],ch='|',ch1='/',ch2='#';int i,j;
	person p[10],temp;
	fstream fout;
	fout.open("file2.txt");
	for(i=0;i<5;i++)
	{
    	cout<<"\nEnter the details of person "<<i+1<<" :\n";
    	cin.clear();fflush(stdin);
    	cout<<"Enter person name : ";gets(p[i].name);  	
    	cout<<"Enter age of person : ";cin>>p[i].age;
    	cin.clear();fflush(stdin);  
		cout<<"Enter date of birth : ";gets(a);
		p[i].Bdate.day=10*(a[0]-48)+a[1]-48;
		p[i].Bdate.month=10*(a[3]-48)+a[4]-48;
		p[i].Bdate.year=1000*(a[6]-48)+100*(a[7]-48)+10*(a[8]-48)+a[9]-48;
	    
    }int q;
    for(i=0;i<5;i++)
    {
    	 q=i;
    	for(j=i+1;j<5;j++)
    	{
    		if(p[q].Bdate.year>p[j].Bdate.year)q=j;
    	    if(p[q].Bdate.year==p[j].Bdate.year&&p[q].Bdate.month>p[j].Bdate.month)q=j;
    	    if(p[q].Bdate.year==p[j].Bdate.year&&p[q].Bdate.month==p[j].Bdate.month&&p[q].Bdate.day>p[j].Bdate.day>p[j].Bdate.day)q=j;
		}
		temp=p[i];
		p[i]=p[q];
		p[q]=temp;
	}
	for(i=0;i<5;i++)
	{
		fout<<p[i].name;
		fout<<ch;
		fout<<p[i].age;
    	fout<<ch;
    	fout<<p[i].Bdate.day;
    	fout<<ch1;
    	fout<<p[i].Bdate.month;
    	fout<<ch1;
    	fout<<p[i].Bdate.year;
		fout<<ch2;
	}fout<<'\0';
	fout.close();
	ifstream fin("file2.txt");
    Bifercate(fin);
    fin.close();
    return 0;
}
