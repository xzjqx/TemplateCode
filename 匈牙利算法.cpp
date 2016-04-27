#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX_V1 10001
#define MAX_V2 10001
using namespace std;

int flag[MAX_V2];        //���V2�еĶ���i�Ƿ��ҵ���
int link[MAX_V2];        //��¼��V2�����еĵ���V1��ƥ��ĵ�ı��
int mat[MAX_V1][MAX_V2];  //�ڽӾ���洢(i,j)�Ƿ��б�
int v1,v2;              //����ͼ�������϶������

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
}//�Ƿ�ƥ��ɹ�

int getNum() {
    int num=0;
    memset(link,-1,sizeof(link));
    for(int i=1;i<=v1;i++) {
        memset(flag,0,sizeof(flag));
        if(dfs(i)) num++;
    }
    return num;
}//�õ����ƥ����
