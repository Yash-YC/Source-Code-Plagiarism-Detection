#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define forn(i,n) for(int i = 0; (i) < (int) (n); i++)
using namespace std;

vector<int> reversed[2000];
int BFF[2000];
vector<int> branches;
int visited[1024];

int findcycle(int i, int c)
{
  if(visited[i]>1) return c;
  if(visited[i]) c++;
  visited[i]++;
  return findcycle(BFF[i], c); 
}

int findpath(int i, int p)
{
  int best = 0;
  forn(j, reversed[i].size())
  {
    int k = reversed[i][j];
    if(k!=p) best = max(best, findpath(k, p));
  }
  return best + 1;
}

int main()
{
#ifdef ACMTUYO
  freopen("C-small-attempt1.in", "r", stdin);
  freopen("C-small-attempt1.out", "w", stdout);
#endif

	int T;
  cin >> T;
  forn(tc,T)
  {
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
	{
    reversed[i].clear();
  }
	for(int i=0; i<n; i++)
	{
		cin >> BFF[i];
    BFF[i]--;
    reversed[BFF[i]].push_back(i);
	}
  
  branches.clear();
  int ans=0;
  memset(visited,0,sizeof(visited));
  for(int i=0; i<n; i++)
  {
    if(!visited[i])
      ans = max(ans, findcycle(i, 0));
    
    if(BFF[i]>i && BFF[BFF[i]]==i)
    {
      branches.push_back(findpath(i, BFF[i])+findpath(BFF[i], i));
    }
  }
	int bestbr = 0;
  sort(branches.begin(), branches.end());
  reverse(branches.begin(), branches.end());
  forn(i, (int) branches.size()) bestbr += branches[i];
  
  
    cout << "Case #" << tc+1 << ": " << max(bestbr, ans);
    cout << "\n";
  }
}
