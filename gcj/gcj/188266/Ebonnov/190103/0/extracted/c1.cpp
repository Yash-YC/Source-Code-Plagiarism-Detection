#include <iostream>
using namespace std;
double cmn[50][50];
void getcmn()
{
	for(int i=1;i<=40;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(j > i-j) cmn[i][j] = cmn[i][i-j];
			else if(j == 0) cmn[i][j] = 1.00;
			else
//			for(int k=0; k<j; k++)
//			{
				cmn[i][j] = cmn[i][j-1] * (double)(i-j+1)/double(j);
//			}
		}
	}
}
double f[50];
int main()
{
	int t,tc;
	getcmn();
	cin >> t;
	for(tc = 1; tc <= t; tc++)
	{
		int c,n;
		cin >> c >> n;
		f[c] = 0.00;
		for(int i=c-1; i>=n; i--)
		{
			f[i] = 0.00;
			for(int j=1; i+j<=c&&j<=n; j++) f[i] += f[i+j]*cmn[i][n-j]*cmn[c-i][j];
			f[i] += cmn[c][n];
			f[i] /= (cmn[c][n]-cmn[i][n]);
			//cout << i << " " << f[i] << endl;
		}
		cout << "Case #" << tc << ": ";
		printf("%.7lf\n",f[n]+1.00);
	}
	return 0;
}
