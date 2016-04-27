#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

/*********************************
          0-1��������
n����Ʒ��
��Ʒi��w[i]��Ч��p[i]����������c
dp[j]����ʾ����Ϊjʱ�������Ч��
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
             ��ȫ��������
n����Ʒ��
��i����Ʒ����w[i]��Ч��p[i]����������c
dp[j]����ʾ����Ϊjʱ�������Ч��ֵ
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
             ���ر�������
n����Ʒ��
��i����Ʒ��n[i]������w[i]Ч��p[i]������c
dp[j]����ʾ����Ϊjʱ��������Ч��
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
/*****************��*******************/
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
/******************����*********************/

/*******************************************
        0-1����ǡ��װ��ʱ����С����
n����Ʒ��
��Ʒi��w[i]��Ч��p[i]����������c
dp[j]����ʾ����Ϊjʱ������СЧ��
********************************************/
void ZeroOnePack_zuixiaoshouyi() {
    for( int i = 0; i < 10001; i ++ )
        dp[i] = INF;//��ʼ��Ϊ���ֵ
    dp[0]=0;//����Ϊ0ʱ����ǡ��װ��������Ϊ0
    for( int i = 0; i < n; i ++ ) {
        for( int j = f- e; j >= w[i]; j -- ) {
            if( dp[j - w[i]] < INF && dp[j - w[i]] + p[i] < dp[j] )
                dp[j] = dp[j - w[i]] + p[i];
        }
    }
    if( dp[f - e] != INF )
        //�����ǡ��װ����dp[f - e]Ϊ��С����
    else
        //����ǡ��װ��
}
/*******************��*********************/
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
/******************����*********************/

/*************************************************
            ��ά���õı�������
n����Ʒ��
��Ʒi����������a[i],b[i]��Ч��p[i]
����Ҫ��������Ҫ��
dp[j][k]����ʾ����Ҫ��Ϊj��kʱ�������С��Ч��
**************************************************/
/*******************��*********************/
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
/******************����*********************/
