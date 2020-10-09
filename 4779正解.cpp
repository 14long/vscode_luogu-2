#include<bits/stdc++.h>
using namespace std;
const int MaxN = 100010, MaxM = 500010;
struct edge{
    int to, dis, next;
};
edge e[MaxM];
int head[MaxN], dis[MaxN], cnt;
bool vis[MaxN];
int n, m, s;

void add_edge( int u, int v, int d ){
    cnt++;
    e[cnt].dis = d;
    e[cnt].to = v;
    e[cnt].next = head[u];///
    head[u] = cnt;///
}//e和head形成邻接表
struct node{
    int dis;
    int pos;
    bool operator <( const node &x )const{
        return x.dis < dis;
    }////重载???
};
std::priority_queue<node> q;
void dijkstra(){
    dis[s] = 0;
    q.push( (node){0, s} );////push顺序已经重载
    while( !q.empty() ){
        node tmp = q.top();
        q.pop();
        int x = tmp.pos;
        if( vis[x] ) continue;////懒惰删除?????
        vis[x] = 1;
        for( int i = head[x]; i; i = e[i].next ){
            int y = e[i].to;
            if( dis[y] > dis[x] + e[i].dis )
            {
                dis[y] = dis[x] + e[i].dis;
                if(!vis[y]) q.push( ( node ){dis[y], y} );
            }
        }
    }
}
int main(){
    scanf( "%d%d%d", &n, &m, &s );
    for(int i = 1; i <= n; ++i) dis[i] = 0x7fffffff;
    for(int i = 0; i < m; ++i ){
        int u, v, d;
        scanf( "%d%d%d", &u, &v, &d );
        add_edge( u, v, d );
    }
    dijkstra();
    for( int i = 1; i <= n; i++ )
        printf( "%d ", dis[i] );
    return 0;
}