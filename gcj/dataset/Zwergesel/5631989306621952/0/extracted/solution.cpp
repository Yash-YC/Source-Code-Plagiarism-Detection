#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

#define FOR(i,n) for (int i=0; i<n; ++i)
#define FORVEC(it,v) for (auto it=(v).begin(); it != (v).end(); ++it)
#define NUL(arr) memset(arr, 0, sizeof(arr));
#define SORT(x) sort((x).begin(), (x).end());

string best_word(const string& word)
{
	if (word.size() <= 1) return word;
	int h = 0;
	FOR(i,(int)word.size()) {
		if (word[i] >= word[h]) h = i;
	}
	return string(1, word[h]) + best_word(word.substr(0,h)) + word.substr(h+1);
}

void solve()
{
	string word;
	cin >> word;
	cout << best_word(word);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i=1; i<=t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
		cout << "\n";
	}
	return 0;
}
