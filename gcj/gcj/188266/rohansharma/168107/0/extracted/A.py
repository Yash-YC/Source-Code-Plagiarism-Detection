#!/usr/bin/python

import operator

MAX = 50000
NBASES = 11

def digs(n, b):
    l = []
    while n:
        l.append(n % b)
        n /= b
    return l

def sqdigs(n, b):
    return sum(i**2 for i in digs(n, b))

hmap = [{} for i in xrange(NBASES)]
done = [{} for i in xrange(NBASES)]
hset = [set() for i in xrange(NBASES)]

def happy(n, b):
    if not n in hmap[b]:
        if n in done[b]:
            hmap[b][n] = False
        else:
            done[b][n] = True
            hmap[b][n] = happy(sqdigs(n, b), b)
    return hmap[b][n]

def ans(bases):
    hl = sorted(hset[bases[0]])
    for i in hl:
        if reduce(operator.and_, (i in hset[base] for base in bases)):
            return i

if __name__ == "__main__":

    for i in xrange(NBASES):
        hmap[i][0] = False
        hmap[i][1] = True
    for i in xrange(2, NBASES):
        for j in xrange(2, MAX):
            if happy(j, i):
                hset[i].add(j)

    tc = int(raw_input())

    for i in xrange(tc):
        print "Case #%d: %d" % (i + 1, ans(map(int, raw_input().split(' '))))

        

    

            
    

