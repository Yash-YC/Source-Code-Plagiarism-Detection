#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

double arr[1024];
double ps[1024][1024];
double asd[100][64][64];

int main()
{
	int t;cin>>t;
	for(int a=0; a<t; ++a) {
		int C,N;
		cin>>C>>N;
		arr[0]=0;
		memset(asd, 0, sizeof(asd));
		for(int i=0; i<=N; ++i) asd[0][i][0] = 1;
		for(int i=1; i<=C; ++i) {
			asd[i][N][0] = 1;
			for(int j=1; j<=N; ++j) asd[i][N][j] = 0;
			for(int j=N-1; j>=0; --j) {
				for(int k=0; k<=N; ++k) {
					double p = double(i)/(C-j);
					asd[i][j][k] = p*asd[i-1][j+1][k-1] + (1-p)*asd[i][j+1][k];
				}
			}
			for(int j=0; j<=N; ++j) ps[i][j] = asd[i][0][j];
			double e=0;
//			printf("ps %d 0: %f\n", i, ps[i][0]);
			for(int j=1; j<=N; ++j) {
//				printf("ps: %d %d: %f\n", i, j, ps[i][j]);
				if (j>i) break;
//				e += ps[i][j]*arr[i-j];
				e += ps[i][j]*(1+arr[i-j]);
			}
			double x=ps[i][0];
//			printf("e0 %d: %f\n", i, e);
//			e = ((1-x)*(1+e) + x)/(1-x);
//			e = 1+e + x/(1-x);
			e = (e + x)/(1-x);
//			printf("e1 %d: %f\n", i, e);
			arr[i] = e;
		}
//		cout<<"Case #"<<a+1<<": "<<arr[C]<<'\n';
		printf("Case #%d: %.10f\n", a+1, arr[C]);
	}
}
