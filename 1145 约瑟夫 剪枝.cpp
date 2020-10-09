#include <bits/stdc++.h>
using namespace std;
queue<int> ji;////[][参数]
int k;
int findout(int bushu);
int main(){
    cin>>k;
    for(int m=k+1;m<14;m++){
        aa:
        while(!ji.empty()) ji.pop();
        ///cout<<ji.size()<<endl;
        for(int i=1;i<=2*k;i++){
            ji.push(i);
        }
  ///      cout<<ji.front()<<endl;
        while(ji.size()>k){
            int biao=findout(m);
            for(int i=1;i<biao;i++){
                int j=ji.front();
                ji.pop();ji.push(j);
    ///            cout<<ji.back()<<endl;
            }
            if(ji.front()==1){
                m++;
                ///cout<<14<<endl;
                goto aa;////goto后文出现
            }
            ji.pop();
        }
   ///     cout<<"ss"<<m<<endl;
        bool all=false;
        while(!ji.empty()){
      ///      cout<<"a"<<ji.front()<<endl;
            if(ji.front()<=k){
                ji.pop();
            }
            else if(ji.front()>k){
                all=true;
               /// cout<<13<<endl;
                break;
            }
        }
        bb:
 ///       cout<<12<<endl;
        if(all){
            m++;
            goto aa;
        }
        else{
            cout<<m<<endl;
            return 0;
        }
    }
    return 0;    
}
int findout(int bushu){
    if(ji.size()<bushu) return bushu%ji.size();
    else return bushu;
}
////链表 queue 指针
////s=(s+m-1)%(2*k-i)正解
