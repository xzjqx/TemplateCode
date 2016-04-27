#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 100001;
int tree[20][N];
int sum[20][N];
int as[N];

void build( int p, int l, int r )
{
    int mid = ( ( l + r ) >> 1 );
    int lm = 0, ls = l, rs = mid + 1;
    for ( int i = mid; i >= l; i-- )
    {
        if ( as[i] == as[mid] )
            lm++;
        else
            break;
    }
    for ( int i = l; i <= r; i++ )
    {
        if ( i == l )
            sum[p][i] = 0;
        else
            sum[p][i] = sum[p][i - 1];
        if ( tree[p][i] == as[mid] )
        {
            if ( lm )
            {
                lm--;
                sum[p][i]++;
                tree[p + 1][ls++] = tree[p][i];
            }
            else
            {
                tree[p + 1][rs++] = tree[p][i];
            }
        }
        else if ( tree[p][i] < as[mid] )
        {
            sum[p][i]++;
            tree[p + 1][ls++] = tree[p][i];
        }
        else
        {
            tree[p + 1][rs++] = tree[p][i];
        }
    }
    if ( l == r )
        return ;
    build( p + 1, l, mid );
    build( p + 1, mid + 1, r );
}

int query( int p, int l, int r, int ql, int qr, int k )
{
    if ( l == r )
        return tree[p][l];
    int mid = ( ( l + r ) >> 1 );
    int s, ss;
    if ( ql == l )
        s = 0, ss = sum[p][qr];
    else
        s = sum[p][ql - 1], ss = sum[p][qr] - s;
    if ( k <= ss )
        return query( p + 1, l, mid, l + s, l + sum[p][qr] - 1, k );
    else
        return query( p + 1, mid + 1, r, mid + 1 - l + ql - s, mid + 1 - l + qr - sum[p][qr], k - ss );
}

int main ()
{
    int n, m;
    while ( scanf("%d%d", &n, &m) != EOF )
    {
        for ( int i = 1; i <= n; i++ )
        {
            scanf("%d", as + i);
            tree[0][i] = as[i];
        }
        sort( as + 1, as + 1 + n );
        build( 0, 1, n );
        while ( m-- )
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            printf("%d\n", query( 0, 1, n, a, b, c ));
        }
    }
    return 0;
}
