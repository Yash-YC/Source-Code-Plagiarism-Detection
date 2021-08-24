// pp1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <string.h>
bool mk[1000];

bool judge(int a, int b) {
	memset(mk, 0, sizeof(mk));
	while (1) {
		int now = 0;
		while (a) {
			now += (a % b) * (a % b);
			a /= b;
		}
		a = now;
		if (a == 1) {
			return true;
		}
		if (mk[a]) {
			return false;
		}
		mk[a] = 1;
	}
}

int main()
{
	freopen("d:/in.txt",  "r", stdin);
	freopen("d:/out.txt", "w", stdout);
	int T;
	int b[100];
	scanf("%d", &T);
	char str[1000];
	gets(str);
	for (int i = 1; i <= T; i++) {
		gets(str);
		int j = 0;
		int l = strlen(str);
		str[l] = ' ';
		str[l + 1] = 0;
		int nb = 0;
		int k = 0;
		while (k <= l) {
			sscanf(str + k, "%d", &b[j]);
			j++;
			nb++;
			while (str[k] != ' ') {
				k++;
			}
			k++;
		}
		for (int ret = 2; ; ret++) {
			bool ok = true;
			for (j = 0; j < nb; j++) {
				if (!judge(ret, b[j])) {
					ok = false;
					break;
				}
			}
			if (ok) {
				printf("Case #%d: %d\n", i, ret);
				break;
			}
		}
	}
	return 0;
}