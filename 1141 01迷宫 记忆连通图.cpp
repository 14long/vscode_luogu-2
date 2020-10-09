#include <bits/stdc++.h>
using namespace std;
char an[1010][1010];
int tu[1010][1010][1010];
int jiyi[1010][1010];
int cnttu=1;
struct st{int hang;int lie;};
st biao[100010];
int cnt=0;
int n,m;
void bfs(int hang,int lie);
int main(){
    ios::sync_with_stdio(false);
    memset(tu,0,sizeof(tu));
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin>>an[i][j];
    }
    for(int i=1;i<=m;i++){
        cin>>biao[i].hang>>biao[i].lie;
        memset(jiyi,0,sizeof(jiyi));
        for(int j=1;j<=cnttu;j++){
            if(tu[j][biao[i].hang][biao[i].lie]!=0){
                for(int a=1;a<=n;a++){
                    for(int b=1;b<=n;b++){
                        if(tu[j][a][b]!=0) cnt++;
                    }
                }
                cout<<cnt<<endl;
                goto aa;
            }
        }
        cnt++;
        jiyi[biao[i].hang][biao[i].lie]++;
        bfs(biao[i].hang,biao[i].lie);
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(jiyi[j][k]!=0) tu[cnttu][j][k]++;
            }
        }
        
        cnttu++;
        cout<<cnt<<endl;
        aa:
        cnt=0;
    }
    return 0;
}
void bfs(int hang,int lie){
    bool shang,xia,zuo,you;
    shang=xia=zuo=you=false;
    if(hang+1<=n&&jiyi[hang+1][lie]==0&&an[hang][lie]!=an[hang+1][lie]){
        cnt++;
        jiyi[hang+1][lie]++;
        shang=true;
    }
    if(hang-1>=1&&jiyi[hang-1][lie]==0&&an[hang][lie]!=an[hang-1][lie]){
        cnt++;
      ///  cout<<'a'<<endl;
        jiyi[hang-1][lie]++;
        xia=true;
    }
    if(lie+1<=n&&jiyi[hang][lie+1]==0&&an[hang][lie]!=an[hang][lie+1]){
        cnt++;
        zuo=true;
        jiyi[hang][lie+1]++;
    }
    if(lie-1>=1&&jiyi[hang][lie-1]==0&&an[hang][lie]!=an[hang][lie-1]){
        cnt++;
        you=true;
        jiyi[hang][lie-1]++;
    }
    if(shang==true) bfs(hang+1,lie);
    if(xia==true) bfs(hang-1,lie);
    if(zuo==true) bfs(hang,lie+1);
    if(you==true) bfs(hang,lie-1);
    return;
}