#include <bits/stdc++.h>
using namespace std;
const int maxn=1100;
int n,m,ans;
int all[maxn];
vector<int> x[maxn];
void pre()
{
    ans=1;
    memset(all,1,sizeof(all));
}
void input()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a1;
        cin>>a1;
        for(int j=1;j<=a1;j++)
        {
            int a2;
            cin>>a2;
            x[i].push_back(a2);
        }
    }

}
int main()
{
    pre();
    input();
    return 0;
}