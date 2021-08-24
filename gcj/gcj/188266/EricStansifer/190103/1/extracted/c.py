#!/usr/bin/python

from common import *

def gcd(a, b):
    if a == 0:
        return b
    while b != 0:
        r = a % b
        a = b
        b = r
    return a

def red(x):
    d = gcd(x[0], x[1])
    return (x[0] / d, x[1] / d)

def mult(x, y):
    return red((x[0] * y[0], x[1] * y[1]))

def add(x, y):
    return red((x[0] * y[1] + y[0] * x[1], x[1] * y[1]))

def invert(x):
    return (x[1], x[0])

def scale(x, n):
    return red((x[0] * n, x[1]))

def div(x, n):
    return red((x[0], x[1] * n))

def frac(n):
    return (n, 1)


def nice(x):
    return "%f" % ((x[0] * 1.0) / x[1])



choose = []

for a in xrange(0, 50):
    choose.append([0] * 50)

for a in xrange(0, 50):
    choose[a][0] = 1
    for b in xrange(1, a):
        choose[a][b] = choose[a - 1][b - 1] + choose[a - 1][b]
    choose[a][a] = 1



def prob(c_choose_n, c, n, r, k):
    return div(frac(choose[r][k] * choose[c - r][n - k]), c_choose_n)


def testcase(x):
    c, n = readintegers()
    expect = [frac(0)] * (c + 1)

    c_choose_n = choose[c][n]

    cur = c - 1
    while cur >= n:
        # calculate expect[cur]

        s = frac(0)
        for k in xrange(1, c - cur + 1):
            s = add(s, mult(expect[cur + k], prob(c_choose_n, c, n, c - cur, k)))
        s = add(s, frac(1))
        p0 = prob(c_choose_n, c, n, c - cur, 0)
        s = mult(s, invert(add(frac(1), scale(p0, -1))))
        expect[cur] = s

        cur -= 1

    e = expect[n]

    e = add(e, frac(1))

    ef = (e[0] * 1.0) / e[1]

    writeline("Case #%d: %f" % (x, ef))

run_tests(testcase)
