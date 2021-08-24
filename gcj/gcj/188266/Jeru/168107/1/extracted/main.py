import sys

if sys.argv[1:]:
    sys.stdin = open(sys.argv[1] + '.in')
    sys.stdout = open(sys.argv[1] + '.out', 'w')

d = open('a2.bin')
d.readline()
P = [map(int, line.split()) for line in d.xreadlines()]

def solve(d):
    for v, m in P:
        if (m | d) == m:
            return v;
    return None

ccc = int(sys.stdin.readline())
for cc in range(1, ccc + 1):
    d = 0
    for x in sys.stdin.readline().split():
        d |= 1 << int(x)
    print "Case #%d: %d" % (cc, solve(d))
