#!/usr/bin/env python

import sys

T = int(sys.stdin.readline())

happy = {}

def to_base(i, b):
	out = ''
	while i >= b:
		out = '%s' % (i%b) + out
		i = (i-(i%b))/(b)
	out = '%s' % i + out
	return out

cycle = []
def is_happy(i, b):
	if i == 1:
		return 1
	if i in cycle:
		return 0
	cycle.append(i)
	based = to_base(i, b)
	new_i = 0
	for c in based:
		new_i = new_i + int(c)*int(c)
	return is_happy(new_i, b)

for i in range(1, T+1):
	base = map(int, sys.stdin.readline().split())

	common = 2
	while 1:
		result = 0
		for b in base:
			cycle = []
			result = result + is_happy(common, b)
		if result == len(base):
			break
		common = common + 1
		
	print "Case #%s: %s" % (i, common)
