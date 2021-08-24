#!/usr/bin/python2.5
def combinations(n, r):
    global combinations_cache
    if ((n,r) in combinations_cache): return combinations_cache[n,r]
    prod1 = 1
    prod2 = 1
    for j in range(1,r+1): prod1 = prod1 * j
    for j in range(n-r+1, n+1): prod2 = prod2 * j
    combinations_cache[n,r] = prod2/prod1
    return combinations_cache[n,r]

def compute_expected_number_booster_packs():
    expected_number_booster_packs = 0.000000
    num_remaining = C
    while (num_remaining > 0):
        if (num_remaining > N):
            numerator = combinations(num_remaining, N)
            denominator = combinations(C, N)
        else:
            numerator = combinations(N, num_remaining)
            denominator = combinations(C, num_remaining)
        expected_number_booster_packs += float(denominator)/float(numerator)
        num_remaining -= N
    return expected_number_booster_packs

T = input()
for case in range(T):
    combinations_cache = {}
    (C, N) = map(int, raw_input().split())
    expected_number_booster_packs = compute_expected_number_booster_packs()
    print('Case #%d: %0.6f') % (case+1, expected_number_booster_packs)
