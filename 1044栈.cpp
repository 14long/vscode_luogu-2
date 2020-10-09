#include <bits/stdc++.h>
using namespace std;
stack<int> q;
queue<int> in,out;
int cnt;
void di(int inp,int st);
int main(){
    int n;
    cin>>n;cnt=0;
    for(int i=1;i<=n;i++) in.push(i);
    di(n,0);
    cout<<cnt<<endl;
    return 0;
}
void di(int inp,int st){
    if(inp==0){
        cnt++;return;
    }
    if(inp==1&&st==0){
        cnt++;return;
    }
    if(!in.empty()&&q.empty()){
        q.push(in.front());
        in.pop();
        di(inp-1,st);
        return;
    }
    if(!in.empty()&&!q.empty()){
        q.pop();
        di(inp,st-1);
        q.push(1);
        q.push(in.front());
        in.pop();
        di(inp-1,st+1);
    }
}