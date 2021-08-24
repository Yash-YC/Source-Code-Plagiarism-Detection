#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <sstream>
#include <string>

using namespace std;

const int maxn = 1000000;

int good[11][maxn], tn;
int n, a[20];
char temp[1000];

int f( int base, int n )
{
  int &ans = good[base][n];
  if (ans != -1)
    return ans;
  ans = 0;
  int next = 0;
  for (int t = n; t > 0; t = t / base)
  {
    int digit = t % base;
    next = next + digit * digit;
  }
  if (f(base, next))
    ans = 1;
  return ans;
}

int main()
{
  memset(good, -1, sizeof(good));
  for (int base = 2; base <= 10; base++)
  {
    good[base][1] = 1;
    for (int i = 2; i < maxn; i++)
      f(base, i);
  }
  scanf("%d ", &tn);
  for (int test = 1; test <= tn; test++)
  {
    n = 0;
    gets(temp);
    stringstream ss(temp);
    string s;
    while (ss >> s)
      a[n++] = atoi(s.c_str());
/*  fprintf(stderr, "[n=%d {", n);
    for (int i = 0; i < n; i++)
      fprintf(stderr, "%d,", a[i]);
    fprintf(stderr, "}]\n");*/
    int ans = -1;
    for (int i = 2; i < maxn; i++)
    {
      bool good = true;
      for (int j = 0; j < n; j++)
        if (f(a[j], i) == 0)
        {
          good = false;
          break;
        }
      if (good)
      {
        ans = i;
        break;
      }
    }
    if (ans == -1)
      fprintf(stderr, "[error] Case #%d\n", test);
    printf("Case #%d: %d\n", test, ans);
  }
  return 0;
}

