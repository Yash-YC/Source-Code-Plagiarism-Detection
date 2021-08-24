#! /usr/bin/env python

import collections

T = int(raw_input())
for case in range(T):
    counter = collections.Counter()
    N = int(raw_input())
    for _ in range(2 * N - 1):
        line = map(int, raw_input().split())
        for num in line:
            counter[num] += 1
    keys = []
    for k, v in counter.items():
        if v % 2:
            keys.append(k)
    assert len(keys) == N
    answer = ' '.join(map(str, sorted(keys)))
    print 'Case #{}: {}'.format(case + 1, answer)
