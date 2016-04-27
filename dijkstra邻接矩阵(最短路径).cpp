#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>
#define MAX_N 1001
#define MAX_M 10001
#define INF 1<<29
#define pii pair<int,int>
using namespace std;

int edge[MAX_N][MAX_N];
int flag[MAX_N][MAX_N];
int vis[MAX_N];
int dis[MAX_N];
int num[MAX_N];
int path[MAX_N];
int n,m,ans;

struct node {
    int num,pos;
}nu[MAX_N];

bool cmp(int a,int b) {
    return a>b;
}

int dijkstra() {
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)
        dis[i]=INF;
    dis[1]=0;
    memset(path,0,sizeof(path));
    path[1]=num[1];
    for(int i=1;i<=n;i++) {
        int m=INF,v;
        for(int j=1;j<=n;j++)
            if(!vis[j] && dis[j]<m) {
                v=j;
                m=dis[j];
            }
        if(m==INF) break;
        vis[v]=1;
        for(int j=1;j<=n;j++)
            if(!vis[j]) {
                if(dis[v]+edge[v][j]<dis[j]) {
                    dis[j]=dis[v]+edge[v][j];
                    path[j]=path[v]+flag[v][j];
                }
                else if(dis[v]+edge[v][j]==dis[j]) {
                    if(path[v]+flag[v][j]>path[j])
                        path[j]=path[v]+flag[v][j];
                }
            }
    }
    if(dis[n]==INF) return -1;
    else return path[n];
}

int main()
{
    int x,y,val;
    while(scanf("%d%d",&n,&m)!=EOF) {
        ans = 0;
        memset(path,0,sizeof(path));
        for( int i=1; i <= n; i ++)  {
            scanf("%d",&num[i]);
        }

        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                edge[i][j]=edge[j][i]=INF;
        memset(flag,0,sizeof(flag));
        while(m--) {
            scanf("%d%d%d",&x,&y,&val);
            if(edge[x][y]>val) {
                edge[x][y]=val;
                edge[y][x]=val;
                flag[x][y]=num[y];
                flag[y][x]=num[x];
            }
        }
        printf("%d\n",dijkstra());
    }
    return 0;
}
