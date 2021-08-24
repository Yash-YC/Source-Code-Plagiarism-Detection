#!/usr/bin/python

from common import *

def cross(cur, green, red, phase):
    per = green + red
    phase = phase % per
    if phase > cur:
        phase -= per

    if phase + per <= cur:
        phase += per * ((cur - phase) / per)

    if phase + green >= cur:
        return cur + 1

    return phase + per + 1

def testcase(x):
    n, m = readintegers()
    swt = [None] * n
    for i in xrange(0, n):
        swt[n - i - 1] = readintegers()

    s = [None] * n
    w = [None] * n
    t = [None] * n
    for i in xrange(0, n):
        s[i] = [None] * m
        w[i] = [None] * m
        t[i] = [None] * m
        for j in xrange(0, m):
            s[i][j] = swt[i][3 * j]
            w[i][j] = swt[i][3 * j + 1]
            t[i][j] = swt[i][3 * j + 2]

    best = [None] * n
    for i in xrange(0, n):
        best[i] = [None] * m
        for j in xrange(0, m):
            best[i][j] = [None] * 4

    best[0][0][0] = 0

    for i in xrange(0, n):
        for j in xrange(0, m):
            if j > 0:
                best[i][j][0] = best[i][j - 1][1] + 2
            if i > 0:
                temp = best[i - 1][j][2] + 2
                if best[i][j][0] is None or temp < best[i][j][0]:
                    best[i][j][0] = temp

            best[i][j][1] = cross(best[i][j][0], w[i][j], s[i][j], t[i][j] + s[i][j])

            if i > 0:
                temp = best[i - 1][j][3] + 2
                if temp < best[i][j][1]:
                    best[i][j][1] = temp

            # print "%d %d %d: %d" % (i, j, 0, best[i][j][0])
            # print "%d %d %d: %d" % (i, j, 1, best[i][j][1])

        for j in xrange(0, m):
            best[i][j][2] = cross(best[i][j][0], s[i][j], w[i][j], t[i][j])
            if j > 0:
                temp = best[i][j - 1][3] + 2
                if temp < best[i][j][2]:
                    best[i][j][2] = temp
            
            best[i][j][3] = cross(best[i][j][2], w[i][j], s[i][j], t[i][j] + s[i][j])
            temp = cross(best[i][j][1], s[i][j], w[i][j], t[i][j])
            if temp < best[i][j][3]:
                best[i][j][3] = temp

            # print "%d %d %d: %d" % (i, j, 2, best[i][j][2])
            # print "%d %d %d: %d" % (i, j, 3, best[i][j][3])

    ans = best[n - 1][m - 1][3]

    writeline("Case #%d: %d" % (x, ans))

run_tests(testcase)
