#include <bits/stdc++.h>
using namespace std;
const int maxn=210;
const int maxm=10000000;
int n;
int cnt=0,ans=0;
int d[maxn];
int low[maxn];
bool vis[maxn];
vector<int> q[maxn];
stack<int> k;
void input()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        while(1)
        {
            int a1;
            cin>>a1;
            if(a1==0) break;
            q[i].push_back(a1);
        }
    }
}
void dfs(int now)
{
    k.push(now);
    d[now]=cnt;
    low[now]=cnt;
    vis[now]=1;
    cnt++;
    for(int i=0;i<q[now].size();i++)
    {
        int ne=q[now][i];
        if(d[ne]==0)
        {
            dfs(ne);
            low[now]=min(low[now],low[ne]);
        }
        else if(vis[ne]==1)
        {
            low[now]=min(low[now],d[ne]);
        }
    }
    if(low[now]==d[now])
    {
        int a1;
        do
        {
            a1=k.top();
            k.pop();
            vis[a1]=0;
        }while(now!=a1);
        ans++;
    }
}
void pre()
{
    memset(vis,0,sizeof(vis));
    memset(d,0,sizeof(d));
    memset(low,0,sizeof(low));
}
int main()
{
    pre();
    input();
    dfs(1);
    cout<<ans<<endl;
    return 0;
}