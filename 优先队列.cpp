#include <bits/stdc++.h>
using namespace std;
struct node{
    int a1;
    int a2;
    friend bool operator <(node s1,node s2){
        return s1.a1<s2.a1;//降序
    }
};
int shu[1000];
struct cmp{
    bool operator()(int a1,int a2)
    {
        return shu[a1]<shu[a2];//降序
    }
};
priority_queue<node> q1;
priority_queue<int,vector<int>,cmp> q2;
int main(){
    q1.push((node){12,3});
    q1.push((node){19,4});
    q1.push((node){3,90});
    while(!q1.empty()){
        cout<<q1.top().a1<<endl;
        q1.pop();
    }
    //
    cout<<endl;
    shu[1]=100;
    shu[2]=80;
    shu[3]=120;
    shu[4]=10;
    shu[5]=1;
    for(int i=1;i<=5;i++) q2.push(i);
    while(!q2.empty()){
        cout<<q2.top()<<endl;
        q2.pop();
    }
    //

    return 0;

}