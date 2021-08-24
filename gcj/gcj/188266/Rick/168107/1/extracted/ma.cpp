#include<iostream>
#include<string>
#include<sstream>

#include<vector>

using namespace std;

const int M = 1000000;

int cache[M][10];

int getcode(int n, int b)
{
	int sum = 0;

	while (n > 0)
	{
		sum += (n%b)*(n%b);
		n/=b;
	}
	return sum;
}

int mark(int x, int b)
{
	if (x>=M) cout<<"wrong"<<endl;
	if (x==1) return 1;
	if (cache[x][b] >=0) return cache[x][b];

	if (cache[x][b] == -2) return cache[x][b] = 0;
	cache[x][b] = -2;

	int y = getcode(x,b);
	return cache[x][b] = mark(y,b);
}

int main()
{
	string line;
	 int c;
	 cin>>c;
	 getline(cin,line);

	 for (int i = 0;i<M;i++)
		 for (int j = 0;j<10;j++) cache[i][j]=-1; //undiscovered;
	 for (int cc = 1;cc<=c;cc++)
	 {
		 getline(cin , line);

		 istringstream istr(line);

		 vector<int> base;
		 for(;;) { int b; if (istr >>b) base.push_back(b); else break; }
		// for (int i = 0;i<base.size();i++) cout<<base[i]<<endl;
			 int ans= 0 ;
			 for(ans = 2;;ans++)
			 {
				bool flag = true;

				for (int i = 0;i<base.size();i++)
				{
					int b = base[i];
					int x = ans;
					int t = getcode(x, b);
					if (mark(t,b) == 0) {flag = false; break;};
				}
				if (flag) break;
			 }
		 printf("Case #%d: %d\n", cc, ans);
	 }
}
