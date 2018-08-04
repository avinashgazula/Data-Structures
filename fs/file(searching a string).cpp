#include<iostream>                                                                                                                                                                                           
#include<fstream>                                                                                                                                               
using namespace std;                                                                                                                                                                                   
int main()                                                                                                                                        
{                                                                          
	fstream test("files1.txt");                          
	int c,m,n,i,j,k=0,x[30],z=0,l=0;char a[30];
	cout<<"Enter data you want to enter in the file\n";
	cin.getline(a,30);
	test<<a;

	cout<<"enter the no. of characters in the word you want to search in the file\n";
	cin>>m;
	char b[m];
	cout<<"enter the word you want to search in the file\n";
	cin>>b;

	test.close();  
	ifstream test1("files1.txt");
	char y[30];
	test1.getline(y,30);                  
                        
	for(i=0;i<30;i++)                 
	{                                                                                                                                                          
	
			if(y[i]==b[0])
			{                     
			x[z]=i;
			z++;
			}
	}                                                                                                                                                         
	for(n=0;n<z;n++)
	{
		for(c=0;c<m;c++)
		{
			if(y[x[z]+c]=b[c])
			k++;
		}
	}		

	if(k!=m)
	cout<<"The word is not present in the text file";
	else
	cout<<"The word is present in the file";
	return 0;
}
