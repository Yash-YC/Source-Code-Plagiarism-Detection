#include <string>
#include <iostream>
using namespace std;
template <class T> void out(T A[], int n) {for (int i = 0; i<n; i++) cout << A[i] << ' '; cout << endl;}  

int ts, no;
int a[10000000][12];
int chk[12], i, j, f;
char ch;

char g() {
	while (1)
	{
		ch = getchar();
		if (ch != ' ')
		{
			return ch;
		}
	}
}

int ck(int n, int b) {
	if (a[n][b] == 1 || a[n][b] == 2)
	{
		return a[n][b] == 1;
	}
	if (n == 1)
	{
		return a[n][b] = 1;
	}
//	cout << a[n][b] << endl;
	if (a[n][b] == 4)
	{
		a[n][b] = 2; return 0;
	}
	a[n][b] = 4;
	int k = n, t = 0;
	while (k)
	{
		t += (k%b)*(k%b);
		k /= b;
	}
//	cout << t <<  ' ' << b << endl;
	a[n][b] = ck(t, b);
	return a[n][b] == 1;
}

main() {
	freopen("a0.in", "r", stdin);
	freopen("1.out", "w", stdout);

	cin >> ts;
	while ((ch = g()) != '\n') {}
	for (int no=0; no<ts; no++) {
		cout << "Case #" << no+1 << ": ";
		memset(chk, 0, sizeof(chk));
		while ((ch = g()) != '\n')
		{
			if (ch == '1')
			{
				ch = getchar();
				chk[10] = 1;
			} else 
				chk[ch-'0'] = 1;
		}
//		out(chk, 10);
		for (i=2; 1; i++)
		{
//			cout << i << endl;
			f = 1;
			for (j=2; j<=10; j++) if (chk[j])
			{
				if (!ck(i, j))
				{
					f = 0; break;
				}
			}
//			cout << f << endl;
			if (f)
			{
				cout << i << endl;
				break;
			}
		}
	}
}
