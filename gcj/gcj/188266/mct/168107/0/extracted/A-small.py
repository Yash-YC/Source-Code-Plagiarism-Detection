#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys

input = 'A-small.in'
output = 'A-small.out'

##

def Conv(n,base):
    x = n
    y = []
    while x > 0:
        y.append(x % base)
        x = x // base
    return y

def Sum(list):
    return sum([ x * x for x in list])

def Check(n,b):
    list = []
    k = n
    while k not in list:
        list.append(k)
        l = Conv(k,b)
        m = Sum(l)
        if m == 1:
            return 0
        k = m
    return 1

##

f = file(input)
g = file(output,'w')

n_cases = int(f.readline().strip())

for k in range(n_cases):
    
    bases = f.readline().strip().split()
    
    n = 2
    while True:
        n += 1
        m = 0
        for b in bases:
            m += Check(n,int(b))
            if m == 1:
                break
        if m == 0:
            break
    
    str = "Case #%d: %d" % (k+1, n)
    
    print str
    g.write("%s\n" % str)

f.close()
g.close()
