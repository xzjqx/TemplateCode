#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX_V1 10001
#define MAX_V2 10001
using namespace std;

int flag[MAX_V2];        //标记V2中的顶点i是否被找到过
int link[MAX_V2];        //记录在V2集合中的点与V1合匹配的点的编号
int mat[MAX_V1][MAX_V2];  //邻接矩阵存储(i,j)是否有边
int v1,v2;              //二分图两个集合顶点个数

bool dfs(int x) {
    for(int i=1;i<=v2;i++) {
        if(!flag[i]&&mat[x][i]) {
            flag[i]=1;
            if(link[i]==-1||dfs(link[i])) {
                link[i]=x;
                return true;
            }
        }
    }
    return false;
}//是否匹配成功

int getNum() {
    int num=0;
    memset(link,-1,sizeof(link));
    for(int i=1;i<=v1;i++) {
        memset(flag,0,sizeof(flag));
        if(dfs(i)) num++;
    }
    return num;
}//得到最大匹配数
