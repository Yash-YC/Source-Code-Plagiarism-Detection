def calc(bases):
    n = 2
    while True:
        happy = True
        for base in bases:
            if not is_happy(base, n, set()):
                happy = False
                break
        if happy:
            return n
        n += 1

D = {}

def is_happy(base, n, prev):
    #print 'is_happy(): base=%i, n=%i, prev=%s' % (base, n, prev)
    digits = sorted(get_digits(base, n))
    str_digits = ''.join(str(d) for d in digits)
    if str_digits in prev:
        #print 'in prev, returning False'
        D[base, str_digits] = False
        return False
    if (base, str_digits) in D:
        #print 'in D, returning', D[base, str_digits]
        return D[base, str_digits]
    
    sum_squares = sum(d*d for d in digits)
    #print 'sum_squares =', sum_squares

    if sum_squares == 1:
        res = True
    else:
        prev.add(str_digits)
        res = is_happy(base, sum_squares, prev)

    #print 'res =', res
    D[base, str_digits] = res
    return res

def get_digits(base, n):
    while n > 0:
        yield n % base
        n = n // base

T = input()
for i in xrange(T):
    bases = [int(b) for b in raw_input().split()]
    print "Case #%i: %i" % (i+1, calc(bases))
