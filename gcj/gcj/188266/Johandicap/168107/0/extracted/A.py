#!/usr/bin/env python
# -*- coding: utf8 -*-
# Johan Musaeus Bruun, 20090912

import sys

def main(fin):
	
	T = int(fin.readline()) # T = number of cases
	#print T, "cases..." # temp
	
	for case in xrange(T):
		bases = map(int, fin.readline().split())
		#print "Bases in this case:", bases # temp
		
		winner = findhappy(bases)
		
		print "Case #%d: %d" % (case+1, winner)


################################

def findhappy(bases):
	found = False
	j = 1
	while not found:
		j = j + 1
		
		good = True
		k = 0
		while good and k < len(bases):
			base = bases[k]
			s = tobase(j,base)  
			good = good and happy(s,base)
			k = k + 1
		if good:
			return j


def happy(s,base):
	seen = [s]
	while s != '1':
		s = digitsqsum(s,base)
		if s in seen:
			return False
		seen.append(s)
	return True


def digitsqsum(numstr,base):
	sum = 0
	for c in numstr:
		cnum = int(c,base)
		sum = sum + cnum**2
	sumstr = tobase(sum,base)
	return sumstr


def tobase(num, base, numerals="0123456789abcdefghijklmnopqrstuvwxyz"):
    """
    From: http://code.activestate.com/recipes/65212/
    
    Convert any int to base/radix 2-36 string. Special numerals can be used
    to convert to any base or radix you need. This function is essentially
    an inverse int(s, base).

    For example:
    >>> baseN(-13, 4)
    '-31'
    >>> baseN(91321, 2)
    '10110010010111001'
    >>> baseN(791321, 36)
    'gyl5'
    >>> baseN(91321, 2, 'ab')
    'babbaabaababbbaab'
    """
    if num == 0:
        return "0"

    if num < 0:
        return '-' + baseN((-1) * num, base, numerals)

    if not 2 <= base <= len(numerals):
        raise ValueError('Base must be between 2-%d' % len(numerals))

    left_digits = num // base
    if left_digits == 0:
        return numerals[num % base]
    else:
        return tobase(left_digits, base, numerals) + numerals[num % base]


################################

if __name__ == '__main__':
	try:
		#inputfile = "A-test.in"
		#fin = open(inputfile, 'r')
		fin = sys.stdin 
		main(fin)
	except IOError:
		print "File I/O error!"
