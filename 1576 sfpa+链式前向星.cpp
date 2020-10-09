#include <bits/stdc++.h>
using namespace std;
const int maxn=10000100;
const int maxm=202000;
int n,m,s1,s2;
struct node{
    double w;
    int to;
    int next;
};
int head[maxm];
double dis[maxn];
bool in[maxn];
node q[maxn];
queue<int> t;
void pre()
{
    memset(head,-1,sizeof(head));
    for(int i=0;i<maxn;i++) dis[i]=0;
    memset(in,0,sizeof(in));
}
void input()
{
    cin>>n>>m;
    int cnt=1;
    for(int i=1;i<=m;i++)
    {
        int a1,a2;
        double a3;
        cin>>a1>>a2>>a3;
        q[cnt].w=1-(double)a3/100;
        q[cnt].to=a2;
        q[cnt].next=head[a1];
        head[a1]=cnt;
        cnt++;
        q[cnt].w=1-(double)a3/100;
        q[cnt].to=a1;
        q[cnt].next=head[a2];
        head[a2]=cnt++;
    }
    cin>>s1>>s2;
}
void sfpa()
{
    dis[s1]=1;
    in[s1]=1;
    t.push(s1);
    while(!t.empty())
    {
        int a1=t.front();
        t.pop();
        in[a1]=0;
        for(int i=head[a1];i!=-1;i=q[i].next)
        {
            if(dis[a1]*q[i].w>dis[q[i].to])
            {
                dis[q[i].to]=dis[a1]*q[i].w;
                if(in[q[i].to]==0)
                {
                    in[q[i].to]=1;
                    t.push(q[i].to);
                }
            }
        }
    }
    cout<<setiosflags(ios::fixed)<<setprecision(8)<<100*(dis[s1]/dis[s2])<<endl;
}

int main()
{
    pre();
    input();
    sfpa();
    return 0;
}
////宽泛化的Dijkstra算法