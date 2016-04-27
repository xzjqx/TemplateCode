//��С������Kruskal
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
        length+=e[i].val;//lengthΪ��С����������
        //��i���߼�����С������
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
        addedge(y,x,val);//��Ϊ����ͼ
    }
    /*����ߣ���ʼ���߼�����*/
    sort(e,e+cnt,cmp);//��������
    for(int i=0;i<cnt;i++)
        Union(i);//�жϵ�i�����Ƿ������С������

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
