#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <set>
#include <algorithm>
#include <list>
#include <queue>

using namespace std;

string next(string str,int base)
{
	int n = 0;
	for(int i = 0; i < str.length(); i++) {
		n += (str[i]-'0')*(str[i]-'0');
	}
	// cout << "debug" << n << " " << base << endl;
	string res = "";
	while(n) {
		res += (char)(n%base + '0');
		n = n/base;
	}
	reverse( res.begin(), res.end() );
	return res;
}

bool yeah(string str, int base)
{
	if( base == 2 ) return true;

	set <string> strs;
	strs.insert( str );
	string nextstr = str;
	while( true ) {
		nextstr = next( nextstr, base );
		// cout << "debug " << nextstr << endl;
		if( strs.count( nextstr ) != 0 ) return false;
		else {
			if( nextstr == "1" ) return true;
			strs.insert( nextstr );
		}
	}
}

void solve()
{
	vector <int> vec;

	string buffer;
	getline(cin, buffer);

	while( buffer.find(" ") != string::npos ) {
		int i = buffer.find(" ");
		vec.push_back( atoi(buffer.substr(0,i).c_str()) );
		buffer = buffer.substr(i+1);
	}
	vec.push_back( atoi(buffer.c_str()) );

	/*for(int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";		
	}
	cout << endl;*/

	bool f = true;
	int n;
	for(int i = 2; ; i++) {
		f = true;
		for(int j = 0; j < vec.size(); j++) {
			string str = "";
			n = i;
			while(n) {
				str += (char)(n%vec[j] + '0');
				n = n/vec[j];
			}
			reverse( str.begin(), str.end() );
			//cout << "start" << str << endl;
			if( !yeah(str,vec[j]) ) {
				f = false;
				break;
			}
		}
		//cout << "start" << i << endl;
		if( f ) {
			cout << i;
			break;
		}
	}
}

int main()
{
	int T;
	vector <int> vec;

	string buffer;
	getline(cin, buffer);
	T = atoi(buffer.c_str());
	for(int i = 0; i < T; i++) {
		cout << "Case #" << i+1 << ": ";
        solve();
        cout << endl;
	}
    return 0;
}
