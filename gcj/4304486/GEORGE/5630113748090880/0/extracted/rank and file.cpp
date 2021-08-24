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
	
	
	freopen("B-small-attempt0.in","r", stdin);
	freopen("out","w",stdout);
	
	int cases;
	cin >> cases;
	for(int cas =1; cas <= cases; cas++){

// code starts here 
		int n, temp;
		cin >> n;
		set<vector<int>> s;
		vector<int> last;
		
		for(int i=0; i< (2*n-1); i++){
			vector<int> v;
			for(int j=0; j<n; j++){
				
				cin >> temp;
				v.push_back(temp);
			}	
			s.insert(v);
			last.push_back(v[n-1]);
		}
		
		set<int> m;
		for(auto &c: last)
			m.insert(c);
		
		vector<int> ans;
		
		for(auto &c:m){
			ans.push_back(c);
		}
		
		int sz = ans.size();
		vector<int> v;
		for(int i=0; i< (1<<sz); i++){
			for(int j=0; j< sz; j++){
				if( i & (1<<j))
					v.push_back(ans[j]);
			}
			
			if(v.size() != n) { v.clear(); continue;}
			else {
				sort(v.begin(), v.end());
				if(s.find(v) == s.end()){
					bool found = false;
					for(auto &c: s){
						if(c[0] == v[0] && c[n-1]== v[n-1])	{ found = true; break;}
					}
					if(found) break;
					else {v.clear(); continue;}
				}
			}
		}

		
		
// code ends here 

	
	 cerr << "test " << cas << " done" << endl;

	cout << "Case #"<< cas << ": ";
	for(int i=0; i<n; i++){
		cout << v[i];
		if(i!=n-1) cout << " ";
	}
	cout <<"\n";
	


	}

	return 0;
}