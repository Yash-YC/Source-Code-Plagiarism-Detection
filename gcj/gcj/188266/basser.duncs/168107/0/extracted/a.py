#!/usr/bin/env python

import sys, math

def changeBaseFromTen(num,base):
    digits = []
    while num > 0:
        digits.insert(0, str(num % base))
        num /= base
    return "".join(digits)

def isHappy(num,base):
    thisNum = changeBaseFromTen(num,base)
    numsPassed = [thisNum]
    while (thisNum != "1"):
        digits = map(int,thisNum)
        sqDigits = map(lambda x: pow(x,2), digits)
        thisNum = sum(sqDigits)
        thisNum = changeBaseFromTen(thisNum,base)
        if thisNum in numsPassed:
            return False
        else:
            numsPassed.append(thisNum)
    return True

n = int(sys.stdin.readline().strip())

for i in range(n):
    bases = map(int,sys.stdin.readline().strip().split(" "))
    res = 0

    for j in range(2,10000000):
        found = True
        for base in bases:
            if not isHappy(j,base):
                found = False
                break
        if found:
            res = j
            break

    print "Case #%d: %d" % (i+1, res) 
