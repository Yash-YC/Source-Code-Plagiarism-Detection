import sys

def solve():
	s = raw_input()
	ret = s[0]
	for c in s[1:]:
		if (c >= ret[0]):
			ret = c + ret
		else:
			ret = ret + c
	return ret

n = int(raw_input())
for i in range(n):
    print "Case #{}: {}".format(i + 1, solve())
