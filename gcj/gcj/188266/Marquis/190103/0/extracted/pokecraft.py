#!/usr/bin/python

t = int(raw_input())

for i in range(0, t):
    c,n = map(int, raw_input().split())
    x = 0.0
    y = 1.0
    z = 1.0

    j = 2
    while z > 10**-12:
        z = (y*n/c)
        x += z*j
        j += 1
        y -= z

    print "Case #"+str(i+1)+":","%.7f"%x
         