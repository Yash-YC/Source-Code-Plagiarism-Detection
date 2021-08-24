#!/usr/bin/python

import sys
import math


def BN(num,n):
    b=''
    c=num
    while c!=0:
        r=c%n
        r_string=str(r)
        b=r_string+b
        c= c / n
    return b

def happy(n, base):
  #print n, base
  sum = 0
  seen = set([n])
  while n != 1:
    sum = 0
    for d in BN(n, base):
      #print d,
      d = int(d)
      sum += d * d
    #print 'sum:', sum
    n = sum
    if n in seen:
      #print 'n seen', n
      break
    seen.add(n)
  return n == 1

def solve(b):
  n = 2
  while True:
    bad = False
    for i in b:
      if not happy(n, i):
        bad = True
        break
    if not bad:
      return n
    n += 1

if __name__ == '__main__':
  if len(sys.argv) != 2:
     print ('Usage: %s file' % sys.argv[0])
     sys.exit(1)

  f = open(sys.argv[1])
  NTEST =  int(f.readline())
  for i in xrange(NTEST):
    print ('Case #%d:' % (i + 1)),
    print solve(map(int, f.readline().strip().split()))
