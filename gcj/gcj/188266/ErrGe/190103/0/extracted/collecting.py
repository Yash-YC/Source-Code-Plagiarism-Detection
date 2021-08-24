#!/usr/bin/python2.6

from sys import stdin, stdout, stderr
from collections import defaultdict
from gmpy import comb
from fractions import Fraction

def read_int(strLine):
    return map(int,
               strLine.split(' '))

def read_string(strLine):
    return strLine.split(' ')

def read_float(strLine):
    return map(float,
               strLine.split(' '))

def rsreadline():
    return stdin.readline().rstrip('\r\n')

class MemoizeMutable:
    """Memoize(fn) - an instance which acts like fn but memoizes its arguments
       Will work on functions with mutable arguments (slower than Memoize)
    """
    def __init__(self, fn):
        self.fn = fn
        self.memo = {}
    def __call__(self, *args):
        import cPickle
        str = cPickle.dumps(args)
        if not self.memo.has_key(str):
            self.memo[str] = self.fn(*args)
        return self.memo[str]

class Memoize:
    """Memoize(fn) - an instance which acts like fn but memoizes its arguments
       Will only work on functions with non-mutable arguments
    """
    def __init__(self, fn):
        self.fn = fn
        self.memo = {}
    def __call__(self, *args):
        if not self.memo.has_key(args):
            self.memo[args] = self.fn(*args)
        return self.memo[args]

def solve(X):
    C, N, R = X
    if R == 0:
#        print C, N, R, ':', 1, 1
        return Fraction(0,1)
    if R == 1:
#        print C, N, R, ':', float(comb(C, N)), comb(C-R, 1)
        return Fraction(comb(C, N),comb(C-1, N-1))
    tmpR = min(N, R)
    tmpN = 0
    sum = Fraction(0, 1)
    while tmpR > 0 and tmpN <= N:
#        print ' ', C, N, R, '=', C-R, 'a', tmpN, 'sz', R, 'a', tmpR, 'SZ', C, N, R-tmpR
        sum += Fraction(comb(C-R, tmpN),1)*Fraction(comb(R, tmpR),1)*(solve((C, N, R-tmpR))+Fraction(1,1))
#        print ' ', sum
        tmpN += 1
        tmpR -= 1
#    print C, N, R, ':', float(sum), comb(C, N)
    return sum * Fraction(1,comb(C, N))

solve = Memoize(solve)
def main():
    cCase = int(rsreadline())
    for iCase in range(0, cCase):
        C, N = read_int(rsreadline())
        if (C == N): print 'Case #%d: %.8f' % (iCase + 1, float(1))
        else: print 'Case #%d: %.8f' % (iCase + 1, solve((C, N, C-N))+1.0)
        stdout.flush()

main()
