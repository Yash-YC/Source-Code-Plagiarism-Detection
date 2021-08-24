#!/usr/bin/python
"Google Round1 - A"

dcache = {}
def digits(n, b):
    key = '%d-%d' % (n, b)
    #print 'digits', key,
    if key in dcache:
        #print dcache[key]
        return dcache[key]
    else:
        d = []
        n2 = n
        while n2:
            d.append(n2 % b)
            n2 = (n2 // b)
        d.reverse()
        #print d
        dcache[key] = d
        return d

cache = {}
def happy(n, b):
    key = '%d-%d' % (n, b)
    #print 'happy', key
    if key in cache:
        #print 'happy', key, cache[key]
        return cache[key]
    else:
        cache[key] = False
    d = digits(n, b)
    h = 0
    for i in d:
        h += i * i
    if h == 1:
        cache[key] = True
        #print 'happy', key, cache[key]
        return True
    elif h == n:
        cache[key] = False
        #print 'happy', key, cache[key]
        return False
    else:
        hr = happy(h, b)
        cache[key] = hr
        #print 'happy', key, cache[key]
        return hr


assert happy(82, 10)
assert not happy(82, 3)
#sys.exit()

cases = int(raw_input())

for case in range(1, cases + 1):
    line = raw_input().strip().split()
    bases = [int(b) for b in line]

    i = 2
    while True:
        success = True
        for b in bases:
            h = happy(i, b)
            if not h:
                success = False
        if success:
            print 'Case #%d: %d' % (case, i)
            break
        i += 1
