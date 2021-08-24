#!/usr/bin/env python

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

def get_digits(n, b):
	d = []
	while n > 0:
		d.append(n % b)
		n = n / b
	return d

def sum_squared_digits(n, b):
	return sum([ x*x for x in get_digits(n, b) ])

def happy_in_base(n, b):
	values_so_far = set()
	while True:
		values_so_far.add(n)
		n = sum_squared_digits(n, b)
		if n == 1:
			return True
		if n in values_so_far:
			return False
	return False

cases = data[1:]

for case in cases:
	bases = map(int, case.split())
	for x in itertools.count(2):
		happy = True
		for base in bases:
			happy = happy & happy_in_base(x, base)
		if happy:
			print_case(str(x))
			break
