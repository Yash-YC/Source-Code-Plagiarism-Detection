#!/usr/bin/python
#
# Copyright (c) 2009 by T. Chan.

from __future__ import division
from StringIO import StringIO
import sys
from pdb import set_trace as debugger
import pprint

def wait(t,o,m,tt):
	off = (tt+o-t)%m
	on = (o-t)%m
	if off and off < tt:
		return 0
	return on

def read3s(l):
	out = []
	while l:
		out.append((l[0],l[1],l[2]))
		l = l[3:]
	return out

def process(f, out = None):
	if isinstance(f,str):
		if not out:
			out = open(f+'.out.txt','wb')
		f = open(f,'rb')
	else:
		if not out:
			out = StringIO()
	t = int(f.readline().strip())
	for xm1 in range(t):
		n,m = map(int,f.readline().strip().split())
		timing = []
		for x in range(n):
			timing.append(read3s(map(int,f.readline().strip().split())))
			assert len(timing[-1]) == m
		timing.reverse()
		soln = map(list,[[None]*(2*m)]*(2*n))
		soln[0][0] = 0
		while True:
			changed = False
			for y in range(2*n):
				for x in range(2*m):
					if soln[y][x] is None:
						continue
					time = soln[y][x]
					timing_ = timing[y//2][x//2]
					if y < 2*n-1:
						if y%2 == 0:
							north = time+wait(time,timing_[2],timing_[0]+timing_[1],timing_[0])+1
						else:
							north = time+2
						if soln[y+1][x] is None or soln[y+1][x] > north:
							soln[y+1][x] = north
							changed = True
					if x < 2*m-1:
						if x%2 == 0:
							east = time+wait(time,timing_[2]+timing_[0],timing_[0]+timing_[1],timing_[1])+1
						else:
							east = time+2
						if soln[y][x+1] is None or soln[y][x+1] > east:
							soln[y][x+1] = east
							changed = True
			if not changed:
				break
		out.write('Case #%d: %d\n' % (xm1+1,soln[2*n-1][2*m-1]))
		out.flush()

	#f.close()
	#out.close()
	if isinstance(out,StringIO):
		print out.getvalue()
		return out.getvalue()

TEST_DATA=(
"""2
1 1
3 2 10
1 2
1 5 3 1 5 2""",
"""Case #1: 4
Case #2: 7
""")

def go():
	assert process(StringIO(TEST_DATA[0])) == TEST_DATA[1]
	l = sys.argv[1:]
	if not l:
		l = ['C-small-attempt0.txt', 'C-large.in.txt']
	for x in l:
		process(x)

if __name__ == '__main__':
	go()