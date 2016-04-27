//一维树状数组
int n;//初始元素个数
//初始化时将ar[]置为0
int lowbit( int i ) {
    return i & ( -i );
}

void add(int i, int v) {
    for( ; i <= n; ar[i] += v, i += lowbit(i) );
}//将i点的值加v

int sum(int i) {
    int ret = 0;
    for( ; i > 0; ret += ar[i], i -= lowbit(i) );
    return ret;
}//求[1, i]的和

//二维树状数组
int n, m;
//初始化将ar[][]置为0
int lowbit(int i) {
    return i & ( -i );
}

void add( int i, int j, int v ) {
    for( int ii = i; ii <= n; ii += lowbit(ii) )
        for( int jj = j; jj <= m; jj += lowbit(jj) )
            ar[ii][jj] += v;
}

int sum( int i, int j ) {
    int ret = 0;
    for( int ii = i; ii > 0; ii -= lowbit(ii) )
        for( int jj = j; jj > 0; jj -= lowbit(jj) )
            ret += ar[ii][jj];
    return ret;
}

//树状数组实现单点查询，区间更新
/*************************************************
有时题目是区间修改，点查询
我们可以把它转化为点修改，区间查询
如已知数列a[]，有两种操作，一种是询问a[i]的值，另一种是将a[i]到a[j]的元素都加上k
建立数组b[]，b[1]=a[1]，b[2]=a[2]-a[1]，
            b[3]=a[3]-a[2]，……，b[i]=a[i]-a[i-1]
这样b[1]+b[2]+……+b[i]=a[i]
将点查询变成了区间查询
若要将a[i]到a[j]的元素都加上k
令b[i]+=k，b[j+1]-=k，就将区间修改转化为了点修改
*************************************************/
/*
OJ: HDOJ
ID: forever
TASK: 1556.Color the ball
LANG: C++
NOTE: 树状数组
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 100010
using namespace std;

int t, n, q, x, y, z;
int ar[MAX];

int lowbit(int x) {
    return x & ( -x );
}

void add( int i, int v ) {
    for( ; i <= n; ar[i] += v, i += lowbit(i) );
}

int sum(int i) {
    int ret = 0;
    for( ; i > 0; ret += ar[i], i -= lowbit(i) );
    return ret;
}

int main()
{
    while( scanf( "%d", &n ), n ) {
        memset( ar, 0, sizeof(ar) );
        for( int i = 0; i < n; i ++ ) {
            scanf( "%d%d", &x, &y );
            add( x, 1 );
            add( y + 1, -1 );
        }
        for( int i = 1; i < n; i ++ )
            printf( "%d ", sum(i) );
        printf( "%d\n", sum(n) );
    }
}
