#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


vector<int> bases;
int hn[11][10001];


vector<int> convert(int num, int base)
{
	vector<int> re;
	while(num>0) {
		int mod = num%base;
		re.push_back(mod);
		num = num/base;
	}
	reverse(re.begin(), re.end());
	return re;	
}

int getssum( vector<int>& v )
{
	int re=0;
	for( int i=0; i<v.size(); i++ ) {
		re += (v[i]*v[i]);
	}
	return re;
}

bool ishappy( int nownum, int base ) 
{
	set<int> visited;
	while(true) {
		vector<int> num = convert(nownum, base);
		int sum = getssum(num);
		if( sum==1 ) { 
			return true;
		}

		if( visited.find(sum) != visited.end() ) {
			return false;
		}
		else {
			visited.insert(sum);
		}

		nownum = sum;	
		
	}
}

void process()
{
	int nownum = 2;
	while( true )
	{
		int happy =0;
		for( int i=0; i<bases.size(); i++ ) {
			if(ishappy(nownum, bases[i]) == true ) {
				happy++;
			}
		}
		if( happy == (int)bases.size() ) {
			cout<<nownum<<endl;
			break;
		}
		nownum++;
	}
}
int main()
{
	int T;
	freopen("A-small-attempt1.in", "rt", stdin);



	freopen("a.txt", "wt", stdout);
	cin>>T;
	char ins[1000];
	string s;
	int base;
	cin.getline(ins,1000);

	for(int i=0; i<T; i++ ) {
		bases.clear();
		cin.getline(ins,1000);
		s = ins;
		istringstream iss(ins);
		while(iss.eof()==false) {
			iss>>base;
			bases.push_back(base);
		
		}

		cout<<"Case #"<<i+1<<": ";
		process();

	}
	return 0;
}