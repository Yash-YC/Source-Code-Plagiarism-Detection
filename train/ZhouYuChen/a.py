#!/usr/bin/env pypy

T = input()

def sol(s):
	a = s[0]
	for c in s[1:]:
		if c < a[0]:
			a = a +c
		else:
			a = c + a
	return a

for x in xrange(T):
	print "Case #%d: %s"%(x+1, sol(raw_input()))
