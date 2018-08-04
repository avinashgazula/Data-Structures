#include<iostream>
using namespace std;
int fact(int n)
{
	if(n==0||n==1)
	return 1;
	
	return n*fact(n-1);	
}
int main()
{
 int a;
 cout<<"Enter the number for which you want to find the factorial ";
 cin>>a;
 cout<<"factorial of "<<a<<" is "<<fact(a);
 return 0;	
}
