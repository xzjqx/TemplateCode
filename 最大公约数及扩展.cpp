//Euclidean算法求gcd
int gcd( int a, int b ) {
    return b == 0 ? a : gcd( b, a%b );
}

//扩展欧几里德算法
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
}//获取gcd(a,b)=ax+by中的x，y的值

/*******************************************
扩展欧几里得算法求乘法逆元
调用：exgcd( a, b, x, y );
则：  x为a模b的乘法逆元，y为b模a的乘法逆元
********************************************/

/*************例************/
/***********************
OJ: HDOJ
ID: forever
TASK: 1576.A/B
LANG: C++
NOTE: exgcd求乘法逆元
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
/************例完************/

/*******************************************

扩展欧几里得算法求解模线性方程
调用：exgcd( a, b, x, y );
则：  x为a模b的乘法逆元，y为b模a的乘法逆元
     d为gcd( a, n )，依次输出方程的解
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
