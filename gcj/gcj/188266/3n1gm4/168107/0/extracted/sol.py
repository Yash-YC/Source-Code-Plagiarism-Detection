#!/usr/bin/python
import sys
from psyco import full
full()
rdl = sys.stdin.readline

class aliensys(object):
    def __init__(self, stringa):
        self.symbols = list(stringa)
        self.N = len(self.symbols)
    def a2d(self, n):
        s = 0
        n = list(n)
        n.reverse()
        for i in xrange(0, len(n)):
            s += self.symbols.index(n[i])*(self.N**i)
        return s
    def d2a(self, n):
        s = ''
        while n>=1:
            r = n%self.N
            n/=self.N
            s = self.symbols[r]+s
        return s
    def convert(self, n, target): # target must be an aliensys
        to = self.a2d(n)
        return target.d2a(to)

def is_happy(n, base, done = []):
    if n in done: return False
    s = 0
    b = aliensys('0123456789'[:base])
    for d in b.d2a(n):
        if d == '0': continue
        #cur = b.a2d(d)
        #s += cur**2
        s+= int(d,base)**2
    
    if s == 1: return True
    return is_happy(s, base, done + [n])

def count():
    cur = 2
    while True:
        yield cur
        cur += 1

def process(case):
    """precessing case #"""
    bases = [int(x) for x in rdl().split()]
    
    for n in count():
        if all([is_happy(n, base) for base in bases]):
            return str(n)


cases = int(rdl())
for case in xrange(1, cases+1):
    print "Case #%d:"%case, process(case)


