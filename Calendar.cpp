#include<iostream>
using namespace std;
void printday()
{
	cout<<"S  M  T  W  T  F  S\n";
}
void printmonth(int m)
{
	if(m==1) cout<<"\tJanuary\n";
	if(m==2) cout<<"\tFebruary\n";
	if(m==3) cout<<"\tMarch\n";
	if(m==4) cout<<"\tApril\n";
	if(m==5) cout<<"\tMay\n";
	if(m==6) cout<<"\tJune\n";
	if(m==7) cout<<"\tJuly\n";
	if(m==8) cout<<"\tAugust\n";
	if(m==9) cout<<"\tSeptember\n";
	if(m==10) cout<<"\tOctober\n";
	if(m==11) cout<<"\tNovember\n";
	if(m==12) cout<<"\tDecember\n";
}
int no_days(int m,int y)
{
	if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
	return 31;
	else if(m==2&&y%4==0)
	return 29;
	else if(m==2)
	return 28;
	else
	return 30;
}
int main()
{
	int f,y,m=0,w=1,d=1;
	cout<<"Enter the year\n";
	cin>>y;
	cout<<"Enter the day on which Jan 1 falls(1:Sunday  7:Saturday)\n";
	cin>>f;
	w=f;
	for(m=1;m<=12;m++)
	{
		printmonth(m);
		printday();
		for(int i=1;i<w;i++)
		cout<<"   ";
		while(d<=no_days(m,y))
		{
			cout<<d++<<" ";
			if(d>=2&&d<=10)
			cout<<" ";
			w++;
			if(w==8)
			{
				cout<<endl;
				w=1;
			}
		}
		cout<<endl;
		d=1;
	}
	
}
