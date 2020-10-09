#include <bits/stdc++.h>
using namespace std;
const int maxn=100000;
struct cn{
    int u;
    int v;
    int w;
};
vector<cn> t;
int des[maxn][3];
int dis[maxn];
int n,m,d3,s1,s2;

void input()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a1,a2,a3;
        cin>>a1>>a2>>a3;
        t.push_back((cn){a1,a2,a3});
    }
    cin>>d3;
    for(int i=0;i<d3;i++)
    {
        cin>>des[i][1]>>des[i][2];
    }
    cin>>s1>>s2;
}
void bellman()
{
    dis[s1]=0;
    for(int j=1;j<=n;j++)
    {
        for(int i=0;i<m;i++)
        {
            if(dis[t[i].v]>dis[t[i].u]+t[i].w)
            {
                dis[t[i].v]=dis[t[i].u]+t[i].w;
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<dis[i]<<endl;
}
void pre()
{
    for(int i=0;i<maxn;i++) dis[i]=maxn;
}
int main()
{
    input();
    pre();
    bellman();

    return 0;
}
///按一定的遍历顺序遍历所有边m n次