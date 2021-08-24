#!/usr/bin/python
# -*- coding: utf8 -*-

import psyco
psyco.full()

from sets import Set
import math
import sys
import datetime

class Timer:
    def start(self):
        self.inicial = datetime.datetime.now()

    def stop(self):
	d = datetime.datetime.now()- self.inicial
	print "%s.%s segundos" % (d.seconds, str(d.microseconds)[:2]) 
	t = float("%s.%s" % (d.seconds, str(d.microseconds)[:4]))
	return t

def readInts():
    return list(map(int, sys.stdin.readline().strip().split(" ")))


#####################################################
# Implementation starts here                        #
#####################################################

def frombase10(n, base):
    top = int(math.ceil(math.log(n)/math.log(base)))
    s = ''
    while top >= 0:
        dig = n // (base**top)
        n = n % (base**top)
        top = top - 1
        s += str(dig)
    if s[0] == '0':
        return s[1:]
    else:
        return s

def is_happy(n, base):
    n_orig = n
    unhappy = Set([0])

    while not (n in unhappy):
        if n == 1:
            return True
        else:
            unhappy.add(n)
            digs = frombase10(n, base)
            sumacuads = sum([int(x)**2 for x in digs])
            n = sumacuads
    
    return False




def resolver():
    n = readInts()[0]
    for c in range(1, n+1):
        print "Case #%s:" % c,
        bases = readInts()
        i = 2
        happy = False
        while not happy:
            happy = True
            for b in bases:
                if not is_happy(i, b):
                    happy = False
                    i = i+1
        print i
        





#####################################################
# End of implementation                             #
#####################################################


def main():
    return resolver()

if __name__ == '__main__':
    main()
    
