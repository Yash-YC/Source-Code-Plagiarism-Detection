// codejam.cpp : Defines the entry point for the console application.
//
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <fstream>
#include <numeric>
#define _USE_MATH_DEFINES 
#include <cmath>
#include <math.h>
using namespace std;

#define sz(v) ((int)(v).size())
#define F(i,a,b) for(int i=(a);i<(b);++i)
#define FSZ(i,a,v) F(i,a,sz(v))
#define all(v) v.begin(),v.end()

// sort Dic
// 24^15 = 
// 5000*15*15*500 

// 24*15 = square by test word
// insert Dic


void A() {
	//	cout << 'z'-'a'+1 << endl;

	int L, D, N;
	cin >> L >> D >> N;

	vector<string> dic;
	for(int t=0; t<D; ++t) {
		string s;
		cin >> s;
		dic.push_back(s);
	}

	for(int t=0; t<N; ++t) {
		string s;
		cin >> s;
		bool flag = false;
		int pos = 0;
		vector<vector<int> > letter_map(26, vector<int>(L, 0));
		FSZ(i,0,s) {
			if(s[i] == '(') {
				flag = true;
			} else if(s[i] == ')') {
				flag = false;
				++pos;
			} else {
				if(flag) {
					letter_map[s[i]-'a'][pos] = 1;
				} else {
					letter_map[s[i]-'a'][pos] = 1;
					++pos;
				}
			}
		}

		int cnt(0);
		FSZ(i,0,dic) {
			bool b = true;
			FSZ(j,0,dic[i]) {
				char c = dic[i][j];
				if(letter_map[c-'a'][j] != 1) {
					b = false;
					break;
				}
			}
			if(b) ++cnt;
		}

		cout << "Case #" << (t+1) << ": " << cnt << endl;
	}
}

// (count)*14 / 10000
// 앞 포지션으로 이어지는 애들은 모두 더해주기
// 다시 시작되는 걸 조심해야 함
void C() {
	int N;
	cin >> N;
	string welcome = "welcome to code jam";
	string str;
	getline(std::cin, str);
	for(int t=0; t<N; ++t) {
		getline(std::cin, str);
		vector<vector<int> > v(str.size(), vector<int>(welcome.size(), 0));
		FSZ(i,0,str) {
			if(str[i] == 'w') v[i][0] = 1;
		}
		FSZ(i, 1, welcome) {
			FSZ(j,0,str) {
				if(welcome[i] == str[j]) {
					int sum(0);
					for(int k=0; k<j; ++k) {
						sum = (sum + v[k][i-1]) % 10000;
					}
					v[j][i] = sum;
				}
			}
		}
		int cnt(0);
		FSZ(i,0,v) {
			cnt = (cnt + v[i][welcome.size()-1]) % 10000;
		}
		char buf[512];
		itoa(cnt, buf, 10);
		int padding = 4-strlen(buf);
		string rr;
		for(int i=0; i<padding; ++i) {
			rr += '0';
		}
		rr += buf;
		cout << "Case #" << (t+1) << ": " << rr << endl;
	}
}

// (connected(n), basin(n))
// 
void B() {
	int move[4][2] = {
		{-1,0}, {0,-1}, {0,1}, {1,0}
	};

	int N;
	cin >> N;
	for(int t=0; t<N; ++t) {
		int X, Y;
		cin >> X >> Y;
		vector<vector<int> > geo_map(X, vector<int>(Y, 0));
		vector<vector<pair<int, int> > > conn_map(X, vector<pair<int, int> >(Y, make_pair(-1, -1)));
		vector<vector<pair<int, int> > > basin_map(X, vector<pair<int, int> >(Y, make_pair(-1, -1)));
		for(int x=0; x<X; ++x) {
			for(int y=0; y<Y; ++y) {
				int v;
				cin >> v;
				geo_map[x][y] = v;
			}
		}
		for(int x=0; x<X; ++x) {
			for(int y=0; y<Y; ++y) {
				pair<int, int> near(x,y);
				for(int i=0; i<4; ++i) {
					int nx=x+move[i][0], ny=y+move[i][1];
					if(0<=nx&&nx<X && 0<=ny&&ny<Y) {
						if(geo_map[nx][ny]<geo_map[near.first][near.second]) {
							near.first = nx;
							near.second = ny;
						}
					}
				}
				conn_map[x][y] = near;
			}
		}
		// set basin
		for(int x=0; x<X; ++x) {
			for(int y=0; y<Y; ++y) {
				pair<int, int> pos(x, y);
				while(conn_map[pos.first][pos.second] != pos) {
					pos = conn_map[pos.first][pos.second];
				}
				basin_map[x][y] = pos;
			}
		}
		// set alphabet
		char start = 'a';
		vector<vector<char> > rr(X, vector<char>(Y, '.'));
		for(int x=0; x<X; ++x) {
			for(int y=0; y<Y; ++y) {
				if(rr[x][y] == '.') {
					pair<int, int> basin = basin_map[x][y];
					for(int x2=0; x2<X; ++x2) {
						for(int y2=0; y2<Y; ++y2) {
							if(basin_map[x2][y2] == basin) {
								rr[x2][y2] = start;
							}
						}
					}
					++start;
				}
			}
		}
		// print
		cout << "Case #" << t+1 << ":" << endl;
		for(int x=0; x<X; ++x) {
			for(int y=0; y<Y; ++y) {
				cout << rr[x][y] << " ";
			}
			cout << endl;
		}
	}

}

bool dfs1(set<int>& ok, set<int>& not, set<int>& que, int num, int base) {
	while(true) {
		que.insert(num);
		int t_num = num;
		bool b = true;
		while(t_num > 1) {
			if(t_num % base !=0) {
				b = false;
				break;
			}
			t_num /= base;
		}
		char sz[512];
		itoa(num, sz, base);
		string new_num = sz;
		int i_num(0);
		FSZ(i,0,new_num) {
			i_num += (new_num[i]-'0')*(new_num[i]-'0');
		}
		if(ok.find(i_num)!=ok.end()) b = true;
		if(b) {
			ok.insert(que.begin(), que.end());
			que.clear();
			return true;
		}
		if(not.find(i_num)!=not.end()) {
			not.insert(all(que));
			que.clear();
			return false;
		}
		if(que.find(i_num)!=que.end()) {
			not.insert(all(que));
			que.clear();
			return false;
		}
		num = i_num;
	}
}

int NN = 100000;

set<int> getHappy(int base) {
	set<int> ok, not, question;
	for(int i=2; i<NN; ++i) {
		if(ok.find(i)!=ok.end()) continue;
		if(not.find(i)!=not.end()) continue;
		dfs1(ok, not, question, i, base);
	}
	return ok;
}

void A1() {
	map<int, set<int> > happies;
	for(int i=2; i<=10; ++i) {
		happies[i] = getHappy(i);
	}
	cerr << "check ok" << endl;

	int N;
	cin >> N;
	string str;
	getline(std::cin, str);
	for(int t=0; t<N; ++t) {
		getline(std::cin, str);
		stringstream ss;
		ss << str;
		vector<int> bases;
		int base;
		while(ss >> base) bases.push_back(base);

		vector<int> rr(NN+1, 0);
		FSZ(i,0,bases) {
			set<int> s = happies[bases[i]];
			set<int>::iterator it;
			for(it=s.begin(); it!=s.end(); ++it) {
				rr[*it]++;
			}
		}
		FSZ(i,0,rr) {
			if(bases.size() == rr[i]) {
				cout << "Case #" << t+1 << ": " << i << endl;
				break;
			}
		}
	}
}

int main(int argc, char* argv[])
{
//	A();
//	B();
//	C();
	A1();
	return 0;
}

