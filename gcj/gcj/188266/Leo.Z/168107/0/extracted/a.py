#! /usr/bin/python

import sys

f = file(sys.argv[1])

line = f.readline()


def baseN(num, b):
  return ((num == 0) and  "0" ) or ( baseN(num // b, b).lstrip("0") + "0123456789abcdefghijklmnopqrstuvwxyz"[num % b])

def lucky( n, base ):
    #print n, base
    tmp = n
    for count in range(20):
        sum = 0
        for x in baseN(tmp, base):
            x1 = int(x)
            sum += x1 * x1
        if sum == 1:
            return True
        else:
            tmp = int(baseN(sum, base), base)

    return False

fo = file("out.a", "w")
for j in range( int(line) ):
    bases = f.readline().split()
    b2 = [ int(x) for x in bases ]
    #print b2
    i = 2
    while i > 1:
        ok = True
        for b in b2:
            if not lucky( i, b):
                ok = False
                break
        if ok:
            #print i
            fo.write("Case #%d: %d\n" % (j+1, i ) )
            break
        i += 1

f.close()
fo.close()
