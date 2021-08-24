#!/usr/bin/python

import sys

def line():
    return sys.stdin.readline()[:-1]

def readList():
    return map(eval,line.split())

def toBase(n,b):
    result = []
    m = n
    while m > 0:
        result.append(m % b)
        m = m / b
    return result

known = eval(open("known").readline())

def isHappy(n,b):
    if n in known[b]:
        return True
    number = toBase(n,b)
    visited = set()
    visited.add(n)
    while True:
        m = sum([x ** 2 for x in number])
        if m in known[b]:
            known[b].update(visited)
            return True
        elif m in visited:
            return False
        visited.add(m)
        number = toBase(m,b)

# b = 9
# for i in range(0,100000):
#     if isHappy(i,b):
#         pass
# for b in known:
#     print len(known[b])

# precompute = dict()
# for b in range(2,11):
#     precompute[b] = set()
#     input = open(str(b))
#     while True:
#         line = input.readline()
#         if line == "":
#             break
#         precompute[b].add(eval(line))

# for b in precompute:
#     print len(precompute[b])
# print "Listo"

for b1 in range(2,11):
    for b2 in range(b1+1,11):
        for b3 in range(b2+1,11):
            if len(known[b1] & known[b2] & known[b3]) == 1:
                print b1,b2,b3

# for b in range(2,7):
#     precompute[b] = set()
#     for i in range(10000):
#         if isHappy(i,b):
#             precompute[b].add(i)

# for b in range(7,9):
#     precompute[b] = set()
#     for i in range(500000):
#         if isHappy(i,b):
#             precompute[b].add(i)

# for b in range(9,11):
#     precompute[b] = set()
#     for i in range(100000):
#         if isHappy(i,b):
#             precompute[b].add(i)

print >>open("known","w"),known
