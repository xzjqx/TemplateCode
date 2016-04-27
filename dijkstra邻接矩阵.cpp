//dijkstra(Adjacency Matrix)
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#define MAX_N 1001
#define INF 1<<29
#define pii pair<int,int>
using namespace std;

int edge[MAX_N][MAX_N];
int vis[MAX_N];
int dis[MAX_N];
int n;

void dijkstra() {
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)
        dis[i]=edge[1][i];

    for(int i=1;i<=n;i++) {
        int m=INF,v;
        for(int j=1;j<=n;j++)
            if(!vis[j] && dis[j]<m) {
                v=j;
                m=dis[j];
            }
        vis[v]=1;
        for(int j=1;j<=n;j++)
            if(!vis[j] && dis[j]>edge[v][j]+dis[v])
                dis[j]=edge[v][j]+dis[v];
    }
    printf("%d\n",dis[n]);
}

int main()
{
    int t,x,y,val;
    while(scanf("%d%d",&t,&n)!=EOF) {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i==j)
                    edge[i][i]=0;
                else edge[i][j]=edge[j][i]=INF;
        while(t--) {
            scanf("%d%d%d",&x,&y,&val);
            if(edge[x][y]>val) {
                edge[x][y]=val;
                edge[y][x]=val;
            }
        }
        dijkstra();
    }
    return 0;
}
