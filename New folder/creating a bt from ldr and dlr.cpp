#include<iostream>
#include<cstring>
using namespace std;

typedef struct btnode{
	struct btnode *lchild;
	char data;
	struct btnode *rchild;
}* btptr;

void del(char a[],char ch,int len)
{
	int t;
	for(int i=0;i<len;i++)
	{
		if(a[i]==ch)
		t=i;
	}
	for(int j=t+1;j<len;j++)
	{
		a[j-1]=a[j];
	}
	a[len-1]=NULL;
}

void check(btptr t,char a)
{
	
	while(t!=NULL)
	{
		if(t->data==a)
		return ;
		else
		{
			check(t->lchild,a);
			check(t->rchild,a);
		}
	}
	return 0;


}

void create(btptr &t,char ldr[],char dlr[],int len)
{
	char x=dlr[0];
	if(t==NULL)
	{
		t=new btnode;
		t->data=dlr[0];
		t->lchild=NULL;
		t->rchild=NULL;
	}
	else
	{
		int t1=len;
		int t2=len;
		while(t1>=0)
		{
			if(dlr[0]==ldr[t1])
			t2=t1;
			t1--;
		}
		t2++;
		t->lchild=dlr[1];
		t->rchild=dlr[t2];
		del(ldr,x);
		del(dlr,x);
		create(t->lchild,ldr,dlr,len);
		create(t->rchild,ldr,dlr,len);
		len--;
		
	}
}

int main()
{
	btptr t;
	t=NULL;
	char ldr[30];
	char dlr[30];
	cout<<"Enter the LDR form\n";
	cin>>ldr;
	cout<<"Enter the DLR form\n";
	cin>>dlr;
	int l1=strlen(ldr);
	int l2=strlen(dlr);
	if(l1!=l2)
	cout<<"Wrong Input\n";
	else
	create(t,ldr,dlr,l1);
	
	print(t);
	
}
