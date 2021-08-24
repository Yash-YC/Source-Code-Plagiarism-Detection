#!/usr/bin/python
import sys

def nextLine():
	return sys.stdin.next()[:-1]

def debug(s):
	sys.stderr.write("# "+s+"\n")

happyHash = {}

def cbase(num,n):
	r = []
	while num >= 1:
		m = num%n
		r.append(m)
		num = num/n
	r.reverse()
	return r

def happySum(l):
	t = 0
	for i in l: t+= i*i
	return t

def isHappy(l,base = 10):
	m = {}
	while True:
		t = happySum(l)
		if t in m: return False
		if t == 1: return True
		m[t] = 1
		l = cbase(t,base)
	
def happyBase(l):
	for i in xrange(2,10**9):
		res = True
		for x in l:
			if res and not isHappy(cbase(i,x),x):
				res = False
		if res == True: return i
	return 0

N = int(nextLine())
for c in range(N):
	input = map( lambda x: int(x), nextLine().split())
	total = happyBase(input)
	print "Case #%d: %d"%(c+1,total)
	debug("Case #%d: %d"%(c+1,total))

