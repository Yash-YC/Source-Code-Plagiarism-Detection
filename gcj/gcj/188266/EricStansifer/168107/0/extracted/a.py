#!/usr/bin/python

from common import *

def next(n, b):
    s = 0
    while n > 0:
        s += (n % b) * (n % b)
        n = n / b
    return s

happy = []

def is_happy(n, b):
    if n < 1000:
        return happy[b][n]
    return is_happy(next(n, b), b)

def pre_is_happy(n, b):
    global happy
    if happy[b][n] is None:
        happy[b][n] = False
        happy[b][n] = pre_is_happy(next(n, b), b)
    return happy[b][n]

def init():
    global happy
    for b in xrange(0, 11):
        happy.append([None] * 1000)
    for b in xrange(2, 11):
        happy[b][1] = True
        for n in xrange(2, 1000):
            pre_is_happy(n, b)

init()

def testcase(x):
    bases = readintegers()
    n = 2
    while True:
        for b in bases:
            if not is_happy(n, b):
                break
        else:
            break
        n += 1

    writeline("Case #%d: %d" % (x, n))

run_tests(testcase)
