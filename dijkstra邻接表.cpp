//dijkstra(Adjacency Table)
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#define MAX_N 1001<<1
#define INF 1<<29
using namespace std;

struct edge {
    int from,to,val;
    int next;
}e[MAX_N<<1];
int head[MAX_N];
int vis[MAX_N];
int dis[MAX_N];
int n,cnt;

void addedge(int from,int to,int val) {
    e[cnt].from=from;
    e[cnt].to=to;
    e[cnt].val=val;
    e[cnt].next=head[from];
    head[from]=cnt++;
    e[cnt].from=to;
    e[cnt].to=from;
    e[cnt].val=val;
    e[cnt].next=head[to];
    head[to]=cnt++;
}

void dijkstra(int s) {
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)
        dis[i]=INF;
    dis[s]=0;
    vis[s]=1;
    queue<int> q;
    while(!q.empty()) q.pop();

    q.push(s);
    while(!q.empty()) {
        int v=q.front();
        q.pop();
        vis[v]=0;

        for(int i=head[v];i!=-1;i=e[i].next) {
            if(dis[e[i].to]>dis[v]+e[i].val) {
                dis[e[i].to]=dis[v]+e[i].val;
                if(!vis[e[i].to]) {
                    vis[e[i].to]=1;
                    q.push(e[i].to);
                }
            }
        }
    }
    printf("%d\n",dis[n]);
}

int main()
{
    int t,x,y,val;
    while(scanf("%d%d",&t,&n)!=EOF) {
        memset(head,-1,sizeof(head));
        cnt=0;
        while(t--) {
            scanf("%d%d%d",&x,&y,&val);
            addedge(x,y,val);
        }
        dijkstra(1);
    }
    return 0;
}
