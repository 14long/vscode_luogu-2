#include <bits/stdc++.h>
using namespace std;
string s;
void ercha(string fu);
int n;
int main(){
    cin>>n>>s;
//    cout<<n<<s<<endl;
//    cout<<s.size()<<endl;
    ercha(s);
    return 0;
}
void ercha(string fu){
    if(fu.size()==1){
        //cout<<"bottom"<<endl;;///
        if(fu[0]=='0'){
            cout<<'B';return;
        }
        else if(fu[0]==0){
            cout<<'I';return;
        }
    }
    if(fu.size()==0) return;
    //confirm FBI
    bool h0=false;
    bool h1=false;
    for(int i=0;i<fu.size();i++){
        if(fu[i]=='0'&&h0==false) h0=true;
        if(fu[i]=='1'&&h1==false) h1=true;
        if(h0&&h1) break;
    }
    char is;
    if(h0&&h1) is='F';
    else if(!h0&&h1) is='I';
    else is='B';
    //分割
    ///cout<<fu.size()<<endl;
    string qian,hou;
    int len=fu.size()/2;//cout<<len<<' '<<fu.size()<<endl;
    qian=fu.substr(0,len);
    hou=fu.substr(len,len);
    //
    //cout<<qian<<endl<<hou<<endl<<fu<<endl<<endl;
    ercha(qian);
    ercha(hou);
    cout<<is;
    return;
}
///string 需要注意是否越界定义或使用