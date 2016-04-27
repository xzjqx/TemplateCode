//�����ж�
bool is_prime( int u ) {
    if( u == 0 || u == 1 ) return false;
    if( u == 2 ) return true;
    if( u % 2 == 0 ) return false;
    for ( int i = 3; i * i <= u; i ++ )
        if ( u % i == 0 ) return false;
    return true;
}

//����ɸ��һ
vector<int> p;//�����������洢��������
const int MAX = 10000;//Ҫɸѡ���������Χ
void prime1() {
    p.push_back(2);
    for( int i = 3; i <= MAX ; i ++) {
        bool flag = true;
        for ( int j = 0; j < p.size() && p[j] * p[j] <= i; j ++ ) {
            if( i % p[j] == 0) {
                flag = false;
                break;
            }

        }
        if( flag )
            p.push_back(i);
    }
}

//����ɸ����
const int MAX = 10000;//Ҫɸѡ���������Χ
bool isPrime[MAX+1];//Ϊtrueʱ������
void prime2() {
    memset( isPrime, true, sizeof(isPrime) );
    isPrime[0] = isPrime[1] = false;
    for( int i = 2; i <= MAX; i ++ )
        if( isPrime[i] ) {
            for( int j = 2 * i; j <= MAX; j += i )
                isPrime[j] = false;
        }
}
