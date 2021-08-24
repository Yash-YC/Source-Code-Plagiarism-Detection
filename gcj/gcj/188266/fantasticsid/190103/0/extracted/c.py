n = int(raw_input())

memoriz = {}

def com(k, n):
    if memoriz.has_key((k, n)):
        return memoriz[(k, n)]
    if k == n or k == 0:
        return 1
    if k == 1:
        return n
    else:
        memoriz[(k, n)] = com(k, n-1) + com(k-1, n-1)
        return memoriz[(k, n)]

def e(c, n):
    if c == n:
        return 1.0
    else:
        return e(c-1, n) + float(com(n, c)) / float(com(n-1, c-1))

for i in range(n):
    c, n = list(map(int, raw_input().split()))
    print "Case #%d: %f"%(i+1, e(c, n))
