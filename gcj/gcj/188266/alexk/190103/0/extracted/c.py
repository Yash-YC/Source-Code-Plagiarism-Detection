import random

M = {}
def calc(C, K):
    if (C, K) in M: return M[C, K]
    if K == C:
        return 0
    if K == 0:
        res = 1.0 + calc(C, K+1)
    else:
        res = 2 + calc(C, K+1)
    M[C, K] = res
    return res

T = input()
for i in xrange(T):
    C, N = [float(s) for s in raw_input().split()]
    print 'Case #%i: %.8f' % (i + 1, calc(C, 0.0) / N)
