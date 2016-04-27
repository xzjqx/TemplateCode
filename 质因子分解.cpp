vector< pair<int,int> > v;

void get_pp( int n ) {
    v.clear();
	for( int i = 2; i * i <= n; i ++ ) {
		int cnt = 0;
		while( n % i == 0 ) {
			n /= i;
			cnt ++;
		}
		if( cnt != 0 ) {
			v.push_back(make_pair(i,cnt));
		}
	}
}
