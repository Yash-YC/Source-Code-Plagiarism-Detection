#include <iostream>
using namespace std;

double calc( int C, int N ) {
	if( C == N ) return 1.0;
	const int numIter = int(1e5);
	int freq[11];
	int total = 0;
	int bucket[11];
	for(int i=0;i<C;++i) bucket[i] = i;
	for(int i=0;i<numIter;++i) {
		memset( freq, 0, sizeof freq );
		int cnt = 0;
		int j;
		while(++cnt) {
			random_shuffle( bucket, bucket + C );
			for(j=0;j<N;++j) freq[ bucket[j] ]++;
			for(j=0;j<C;++j) if( freq[j] == 0 ) break;
			if(j==C) break;
		}
		total += cnt;
	}
	return double(total) / numIter;
}

int main() {
	srand(time(NULL));
	int tn;
	cin >> tn;
	int N, C;
	for(int cc=1;cc<=tn;++cc) {
		cin >> C >> N;
		double ret = calc( C, N );
		printf("Case #%d: %.6lf\n", cc, ret);
	}

}

