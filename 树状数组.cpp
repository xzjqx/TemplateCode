//һά��״����
int n;//��ʼԪ�ظ���
//��ʼ��ʱ��ar[]��Ϊ0
int lowbit( int i ) {
    return i & ( -i );
}

void add(int i, int v) {
    for( ; i <= n; ar[i] += v, i += lowbit(i) );
}//��i���ֵ��v

int sum(int i) {
    int ret = 0;
    for( ; i > 0; ret += ar[i], i -= lowbit(i) );
    return ret;
}//��[1, i]�ĺ�

//��ά��״����
int n, m;
//��ʼ����ar[][]��Ϊ0
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

//��״����ʵ�ֵ����ѯ���������
/*************************************************
��ʱ��Ŀ�������޸ģ����ѯ
���ǿ��԰���ת��Ϊ���޸ģ������ѯ
����֪����a[]�������ֲ�����һ����ѯ��a[i]��ֵ����һ���ǽ�a[i]��a[j]��Ԫ�ض�����k
��������b[]��b[1]=a[1]��b[2]=a[2]-a[1]��
            b[3]=a[3]-a[2]��������b[i]=a[i]-a[i-1]
����b[1]+b[2]+����+b[i]=a[i]
�����ѯ����������ѯ
��Ҫ��a[i]��a[j]��Ԫ�ض�����k
��b[i]+=k��b[j+1]-=k���ͽ������޸�ת��Ϊ�˵��޸�
*************************************************/
/*
OJ: HDOJ
ID: forever
TASK: 1556.Color the ball
LANG: C++
NOTE: ��״����
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
