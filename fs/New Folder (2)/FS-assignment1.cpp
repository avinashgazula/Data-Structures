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
	DOB Bdate;
	int pid;
};
void Bifercate(ifstream & fout)
{
	ofstream fout1,fout2;
	char a[20];
	const int size=80;
	cout<<"Enter the date : ";
	cin.clear();fflush(stdin);
    gets(a);
	fout1.open("Output1.txt");
    fout2.open("Output2.txt");
    int d,m,y,dd,mm,yy;
    d=10*(a[0]-48)+a[1]-48;
    m=10*(a[3]-48)+a[4]-48;
    y=1000*(a[6]-48)+100*(a[7]-48)+10*(a[8]-48)+a[9]-48;
    int i=0;
	while(!fout.eof())
    {
    	char b[100];
    	fout.getline(b,size);
    	while(b[i]!='|')
    	i++;
    	dd=10*(b[i+1]-48)+b[i+2]-48;
        mm=10*(b[i+4]-48)+b[i+5]-48;
        yy=1000*(b[i+7]-48)+100*(b[i+8]-48)+10*(b[i+9]-48)+b[i+10]-48;
        i=0;
        if(yy>y){fout1<<b;fout1<<endl;}
        else if(yy<y){fout2<<b;fout2<<endl;}
    	else if(mm>m){fout1<<b;fout1<<endl;}
        else if(mm<m){fout2<<b;fout2<<endl;}
        else if(dd>d){fout1<<b;fout1<<endl;}
        else {fout2<<b;fout2<<endl;}
	}
	fout1.close();
    fout2.close();    
}
int main()
{
	char a[20],ch='|',ch1='/';int i;
	person p[10];
	ofstream fout("file1.txt");
	for(i=0;i<5;i++)
	{
    	cout<<"\nEnter the details of person "<<i+1<<" :\n";
    	cin.clear();fflush(stdin);
    	cout<<"Enter person name : ";gets(p[i].name);
		fout<<p[i].name;
		fout<<ch;
    	cin.clear();fflush(stdin);    	
		cout<<"Enter date of birth : ";gets(a);
		p[i].Bdate.day=10*(a[0]-48)+a[1]-48;
		p[i].Bdate.month=10*(a[3]-48)+a[4]-48;
		p[i].Bdate.year=1000*(a[6]-48)+100*(a[7]-48)+10*(a[8]-48)+a[9]-48;
	    fout<<a;
		fout<<ch;
    	cout<<"Enter the person id : ";cin>>p[i].pid;
    	fout<<p[i].pid;
    	fout<<endl;
    }fout.close(); 
    ifstream fin("file1.txt");
    Bifercate(fin);
    fin.close();
	    return 0;
}
