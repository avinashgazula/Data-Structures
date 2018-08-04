#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int s=4;
struct bkt{
	int n1;
	char key[4][5];
};
struct node{
	int count;
	struct bkt *bucket;
};
int get_pos(int n)
{
	if(n==2) return 0;
	else return 1+get_pos((n/2));
}
void print(struct node *b,int n)
{
	cout<<n<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"Bucket "<<i+1<<" : "<<b[i].count<<" : ";
		if(b[i].count==0&&b[i].bucket==NULL)
		cout<<"Empty";
		else
		{
			for(int j=0;j<b[i].count;j++)
			{
				cout<<b[i].bucket->key[j]<<" ";
			}
		}
		cout<<endl;
	}
}
void add(struct node *b,char *data,int &n)
{
	cout<<"data "<<data<<endl;char k[3];
	int pos=get_pos(n);int p=0;
	for(int i=0;i<=pos;i++)
	{
		k[0]=data[i];
		k[1]='\0';
		p=p+pow(2,(atoi(k)));
	}
	cout<<"pos "<<pos<<endl;
	p--;
/*	char k[3];
	k[0]=data[pos];
	k[1]='\0';*/
//	int p=atoi(k);
	cout<<"p "<<p<<endl;
	//cout<<"test";
	if(b[p].count<s)
	{
		if(b[p].count==0)
		{
			b[p].bucket=new bkt;
			b[p].bucket->n1=1;
		}
		strcpy(b[p].bucket->key[b[p].count],data);
		b[p].count++;
		if(b[p].bucket->n1<n)
		{
			if(p%2==0)
			{
				b[p+1].count++;
				b[p+1].bucket=b[p].bucket;
			}
			else
			{
				b[p-1].count++;
				b[p-1].bucket=b[p].bucket;
			}
		}
	}
	else
	{
		if(b[p].bucket->n1<n)
		{
			cout<<"Hello  "<<p<<"\n";
			node *temp;
			temp=new node;
			temp->count=b[p].count;
			temp->bucket=b[p].bucket;
			b[p].bucket=new bkt;
			if(p%2==0)
			{
				b[p+1].bucket=new bkt;
				b[p].count=0;
				b[p+1].count=0;
				b[p].bucket->n1=(temp->bucket->n1)+1;
				b[p+1].bucket->n1=(temp->bucket->n1)+1;
				
			}
			else if(p%2==1)
			{
				b[p-1].bucket=new bkt;
				b[p].count=0;
				b[p-1].count=0;
				b[p].bucket->n1=(temp->bucket->n1)+1;
				b[p-1].bucket->n1=(temp->bucket->n1)+1;
			}
			cout<<"test "<<(temp->bucket->n1)+1<<endl;
			for(int i=0;i<temp->count;i++)
			{
				k[0]=temp->bucket->key[i][pos];
				k[1]='\0';
				p=atoi(k);
				strcpy(b[p].bucket->key[b[p].count],temp->bucket->key[i]);
				b[p].count++;
			}
		}
		else
		{
			cout<<"broo p "<<p<<" n "<<n<<" "<<b[p].bucket->n1<<endl;
			node *temp;
			temp=new node[n];
			for(int i=0;i<n;i++)
			{
				temp[i].count=b[i].count;
				temp[i].bucket=b[i].bucket;
			}
		/*	cout<<endl<<endl;
			print(temp,n);
			cout<<endl<<endl;*/
			n=n*2;
			delete b;
			node *b;
			b=new node[n];
			cout<<"test0\n";
			for(int i=0;i<n;i++)
			{
				b[i].count=0;
				b[i].bucket=NULL;
				b[i].bucket=new bkt;
			}
			cout<<"test1\n";
			for(int i=0;i<n/2;i++)
			{
				b[2*i].bucket->n1=temp[i].bucket->n1+1;
				b[2*i+1].bucket->n1=temp[i].bucket->n1+1;
			}
			pos=pos+1;
			cout<<"test2\n";
			for(int i=0;i<(n/2);i++)
			{
				for(int j=0;j<temp[i].count;j++)
				{
				//	add(b,temp[i].bucket->key[j],n);
					k[0]=temp[i].bucket->key[j][pos];
				//	k[0]=data[pos];
					k[1]='\0';
					p=atoi(k);
					if(p==0)
					{
						strcpy(b[2*i].bucket->key[b[2*i].count],temp[i].bucket->key[j]);
						b[2*i].count++;
						if(b[2*i].bucket->n1<n)
						{
							b[2*i+1].count++;
							b[2*i+1].bucket=b[p].bucket;
						}
					}
					else
					{
						strcpy(b[2*i+1].bucket->key[b[2*i+1].count],temp[i].bucket->key[j]);
						b[2*i+1].count++;
						if(b[2*i+1].bucket->n1<n)
						{
							b[2*i].count++;
							b[2*i].bucket=b[p].bucket;
						}
					}
					
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			if(i%2==0&&b[i].count==0)
			{
				b[i+1].count=b[i].count;
				b[i+1].bucket=b[i].bucket;
			}
			else if(b[i].count==0)
			{
				b[i-1].count=b[i].count;
				b[i-1].bucket=b[i].bucket;
			}
		}
		add(b,data,n);
	}
	//cout<<endl;print(b,n);cout<<endl;
}

int main()
{
	node *b;int d=3,d1=1,n=2;
	b=new node[n];
	for(int i=0;i<n;i++)
	{
		b[i].count=0;
		b[i].bucket=NULL;
	}
	char data[5];
	while(1)
	{
		cout<<"Enter data\n";
		cin>>data;
		if(atoi(data)==-1)
		break;
		add(b,data,n);
	}
	print(b,n);
}
