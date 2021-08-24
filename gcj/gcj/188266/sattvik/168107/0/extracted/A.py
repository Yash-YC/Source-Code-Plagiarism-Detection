#!/usr/bin/env python
def numSplit(num, base):
  sData = []
  while num > 0:
    sData += [num % base]
    num = int(num/base)
  sData.sort()
  result = 0
  for n in sData:
    result = result * 10 + n
  return result

def checkHappy(num, base):
  global happyNumList
  numList = []
  while True:
    n = num
    numSp = numSplit(num,base)
    numList += [numSp]
    if happyNumList.has_key((numSp,base)):
      return happyNumList[(numSp,base)]
    ss = 0
    while n > 0:
      ss += (n % base)*(n % base)
      n = int(n / base)
    if ss == 1:
      for n in numList:
        happyNumList[(n,base)] = True
      return True
    else:
      ssSp = numSplit(ss, base)
      if ssSp in numList:
        for n in numList:
          happyNumList[(n,base)] = False
        return False
      else:
        num = ss

global happyNumList
happyNumList = {}
N = raw_input()
N = int(N)
for i in range(N):
  vals = raw_input()
  vals = vals.split(' ')
  x=0
  y=2
  while x<len(vals):
    if(checkHappy(y, int(vals[x]))):
       x += 1
    else:
       if x>0:
         x = 0
       y += 1
  print "Case #%d: %d" %(i+1,y)
