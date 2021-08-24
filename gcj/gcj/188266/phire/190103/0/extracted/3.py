#!/usr/bin/python

from fractions import Fraction as frac
import sys

C = [[1],[1,1]]

def solve(c,n):
	def prob(x,m):
		return frac(C[m][n-x]*C[c-m][x],C[c][n])
	def f(m):
		if m==0:
			return 1+f(n)
		if m==c:
			return 0
		num = 0 
		for tx in xrange(1,min(c-m+1,n+1)):
			num += prob(tx,m)*f(m+tx)
		return (1 + num)/(1 - prob(0,m))
	return float(f(0))

for i in xrange(len(C),41):
	C.append([1 for i in xrange(len(C[-1])+1)])
	for j in xrange(1,len(C[-1])-1):
		C[-1][j] = C[-2][j] + C[-2][j-1]

ncases = int(sys.stdin.readline())

for case in xrange(1,ncases+1):
	c,n = sys.stdin.readline().split()
	c = int(c)
	n = int(n)
	print "Case #"+str(case)+":", str(solve(c,n))
