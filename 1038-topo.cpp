#include <bits/stdc++.h>
using namespace std;
struct node{
    int c;
    int u;
    vector<int> v;
    vector<int> w;
    void pre()
    {
        c=0;u=0;
    }
};
bool vis[110];
bool shuru[110];
//priority_queue<node> k1;
queue<int> k1;
int rd[110];
int cd[110];
int n,p;
node u1[110];
void input()
{
    cin>>n>>p;
    for(int i=1;i<=n;i++)
    {
        int a1,a2;
        cin>>a1>>a2;
        u1[i].c=a1;
        u1[i].u=a2;
    }
    for(int i=1;i<=p;i++)
    {
        int a1,a2,a3;
        cin>>a1>>a2>>a3;
        cd[a1]++;
        rd[a2]++;
        u1[a1].v.push_back(a2);
        u1[a1].w.push_back(a3);
    }

}
void pre()
{
    memset(rd,0,sizeof(rd));
    memset(cd,0,sizeof(cd));
    for(int i=0;i<110;i++)
    {
        u1[i].pre();
        vis[i]=0;
        shuru[i]=0;
    }
}
void topo()
{
    for(int i=1;i<=n;i++)
    {
        if(rd[i]==0)
        {
            k1.push(i);
            shuru[i]=1;
        }
    }
    while(!k1.empty())
    {
        int tmp=k1.front();
        k1.pop();
        if(rd[tmp])
        {
            k1.push(tmp);
            continue;
        }
        if(vis[tmp])
        {
            continue;
        }
        else
        {
            vis[tmp]=1;
            
            if(shuru[tmp]==0) u1[tmp].c-=u1[tmp].u;
            if(u1[tmp].c<=0)
            {
                for(int i=0;i<u1[tmp].v.size();i++)
                {
                    int ne=u1[tmp].v[i];
                    rd[ne]--;
                }
                continue;
            }
            for(int i=0;i<u1[tmp].v.size();i++)
            {
                int ne=u1[tmp].v[i];
                int we=u1[tmp].w[i];
                rd[ne]--;
                u1[ne].c+=u1[tmp].c*we;
                k1.push(ne);
            }
        }
    }
}
void output()
{
    bool find=false;
    for(int i=1;i<=n;i++)
    {
        
        if(!cd[i]&&u1[i].c>0) 
        {
            find=1;
            cout<<i<<' '<<u1[i].c<<endl;
        }
    }
    if(!find) cout<<"NULL"<<endl;
}
int main()
{
    pre();
    input();
    topo();
    output();
    return 0;
}