#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#define eps 1e-8
#define INF 1e50
#define MAXN 1001
#define Pi acos(-1.0)
#define sign(x) (x>eps?1:(x<-eps?-1:0))
using namespace std;

struct point {
	double x, y;
	point() {};
	point( double _x, double _y ) {
		x = _x;
		y = _y;
	}
	point operator - ( const point& ne ) const {
		return point( x - ne.x, y - ne.y );
	}
	point operator + ( const point& ne ) const {
		return point( x + ne.x, y + ne.y );
	}
	point operator * ( const double t ) const {
		return point( x * t, y * t );
	}
	point operator / ( const double t ) const {
		if( sign(t) == 0) exit(1);
		return point( x / t, y / t );
	}
	//叉积
    double operator ^ ( const point& b ) const {
        return x*b.y - y*b.x;
    }
};
//直线或线段
struct line {
	point a, b;
	line() {};
	line( point _a, point _b ) {
		a = _a;
		b = _b;
	}
	//两直线相交求交点
    //第一个值为0表示直线重合，为1表示平行，为0表示相交,为2是相交
    //只有第一个值为2时，交点才有意义
    pair<int,point> operator & (const line& p)const
    {
        point res = a;
        double x = (a-b) ^ (p.a-p.b);
        if(sign(x) == 0)
        {
            x = (a-p.b)^(p.a-p.b);
            if(sign(x) == 0)
                return make_pair(0,res);//重合
            else return make_pair(1,res);//平行
        }
        double t = ((a-p.a)^(p.a-p.b))/((a-b)^(p.a-p.b));
        res.x += (b.x-a.x)*t;
        res.y += (b.y-a.y)*t;
        return make_pair(2,res);
    }
    /**************调用************
    pair<int, point> pr;
    point p = pr.second;
    ************交点为p***********/
};
//圆
struct circle {
	point o;
	double r;
	circle() {}
	circle( point _o, double _r ) {
		o = _o;
		r = _r;
	}
};
//矩形
struct rectangle {
	point a, b, c, d;
	rectangle(){}
	rectangle( point _a,point _b,point _c,point _d) {
		a = _a;
		b = _b;
		c = _c;
		d = _d;
	}
};
//多边形
struct polygon {
	point p[MAXN];
	int num;
};
//叉积
inline double xmult( point a, point b ) {
	return a.x * b.y - a.y * b.x;
}
inline double xmult( point o, point a, point b ) {
	return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}
inline double xmult( double x1,double y1,double x2,double y2 ) {
	return x1 * y2 - x2 * y1;
}
//点积
inline double dmult( point o, point a, point b ) {
	return (a.x-o.x)*(b.x-o.x)+(a.y-o.y)*(b.y-o.y);
}
inline double dmult( point a, point b ) {
	return a.x * b.x + a.y * b.y;
}
//向量长度
inline double length( point a ) {
	return sqrt( dmult( a , a ) );
}
//两点距离
inline double dist( point a, point b ) {
	return length( b - a );
}
//返回两圆相交面积
double insection_of_circles(circle a, circle b) {
    double d = dist( a.o, b.o );
    if( d >= a.r + b.r )
        return 0;
    if( d <= fabs( a.r - b.r ) ) {
        double r = a.r < b.r ? a.r : b.r;
        return Pi * r * r;
    }
    double ang1 = acos((a.r * a.r + d * d - b.r * b.r) / 2. / a.r / d);
    double ang2 = acos((b.r * b.r + d * d - a.r * a.r) / 2. / b.r / d);
    double ret = ang1 * a.r * a.r + ang2 * b.r * b.r - d * a.r * sin(ang1);
    return ret;
}
//线段判交
inline int seg_inter(line s,line p) {
	double minx1=min(s.a.x,s.b.x),maxx1=max(s.a.x,s.b.x);
	double minx2=min(p.a.x,p.b.x),maxx2=max(p.a.x,p.b.x);
	double miny1=min(s.a.y,s.b.y),maxy1=max(s.a.y,s.b.y);
	double miny2=min(p.a.y,p.b.y),maxy2=max(p.a.y,p.b.y);
	if((minx1>maxx2+eps)||(minx2>maxx1+eps)||
		(miny1>maxy2+eps)||(miny2>maxy1+eps))
		return 0;
	else
		return sign(xmult(s.a,s.b,p.a)*xmult(s.a,s.b,p.b))<=0 &&
                sign(xmult(p.a,p.b,s.a)*xmult(p.a,p.b,s.b))<=0 ;
}
inline double getarea( point pg[], int n) {
    double area = 0;
    pg[n] = pg[0];
    for( int i = 1; i < n; i ++ )
        area += xmult( pg[0], pg[i], pg[i+1] );
    return fabs(area)/2.0;
}

int main()
{
	cout << eps << endl;
	cout << INF << endl;
	cout << Pi << endl;
	return 0;
}
