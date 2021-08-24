# -*- coding: utf-8 -*-
import sys
import math

def ReadInts():
	return list(map(int, sys.stdin.readline().strip().split(" ")))

def CheckHappy(base, number):
	sum = number
	sumset = set([])
	while True:
		a,b=0,sum
		while b>0:
			v = b % base
			b = b / base
			a += v*v
		if a==1:
			return True
		if a in sumset:
			break
		sumset.add(a)
		sum = a
	return False
		

def DoCase(casestr):
	list = ReadInts()

	print casestr,

	n=2
	while True:
		for i in list:
			if not CheckHappy(i,n):
				break
		else:
			print n
			return
		n=n+1
#print CheckHappy(9,91)

T = ReadInts()[0]
for prob in xrange(1, T + 1):
	DoCase("Case #%d:" % prob)

