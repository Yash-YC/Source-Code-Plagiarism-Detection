#include <iostream>
#include <sstream>

using namespace std;

int prox(int n, int b)
{
	int sqrs = 0;
	while(n > 0)
	{
		sqrs += (n%b)*(n%b);
		n/=b;
	}
	return sqrs;
}

bool feliz(int n, int b)
{
	int a = n;
	int c = prox(n, b);
	while(a != c)
	{
		if(a == 1 || c == 1)
			return true;
		a = prox(a,b);
		c = prox(prox(c, b), b);
	}
	return false;
}

int main()
{
	int T;
	string buf;
	stringstream ss;
	getline(cin, buf);
	ss << buf;
	ss >> T;
	for(int t = 1; t <= T; t++)
	{
		int b, nb, resp, base[16];
		bool achou = false;
		getline(cin, buf);
		ss.clear();
		ss << buf;
		for(nb = 0; ss >> b; nb++)
			base[nb] = b;
		for(resp = 2; !achou; resp++)
		{
			achou = true;
			for(int j = 0; j < nb && achou; j++)
				if(!feliz(resp, base[j]))
					achou = false;
		}
		cout << "Case #" << t <<": " <<  resp-1 << endl;
	}
}
