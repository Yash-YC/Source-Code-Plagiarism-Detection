#!/usr/bin/env python
import array

sdcache = array.array('l', [-1 for x in range(1,1000000)])

def sd(n, base):
    #ck = n*11+base
    #if ck < 1000000:
    #    if sdcache[ck] >= 0:
    #        return sdcache[ck]

    sum = 0
    while n > 0:
        remainder = n%base
        sum += remainder*remainder
        n = n/base
    #if ck < 1000000 and sum < 2147483647:
    #    sdcache[ck] = sum
    return sum

happycache = {}
def happy(n, base):
    ck = (n, base)
    if happycache.has_key(ck):
        return happycache[ck]

    prev = set([n])

    while n > 1:
        n = sd(n, base)
        if n in prev:
            break
        prev.add(n)

    result = (n == 1)
    happycache[ck] = result
    return result

def smallest(bases):
    n = 2
    while True:
        allhappy = True
        for base in bases:
            if not happy(n, base):
                allhappy = False
                break
        if allhappy:
            return n
        n += 1

f = file('A-small.in', 'r')
lines = [x.strip('\n') for x in f.readlines()]
f.close()

for i in range(1, len(lines)):
    bases = [int(x) for x in lines[i].split(' ')]
    result = smallest(bases)
    print "Case #%i: %i" % (i, result)
