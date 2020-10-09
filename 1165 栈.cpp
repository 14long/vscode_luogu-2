#include <bits/stdc++.h>
using namespace std;
struct st{int a1;int zh;};
stack<int> q,che;
int check();
int main(){
    int n,t;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t;
        if(t==0){
            int j;cin>>j;
            q.push(j);//continue;
        }
        else if(t==2){
            cout<<check()<<endl;
        }
        else if(t==1){
            if(q.empty()) continue;
            else{
                q.pop();
            }
        }
    }
}
int check(){
    if(q.empty()) return 0;
    else{
        int j=0;
        che=q;
        while(!che.empty()){
            if(che.top()>j){
                j=che.top();
            }
            che.pop();
        }
        return j;
    }
}