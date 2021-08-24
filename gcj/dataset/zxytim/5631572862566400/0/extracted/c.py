#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# $File: c.py
# $Date: Sat Apr 16 09:58:15 2016 +0800
# $Author: Xinyu Zhou <zxytim[at]gmail[dot]com>

import math

def solve(case_id):

    n = int(input().strip())
    link = [i - 1 for i in map(int, input().strip().split())]
    degin = [0] * n
    for a, b in enumerate(link):
        degin[b] += 1

    queue = [0] * n
    head, tail = 0, 0
    for i, d in enumerate(degin):
        if d == 0:
            queue[tail] = i
            tail += 1

    count = [1] * n

    while head != tail:
        u = queue[head]
        head += 1
        v = link[u]
        count[v] = max(count[v], count[u] + 1)
        degin[v] -= 1
        if degin[v] == 0:
            queue[tail] = v
            tail += 1

    ans = 0
    # find circles
    circle_vtx = set(range(n)) - set(queue[:tail])

    start_vtxs = list(circle_vtx)
    for start in start_vtxs:
        if start not in circle_vtx:
            continue
        u = start
        circle_vtx.remove(u)
        circle = [u]
        while True:
            v = link[u]
            if v not in circle_vtx:
                break
            circle.append(v)
            circle_vtx.remove(v)
            u = v
        circle_size = len(circle)
        ans = max(ans, circle_size)
        assert circle_size >= 2, circle_size
        if circle_size > 2:
            ans = max(ans, circle_size)
        else:  # circle_size == 2
            s = sum([count[i] for i in circle])
            ans = max(ans, s)

    print(ans)


# print(solve())
nr_case = int(input().strip())

for case_id in range(1, nr_case + 1):
    print('Case #{}: '.format(case_id), end='')
    solve(case_id)

# vim: foldmethod=mark
