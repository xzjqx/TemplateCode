//BFS
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 0x7fffffff
#define MAX 210
using namespace std;

int main()
{
    int n, m;
    int sx, sy, ex, ey;
    char str[MAX][MAX];
    int length[MAX][MAX];
    int fx[] = { 0, 0, -1, 1 };
    int fy[] = { 1, -1, 0, 0 };
    while( scanf( "%d%d", &n, &m ) != EOF ) {
        for( int i = 0; i < n; i ++ ) {
            scanf( "%s", str[i] );
            for( int j = 0; j < m; j ++ ) {
                length[i][j] = INF;
                if( str[i][j] == 'r' )
                    sx = i, sy = j;
                if( str[i][j] == 'a' )
                    ex = i, ey = j;
            }
        }

        length[sx][sy] = 0;
        queue< pair< int, int > > q;
        q.push( make_pair( sx, sy ) );
        while( !q.empty() ) {
            pair< int, int > p;
            p = q.front();
            q.pop();

            for( int i = 0; i < 4; i ++ ) {
                int x = p.first;
                int y = p.second;
                int px = x + fx[i];
                int py = y + fy[i];

                if( px >= 0 && px < n && py >= 0 && py < m
                   && str[px][py] != '#' ) {
                    int dis = length[x][y] + 1;
                    if( str[px][py] == 'x' )
                        dis ++;
                    if( dis < length[px][py] ) {
                        length[px][py] = dis;
                        q.push( make_pair( px, py ) );
                    }
                }
            }
        }

        if( length[ex][ey] < INF )
            printf( "%d\n", length[ex][ey] );
        else
            printf("Poor ANGEL has to stay in the prison all his life.\n");
    }
    return 0;
}
