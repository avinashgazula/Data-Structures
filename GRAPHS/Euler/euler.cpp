#include<iostream>
using namespace std;
int n,**g;
struct li
    {
        int n;
        li* lnext;
    };
void display_graph(int **g)
{
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" : ";
        for(int j=1;j<=n;j++)
            cout<<"  "<<g[i][j];
        cout<<endl;

    }
}
int check_if_euler_possible(int **g)
{
    int i,j,cnt;
    for(i=1;i<=n;i++)
    {
        cnt=0;
        for(j=1;j<=n;j++)
        {
            if(g[i][j]==1)
                cnt++;
        }
        if(cnt%2)
            return 0;
    }
    return 1;
}
void insert_in_list(li* &l,int n)
{
    if(l==NULL)
        {
            l=new(li);
            l->n=n;
            l->lnext=NULL;
        }
    else
    {
        li *t=l;
        while(t->lnext!=NULL)
            t=t->lnext;
            t->lnext=new(li);
            t=t->lnext;
            t->n=n;
            t->lnext=NULL;
    }
}
li *l[3],*p;
void filldft(int v1,int **g2,int deg[],int &nolist);
void print_euler_cycle(int **g,int v1)
{
    int i,j,nolist,deg[n+1],**g2,cnt;
    g2=new int*[n+1];
    for(i=1;i<=n;i++)
    {
        cnt=0;
        g2[i]=new int[n+1];
        for(j=1;j<=n;j++)
            {
                g2[i][j]=g[i][j];
                if(g[i][j]==1)
                    cnt++;
            }
            deg[i]=cnt;
    }
    nolist=0;
    p=NULL;
    filldft(v1,g2,deg,nolist);
    for(i=1;i<=n;i++)
        delete []g2[i];
    delete []g2;
}
void splice()
{
    li *t1,*t2,*t3;
    t1=l[0];
    t2=l[1];
    while(t1->lnext->n!=t2->n)
        t1=t1->lnext;
    p=t1;
    t3=t1->lnext;
    t1->lnext=t2;
    while(t2->lnext!=NULL)
        t2=t2->lnext;
    t2->lnext=t3->lnext;
    delete t3;
}
void filldft(int v1,int **g2,int deg[],int &nolist)
{
    insert_in_list(l[nolist],v1);
    if(deg[v1]>0)
    {
        for(int j=1;j<=n;j++)
        if(g[v1][j]!=0)
        {
            deg[v1]--;
            deg[j]--;
            g[v1][j]=0;
            g[j][v1]=0;
            filldft(j,g2,deg,nolist);
            break;
        }
    }
    else
    {
        if(nolist>0)
            {
                splice();
                nolist--;
            }
        if(p==NULL)
            p=l[nolist];
        while(p!=NULL&&deg[p->n]==0)
            p=p->lnext;
        if(p==NULL)
        {
            cout<<"\n the euler path is \n";
            li *t=l[0],*p;
            while(t!=NULL)
            {
                cout<<"  "<<t->n;
                p=t;
                t=t->lnext;
                delete p;
            }
        }
        else
        {
            nolist++;
            filldft(p->n,g2,deg,nolist);
        }
     }
    }
int main()
{
    int i,j,no,v1,v2;
    cout<<"\n enter the no of vertices";
    cin>>n;
    g=new int*[n+1];
    cout<<"\n enter the vertices";
    for(i=1;i<=n;i++)
    {
        g[i]=new int[n+1];
        cin>>no;
        g[i][0]=no;
        for(j=1;j<=n;j++)
            g[i][j]=0;
    }
    cout<<"\n enter the edges -1 to terminate";
     cin>>v1;
    while(v1!=-1)
    {
        cin>>v2;
        g[v1][v2]=1;
        g[v2][v1]=1;
        cin>>v1;
    }
   cout<<"\n the graph created is";
    display_graph(g);
    int l=check_if_euler_possible(g);
    if(l)
        {
            cout<<"euler cycle not possible ";
            return 0;
        }
    cout<<"\n enter the starting vertex for printing euler cycle";
    cin>>v1;
    print_euler_cycle(g,v1);
    for(i=1;i<=n;i++)
        delete []g[i];
    delete []g;
    return 0;
}
