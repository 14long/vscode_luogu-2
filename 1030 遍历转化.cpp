#include <bits/stdc++.h>
using namespace std;
string zhong,hou;
struct st{char gen;char zuo;char you;};
st xushu[1000];
int suan;
void rebui(char ge,string shuzhong,string shuhou);
int main(){
    cin>>zhong>>hou;
 //   cout<<hou[hou.size()-1];
    suan=1;
    rebui(hou[hou.length()-1],zhong,hou);
   // for(int i=0;i<suan;i++) cout<<xushu[i+1].gen<<endl;
    return 0;
}
void rebui(char ge,string shuzhong,string shuhou){
    xushu[suan].gen=ge;
    suan++;
   // cout<<ge;
  //  cout<<suan<<endl;
    //边界
    if(shuzhong.size()==1){
        cout<<ge;
        return;
    }
    if(shuzhong.size()==2){
        cout<<shuzhong[1]<<shuzhong[0];
        return;
    }
    //分割序号
    int gexu;
    for(int i=0;i<shuzhong.size();i++){
        if(shuzhong[i]==ge){
            gexu=i;
            break;
        }
    }
    if(gexu==shuzhong.size()-1){
        string a1zhong,a1hou;
        cout<<shuhou[shuhou.size()-1];
        a1zhong=shuzhong.substr(0,shuzhong.size()-1);
        a1hou=shuhou.substr(0,shuhou.size()-1);
        rebui(a1hou[a1hou.size()-1],a1zhong,a1hou);
        return;
    }
    else if(gexu==0){
        string a1zhong,a1hou;
        cout<<shuhou[shuzhong.size()-1];
        a1zhong=shuzhong.substr(1,shuzhong.size()-1);
        a1hou=shuhou.substr(0,shuhou.size()-1);
        rebui(a1hou[a1hou.size()-1],a1zhong,a1hou);
        return;
    }
    //find zhonghou string
    string a1zhong,a1hou,a2zhong,a2hou;
    a1zhong=shuzhong.substr(0,gexu);
    a2zhong=shuzhong.substr(gexu+1,shuzhong.size()-gexu+1);
    a1hou=shuhou.substr(0,a1zhong.length());
    a2hou=shuhou.substr(a1zhong.length(),a2zhong.length());////jiyi
    //操作
   /// cout<<1<<endl;
    cout<<shuhou[shuhou.size()-1];
    rebui(a1hou[a1hou.size()-1],a1zhong,a1hou);
    rebui(a2hou[a2hou.size()-1],a2zhong,a2hou);
    return;
}
////直接cout前序？
////可简化



///调试
//分步
////技巧
