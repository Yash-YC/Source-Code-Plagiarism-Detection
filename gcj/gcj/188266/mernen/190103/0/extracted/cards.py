#! /usr/bin/env python
from __future__ import division

def compute(c, n):
    if c == n: return 1
    return 1 + c / n

if __name__ == '__main__':
    t = int(raw_input())
    for i in xrange(1, t+1):
        print 'Case #%d:' % i,
        c, n = map(int, raw_input().split())
        print '%.7f' % compute(c, n)
