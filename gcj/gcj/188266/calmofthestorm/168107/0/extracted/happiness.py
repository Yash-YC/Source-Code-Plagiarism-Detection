#!/usr/bin/python

# Solution to happiness problem
# Google Code Jam, 2009 Round 1A
# Alex Roper <alexr@ugcs.caltech.edu>
# California Institute of Technology

# Straightforward DP.

import sys, re, gmpy

def read_tokens(f):
  for line in f:
    yield line

def solve(reader):
  bases = map(int, reader().split())
  dtable = [[False] * 10 for _ in range(100)]

  def hapval(n, b, path = []):
    if n in path: return False
    elif n == 1: return True
    else:
      return hapval(sum([int(i) ** 2 for i in gmpy.digits(n, b)]), b, path + [n])

#  def hapval(n, b, path = []):
#    if n in path: return False
#    if len(dtable) <= n:
#      dtable.extend([[None] * 10 for _ in  range(len(dtable))])
#    if dtable[n][b] != None: return dtable[n][b]
#    else:
#      ans = sum([hapval(int(i) ** 2, b) for i in gmpy.digits(n, b)])
#      rep = gmpy.digits(ans, b)
#      if len(rep) > 1:
#        ans = hapval(ans, b, path + [n])
#      dtable[n][b] = (ans == 1 or ans == True)
#      return dtable[n][b]

  i = 2
  while 1:
    if all([hapval(i, b) for b in bases]): return i
    else: i += 1

def main():
  reader = read_tokens(open(sys.argv[1])).next
  cases = int(reader())

  for c in range(cases):
    print "Case #%i: %i" % (c + 1, solve(reader))

if __name__ == "__main__": main()
