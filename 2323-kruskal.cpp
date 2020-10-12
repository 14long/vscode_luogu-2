#include <bits/stdc++.h>
using namespace std;
const int maxn=10010;
int fat[maxn];
int n,k,m,max1=0;
struct node{
    int u;
    int v;
    int w1;
    int w2;
    int t;
}side[maxn*2];
int ans[maxn*2];
bool cmp1(node &a1,node &a2)
{
    return a1.w1<a2.w1;////
}
void input()
{
    cin>>n>>k>>m;
    for(int i=1;i<=m-1;i++)
    {
        int a1,a2,a3,a4;
        cin>>a1>>a2>>a3>>a4;
        side[i].u=a1;
        side[i].v=a2;
        side[i].w1=a3;
        side[i].w2=a4;
        side[i].t=i;
    }
}
void pre()
{
    memset(ans,0,sizeof(ans));
    memset(fat,0,sizeof(fat));
    for(int i=1;i<=n;i++)
    {
        fat[i]=i;
    }
}
void toge(int a1,int a2)
{
    int fat1=fat[a2];
    for(int i=1;i<=n;i++)
    {
        if(fat[i]==fat1)
        {
            fat[i]=fat[a1];
        }
    }
}
void kruskal1()
{
    sort(side+1,side+m,cmp1);////重置2
    int cnt2=0;
    for(int i=1;i<=m-1;i++)
    {
        int u1=side[i].u;
        int v1=side[i].v;
        int w=side[i].w1;
        if(fat[u1]!=fat[v1])
        {
            toge(u1,v1);
            max1=max(max1,w);
            cnt2++;
            ans[side[i].t]=1;
        }
        if(cnt2==k) break;
    }
}
bool cmp2(node &a1,node &a2)////bool cmp写法
{
    return a1.w2<a2.w2;
}
void kruskal2()
{
    sort(side+1,side+m,cmp2);
    int le=n-1-k;
    for(int i=1;i<=m-1;i++)
    {
        int u1=side[i].u;
        int v1=side[i].v;
        int w=side[i].w2;
        if(fat[u1]!=fat[v1])
        {
            toge(u1,v1);
            le--;
            max1=max(max1,w);
            ans[side[i].t]=2;
        }
        if(le==0) break;
    }
}
void output()
{
    cout<<max1<<endl;
    for(int i=1;i<=m-1;i++)
    {
        if(ans[i]!=0)
        {
            cout<<i<<' '<<ans[i]<<endl;
        }
    }
}
int main()
{
    input();
    pre();
    kruskal1();
    kruskal2();
    output();
    return 0;
}