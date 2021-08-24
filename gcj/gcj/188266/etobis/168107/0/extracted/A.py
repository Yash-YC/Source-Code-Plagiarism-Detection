#!/usr/bin/python

import sys

def line():
    return sys.stdin.readline()[:-1]

def readList():
    return map(eval,line().split())

known = eval(open("known").readline())
# I precomputed it with precompute, adjusting b by hand

if __name__ == '__main__':
    numberOfCases = eval(line())
    for caseNumber in range(numberOfCases):
        # Process a case
        bases = readList()
        candidates = set(known[bases[0]])
        for b in bases[1:]:
            candidates = candidates & known[b]
        # Read one line at a time
        #case = next()
        print "Case #" + str(caseNumber+1) + ":", sorted(candidates)[1]
