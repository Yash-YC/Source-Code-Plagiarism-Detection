#!/usr/bin/python

import os
import sys

#sys.stdin = open('A-test.in', 'r')
#sys.stdin = open('A-small.in', 'r')
#sys.stdout = open('A-small.out', 'w')
sys.stdin = open('A-small-attempt0.in', 'r')
sys.stdout = open('A-small-attempt0.out', 'w')
#sys.stdin = open('A-small-attempt1.in', 'r')
#sys.stdout = open('A-small-attempt1.out', 'w')
#sys.stdin = open('A-large.in', 'r')
#sys.stdout = open('A-large.out', 'w')

DEBUG = 0 or os.getenv("DEBUG")

if str(DEBUG) == 'log':
    sys.stderr = open('log', 'w')

def debug(*what):
    if DEBUG:
        sys.stderr.write("[DEBUG] " + " ".join(map(str, what)) + "\n")

#-----------------------------------------------------------------------------

def is_happy(b, x):
    #debug('is_happy:', b, x)
    y = x
    r = set()
    while y not in r:
        r.add(y)
        z = 0
        while y > 0:
            d = y % b
            z += d * d
            y //= b
        y = z
    return y == 1

def happy_number(b):
    x = 2
    while True:
        ok = True
        for i in range(len (b) - 1, -1, -1):
            if not is_happy(b[i], x):
                debug('%d not happy with base %d' % (x, b[i]))
                ok = False
                break
        if ok:
            debug('happy_number:', x, b)
            return x
        x += 1
        
ncases = int(input())
for case in xrange(ncases):
    debug()
    debug("Case #%d:" % (case + 1))
    b = map(int, raw_input().split())
    debug(b)
    h = happy_number(b)
    print "Case #%d: %d" % (case + 1, h)

