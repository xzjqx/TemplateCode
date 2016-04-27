#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

/*********************************
          0-1背包问题
n件物品：
物品i重w[i]，效益p[i]，背包容量c
dp[j]：表示容量为j时背包最大效益
*********************************/
void ZeroOnePack() {
    memset( dp, 0, sizeof(dp) );
    for( int i = 0; i < n; i++) {
        for( int j = c; j >= w[i]; j --) {
            dp[j] = max( dp[j], dp[j - w[i]] + p[i] );
        }
    }
    printf("%d\n",dp[c]);
}

/***************************************
             完全背包问题
n种物品：
第i种物品的重w[i]，效益p[i]，背包容量c
dp[j]：表示容量为j时背包最大效益值
***************************************/
void CompletePack() {
    memset( dp, 0, sizeof(dp) );
    for( int i = 0; i < n; i++) {
        for( int j = w[i]; j <= c; j ++) {
            dp[j] = max( dp[j], dp[j - w[i]] + p[i] );
        }
    }
    printf("%d\n",dp[j]);
}

/*****************************************
             多重背包问题
n种物品：
第i种物品有n[i]件，重w[i]效益p[i]，容量c
dp[j]：表示容量为j时背包最大的效益
*****************************************/
void MultiplePack() {
    memset( dp, 0, sizeof(dp) );
    for( int i = 0; i < n; i ++ ) {
        if( w[i] * n[i] >= c ) {
            CompletePack(1);
            return;
        }
        int k=1;
        while(k<n[i]) {
            ZeroOnePack(k);
            n[i] -= k;
            k *= 2;
        }
        ZeroOnePack(n[i]);
    }
}
/*****************例*******************/
/*
OJ: HDOJ
ID: forever
TASK: 2191....
LANG: C++
NOTE: MultiplePack
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[101];

void ZeroOnePack(int cost,int weight,int power) {
    for(int j = cost; j >= weight; j -- )
        dp[j] = max( dp[j], dp[j-weight] + power);
}

void CompletePack(int cost,int weight,int power) {
    for(int j = weight; j <= cost; j ++ )
        dp[j] = max( dp[j], dp[j-weight] + power);
}

void MultiplePack(int cost,int weight,int power,int amount) {
    if( weight * amount > cost ) {
        CompletePack( cost, weight, power );
    }
    else {
        int k = 1;
        while( k < amount ) {
            ZeroOnePack( k * cost, k * weight ,power );
            amount = amount - k;
            k = k * k;
        }
        ZeroOnePack( amount * cost, amount * weight, power );
    }
}

int main()
{
    int t,n,m,p[101],h[101],c[101];
    scanf( "%d", &t );
    while( t -- ) {
        scanf( "%d%d", &n, &m );
        memset( dp, 0, sizeof(dp) );
        for( int i = 0; i < m; i ++ )
            scanf( "%d%d%d", &p[i], &h[i], &c[i] );
        for( int i = 0; i < m; i ++ ) {
            MultiplePack( n, p[i], h[i], c[i] );
        }
        printf( "%d\n", dp[n] );
    }
    return 0;
}
/******************例完*********************/

/*******************************************
        0-1背包恰好装满时的最小收益
n件物品：
物品i重w[i]，效益p[i]，背包容量c
dp[j]：表示容量为j时背包最小效益
********************************************/
void ZeroOnePack_zuixiaoshouyi() {
    for( int i = 0; i < 10001; i ++ )
        dp[i] = INF;//初始化为最大值
    dp[0]=0;//容量为0时可以恰好装满，收益为0
    for( int i = 0; i < n; i ++ ) {
        for( int j = f- e; j >= w[i]; j -- ) {
            if( dp[j - w[i]] < INF && dp[j - w[i]] + p[i] < dp[j] )
                dp[j] = dp[j - w[i]] + p[i];
        }
    }
    if( dp[f - e] != INF )
        //则可以恰好装满，dp[f - e]为最小收益
    else
        //不能恰好装满
}
/*******************例*********************/
/*
OJ: HDOJ
ID: forever
TASK: 1114.Piggy-Bank
LANG: C++
NOTE: CompletePack(Exactly filled)
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 0x7ffffff
using namespace std;

int main()
{
    int t, e, f, n;
    int p[501], w[501];
    int dp[10001];
    scanf( "%d", &t );
    while( t -- ) {
        scanf( "%d%d%d", &e, &f ,&n );
        for( int i = 0; i < n; i ++ )
            scanf( "%d%d", &p[i], &w[i] );

        for( int i = 0; i < 10001; i ++ )
            dp[i] = INF;
        dp[0]=0;
        for( int i = 0; i < n; i ++ ) {
            for( int j = w[i]; j <= f - e; j ++ ) {
                if( dp[j - w[i]] < INF && dp[j - w[i]] + p[i] < dp[j] )
                    dp[j] = dp[j - w[i]] + p[i];
            }
        }
        if( dp[f - e] != INF )
            printf( "The minimum amount of money in the piggy-bank is %d.\n", dp[f - e] );
        else
            puts( "This is impossible." );
    }
    return 0;
}
/******************例完*********************/

/*************************************************
            二维费用的背包问题
n件物品：
物品i费用有两项a[i],b[i]，效益p[i]
背包要满足两项要求
dp[j][k]：表示两项要求为j和k时背包最大（小）效益
**************************************************/
/*******************例*********************/
/*
OJ: HDOJ
ID: forever
TASK: 2159.FATE
LANG: C++
NOTE: Two-Dimensional Pack
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n, m , k, s;
    int dp[101][101];
    while( scanf( "%d%d%d%d", &n, &m, &k, &s ) != EOF ) {
        int a[101], b[101];
        for( int i = 0; i < k; i ++ )
            scanf( "%d%d", &a[i], &b[i] );
        for( int i = 0; i < 101; i ++ )
            for( int j = 0; j < 101; j ++ )
                dp[i][j] = 0;

        for( int i = 0; i < k; i ++ ) {
            for( int j = b[i]; j <= m; j ++ )
                for( int p = 1; p <= s; p ++ )
                    if( dp[j][p] < dp[j - b[i]][p - 1] + a[i] )
                        dp[j][p] = dp[j - b[i]][p - 1] + a[i];
        }
        int flag = 1000000;
        for( int i = 0; i <= m; i ++ )
            for( int j = 0; j <= s; j ++ )
                if( dp[i][j] >= n ) {
                    flag = min( i, flag );
                }
        if(flag != 1000000)
            printf( "%d\n", m - flag );
        else puts( "-1" );
    }
    return 0;
}
/******************例完*********************/
