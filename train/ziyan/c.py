#!/usr/bin/env python

import os
import sys
import collections

def chain(graph, bffs, rbffs):
    seen = []
    s = [list(graph)[0]]
    queue = [s]
    while queue:
        s = queue.pop(0)
        seen.append(s)
        for i in graph:
            if i in s:
                continue
            if bffs.get(i, None) == s[0]:
                queue.append([i] + s)
            if bffs.get(s[-1], None) == i:
                queue.append(s + [i])
        if len(s) > 1 and bffs.get(s[-1], None) == s[-2]:
            for j in rbffs.get(s[-1], []):
                if j not in s:
                    queue.append(s + [j])
    m = 0
    best = None
    for s in seen:
        if len(s) <= 1:
            m = len(s)
            best = s
            continue
        if bffs.get(s[-1], None) == s[-2]:
            if len(s) >= m:
                m = len(s)
                best = s
            continue
        if bffs.get(s[-1], None) == s[0]:
            if len(s) > m:
                m = len(s)
                best = s
            continue
    return m, best

def solve(N, bffs, rbffs):
    graphs = []
    leftover = list(range(1, N + 1))
    while leftover:
        graph = set()
        queue = [leftover[0]]
        while queue:
            i = queue.pop(0)
            if i in graph:
                continue
            graph.add(i)
            leftover.remove(i)
            if i in bffs:
                queue.append(bffs[i])
            queue += rbffs.get(i, [])
        graphs.append(graph)

    combined = 0
    lengths = []
    for graph in graphs:
        length, best = chain(graph, bffs, rbffs)
        if len(best) > 1 and bffs.get(best[-1], None) == best[-2]:
            # can be combined
            combined += length
        lengths.append(length)
    lengths.append(combined)
    return max(lengths)

def main():
    T = int(sys.stdin.readline().strip())
    for t in range(T):
        N = long(sys.stdin.readline().strip())
        bffs = dict()
        rbffs = collections.defaultdict(list)
        for i, bff in enumerate(map(int, sys.stdin.readline().strip().split())):
            bffs[i + 1] = bff
            rbffs[bff].append(i + 1)
        result = solve(N, bffs, rbffs)
        print 'Case #%d: %d' % (t + 1, result)

if __name__ == '__main__':
    main()

