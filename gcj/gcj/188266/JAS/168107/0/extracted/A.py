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
import math
import operator

#if (os.environ.get("DEBUG") != None):
#logging.basicConfig(level=logging.DEBUG)

def main():
    input = sys.stdin
    
    # T specifies the number of test cases
    T = int(input.readline())
    logging.info("T = %d", T)
    
    for i in range(T):
        bases = map(int, input.readline().split())
        processTestCase(i + 1, bases)

def toDigits(n, base):
    digits = []
    divisor = base

    # find maximum divisor
    while (n / divisor > 0): divisor *= base
    divisor /= base

    # extract the digits
    while (divisor > 0):
        digit = n / divisor
        n = n % divisor
        digits.append(digit)
        divisor /= base

    return digits

def square(n):
    return n*n

def isHappy(n, base, done):
    if (n in done): return False
    
    #if (depth > 10): return False
    #print "isHappy n =", n
    digits = toDigits(n, base)
    new_digits = map(operator.mul, digits, digits)
    total = sum(new_digits)
    #print digits, new_digits, total
    if (total == 1): return True
    if (total != 1): return isHappy(total, base, done | set([n]))

def processTestCase(index, bases):
    logging.info("index=%d, bases=%s", index, bases)

    i = 1
    while True:
        i += 1
        success = True
        for base in bases:
            if (not isHappy(i, base, set())):
                success = False
                break
        if (success):
            print "Case #" + str(index) + ": " + str(i)
            return


    
main()
sys.exit(0)
