import random

rl = lambda: map(int, raw_input().split())

def solve():
    n, w, l = rl()
    r = rl()
    x = [0] * n
    y = [0] * n
    for i in xrange(n):
        f = False
        while not f:
            xx = random.randrange(w+1)
            yy = random.randrange(l+1)
            f = True
            for j in xrange(i):
                if (xx - x[j]) ** 2 + (yy - y[j]) ** 2 < (r[i] + r[j]) ** 2:
                    f = False
                    break
        x[i], y[i] = xx, yy

    return " ".join("%d %d" % (xx, yy) for xx, yy in zip(x, y))

t = input()
for i in xrange(t):
    print "Case #%d: %s" % (i + 1, solve())
