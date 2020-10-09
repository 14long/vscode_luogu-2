#include <bits/stdc++.h>
using namespace std;
const int maxn=210;
set<int> q[maxn];
int n,cnt=0;
void search(int num)
{
    for(int i=0;i<cnt;i++)
    {
        set<int> s1;
        vector<int> s2;
        s1.insert(num);
        set_intersection(q[i].begin(),q[i].end(),s1.begin(),s1.end(),s2.begin());
        if(s2.size())
        {
            vector<int> s3;
            set_union(q[i].begin(),q[i].end(),q[cnt].begin(),q[cnt].end(),s3.begin());
            for(int i=0;i<s3.size();i++)
            {
                q[i].insert(s3[i]);
            }
            while(1)
            {
                int a2;
                cin>>a2;
                if(a2==0) goto aa;
                q[i].insert(a2);
            }
        }

    }
    aa:
    q[cnt].
    cnt--;
    return;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        while(1)
        {
            int a1;
            cin>>a1;
            if(a1==0) break;
            else
            {
                q[cnt].insert(a1);
                search(a1);
            }
        }
        
    }
    return 0;
}