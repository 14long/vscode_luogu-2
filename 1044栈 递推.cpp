#include <bits/stdc++.h>
using namespace std;
int digui(int st,int in){
    if(in==0){
        return 1;
    }
    if(st==0&&in!=0){
        return digui(1,in-1);
    }
    else
    {
        int i=digui(st+1,in-1)+digui(st-1,in);
        return i;
    }
}
int main(int argc, char const *argv[])
{
    int n;cin>>n;
    cout<<digui(0,n)<<endl;
    return 0;
}
