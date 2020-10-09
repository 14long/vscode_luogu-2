#include <bits/stdc++.h>
using namespace std;
string a[1010];
int jiyi[1010][1010];
struct st{int hang;int lie;};
st biao[100010];////memset
int cnt=0;
int n,m;
void bfs(int hang,int lie);
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i+1];////从1写起
    for(int i=0;i<m;i++) cin>>biao[i+1].hang>>biao[i+1].lie;
    for(int i=0;i<m;i++){
        for(int i=0;i<n;i++) memset(jiyi[i+1],0,sizeof(jiyi[i+1]));
        jiyi[biao[i+1].hang][biao[i+1].lie-1]++;
        bfs(biao[i+1].hang,biao[i+1].lie-1);
        cout<<cnt<<endl;
        cnt=0;
    }
    return 0;
}
void bfs(int hang,int lie){
    cnt++;
  ///  cout<<cnt<<endl;
    char chushi=a[hang][lie];////记忆
    if(lie+1<=n-1&&a[hang][lie+1]!=chushi&&jiyi[hang][lie+1]==0){
        jiyi[hang][lie+1]++;
      ///  cout<<1<<endl;
        bfs(hang,lie+1);
        
    }
    if(lie-1>=0&&a[hang][lie-1]!=chushi&&jiyi[hang][lie-1]==0){
        jiyi[hang][lie-1]++;
        ///cout<<2<<endl;
        bfs(hang,lie-1);
    }
    if(hang+1<=n&&a[hang+1][lie]!=chushi&&jiyi[hang+1][lie]==0){
        jiyi[hang+1][lie]++;
        ///cout<<3<<endl;
        bfs(hang+1,lie);
    }
    if(hang-1>=1&&a[hang-1][lie]!=chushi&&jiyi[hang-1][lie]==0){
        jiyi[hang-1][lie]++;
       /// cout<<4<<endl;
        bfs(hang-1,lie);
    }
////行列
}