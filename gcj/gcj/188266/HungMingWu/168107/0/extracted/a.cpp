#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char str[500], *p;
int bases[10];
int num;
int found[50000];
int size;
bool calc(int v, int b)
{
	for (int i = 0; i < size; i++)
		if (found[i] == v) return false;
	found[size++] = v;
	if (v == 1) return true;
	int sum = 0, origin = v;
	while (v) {
		int t = v % b;
		sum += t * t;
		v /= b;
	}
	return calc(sum, b);
}
int main()
{
	int cases;
	gets(str);
	sscanf(str, "%d", &cases);
	for (int c = 1; c <= cases; c++)
	{
		gets(str);
		num = 0;
		for (p = strtok(str, " "); p; p = strtok(NULL, " "))
			bases[num++] = atoi(p);
		for (int value = 2;; value++)
		{
			bool success = true;
			for (int i = 0; i < num && success; i++)
			{
				size = 0;
				success &= calc(value, bases[i]);
			}
			if (success) {
				printf("Case #%d: %d\n", c, value);
				break;
			}
			
		}
		
	}
	return 0;
}
