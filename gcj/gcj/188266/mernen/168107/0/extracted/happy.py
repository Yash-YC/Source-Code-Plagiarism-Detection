#! /usr/bin/env python

MEMO = {}

def is_happy(n, base):
    m = MEMO.get((n, base), None)
    if m is not None:
        return m
    MEMO[n,base] = False
    s = sum(x*x for x in split(n, base))
    if s == 1:
        MEMO[n, base] = True
        return True
    ih = is_happy(s, base)
    MEMO[n,base] = ih
    return ih

def split(n, base):
    while n > 0:
        n,m = divmod(n, base)
        yield m

def min_happy(bases):
    i = 2
    while True:
        if all(is_happy(i, base) for base in bases):
            return i
        i += 1

if __name__ == '__main__':
    t = int(raw_input())
    for i in xrange(1, t+1):
        print 'Case #%d:' % i,
        bases = map(int, raw_input().split())
        print min_happy(bases)
