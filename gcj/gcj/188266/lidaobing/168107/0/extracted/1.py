import sys
import psyco
psyco.full()


def isHappy(b, x, t):
    if b == 1:
        return True
    if (b,x) in t:
        return t[(b,x)]

    used = set()
    used.add(b)
    
    while 1:
        used.add(b)
        r = 0
        while b:
            r += (b % x) * (b % x)
            b //= x
        if r == 1:
            res = True
            break
        if r in used:
            res = False
            break
        b = r
   
    for xx in used:
        t[(xx,x)] = res
    return res


def foo2(b, a, t):
    for x in a:
        if not isHappy(b, x, t):
            return False
    return True

def foo(idx, ifile):
    a = [int(x) for x in ifile.readline().split()]
    t = {}
    b = 2
    while True:
        if foo2(b, a, t):
            print 'Case #%s: %s' % (idx, b)
            break
        b += 1


def main(ifile):
    n = int(ifile.readline())

    for i in range(n):
        foo(i+1, ifile)

main(sys.stdin)
