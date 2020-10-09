#include <bits/stdc++.h>
using namespace std;
struct st{int fu;int zuo;int you;};
st fu[100000];////memset?
int f;
void bfs(int fk);
int main(){
    cin>>f;
    for(int i=0;i<f;i++){
        cin>>fu[i+1].zuo>>fu[i+1].you;
        fu[i+1].fu=i+1;
    }
    bfs(1);
    return 0;
    
}
void bfs(int fk){
    cout<<fk;
    if(fu[fk].zuo==0&&fu[fk].you==0) return;
    if(fu[fk].zuo==0){
        int you=-1;
        for(int i=0;i<f;i++){
            if(fu[fk].you==fu[i+1].fu){
                you=i+1;break;
            }
        }
        bfs(you);
        return;
    }
    if(fu[fk].you==0){
        int zuo=-1;
        for(int i=0;i<f;i++){
            if(fu[fk].zuo==fu[i+1].fu){
                zuo=i+1;break;
            }
        }
        bfs(zuo);
        return;
    }
    int zuo,you;
    zuo=you=-1;
    for(int i=0;i<f;i++){
        if(fu[fk].zuo==fu[i+1].fu){
            zuo=i+1;break;
            
        }
    }
    for(int i=0;i<f;i++){
        if(fu[fk].you==fu[i+1].fu){
            you=i+1;break;
        }
    }
    if(zuo!=-1&&you!=-1){
        bfs(zuo);
        bfs(you);
        return;
    }
    if(zuo==-1){
        bfs(you);return;
    }
    if(you==-1){
        bfs(zuo);return;
    }
}