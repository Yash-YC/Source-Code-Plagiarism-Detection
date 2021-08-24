#!/usr/bin/env python

import sys
import math

N = int(sys.stdin.readline().strip())

for i in range(N):
    c, n = map(float,sys.stdin.readline().strip().split(" "))
    res = 1 + c/n + (c-n-1)/n
    print "Case #%d: %f" %(i+1,res)
    continue
    numCollected = n
    numPacks = 1.0
    while ( True ):
        cardsLeft = math.ceil(c - numCollected)
        found = False
        for i in range(n):
            numCollected += float(cardsLeft)/c
            if (numCollected >= c):
                numPacks += float(i+1)/float(n)
                found = True
                break
        if found:
            break
        numPacks += 1.0

               

    print "Case #%d: %f" % (i+1,numPacks) 
