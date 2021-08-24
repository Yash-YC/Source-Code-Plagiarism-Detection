#!/usr/bin/python

def get_digits(n, base):
    while n:
        yield n % base
        n = n / base

def is_happy(n, base):
    seen = set([n])
    
    while 1:
        new = 0
        for i in get_digits(n, base):
            new += i*i
            
        # print new
        n = new
        if n in seen: return False
        if n == 1: return True
        seen.add(n)

t = int(raw_input())

for i in range(0, t):
    bases = map(int, raw_input().split())
    n = 2
    done = False
    while not done:
        yes_in_all = True
        for base in bases:
            if not is_happy(n, base):
                yes_in_all = False
                break
        if yes_in_all:
            print "Case #"+str(i+1)+":",n
            done = True
        n += 1
         