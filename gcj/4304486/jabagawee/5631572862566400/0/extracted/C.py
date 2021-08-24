#! /usr/bin/env python

import itertools


def check(circle, BFFs):
    # print 'checking {}'.format(circle)
    for i, kid in enumerate(circle):
        bff = BFFs[kid] - 1
        if i == len(circle) - 1:
            if bff != circle[i-1] and bff != circle[0]:
                # print 'Kid {} is not setting next to BFF {}'.format(kid, bff)
                return False
        else:
            if bff != circle[i-1] and bff != circle[i+1]:
                # print 'Kid {} is not setting next to BFF {}'.format(kid, bff)
                return False
    return True


def best_score(BFFs):
    N = len(BFFs)
    for num_kids in reversed(range(2, N+1)):
        for circle in itertools.combinations(range(N), num_kids):
            for permuted_circle in itertools.permutations(circle):
                if check(permuted_circle, BFFs):
                    return num_kids
    return 0

T = int(raw_input())
for case in range(T):
    N = int(raw_input())
    BFFs = map(int, raw_input().split())
    print 'Case #{}: {}'.format(case + 1, best_score(BFFs))
