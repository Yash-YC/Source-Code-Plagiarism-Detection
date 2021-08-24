def readint(): return int(raw_input())
def readfloat(): return float(raw_input())
def readarray(N, foo):
        res = []
        for _ in xrange(N):
                res.append(foo())
        return res
def readlinearray(foo): return map(foo, raw_input().split())


def get_number_at_base(n, base):
    
    result = []
    
    nn = n
    while(nn != 0):
        result.append(nn % base)
        nn = nn / base
    return result

def get_base10_number_at_base(n, base):
    r = 0
    pow = 0
    for i in xrange(len(n)):
        r += n[i] * base ** pow
        pow += 1
    
    return r

def sum_(n1, n2, base):
    
    if len(n1) > len(n2):
        for _ in xrange(len(n1) - len(n2)):
            n2.append(0)
    elif len(n1) < len(n2):
        for _ in xrange(len(n2) - len(n1)):
            n1.append(0)
    
    assert len(n1) == len(n2)
    
    summ = []
    next = 0
    
    for index in xrange(len(n1)):
        temp = n1[index] + n2[index] + next
        summ.append(temp % base)
        next = temp / base
    
    if(next != 0):
        summ.append(next)
    
    return summ

def sum_n_times(n, times, base):
    result = n
    for _ in xrange(times - 1):
        result = sum_(result, n, base)
    
    return result

def is_happy(n, base):
    
    sofar = set()
    while True:
        
        summ = [0]
        for digit in n:
            summ_up = get_number_at_base(digit * digit, base)
            summ = sum_(summ, summ_up, base)
        n = summ
        n10 = get_base10_number_at_base(n, base)
        if n10 in sofar:
            break
        else:
            sofar.add(n10)
        
    return n10 == 1

if __name__ == '__main__':
    T = readint()
    
    for case in xrange(1, T+1):
        
        bases = readlinearray(int)
        
        ans = 2
        while True:
            got = True
            for base in bases:
                got &= is_happy(get_number_at_base(ans, base), base)
            if got:
                break
            ans += 1
        print 'Case #%d: %d' % (case, ans)
        
        