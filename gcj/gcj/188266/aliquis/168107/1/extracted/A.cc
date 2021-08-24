#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

char v[10000];

int top = 0;

bool eval(int num, int base)
{
  if(num<10000) {
    if(v[num]) return 2==v[num];
    v[num] = 1;
  }
  int k = 0;
  int n = num;
  while(n) {
    k += (n%base)*(n%base);
    n /= base;
  }
  top >?= k;
  if(num<10000) {
    v[num] = 1+eval(k, base);
    return 2==v[num];
  } else
    return 2==v[k];
}

int main()
{
  std::vector<int> v2[9];

  for(int j=2; j<=10; ++j) {
    memset(v, 0, sizeof(v));
    v[1] = 2;
    for(int i=2; i<11814486; ++i) {
      if(eval(i, j))
	  v2[j-2].push_back(i);
    }
  }
  fprintf(stderr, "%d\n", top);
  int T;
  scanf("%d ", &T);
  char str[1000];
  for(int i=0; i<T; ++i) {
    gets(str);
    int j=0;
    int x;
    sscanf(str, "%d%n", &x, &j);
    std::vector<int> v3 = v2[x-2];
    int k=0;
    while(1==sscanf(str+j, "%d%n", &x, &k)) {
      j += k;
      std::vector<int> v4;
      std::back_insert_iterator<std::vector<int> > ii(v4);
      std::set_intersection(v3.begin(), v3.end(), v2[x-2].begin(), v2[x-2].end(), ii);
      v3 = v4;
    }
    fprintf(stderr, "Length %lu\n", v3.size());
    printf("Case #%d: %d\n", i+1, v3.front());
  }
  return 0;
}
