#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

#define PROBLEM "C"
#define INPUT "large"
#define ATTEMPT "0"
#define VERIFY 0
const string PATH("C:\\Users\\stan\\Documents\\visual studio 2013\\Projects\\ConsoleApplication1\\ConsoleApplication1\\GCJ2016_R1A");

class solver
{
	int n;
	vector<int> BFF;
	vector<vector<int>> RG;

public:
	solver()
	{
		cin >> n;
		BFF = vector<int>(n);
		RG = vector<vector<int>>(n);
		
		for (int i = 0; i < n; i++)
		{
			cin >> BFF[i], BFF[i]--;
			RG[BFF[i]].push_back(i);
		}

	};

	int deepest(int node, int taboo = -1)
	{
		int deep = 0;
		for (int i = 0; i < RG[node].size(); i++)
		if (RG[node][i] != taboo) deep = max(deep, deepest(RG[node][i]) + 1);
		return deep;
	}
	
	void solve(stringstream &cout)
	{
		vector<char> visited(n, false);

		//longest closed cycle
		set<pair<int, int>> shortcycles;
		int longest_cycle = 0;

		for (int i = 0; i < n; i++)
		if (!visited[i])
		{
			vector<int> counter(n, -1);
			int c = 0;
			counter[i] = c++;
			int head = BFF[i];
			while (counter[head] == -1) visited[head] = true, counter[head] = c++, head = BFF[head];
			if (c - counter[head] == 2)
				shortcycles.insert({ min(head, BFF[head]), max(BFF[head], head) });
			longest_cycle = max(longest_cycle, c - counter[head]);
		}

		int combined_cycle = 0;
		for (auto s: shortcycles)
			combined_cycle += 2 + deepest(s.first, s.second) + deepest(s.second, s.first);

		cout << max(longest_cycle, combined_cycle);

	}
};



int main()
{
	clock_t start = clock();

	string Name = PATH + '\\' + PROBLEM + "-" + INPUT;
	if (INPUT == "small") Name = Name + "-attempt" + ATTEMPT;
	string InName = Name + ".in";
	string OutName = Name + ".out";

	freopen(InName.c_str(), "r", stdin);
	ofstream output;
	ifstream input;
	string before = "";
	vector<string> Before;
	if (VERIFY)
	{
		input.open(OutName.c_str());
		string T;
		while (getline(input, T)) before += T + "\n";

		int i = 1;
		int j = 0;
		while (true)
		{
			string search = "Case #" + to_string((long long)i) + ":";
			int j2 = before.find(search);
			if (j2 == string::npos) break;
			if (j != 0) Before.push_back(before.substr(j + 1, j2 - 2 - j));
			j = j2 + search.length();
			i++;
		}
		Before.push_back(before.substr(j + 1, before.length() - 2 - j));
	}
	else  output.open(OutName.c_str());

	int T;
	cin >> T;

	vector<solver> A(T);
	vector<string> Answers(T);



	for (size_t i = 0; i < A.size(); i++)
	{
		stringstream S;
		A[i].solve(S);
		Answers[i] = S.str();
		cout << "Case #" << (i + 1) << ": " << Answers[i] << "\n";
	}

	bool errors = false;

	for (size_t i = 0; i < A.size(); i++)
	{
		cout << "Case #" << (i + 1) << ": " << Answers[i] << "\n";
		if (VERIFY)
		{
			if (Before[i] != Answers[i])
			{
				cout << "ERROR - PREVIOUSLY: " << Before[i] << "\n";
				errors = true;
			};

		}
		else output << "Case #" << (i + 1) << ": " << Answers[i] << "\n";
	}

	if (errors) cout << "ERRORS WERE FOUND IN SOLUTION" << "\n";

	clock_t end = clock();
	cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << "\n";

};