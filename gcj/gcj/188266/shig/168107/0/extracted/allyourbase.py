#! /usr/bin/python

import sys

def to_base_str(n,base):
	out = ""
	while (n > 0):
		out = str(n%base) + out
		n /= base
	if out == "": out = "0"
	return out

def sumsquaredigits(nstr):
	out = 0
	while (len(nstr) > 0):
		out += int(nstr[0])**2
		nstr = nstr[1:]
	return out

def does_repeat(ns):
	if len(ns) < 2: return False
	for chunksize in xrange(1,len(ns)/2+1):
		head = ns[:-chunksize]
		tail = ns[-chunksize:]
		if head[-chunksize:] == tail:
			return True
	return False

happycache = {}
def is_happy(base, startfrom=1):
	if base == 2 or base == 4: return True
	if happycache.has_key((startfrom,base)):
		if happycache[(startfrom,base)]: return startfrom
	previous = []
	n = startfrom
	result = False
	while True:
		n = sumsquaredigits(to_base_str(n,base))
		previous.append(n)
		if n == 1:
			result = True
			break
		if does_repeat(previous):
			break
	happycache[(startfrom,base)] = result
	return result

def iter_happy(base, startfrom=1):
	while True:
		if is_happy(base,startfrom): yield startfrom
		startfrom += 1
if __name__ == "__main__":
	assert to_base_str(9,3) == "100"
	assert to_base_str(9,10) == "9"
	assert to_base_str(9,9) == "10"
	assert to_base_str(0,9) == "0"
	assert sumsquaredigits("123") == 9+4+1
	assert sumsquaredigits("5") == 25
	assert sumsquaredigits("") == 0
	assert does_repeat([]) == False
	assert does_repeat("0") == False
	assert does_repeat("32121") == True
	assert does_repeat("2121") == True
	assert does_repeat("211") == True
	assert does_repeat("11") == True
	assert does_repeat("121") == False
	assert does_repeat("122221") == False
	assert zip(iter_happy(10), xrange(5)) == [(1,0),(7,1),(10,2),(13,3),(19,4)]
	assert zip(iter_happy(4), xrange(5)) == [(1,0),(2,1),(3,2),(4,3),(5,4)]
	inputs = int(sys.stdin.readline().strip())
	for casenum in xrange(1,inputs+1):
		bases = map(int, sys.stdin.readline().strip().split())
		n = 1
		result = False
		while not result:
			n += 1
			result = True
			for base in bases:
				if not is_happy(base,n):
					result = False
					break
		print "Case #%d: %d" %(casenum,n)

