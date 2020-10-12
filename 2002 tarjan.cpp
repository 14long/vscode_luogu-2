#include <bits/stdc++.h>
using namespace std;
int cnt=0;
int n,m;
const int maxn=100010;
vector<int> u[maxn];
bool vis[maxn];
int d[maxn];
int l[maxn];
stack<int> k;
void input()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a1,a2;
        cin>>a1>>a2;
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
        while(!k.empty())
        {
            int t1=k.top();
            vis[t1]=0;////reset!!
            k.pop();
            if(t1==now)
            {
                cout<<t1<<endl;
                break;
            }
            else 
            {
                cout<<t1<<' ';
            }
        }
    }
}
void pre()
{
    for(int i=0;i<maxn;i++)
    {
        vis[i]=false;
        l
        [i]=0;
        d[i]=0;
    }
}
int main()
{
    pre();
    input();
    for(int i=1;i<n;i++) 
        if(!d[i])
            tarjan(i);

    return 0;
}