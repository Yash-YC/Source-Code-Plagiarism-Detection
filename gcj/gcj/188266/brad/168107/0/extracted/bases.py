from itertools import *

def tobase(n, b):
	s = ''
	while n > 0:
		n,c = divmod(n,b)
		s = str(c) + s
	return s

def ishappy(n, b):
	d = set()
	while True:
		n = sum(int(c)**2 for c in tobase(n,b))
		if n == 1:
			return True
		if n in d:
			return False
		d.add(n)

N = int(input())
for n in range(1,N+1):
	
	bases = [int(s) for s in input().split()]
	
	for i in count(2):
		if all(ishappy(i, b) for b in bases):
			print('Case #%s: %s' % (n,i))
			break
