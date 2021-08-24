#!/usr/bin/env python

import os
import sys

def solve(S):
    result = S[0]
    for l in S[1:]:
        if l >= result[0]:
            result = l + result
        else:
            result += l
    return result

def main():
    T = int(sys.stdin.readline().strip())
    for t in range(T):
        S = sys.stdin.readline().strip()
        result = solve(S)
        print 'Case #%d: %s' % (t + 1, result)

if __name__ == '__main__':
    main()

