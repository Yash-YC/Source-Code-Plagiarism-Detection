import random,sys

def func(C, N):
    c = set()
    S = range(C)
    count = 0
    while True:
        count += 1
        p = random.sample(S, N)
        c |= set(p)
        if len(c) == C:
            return count

f = open(sys.argv[1])
T = int(f.readline())
B = 4096
for i in range(1,T+1):
    C,N = [int(i) for i in f.readline().split()]
    if N == C:
        print("Case #%d: %.7f" % (i, 1.0))
        continue
    s = 0
    for t in range(B):
        s += func(C, N)
    print("Case #%d: %.7f" % (i, s / B))
