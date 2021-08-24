#!/usr/bin/env python

import os
import sys
import collections

def solve(N, pieces):
    count = collections.defaultdict(int)
    for p in pieces:
        for v in p:
            count[v] += 1
    n = [v for v, c in count.iteritems() if c % 2 == 1]
    assert(len(n) == N)
    n.sort()
    return n

def main():
    T = int(sys.stdin.readline().strip())
    for t in range(T):
        N = long(sys.stdin.readline().strip())
        pieces = []
        for i in range(2*N-1):
            piece = map(int, sys.stdin.readline().split())
            pieces.append(piece)
        result = solve(N, pieces)
        print 'Case #%d: %s' % (t + 1, ' '.join(map(str, result)))

if __name__ == '__main__':
    main()

