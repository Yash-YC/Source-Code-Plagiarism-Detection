//nirmalgeo25 template
#include<bits/stdc++.h>
#define inf (long long)1e18
using namespace std;

int xarr[] = {-1,0,1,1,1,0,-1,-1};
int yarr[] = {-1,-1,-1,0,1,1,1,0};
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	
	freopen("A-large.in","r", stdin);
	freopen("out","w",stdout);
	
	int cases;
	cin >> cases;
	for(int cas =1; cas <= cases; cas++){
	
// code starts here 
		
		string s;
		cin >> s;
		string ans = "";
		ans = s[0];
		
		int n = s.length();
		for(int i=1; i<n; i++)
		{
			if( (ans+ s[i]) > (s[i] + ans))
				ans = ans + s[i];
			else
				ans = s[i] + ans;		
		}
		
		
	
// code ends here 

	
	 cerr << "test " << cas << " done" << endl;

	cout << "Case #"<< cas << ": "<< ans <<"\n";


	}

	return 0;
}