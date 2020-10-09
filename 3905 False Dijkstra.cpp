#include <bits/stdc++.h>
using namespace std;
const int maxn=100000;
int n,m;
int s1,s2,d3;
int dis[maxn];
int xiang[maxn];
int bre[maxn][3];
bool vis[maxn];
struct node{
    int v;
    int w;
};
struct cmp{
    bool operator()(int a1,int a2)
    {
        return dis[a1]>dis[a2];///////false
    }
};
vector<node> d[maxn];
priority_queue<int,vector<int>,cmp> q;
void add(int u,int v,int w)
{
    d[u].push_back((node){v,w});
}
void input()
{
    for(int i=1;i<=m;i++)
    {
        int a1,a2,a3;
        cin>>a1>>a2>>a3;
        add(a1,a2,a3);
        add(a2,a1,a3);
    }
    cin>>d3;
    for(int i=0;i<d3;i++)
    {
        cin>>bre[i][1]>>bre[i][2];

    }
    cin>>s1>>s2;
  /*  int d1;
    cin>>d1;
    for(int i=0;i<d1;i++)
    {
        int a1,a2;
        cin>>a1>>a2;
        for(int j=0;j<d[a1].size();j++)
        {
            if(d[a1][i].v==a2)
            {
                d[a1].erase(d[a1].begin()+j);////无法删除边，仅有真邻接表可以删除
            }

        }
        for(int j=0;j<d[a2].size();j++)
        {
            if(d[a2][j].v==a1)
            {
                d[a2].erase(d[a2].begin()+j);
            }
        }
    }
    */
}
void dijkstra()
{
    q.push(s1);
    dis[s1]=0;
    while(!q.empty())
    {
        int w1=q.top();
        q.pop();
        if(vis[w1]) continue;
        vis[w1]=1;
        if(vis[s2]==1) break;
        for(int i=0;i<d[w1].size();i++)
        {
            int v=d[w1][i].v;
            int w=d[w1][i].w;
            if(dis[v]>dis[w1]+w)
            {
                dis[v]=dis[w1]+w;
                xiang[v]=w1;
                if(!vis[v]) q.push(v);
            }
        }

    }
////    cout<<dis[s2]<<endl;
}
int main(){
    cin>>n>>m;
    input();
    for(int i=0;i<maxn;i++)
    {
        dis[i]=maxn;
        vis[i]=0;
    }
    dijkstra();
    int cnt=0;
    for(int i=0;i<d3;i++)
    {
        int tt=s2;
        while(tt!=s1)
        {
            if((bre[i][1]==tt&&bre[i][2]==xiang[tt])||(bre[i][1]==xiang[tt]&&bre[i][2]==tt))
            {
                for(int j=0;j<d[tt].size();j++)
                {
                    if(d[tt][j].v==xiang[tt])
                    {
                        cnt+=d[tt][j].w;
                        break;
                    }
                }
            }
            tt=xiang[tt];

        }


    }
    cout<<cnt<<endl;
    return 0;
}
//无向图
////用vis数组保证确定点不再访问
////用优先队列保证从最小点拓展