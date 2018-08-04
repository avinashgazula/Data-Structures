#include<iostream>
using namespace std;
struct prim{
	int w,e1,e2;
};
struct stack{
	int top;
	int size;
	prim elements[30];
};

void push(stack &s,prim &t)
{
	if(s.top==s.size-1)
		cout<<"Stack is full\n";
	else
	{
		s.top++;
		s.elements[s.top]=t;
	}
}
prim pop(stack &s)
{
	if(s.top==-1)
	cout<<"Stack is empty\n";
	else
	return s.elements[s.top--];
}
void swap(prim &a,prim &b)
{
	prim temp;
	temp=a;
	a=b;
	b=temp;
}
void percolate_up(prim h[],int &s,prim k)
{
	s++;
	h[s]=k;
	int j=s;
//	cout<<"test\n";
	while(j!=0&&h[j].w<h[j/2].w)
	{
		swap(h[j],h[j/2]);
		j=j/2;
	}
}
prim percolate_down(prim h[],int &s)
{
	prim r=h[0];
	h[0]=h[s];
	s--;
	int j=0;
	while(2*j<=s&&(h[j].w>h[2*j+1].w||h[j].w>h[2*j+2].w))
	{
		if(h[2*j+1].w<h[2*j+2].w)
		
		{
			swap(h[j],h[2*j+1]);
			j=2*j+1;	
		}
		else
		{
			swap(h[j],h[2*j+2]);
			j=2*j+2;
			
		}
	}
	return r;
}
int adj(int **AdjMatrix,int v1,int v2)
{
	if(v1!=v2&&AdjMatrix[v1][v2]==0)
	return 0;
	return 1;
}
int main()
{
	int **AdjMatrix,i,j,size,s=0,a,min=0,m=0;prim h[100];
	cout<<"Enter the no. of vertices\n";
	cin>>size;
	prim t;stack stk;stk.top=-1;stk.size=100;int v[s];
	AdjMatrix=new int *[size];
	for(i=0;i<size;i++)
	AdjMatrix[i]=new int[size];
	cout<<"Enter the adjacency Matrix\n";
	for(i=0;i<size;i++)
	{
		v[i]=0;
		AdjMatrix[i][i]=0;
		for(j=i+1;j<size;j++)
		{
		//	cout<<"Enter AdjMatrix["<<i<<"]["<<j<<"] :";
			cin>>AdjMatrix[i][j];
			AdjMatrix[j][i]=AdjMatrix[i][j];
			t.w=AdjMatrix[i][j];
			t.e1=i;
			t.e2=j;
			if(t.w!=0)
			percolate_up(h,s,t);
		}
	}
	int ds[s];
	cout<<"Enter disjoint set\n";
	for(i=0;i<s;i++)
	int count=1;
	while(count<s)
	{
		prim d=percolate_down(h,s);
		if(count==1)
		{
			cout<<p.e1<<" "<<p.e2<<endl;
			v1[k]=p.e1;v2[k++]=p.e2;
		}
		else
		{
			
		}
	}
}
