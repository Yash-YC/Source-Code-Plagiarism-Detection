#!/usr/bin/env pypy



def sol(n, l):
	l.sort()
	'''print '-' * 20
	for x in l: print x
	print '-' * 20'''
	t, missing = zip(l, xrange(n*2)), -1
	for i in xrange(n):
		r = 2
		if((len(t) == 1) or t[1][0][0] != t[0][0][0]):
			missing, r, u = i, 1, l[t[0][1]]
		t = sorted(list(map(lambda x: (x[0][1:], x[1]), t[r:])))
	
	res = [u[missing]]
	cnt = {}
	for p in l: cnt[p[missing]] = 0
	for p in l: cnt[p[missing]] += 1
	for x in u: cnt[x] -=1
	for k, v in cnt.items():
		if v == 1:
			res.append(k)
	res.sort()
	return ' '.join(map(str, res))
	
T = input()
for x in xrange(T):
	n = input()
	l = [tuple(map(int,raw_input().split())) for j in xrange(n*2-1)]
	print "Case #%d: %s" % (x+1, sol(n, l))
