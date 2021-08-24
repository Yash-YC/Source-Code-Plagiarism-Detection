#include <iostream>
using namespace std;
int f[11][1000];
bool fun(int x, int b)
{
	int y=0;
	while(x % b == 0) x /= b;
	if(x < 1000)
	{
		if(f[b][x] == 1) return true;
		if(f[b][x] == -1) return false;
	//cout << x << " " << b << endl;
		f[b][x] = -1;
	}
	int u = x;
	while(x >= b)
	{
		y+=(x%b)*(x%b);
		x /= b;
	}
	y += x*x;
	if(fun(y,b))
	{
		if(u  < 1000) f[b][u] = 1;
		return true;
	}
	else return false;
}
int main()
{
	int t;
	cin >> t;
	FILE *fout = fopen("a_l.out", "w");
	for(int i=0; i<11; i++) for(int j=0; j<1000; j++) f[i][j] = 0;
	for(int i=0; i<11; i++) f[i][1] = 1;
	for(int c=1;c<=t; c++)
	{
		char s[50];
		int a[15];
		if(c==1) cin.getline(s,5);
		cin.getline(s,50);
//		cout << s << endl;
		int q=0;
		for(int p=0; s[p]>0;)
		{
			sscanf(s+p,"%d",&a[q]);
//			cout << a[q] << endl;
			if(a[q] == 10) p++;
			if(!(a[q] == 2 || a[q] == 4)) q++;
			p++;
			if(s[p] == 0) break;
			p++;
		}
		for(int i=2;;i++)
		{
			int j = 0;
			for(j=0; j<q; j++) if(!fun(i,a[j]))
			{
				//cout << i << " " << a[j] << endl;
				break;
			}
			if(j == q)
			{
				fprintf(fout, "Case #%d: %d\n",c,i);
				cout << ".";
				//cout << "Case #" << c << ": " << i << endl;
				break;
			}
		}
	}
	fclose(fout);
	return 0;
}
