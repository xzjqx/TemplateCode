//������ȡģ
int multi( int a, int b, int mod )//���㷵��a^b
{
    int ret = 1;
    while( b > 0 ) {
        if( b & 1 ) ret = ( ret * a ) % mod;
        a = ( a * a ) % mod;
        b /= 2;
    }
    return ret;
}

/**************************************
            ���������
**************************************/
struct Mat {
    int mat[MAX][MAX];
};

Mat operator * ( Mat a, Mat b ) {//�����Զ���ṹ�ṹ��*����
    Mat ret;
    memset( ret.mat, 0, sizeof(ret.mat) );

    for( int i = 0; i < n; i ++ ) {
        for ( int j = 0; j < n; j ++ ) {
            for ( int k = 0; k < n; k ++ ) {
                ret.mat[j][k] += a.mat[j][i] * b.mat[i][k];
            }
        }
    }
    return ret;
}

Mat operator ^ ( Mat a, int b ) {//�����Զ������ṹ��^����
    Mat ret;
    for( int i = 0; i < n; i ++ )
        for( int j = 0; j < n; j ++ )
            ret.mat[i][j] = ( i == j );
    while( b > 0 ) {
        if ( b & 1 ) ret = ret * a;
        a = a * a;
        b /= 2;
    }
    return ret;
}
