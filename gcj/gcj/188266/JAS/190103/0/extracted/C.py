#!/usr/bin/env python 
################################################################################
# Jeffrey A. Sandoval
# http://www.cs.rice.edu/~jasandov
# Google Code Jam
################################################################################
#
################################################################################

import sys
import os
import logging
import operator
import random

#if (os.environ.get("DEBUG") != None):
#logging.basicConfig(level=logging.DEBUG)

def main():
    input = sys.stdin
    
    # T specifies the number of test cases
    T = int(input.readline())
    logging.info("T = %d", T)
    
    for i in range(T):
        (C, N) = tuple(map(int, input.readline().split()))
        processTestCase(i + 1, C, N)

def fact(n):
    return reduce(operator.mul, range(1, n+1))

def comb(n, k):
    return fact(n) / fact(k) / fact(n - k)

def runExperiment(C, N):
    universe = range(C)
    value = [1] * C
    net_value = 0
    count = 0

    #print "universe =", universe
    
    while (net_value < C):
        pack = random.sample(universe, N)
        count += 1
#         print "net_value =", net_value,
#         print "value =", value,
#         print "pack =", pack
        for c in pack:
            net_value += value[c]
            value[c] = 0
    return count



def allEqual(l):
    if (len(l) < 2): return True
    if (l[0] != l[1]): return False
    return allEqual(l[1:])

def processTestCase(index, C, N):
    logging.info("index=%s, C=%s, N=%s", index, C, N)
    tries = 0
    packs = 0
    running_avg = range(2)
    threshold = 1000

    i = 0
    while (not allEqual(running_avg)):
        #print "running_avg =", running_avg
        packs += runExperiment(C, N)
        tries += 1
        running_avg[i] = packs * threshold / tries
        i = (i + 1) % len(running_avg)

    print "Case #" + str(index) + ": " + str(float(running_avg[0]) / float(threshold))
    
main()
sys.exit(0)
