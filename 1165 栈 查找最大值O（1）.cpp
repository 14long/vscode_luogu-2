#include <bits/stdc++.h>
using namespace std;
int f[100000]={0};//辅助数组
stack<int> q;
int check();
int main(){
    int n,t,all;
    all=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t;
        if(t==0){
            int j;cin>>j;
            q.push(j);
            all++;f[all]=max(f[all-1],j);//continue;
        }
        else if(t==2){
            cout<<f[all]<<endl;
        }
        else if(t==1){
            if(q.empty()) continue;
            else{
                all--;
                q.pop();
            }
        }
    }
}