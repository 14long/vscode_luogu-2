#include <bits/stdc++.h>
using namespace std;
const int maxn=2010;
const int maxm=100000010;
int dis[maxn][maxn];
int num[maxn][maxn];
bool impo[maxn];
bool all=0;
int n,m;
void input()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a1,a2,a3;
        cin>>a1>>a2>>a3;
        dis[a1][a2]=a3;
        dis[a2][a1]=a3;
        num[a1][a2]=1;
        num[a2][a1]=1;
    }
}
void pre()
{
    for(int i=0;i<maxn;i++)
    {
        for(int j=0;j<maxn;j++)
        {
            dis[i][j]=maxm;
            num[i][j]=0;
        }
    }
    for(int i=0;i<maxn;i++) impo[i]=0;
}
void floyd()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)////遍历顺序不能更改？？？？
            {
                if(i==j||j==k||k==i) continue;
                if(dis[i][k]+dis[k][j]<dis[i][j])
                {
                    dis[i][j]=dis[i][k]+dis[k][j];
                    num[i][j]=num[i][k]*num[k][j];
                }
                else if(dis[i][k]+dis[k][j]==dis[i][j])
                {
                    num[i][j]+=(num[i][k]*num[k][j]);
                }
            }
        }
    }
}
void panduan()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j||j==k||k==i) continue;
                if(impo[k]) continue;
                if(dis[i][j]==dis[i][k]+dis[k][j]&&num[i][j]==num[i][k]*num[k][j])
                {
                    impo[k]=1;
                    all=1;
                }
            }
        }
    }
}
void ouput()
{
    if(!all)
    {
        cout<<"No important cities.";
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(impo[i])
        {
            cout<<i<<' ';
        }
    }
}
int main()
{
    pre();
    input();
    floyd();
    panduan();
    ouput();
    return 0;
}