#include <bits/stdc++.h>
using namespace std;
const int maxn=3010;
const long long maxm=1000000000;
struct node{
    int v;
    long long w;
};
struct edge{
    int u;
    long long dis;
    bool operator <(const edge &a)const
    {
        return dis>a.dis;
    }
};
int n,m;
long long dis0[maxn];
long long dis[maxn];
bool vis[maxn];
bool inf=0;
vector<node> u[maxn];
priority_queue<edge> t;
void input()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u1,v1;
        long long w1;
        cin>>u1>>v1>>w1;
        u[u1].push_back((node){v1,w1});
    }
}
void bellman()
{
    dis0[0]=0;
    for(int i=1;i<=n;i++) u[0].push_back((node){i,0});
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            for(int k=0;k<u[j].size();k++)
            {
                if(dis0[u[j][k].v]>dis0[j]+u[j][k].w)
                {
                    dis0[u[j][k].v]=dis0[j]+u[j][k].w;
                }
            }
        }
    }
}
void pre()
{
    for(int i=0;i<maxn;i++) dis0[i]=maxm;
}
void trans()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<u[i].size();j++)
        {
            u[i][j].w+=dis0[i]-dis0[u[i][j].v];
        }
    }
}
void predis()
{
    for(int i=0;i<maxn;i++)
    {
        dis[i]=maxm;
        vis[i]=0;
    }
}
void dijkstra()
{
    for(int k=1;k<=n;k++)
    {
        predis();
        dis[k]=0;
        t.push((edge){k,0});
        while(!t.empty())
        {
            int tmp=t.top().u;
            t.pop();
            if(vis[tmp]) continue;
            vis[tmp]=1;
            for(int i=0;i<u[tmp].size();i++)
            {
                int v1=u[tmp][i].v;
                long long w1=u[tmp][i].w;
                if(dis[v1]>w1+dis[tmp])
                {
                    dis[v1]=w1+dis[tmp];
                    t.push((edge){v1,dis[v1]});//
                }
            }
        }
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            if(dis[i]==maxm)
            {
                ans+=dis[i]*i;
            }
            else
            {
                dis[i]+=dis0[i]-dis0[k];
                ans+=dis[i]*i;
            }
        }
        cout<<ans<<endl;
    }
}
void define()
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<u[i].size();j++)
        {
            if(dis0[u[i][j].v]>dis0[i]+u[i][j].w)
            {
                inf=1;
                return;
            }
        }
    }
}
int main()
{
    pre();
    input();
    bellman();
    define();
    if(inf)
    {
        cout<<-1<<endl;
        return 0;
    }
    trans();
    dijkstra();
    return 0;
}