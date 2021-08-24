#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<vector>

using namespace std;


int n,m;

long d[40][40];

long s[20][20],w[20][20],t[20][20];

int dx []  = {0,1,0,-1};
int dy []  = {1,0,-1,0};


long cross(long start, long s,long w,long t)
{
//	cout<< start << " " << s << ' ' << w << ' ' << t<<endl;
	long len = s + w;
	t = (( start - t ) / len -2) * len + t;

	long min = -1;

	while (t<=start + len)
	{
		if (t + s > start)
		{
			long m = start;
			if (t > m) m = t;
			if (min == -1 || m < min) min = m;
		}
	//	cout<<t <<  ' ' << min <<endl;
		t+=len;
	}
	return min;
}

int main()
{
	string line;
	 int c;
	 cin>>c;

	 for (int cc = 1;cc<=c;cc++)
	 {
		 cin >> n >>m ;
		 for (int i = 0;i<n;i++)
			 for (int j = 0;j<m;j++)
			 {
				 int ii = n - 1 - i;
				 cin >> s[ii][j] >> w[ii][j] >> t[ii][j];
			 }
		 for (int i = 0;i<n*2;i++)
			 for (int j = 0;j<m*2;j++) d[i][j] = -1;
		 d[0][0] = 0;

		 for(;;)
		 {
			 bool update = false;

		 for (int i = 0;i<n*2;i++)
			 for (int j = 0;j<m*2;j++) if (d[i][j] != -1)
			 {
				 for (int u = 0;u<4;u++) {
					 int x = i + dx[u]; int y = j + dy[u];
					 if (x>=0 && x<n*2 && y>=0 && y<m*2)
					 {
						 bool samerow = (x/2 == i /2);
						 bool samecol = (y/2 == j /2);
						 long d0 = 0;
						 if (samerow  && samecol) 
						 {
								 int ii = x /2, jj = y /2;
							 if (x == i)// west cross
							 {
								 d0 = cross(d[i][j],w[ii][jj],s[ii][jj],t[ii][jj]+s[ii][jj]  )+1;
							 }
							 else //north cross
							 {
 								 d0 = cross(d[i][j],s[ii][jj],w[ii][jj],t[ii][jj])+1;
							 }
						 }
						 else if (samerow) d0 = d[i][j] + 2;
						 else if (samecol) d0 = d[i][j] + 2;


						 if (d[x][y] == -1 || d0 < d[x][y])
						 {
							 d[x][y] = d0;
							 update = true;
						 }
					 }
				 }
			 }

		 if (!update) break;
		 }
		 if (false)
		 for (int i = 0;i<n*2;i++)
		 {
			 for (int j = 0;j<m*2;j++)
				 cout<< " " << d[i][j];
			 cout<<endl;
		 }
		 int ans = d[n*2-1][m*2-1];
		 printf("Case #%d: %d\n", cc, ans);
	 }
//	 cout<<cross(6,5,1,3)<<endl;
}
