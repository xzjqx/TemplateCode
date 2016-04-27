//ֱ�����ŷ������
int euler( int n ){ //����euler(n)
     int res = n, a = n;
     for( int i = 2; i * i <= a; i ++ ) {
         if( a % i == 0 ){
             res = res / i * ( i - 1 );//�Ƚ��г�����Ϊ�˷�ֹ�м����ݵ����
             while( a % i == 0 )
                a /= i;
         }
     }
     if( a > 1 )
        res = res / a * ( a - 1 );
     return res;
}

//ɸѡ����ŷ��������
#define Max 1000001
int euler[Max];
void Init(){
     euler[1] = 1;
     for( int i = 2; i < Max; i ++ )
       euler[i] = i;
     for( int i = 2; i < Max; i ++ )
        if( euler[i] == i )
           for( int j = i; j < Max; j += i )
              euler[j] = euler[j] / i * ( i - 1 );//�Ƚ��г�����Ϊ�˷�ֹ�м����ݵ����
}
