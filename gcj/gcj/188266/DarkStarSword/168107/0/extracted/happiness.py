#!/usr/bin/env python

#Generic libraries for the framework:
import sys
import os

#Any libraries used specifically for this problem:

def convertBase(i,b):
  ret = ''
  while i:
    r = i % b
    ret = str(r) + ret
    i /= b
  return ret

happy = {}

def isHappy(i, b):
  prev = happy.get((i,b))
  if prev != None:
    #print 'Checking if %i is happy in %i' % (i,b)
    #print 'returning previous result'
    return prev
  happy[(i,b)] = 0
  s = 0
  c = convertBase(i,b)
  #print 'Checking if %i (%s) is happy in %i' % (i,c,b)
  for d in c:
    s += int(d)**2
  if s > 1:
    if isHappy(s, b):
      happy[(i,b)] = 1
    else:
      return 0
  if s == 1:
    happy[(i,b)] = 1
  return s

def solve(input, output):
  T = int(input.next().strip())
  for t in range(1,T+1):
    B = map(int, input.next().split())
    i = 1
    happy = 0
    while not happy:
      happy = 1
      i += 1
      for b in B:
        happy = isHappy(i, b)
        if not happy: break

    output.write('Case #%d: %d\n' % (t, i))
    output.flush()

def genlines(file):
  """
  Generator to read a file stripping excessive
  whitespace and only returning non empty lines
  """
  for line in file:
    line = ' '.join(line.split())
    if (line != ''):
      yield line

def checkresult(result, check):
  """
  Compare result to a provided answer ignoring
  excessive whitespace and empty lines
  """
  resultlines = genlines(result)
  checklines  = genlines(check)
  for rline in resultlines:
    try:
      cline = checklines.next()
    except:
      print ">>> Result too large, this line was extra:"
      print "   ", rline
      break
    if rline != cline:
      print "X!     result:", rline
      print " !> should be:", cline
  try:
    cline = checklines.next()
    print "<<< Result too small, missing this line:"
    print "   ", cline
  except: pass

def usage():
  print sys.argv[0] + " in out [test]"

def main():
  """
  Framework for processing and
  checking Google's Code Jam problems
  """
  if not 2 < len(sys.argv) < 5:
    usage()
    return
  checkanswer = len(sys.argv) == 4

  if os.path.exists(sys.argv[2]):
    print sys.argv[2] + " exists, overwrite?"
    if sys.stdin.readline().strip().lower()[0] != 'y':
      return

  input  = open(sys.argv[1], 'rb')
  output = open(sys.argv[2], 'wb')
  if checkanswer:
    check = open(sys.argv[3], 'rb')

  solve(input, output)

  if checkanswer:
    print "Checking result..."
    output.close()
    output = open(sys.argv[2], 'rb')
    checkresult(output, check)
    print "Done"
  else:
    print "Not checking result"

if __name__ == '__main__':
  main();
