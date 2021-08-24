from sys import stdin
from sys import stdout

def transform(n, base):
    s = 0
    while n > 0:
        s += (n % base) ** 2
        n /= base
    return s

def compute_happy(n, base, hist, h):
    if n not in h:
        s = transform(n, base)
        if s in hist:
            h[n] = False
        else:
            hist.append(s)
            h[n] = compute_happy(s, base, hist, h)
    return h[n]

MAX = 9 ** 2 * 10
H = {}
for base in xrange(2, 11):
    h = {1: True}
    for n in xrange(2, MAX + 1):
        compute_happy(n, base, [n], h)
    H[base] = h

def is_happy(n, base):
    if n not in H[base]:
        n = transform(n, base)
    return H[base][n]

T = int(stdin.readline().strip())
for i in xrange(1, T + 1):
    parts = stdin.readline().split()
    bases = [int(part) for part in parts]
    n = 2
    while True:
        if all(is_happy(n, base) for base in bases):
            break
        n += 1
    stdout.write('Case #%d: %d\n' % (i, n))
