//Euclidean�㷨��gcd
int gcd( int a, int b ) {
    return b == 0 ? a : gcd( b, a%b );
}

//��չŷ������㷨
int exgcd( int a, int b, int& x, int& y ) {
    if( b == 0 ) {
        x = 1;
        y = 0;
        return a;
    }
    int ret = exgcd( b, a % b, x, y );
    int tmp = x;
    x = y;
    y = tmp - a / b * y;
    //y = ( ( tmp - a / b * y ) % mod + mod ) % mod;
    return ret;
}//��ȡgcd(a,b)=ax+by�е�x��y��ֵ

/*******************************************
��չŷ������㷨��˷���Ԫ
���ã�exgcd( a, b, x, y );
��  xΪaģb�ĳ˷���Ԫ��yΪbģa�ĳ˷���Ԫ
********************************************/

/*************��************/
/***********************
OJ: HDOJ
ID: forever
TASK: 1576.A/B
LANG: C++
NOTE: exgcd��˷���Ԫ
***********************/
#include <cstdio>
#define mod 9973

int exgcd( int a, int b, int& x, int& y ) {
    if( b == 0 ) {
        x = 1;
        y = 0;
        return a;
    }
    int ret = exgcd( b, a % b, x, y );
    int tmp = x % mod;
    x = y % mod;
    y = ( ( tmp - a / b * y ) % mod + mod ) % mod;
    return ret;
}

int main()
{
    int t, n, b;
    scanf( "%d", &t );
    while( t -- ) {
        scanf( "%d%d", &n, &b );
        int x, y;
        x = y = 0;
        int ret = exgcd( b, mod, x, y );
        printf( "%d\n", ( x * n ) % mod );
    }
}
/************����************/

/*******************************************

��չŷ������㷨���ģ���Է���
���ã�exgcd( a, b, x, y );
��  xΪaģb�ĳ˷���Ԫ��yΪbģa�ĳ˷���Ԫ
     dΪgcd( a, n )������������̵Ľ�
********************************************/
int Modular_Linear( int a, int b, int n ) {
	int d, x, y, x0;
	d = exgcd( a, n, x, y );
	if( b % d == 0 ) {
		x0 = ( x * ( b/d ) ) % n;
		if( x0 < n ) 
			x0 +=n;
	}
	for( int i = 0; i < d; i ++ )
		cout << ( x0 + i * n /d ) % n << endl;
}
