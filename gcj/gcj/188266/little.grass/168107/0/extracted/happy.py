import sys
def get_repr(n, base):
    assert base <= 10, 'Base is %d' % base
    r = []
    while True:
        quot,rem = divmod(n, base)
        r.append(str(rem))
        if quot == 0:
            break
        else:
            n = quot

    r.reverse()
    return ''.join(r)

def check_happy(base, s, rset=[]):
    n = int(s, base)
    if n == 1:
        return True
    elif n in rset:
        return False
    else:
        tmp = 0
        for i in s:
            tmp = tmp + int(i,10)**2
        rset.append(n)
        return check_happy(base, get_repr(tmp, base),rset)

def find_smallest(line):
    bases = line.split()
    bases = [int(i) for i in bases]
    result = [False for i in bases]
    n = 1
    rset = []
    while True:
        n = n + 1
        for index in range(len(bases)):
            base = bases[index]
            result[index] = check_happy(base, get_repr(n, base),[])
        if all(result):
            return n
