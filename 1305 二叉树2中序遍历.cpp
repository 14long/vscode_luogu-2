#include <bits/stdc++.h>
using namespace std;
struct st{char zhong;char zuo;char you;};
st shu[30];
int n;
void qianxu(char top);
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>shu[i].zhong>>shu[i].zuo>>shu[i].you;
    }
    //cout<<shu[2].zhong<<endl;
    qianxu(shu[1].zhong);
//    cout<<1<<endl;
    return 0;
}
void qianxu(char top){
    bool zuo1=false;
    bool you1=false;
    int i=0;//sreach xiabiao
    for(int j=0;j<n;j++){
        if(shu[j+1].zhong==top){
            i=j+1;break;
        }
    }
//    cout<<shu[i].zhong;
    if(shu[i].zuo=='*') zuo1=false;
    if(shu[i].you=='*') you1=false;
    for(int j=1;j<=n;j++){
        if(shu[j].zhong==shu[i].zuo){
            zuo1=true;
        }
        else if(shu[j].zhong==shu[i].you) you1=true;
    }
    //if()
    if(zuo1==false&&you1==false){
        if(shu[i].zuo!='*') cout<<shu[i].zuo;
        cout<<shu[i].zhong;
        if(shu[i].you!='*') cout<<shu[i].you;//cout<<1<<endl;
        return;
    }//
    else if(zuo1==true&&you1==true){
        qianxu(shu[i].zuo);
        cout<<shu[i].zhong;
        qianxu(shu[i].you);
    }
    else if(zuo1==true){
        qianxu(shu[i].zuo);
        cout<<shu[i].zhong;
        if(shu[i].you!='*') cout<<shu[i].you;
    }
    else if(you1==true){
        if(shu[i].zuo!='*') cout<<shu[i].zuo;
        cout<<shu[i].zhong;
        qianxu(shu[i].you);
    }
}