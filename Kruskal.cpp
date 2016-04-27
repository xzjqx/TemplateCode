//最小生成树Kruskal
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_E=80*2;
const int MAX_V=30;

struct edge {
    int from;
    int to;
    int val;
}e[MAX_E];
int cnt,length,n;
int father[MAX_V];

void addedge(int from,int to,int val) {
    e[cnt].from=from;
    e[cnt].to=to;
    e[cnt].val=val;
    cnt++;
}

int cmp(edge i,edge j) {
    return i.val<j.val;
}

void init() {
    for(int i=0;i<=n;i++)
        father[i]=i;
    cnt=0;
    length=0;
}

int Find(int x) {
    if(father[x]==x)
        return x;
    father[x]=Find(father[x]);
    return father[x];
}

void Union(int i) {
    int x=Find(e[i].from);
    int y=Find(e[i].to);
    if(x!=y) {
        length+=e[i].val;//length为最小生成树长度
        //第i条边加入最小生成树
        father[x]=y;
    }
}

void Kruskal() {
    init();
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int x,y,val;
        scanf("%d%d%d",&x,&y,&val);
        addedge(x,y,val);
        addedge(y,x,val);//若为无向图
    }
    /*加入边，初始化边集数组*/
    sort(e,e+cnt,cmp);//升序排序
    for(int i=0;i<cnt;i++)
        Union(i);//判断第i条边是否加入最小生成树

}

int main()
{
    int n,m,l,ans;
    char a,b;
    while(scanf("%d",&n),n) {

        printf("%d\n",length);
    }
    return 0;
}
