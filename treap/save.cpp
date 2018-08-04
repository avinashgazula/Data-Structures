#include<iostream>
using namespace std;
struct s
{
	int n;
	char r;
};
struct queue
{
	int front;
	int rear;
	int size;
	s elem[20];
};
void enque(queue &q,s &st)
{
	if((q.rear+1)%q.size==q.front)
	{
		cout<<"full ";
	}
	else
	{
		if(q.front==-1)
		{
			q.front++;
		}
		q.rear=((q.rear+1))%q.size;
		q.elem[q.rear].n=st.n;
		q.elem[q.rear].r=st.r;
	}
}
s deque(queue &q)
{
	if(q.rear==-1)
	{
		cout<<"empty ";
	}
	else
	{
		s t;
		t.n=q.elem[q.front].n;
		t.r=q.elem[q.front].r;
		if(q.front==q.rear)
		{
			q.front=-1;
			q.rear=-1;
		}
		else
		{
			q.front=(q.front+1)%q.size;
		}
		return t;
	}
}
int main()
{
	struct queue q;
	q.front=-1;
	q.rear=-1;
	q.size=20;
	s t;
	cout<<"enter n c ";
	cin>>t.n>>t.r;
	while(t.n!=-1)
	{
		enque(q,t);
		cout<<"enter n and c ";
		cin>>t.n>>t.r;
	}
	cout<<"the elments "<<endl;
	while(q.front!=-1)
	{
		t=deque(q);
		cout<<t.n<<" "<<t.r<<endl;
	}
	return 0;
	
}
