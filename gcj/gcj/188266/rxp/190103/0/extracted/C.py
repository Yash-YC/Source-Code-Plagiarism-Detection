#!/usr/bin/env python
from __future__ import division
########################################################################
# template
import sys
if len(sys.argv) < 2:
	print "Usage: %s datafile" % sys.argv[0]
data = [x.strip() for x in open(sys.argv[1]).readlines()]
import itertools
from numpy import *
# >>> array([[1, 3],[2, 4]])
# array([[1, 3],
#        [2, 4]])
# indices are a[row,col]
# zeros(r,c), ones(r,c) create pre-filled arrays
# linspace(min, max, n) creates n evenly spaced elements between min and max, inclusive
def err(s):
	sys.stderr.write(s)
case_num = 1
def print_case(s):
	global case_num
	print "Case #%d: %s" % (case_num, s)
	case_num = case_num + 1
########################################################################

cases = data[1:]

def EV(C, N, F):
	"how many you expect to get from a booster pack"
	return N * (C-F) / C

for l in cases:
	C, N = map(int, l.split())
	F = N # num found
	T = 1 # num bought
	
	while F < C and EV(C, N, F) > 1:
		F = F + EV(C, N, F)
		T = T + 1
	
	if EV(C, N, F) > 0:
		T = T + 1 / EV(C, N, F)
	
	print_case(T)
	
