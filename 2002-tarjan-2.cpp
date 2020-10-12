#include <bits/stdc++.h>
using namespace std;
int cnt=0;
int n,m;
const int maxn=100010;
vector<int> u[maxn];
bool vis[maxn];
int d[maxn];
int l[maxn];
int rd[maxn];
int tot2[maxn];
int tot=0;
stack<int> k;
void input()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a1,a2;
        cin>>a1>>a2;
       /* bool con=0;
        for(int j=0;j<u[a1].size();j++)
        {
            if(u[a1][j]==a2)
            {
                con=1;
                break;
            }
        }
        if(con) continue;*/
        if(a1!=a2) u[a1].push_back(a2);
        else
        {
            continue;////自环
        }
    }
}
void tarjan(int now)
{
    vis[now]=1;
    d[now]=l[now]=++cnt;
    k.push(now);
    for(int i=0;i<u[now].size();i++)
    {
        int v=u[now][i];
        if(!d[v])
        {
            tarjan(v);
            l[now]=min(l[now],l[v]);////同化最小点的下标
        }
        else if(vis[v])
        {
            l[now]=min(l[now],d[v]);
        }
        else continue;
    }
    
    if(d[now]==l[now])
    {
        tot++;
        while(!k.empty())
        {
            int t1=k.top();
            vis[t1]=0;////reset!!
            tot2[t1]=tot;
            k.pop();
            if(t1==now) break;
        }
    }
}
void pre()
{
    for(int i=0;i<maxn;i++)
    {
        vis[i]=false;
        l[i]=0;
        d[i]=0;
        tot2[i]=0;
    }
    memset(rd,0,sizeof(rd));
}
void suodian()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<u[i].size();j++)
        {
            int v=u[i][j];
            if(tot2[v]!=tot2[i])
            {
                rd[tot2[v]]++;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=tot;i++)
    {
        if(!rd[i]) ans++;
    }
    cout<<ans<<endl;

}
int main()
{
    pre();
    input();
    for(int i=1;i<=n;i++) 
        if(!d[i])
            tarjan(i);

    suodian();
    return 0;
}
///入度统计+裸tarjan