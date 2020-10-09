#include <bits/stdc++.h>
using namespace std;
int cnt=0;
void di(int st,int in){
    if(st==0&&in!=0){
        di(1,in-1);
        return;//
    }
    if(in==0){
        cnt++;return;
    }//
    if(st!=0&&in!=0){
        di(st-1,in);
        di(st+1,in-1);
    }
}
int main(){
    int n;
    cin>>n;
    di(0,n);
    cout<<cnt<<endl;
    return 0;
}