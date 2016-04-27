//Tarjan(vector)
#include <cstdio>
#include <cstring>
#include <vector>
#define MAX_N 101
using namespace std;

vector<int> e[MAX_N];
int dfn[MAX_N],low[MAX_N];
int isGedian[MAX_N],time,sons;
void init() {
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(isGedian,0,sizeof(isGedian));
    memset(e,0,sizeof(e));
    time=1;
    sons=0;
}

void Tarjan(int u,int pre) {
    dfn[u]=low[u]=time++;
    for(int i=0;i<e[u].size();i++) {
        int v=e[u][i];
        if(!dfn[v]) {
            Tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if (low[v] >= dfn[u] && u != 1) {
                isGedian[u]=1;
            }
            else if (u == 1) {
                sons++;
            }
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
            while(getchar() != '\n') {
                scanf("%d",&v);
                e[u].push_back(v);
                e[v].push_back(u);
            }
        }
        Tarjan(1,-1);
        int num=(sons>1)?1:0;
        for(int i=1;i<=n;i++)
            if(isGedian[i]) num++;
        printf("%d\n",num);
    }
}
