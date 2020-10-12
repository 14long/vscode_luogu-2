#include <bits/stdc++.h>
using namespace std;
const int maxn=100010;
const int maxm=1000010;
int n,m,k=0;
int h[maxn];
bool vis[maxn];
int fat[maxn];
queue<int> k1;
struct edge{
    int u;
    int v;
    int w;
}side[maxm*5];
struct node{
    int u;
    vector<int> v;
    vector<int> w;
}dian[maxn];
void input()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>h[i];
    }
    int cnt=0;
    for(int i=1;i<=m;i++)
    {
        int a1,a2,a3;
        cin>>a1>>a2>>a3;
        
        if(h[a1]>h[a2])
        {
            side[++cnt].u=a1;
            side[cnt].v=a2;
            side[cnt].w=a3;
            dian[a1].v.push_back(a2);
            dian[a1].w.push_back(a3);
        }
        else if(h[a1]<h[a2])
        {
            side[++cnt].u=a2;
            side[cnt].v=a1;
            side[cnt].w=a3;
            dian[a2].v.push_back(a1);
            dian[a2].w.push_back(a3);
        }
        else
        {
            side[++cnt].u=a2;
            side[cnt].v=a1;
            side[cnt].w=a3;
            side[++cnt].u=a1;
            side[cnt].v=a2;
            side[cnt].w=a3;
            dian[a2].v.push_back(a1);
            dian[a2].w.push_back(a3);
            dian[a1].v.push_back(a2);
            dian[a1].w.push_back(a3);
        }
    }
    m=cnt;
}
void bfs()
{
    int ans1=0;
    k1.push(1);
    while(!k1.empty())
    {
        int tmp=k1.front();
        k1.pop();
        if(vis[tmp]) continue;
        vis[tmp]=1;
        ans1++;
        for(int i=0;i<dian[tmp].v.size();i++)
        {
            int v1=dian[tmp].v[i];
            k1.push(v1);
        }
    }
    cout<<ans1<<' ';
}
void pre()
{
    for(int i=1;i<=n;i++)
    {
        dian[i].u=i;
        vis[i]=0;
        fat[i]=i;/////pre()在input()之后调用
    }
}
bool cmp(const edge &a1,const edge &a2)
{
    if(h[a1.v]!=h[a2.v]) return h[a1.v]>h[a2.v];
    return a1.w<a2.w;////
}
int find(int a1)
{
    if(fat[a1]!=a1) fat[a1]=find(fat[a1]);
    return fat[a1];
}
void kruskal()
{
    long long ans2=0;
    sort(side+1,side+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        int u1=side[i].u;
        int v1=side[i].v;
        if(!vis[u1]||!vis[v1])
        {
            continue;
        }
        if(find(u1)!=find(v1))
        {
            fat[find(u1)]=find(v1);
            ans2+=side[i].w;
        }
    }
    cout<<ans2<<endl;
}
/*
7 9
10 9 8 7 6 9 12
1 2 4
1 3 2 
2 5 3
2 4 1
3 4 7
4 6 12 
6 7 1
4 5 11
2 3 9
*/
int main()
{
    ios::sync_with_stdio(false);
    input();
    pre();
    bfs();
    kruskal();
    return 0;
}