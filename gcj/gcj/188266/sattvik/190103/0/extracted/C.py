#!/usr/bin/env python
T = int(raw_input())
for i in range(T):
  vals = raw_input()
  vals = vals.split(' ')
  C = int(vals[0]) + 1.0 - 1.0
  N = int(vals[1]) + 1.0 - 1.0
  result = (C+N) / N
  print "Case #%d: %0.07f" % (i+1, result)
