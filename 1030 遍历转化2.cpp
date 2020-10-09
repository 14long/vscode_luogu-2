#include <bits/stdc++.h>
using namespace std;
string zhong,hou;
struct st{char gen;char zuo;char you;};
st xushu[10];
int cnt,suan;
void chushihua();
void rebui(char ge,string shuzhong,string shuhou);
void xianxu();
int main(){
    cin>>zhong>>hou;
    cnt=zhong.size();
    suan=1;
    chushihua();
    rebui(hou[hou.length()-1],zhong,hou);
    xianxu();
    return 0;
}
void rebui(char ge,string shuzhong,string shuhou){
    xushu[suan].gen=ge;
    suan++;
    //边界
    if(shuzhong.size()==1){
        return;
    }
    //分割序号
    int gexu;
    for(int i=0;i<zhong.size();i++){
        if(zhong[i]==ge){
            gexu=i;
            break;
        }
    }
    //find zhonghou string
    string a1zhong,a1hou,a2zhong,a2hou;
    a1zhong=shuzhong.substr(0,gexu);
    a2zhong=shuzhong.substr(gexu+1,shuzhong.size()-gexu+1);
    a1hou=shuhou.substr(0,a1zhong.length());
    a2hou=shuhou.substr(a1zhong.length(),a2zhong.length());////jiyi
    //操作
    cout<<ge;
    rebui(a1hou[a1hou.size()-1],a1zhong,a1hou);
    rebui(a2hou[a2hou.size()-1],a2zhong,a2hou);
    return;
}
void chushihua(){

}
//直接cout前序？