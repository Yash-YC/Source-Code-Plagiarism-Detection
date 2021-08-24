import sys

def solve():
	n = int(raw_input())
	dic = {}
	for i in range(2 * n - 1):
		for x in raw_input().split(" "):
			x = int(x)
			if (dic.has_key(x) == False):
				dic[x] = 0
			dic[x] += 1
	ret = []
	for x in dic:
		if (dic[x] % 2 == 1):
			ret.append(x)
	return " ".join(map(str, sorted(ret)))

t = int(raw_input())
for i in range(t):
    print "Case #{}: {}".format(i + 1, solve())
