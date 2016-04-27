//Tarjan(struct)
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX_V 10000
#define MAX_E 10000
using namespace std;

struct edge {
    int to,next;    //next表示与该边同起点的下一条边的编号
}e[MAX_V];          //边集数组,下标从1开始
int head[MAX_V];    //head[i]表示以i为起点的最后一条边的编号
int cnt;            //边的数量

int time;           //时间戳
int dfn[MAX_V];     //dfn[i]记录的是深搜到第i点的的时间戳
int low[MAX_V];     //low[i]记录的是i能直接通过其深搜子树里的点
                    //间接到达的点的最小时间戳
int isGedian[MAX_V];//初始为0，如果为割点，则为1
int sons;           //记录根节点儿子数

void init() {
    memset(head,-1,sizeof(head));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(isGedian,0,sizeof(isGedian));
    memset(e,0,sizeof(e));
    cnt=0;
    time=1;
    sons=0;
}//初始化

void addedge(int from,int to) {
    e[cnt].to=to;
    e[cnt].next=head[from];
    head[from]=cnt++;
}//加边操作

void dfs(int u,int pre) {
    dfn[u]=low[u]=time++;
    //stack1[top++]=u;
    for(int i=head[u];i!=-1;i=e[i].next) {
        int v=e[i].to;
        if(!dfn[v]) {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if (low[v] >= dfn[u] && u != 1) {
                isGedian[u]=1;
            }
            else if (u == 1) {
                sons++;         //如果u为根节点，sons记录他有几个孩子
            }                   //若有多余1个孩子sons>1)，则为割点
        }
        else if(v!=pre)
            low[u]=min(low[u],dfn[v]);
    }
}

int main()
{
    int n,u,v;
    while(scanf("%d",&n),n) {
        init();
        while(scanf("%d",&u),u) {
            if(u==0) break;
            while(getchar() != '\n'){
                scanf("%d",&v);
                addedge(u,v);
                addedge(v,u);
           }
        }
        dfs(1,-1);
        int num=0;
        if(sons>1) num++;
        for(int i=1;i<=n;i++)
            num+=isGedian[i];
        printf("%d\n",num);
    }
    return 0;
}
