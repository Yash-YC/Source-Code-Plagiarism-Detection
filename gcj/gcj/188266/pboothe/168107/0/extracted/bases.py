#!/usr/bin/env python

def tobase(n,base):
    answer = ""
    while n > 0:
        d = n % base
        answer = str(d) + answer
        n //= base
    return answer

def next(n, base):
    number = tobase(n,base)
    return sum(int(x) ** 2 for x in number)

known = {}
def happy(n, base):
    #print "happy(", n, base, ")"
    if n == 1:
        known[n,base] = True
        return True

    if (n,base) in known:
        return known[n,base]
    else:
        known[n,base] = False
        known[n,base] = happy(next(n, base), base)
        return known[n,base]
    

count = int(raw_input())
for i in range(count):
    bases = map(int, raw_input().split())
    
    found = False
    n = 2
    while not found:
        for b in bases:
            if not happy(n, b):
                #print n, "is not happy in", b
                n += 1 
                break
        else:
            found = True

    print "Case #%d:" % (i+1), n
