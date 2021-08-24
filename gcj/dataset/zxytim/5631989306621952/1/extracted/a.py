#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# $File: a.py
# $Date: Sat Apr 16 09:05:59 2016 +0800
# $Author: Xinyu Zhou <zxytim[at]gmail[dot]com>

import math

def solve():
    s = input().strip()
    r = ''
    for c in s:
        if len(r) == 0:
            r = c
        else:
            if c >= r[0]:
                r = c + r
            else:
                r = r + c
    print(r)

# print(solve())
nr_case = int(input().strip())

for case_id in range(1, nr_case + 1):
    print('Case #{}: '.format(case_id), end='')
    solve()


# vim: foldmethod=marker

