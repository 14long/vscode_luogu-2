#include <bits/stdc++.h>
using namespace std;
int cnt;
int n;
struct dingwei{int s1;int s2;};
//string
char a[200][200];
int s[200][200]={0};
dingwei weizhi[10000];//memset
void panding(int a1,int a2);
int main(){
    cin>>n;
    cnt=0;

    memset(a,0,sizeof(a)); 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]=='y'){
                cnt++;
                weizhi[cnt].s1=i;weizhi[cnt].s2=j;
            }
        }
    }
    for(int i=1;i<=cnt;i++){
        panding(weizhi[i].s1,weizhi[i].s2);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(s[i][j]==0){
                a[i][j]='*';
            }
            cout<<a[i][j];
        }
        cout<<endl;
    }
    return 0;
}
void panding(int a1,int a2){
    if(a2+6<=n&&a[a1][a2+1]=='i'&&a[a1][a2+2]=='z'&&a[a1][a2+3]=='h'&&a[a1][a2+4]=='o'&&a[a1][a2+5]=='n'&&a[a1][a2+6]=='g'){
        for(int i=a2;i<=a2+6;i++) s[a1][i]++;
    }
    if(a2-6>0&&a[a1][a2-1]=='i'&&a[a1][a2-2]=='z'&&a[a1][a2-3]=='h'&&a[a1][a2-4]=='o'&&a[a1][a2-5]=='n'&&a[a1][a2-6]=='g'){
        for(int i=a2;i>=a2-6;i--) s[a1][i]++;
    }
    if(a1+6<=n&&a[a1+1][a2]=='i'&&a[a1+2][a2]=='z'&&a[a1+3][a2]=='h'&&a[a1+4][a2]=='o'&&a[a1+5][a2]=='n'&&a[a1+6][a2]=='g'){
        for(int i=a1;i<=a1+6;i++) s[i][a2]++;
    }
    if(a1-6>0&&a[a1-1][a2]=='i'&&a[a1-2][a2]=='z'&&a[a1-3][a2]=='h'&&a[a1-4][a2]=='o'&&a[a1-5][a2]=='n'&&a[a1-6][a2]=='g'){
        for(int i=a1;i>=a1-6;i--) s[i][a2]++;
    }
    if(a1+6<=n&&a2+6<=n&&a[a1+1][a2+1]=='i'&&a[a1+2][a2+2]=='z'&&a[a1+3][a2+3]=='h'&&a[a1+4][a2+4]=='o'&&a[a1+5][a2+5]=='n'&&a[a1+6][a2+6]=='g'){
        for(int i=0;i<=6;i++){
            s[i+a1][a2+i]++;
        }
    }
    if(a1+6<=n&&a2-6>0&&a[a1+1][a2-1]=='i'&&a[a1+2][a2-2]=='z'&&a[a1+3][a2-3]=='h'&&a[a1+4][a2-4]=='o'&&a[a1+5][a2-5]=='n'&&a[a1+6][a2-6]=='g'){
        for(int i=0;i<=6;i++){
            s[a1+i][a2-i]++;
        }
    }
    if(a1-6>0&&a2-6>0&&a[a1-1][a2-1]=='i'&&a[a1-2][a2-2]=='z'&&a[a1-3][a2-3]=='h'&&a[a1-4][a2-4]=='o'&&a[a1-5][a2-5]=='n'&&a[a1-6][a2-6]=='g'){
        for(int i=0;i<=6;i++){
            s[a1-i][a2-i]++;
        }
    }
    if(a1-6>0&&a2+6<=n&&a[a1-1][a2+1]=='i'&&a[a1-2][a2+2]=='z'&&a[a1-3][a2+3]=='h'&&a[a1-4][a2+4]=='o'&&a[a1-5][a2+5]=='n'&&a[a1-6][a2+6]=='g'){
        for(int i=0;i<=6;i++){
            s[a1-i][a2+i]++;
        }
    }
}
