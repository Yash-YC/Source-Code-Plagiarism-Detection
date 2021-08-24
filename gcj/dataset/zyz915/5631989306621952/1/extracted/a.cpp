#include <cstring>
#include <cstdio>
#include <cstdlib>

char buf[3000], *c = buf + 1500;
char s[3000];

void run(int cas) {
	scanf("%s", s);
	int fr = 0, ed = 0;
	c[ed++] = s[0];
	for (int i = 1; s[i]; i++)
		if (s[i] >= c[fr])
			c[--fr] = s[i];
		else
			c[ed++] = s[i];
	c[ed] = 0;
	printf("Case #%d: %s\n", cas, c + fr);   
}

int main() {
    int tt;
    scanf("%d", &tt);
    for (int cas = 1; cas <= tt; cas++)
        run(cas);
}

