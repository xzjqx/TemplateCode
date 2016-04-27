//DFS
#include <cstdio>
#include <cstring>

struct edge {
    int from,to;
}e[50];
int num[10],n,m,cnt,ans;
int sumA[10],sumB[10];

void dfs(int x) {
    if(x==cnt) {
        ans++;
        return;
    }
    if(sumA[e[x].from]<num[e[x].from]/2&&
       sumA[e[x].to]<num[e[x].to]/2) {
        sumA[e[x].from]++;
        sumA[e[x].to]++;
        dfs(x+1);
        sumA[e[x].from]--;
        sumA[e[x].to]--;
    }

    if(sumB[e[x].from]<num[e[x].from]/2&&
       sumB[e[x].to]<num[e[x].to]/2) {
        sumB[e[x].from]++;
        sumB[e[x].to]++;
        dfs(x+1);
        sumB[e[x].from]--;
        sumB[e[x].to]--;
    }

    return;
}

int main()
{
    int t,a,b;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&m);
        memset(e,0,sizeof(e));
        memset(num,0,sizeof(num));
        memset(sumA,0,sizeof(sumA));
        memset(sumB,0,sizeof(sumB));
        cnt=ans=0;
        for(int i=0;i<m;i++) {
            scanf("%d%d",&a,&b);
            num[a]++;
            num[b]++;
            e[cnt].from=a;
            e[cnt++].to=b;
        }

        int i;
        for(i=1;i<=n;i++)
            if(num[i]%2!=0)
                break;
        if(i==n+1&&m%2==0) {
            dfs(0);
            printf("%d\n",ans);
        }
        else printf("0\n");
    }
    return 0;
}
