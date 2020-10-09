#include <bits/stdc++.h>
using namespace std;
char an[200][200];
int use[200][200];
int ch[8][2]={{0,1},{1,1},{0,-1},{1,-1},{-1,1},{-1,0},{-1,-1},{1,0}};
char sh[7]="izhong";
int n;
void if_yizhong(int i,int j);
void dfs();
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",an[i]);
	}
	dfs();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!use[i][j]) an[i][j]='*';
		}
	}
	for(int i=0;i<n;i++){
		printf("%s\n",an[i]);
	}
	return 0;
}
void dfs(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(an[i][j]=='y'){
				if_yizhong(i,j);
			}
		}
	}
}
void if_yizhong(int i,int j){
	bool a=false;
	for(int t=0;t<8;t++){
		a=false;
		for(int w=1;w<=6;w++){
			if(an[i+ch[t][0]*w][j+ch[t][1]*w]!=sh[w-1]){
				a=true;
				break;
			}
	 	}
		if(!a){
			for(int w=0;w<7;w++){
				use[i+ch[t][0]*w][j+ch[t][1]*w]++;
			}
		}
	}
}