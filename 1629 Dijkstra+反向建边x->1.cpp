#include <bits/stdc++.h>
using namespace std;
int n,m;
const int maxn=10100;
const int maxm=2147483647;
int ans[maxn];
int ans2[maxn];
bool vis[maxn];
struct node{
    int dian;
    int dis;
};
vector<node> q[maxn],re[maxn];
struct cmp{
    bool operator()(int a1,int a2)
    {
        return ans[a1]>ans[a2];
    }
};
struct cmp2{
    bool operator()(int d1,int d2)
    {
        return ans2[d1]>ans2[d2];
    }
};
priority_queue<int,vector<int>,cmp> d;
priority_queue<int,vector<int>,cmp2> d2;
void input(){
    for(int i=1;i<=m;i++){
        int a1,a2,a3;
        cin>>a1>>a2>>a3;
        for(int j=0;j<q[a1].size();j++){
            if(q[a1][j].dian==a2){
                if(q[a1][j].dis>a3) q[a1][j].dis=a3;
                break;
            }
        }
        q[a1].push_back((node){a2,a3});
        for(int j=0;j<re[a2].size();j++){
            if(re[a2][j].dian==a1){
                if(re[a2][j].dis>a3) re[a2][j].dis=a3;
                break;
            }
        }
        re[a2].push_back((node){a1,a3});
    }
}
void dij(){
    ans[1]=0;
    d.push(1);
    while(!d.empty()){
        int tmp=d.top();
        d.pop();
        if(vis[tmp]) continue;
        vis[tmp]=1;
        for(int i=0;i<q[tmp].size();i++){
            int ne=q[tmp][i].dian;
            int ju=q[tmp][i].dis;
            if(ans[ne]>ju+ans[tmp]&&!vis[ne]){
                ans[ne]=ju+ans[tmp];
                d.push(ne);
                //vis[ne]=1;
            }
        }
    }
}
void rebui(){
    for(int i=1;i<=n;i++){
        vis[i]=0;
    }
}
void redij(){
    ans2[1]=0;
    d2.push(1);
    while(!d2.empty()){
        int tmp=d2.top();
        d2.pop();
        if(vis[tmp]) continue;
        vis[tmp]=1;
        for(int i=0;i<re[tmp].size();i++){
            int ne=re[tmp][i].dian;
            int ju=re[tmp][i].dis;
            if(ans2[ne]>ju+ans2[tmp]&&!vis[ne]){
                ans2[ne]=ju+ans2[tmp];
                d2.push(ne);
                //vis[ne]=1;
            }
        }
    }
}
void ouput(){
    int cnt=0;
    for(int i=2;i<=n;i++) cnt+=(ans[i]+ans2[i]);
    cout<<cnt<<endl;
}
int main(){
    cin>>n>>m;
    input();
    for(int i=1;i<=n;i++){
        ans[i]=ans2[i]=maxm;
        vis[i]=0;
    }
    dij();
    rebui();
    redij();
    ouput();
    return 0;
}
////应该有重边？？？？QAQ