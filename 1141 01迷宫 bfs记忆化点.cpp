#include <bits/stdc++.h>
using namespace std;
char an[1010][1010];
int tu[1010][1010];
int cnttu=1;
int cnt=0;
int shu[50000];
int n,m;
void bfs(int hang,int lie);
int main(){
    ios::sync_with_stdio(false);
    memset(tu,0,sizeof(tu));
    memset(shu,0,sizeof(shu));
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin>>an[i][j];
    }
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
//        memset(jiyi,0,sizeof(jiyi));
        for(int j=1;j<=cnttu;j++){
            if(tu[a][b]!=0){

                cout<<shu[tu[a][b]]<<endl;
            //    cout<<14<<endl;
                goto aa;
            }
        }
        cnt++;
        tu[a][b]+=cnttu;
        bfs(a,b);
        shu[cnttu]=cnt;
        cnttu++;
        cout<<cnt<<endl;
        goto aa;
        aa:
        cnt=0;
    }
    return 0;
}
void bfs(int hang,int lie){
    bool shang,xia,zuo,you;
    shang=xia=zuo=you=false;
    if(hang+1<=n&&tu[hang+1][lie]!=cnttu&&an[hang][lie]!=an[hang+1][lie]){
        cnt++;
        tu[hang+1][lie]+=cnttu;
        shang=true;
        ///cout<<12<<endl;
    }
    if(hang-1>=1&&tu[hang-1][lie]!=cnttu&&an[hang][lie]!=an[hang-1][lie]){
        cnt++;
      ///  cout<<'a'<<endl;
        tu[hang-1][lie]+=cnttu;
        xia=true;
        ///cout<<12<<endl;
    }
    if(lie+1<=n&&tu[hang][lie+1]!=cnttu&&an[hang][lie]!=an[hang][lie+1]){
        cnt++;
        zuo=true;
        tu[hang][lie+1]+=cnttu;
     ///   cout<<12<<endl;
    }
    if(lie-1>=1&&tu[hang][lie-1]!=cnttu&&an[hang][lie]!=an[hang][lie-1]){
        cnt++;
        you=true;
    ///    cout<<12<<endl;
        tu[hang][lie-1]+=cnttu;
    }
    if(shang==true) bfs(hang+1,lie);
    if(xia==true) bfs(hang-1,lie);
    if(zuo==true) bfs(hang,lie+1);
    if(you==true) bfs(hang,lie-1);
    return;
}
//无mle