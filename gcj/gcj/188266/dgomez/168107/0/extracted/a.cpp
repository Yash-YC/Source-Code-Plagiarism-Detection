# include <iostream>
# include <cstring>
# include <string>
using namespace std;

string toBase(int i, int base)
{
	string str="";
	while(i>0) {
		str.insert(str.begin(), '0'+(i%base));
		i/=base;
	}
	return str;
}

bool proceso(int n, int *w, int m)
{
	int i, res, p, j, temp;
	bool v[100000];
	string str;
	for (i=0; i<m; i++) {
		memset(v, 0, sizeof v);
		v[n]=true;
		str=toBase(n, w[i]);
		res=n;
		while (str.compare("1")) {
			p=str.size();
			res=0;
			for (j=0; j<p; j++) {
				res+=(str[j]-'0')*(str[j]-'0');
			}
			if (!v[res]) {
				v[res]=true;
			}
			else {
				return false;
			}
			str=toBase(res, w[i]);
		}
	}
	return true;
}

int main()
{
	int t, w[1000], tt=1, i, n, m, p;
	char c[1000];
	scanf("%d", &t);
	gets(c);
	while(t--) {
		m=0;
		gets(c);
		n=strlen(c);
		for (i=0; i<n; i++) {
			p=0;
			while(isdigit(c[i])) {
				p=p*10+c[i]-'0';
				i++;
			}
			w[m++]=p;
		}
		for (i=2; i<100000; i++) {
			if (proceso(i, w, m)) {
				printf("Case #%d: %d\n", tt++, i);
				break;
			}
		}
	}
	return 0;
}
