//Tarjan(struct)
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX_V 10000
#define MAX_E 10000
using namespace std;

struct edge {
    int to,next;    //next��ʾ��ñ�ͬ������һ���ߵı��
}e[MAX_V];          //�߼�����,�±��1��ʼ
int head[MAX_V];    //head[i]��ʾ��iΪ�������һ���ߵı��
int cnt;            //�ߵ�����

int time;           //ʱ���
int dfn[MAX_V];     //dfn[i]��¼�������ѵ���i��ĵ�ʱ���
int low[MAX_V];     //low[i]��¼����i��ֱ��ͨ��������������ĵ�
                    //��ӵ���ĵ����Сʱ���
int isGedian[MAX_V];//��ʼΪ0�����Ϊ��㣬��Ϊ1
int sons;           //��¼���ڵ������

void init() {
    memset(head,-1,sizeof(head));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(isGedian,0,sizeof(isGedian));
    memset(e,0,sizeof(e));
    cnt=0;
    time=1;
    sons=0;
}//��ʼ��

void addedge(int from,int to) {
    e[cnt].to=to;
    e[cnt].next=head[from];
    head[from]=cnt++;
}//�ӱ߲���

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
                sons++;         //���uΪ���ڵ㣬sons��¼���м�������
            }                   //���ж���1������sons>1)����Ϊ���
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
