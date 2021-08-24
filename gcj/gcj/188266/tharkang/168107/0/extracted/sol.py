from sys import stdin

def main():
    hs = set()
    us = set()
    def happy(n, b):
        if n == 1:
            return True
        elif (n,b) in hs:
            return True
        elif (n,b) in us:
            return False
        else:
            nn = n
            us.add((nn,b))
            x = 0
            while n > 0:
                x += (n%b)*(n%b)
                n //= b
            if happy(x, b):
                us.remove((nn,b))
                hs.add((nn,b))
                return True
            else:
                return False
    bs = map(int, stdin.readline().split())
    for i in xrange(2, 100000000):
        #print i
        if all(happy(i, b) for b in bs):
            return str(i)
    return "uf"

tno = int(stdin.readline())
for i in xrange(0, tno):
    print "Case #%d: %s"%(i+1, main())
