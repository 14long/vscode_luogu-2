#include <bits/stdc++.h>
using namespace std;
const int maxn=1000000;
struct node{
    int w;
    int to;
    int next;
}q[maxn];
int head[maxn];
////vector<node> q;

int cnt=0;
int n,m;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a1,a2,a3;
        cin>>a1>>a2>>a3;
        q[cnt].w=a3;
        q[cnt].to=a2;
        q[cnt].next=head[a1];////next存储上一条边（编号更小）的编号
        head[a1]=cnt;
        cnt++;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<i<<' ';
        for(int j=head[i];j!=0;j=q[j].next)
        {
            cout<<q[j].to<<' '<<q[j].w<<'A'<<' ';
        }
        cout<<endl;
    }
    return 0;
}
