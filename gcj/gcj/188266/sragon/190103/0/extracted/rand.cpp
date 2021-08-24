#include<iostream>
using namespace std;

int		main(){
		//freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
		int n,c,t, T;
		for(cin>>T,t=1; t<=T; t++)
		{
			cin>>c>>n;
			if (n==c) printf("Case #%d: %.7lf\n",t, 1.0);
			else printf("Case #%d: %.7lf\n", t, double(c*c-n*n)/n);
		}
		return 0;
}