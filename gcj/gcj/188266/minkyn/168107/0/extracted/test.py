def ishappy(num, base, ss):
    if num == 0:
        return False
    elif num == 1:
        return True
    elif num in ss:
        return False
    else:
        t = 0
        nt = num
        while nt > 0:
            a = nt % base
            t += a * a
            nt = nt // base
        if t > num ** 2:
            return False
        else:
            ss.add(num)
            return ishappy(t, base, ss)

def solve(bases):
    n = 2
    while True:
        for base in bases:
            if not ishappy(n, int(base), set()):
                break
        else:
            return n
        n += 1

with open('A-small-attempt0.in') as file:
    t = int(file.readline().strip())
    for i in range(t):
        res = solve(file.readline().split())
        print('Case #{0}: {1}\n'.format(i + 1, res))