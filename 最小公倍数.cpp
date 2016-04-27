//gcd求最小公倍数lcm
void lcm( int a, int b ) {
    return ( a / gcd( a, b ) * b );
}
void gcd( int a, int b ) {
    return ( ( b == 0 ) ? a : gcd( b, a % b ) );
}
