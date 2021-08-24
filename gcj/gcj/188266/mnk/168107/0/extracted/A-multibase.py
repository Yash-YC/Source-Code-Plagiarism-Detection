#!/usr/bin/env python

import sys

infile = open(sys.argv[1], 'r')
outfile = open("%s.out" % sys.argv[1], 'w')

tests = int(infile.readline().strip())

MAX = 100000

HAPPY   = 1
SAD     = -1
UNKNOWN = 0

happy = {}
for i in range(2,11):
  happy[i] = {}
  for j in range(2,MAX):
    happy[i][j] = UNKNOWN

# for i in range(2,MAX):
#   happy[2][i] = HAPPY

def tokenize(i):
  res = []
  while(i > 0):
    res.append(i % 10)
    i /= 10
  return res

## tobase code from: http://myphotoblogbeta.blogspot.com/2007/07/python-convert-to-and-from-base-b.html
def tobase(base,number):
  global tb
  def tb(b,n,result=''):
    if n == 0: return result
    else: return tb(b,n/b,str(n%b)+result)
  if type(base) != type(1):
    raise TypeError, 'invalid base for tobase()'
  if base <= 0:
    raise ValueError, 'invalid base for tobase(): %s' % base
  if type(number) != type(1) and type(number) != type(1L):
    raise TypeError, 'tobase() of non-integer'
  if number == 0:
    return '0'
  if number > 0:
    return tb(base, number)
  if number < 0:
    return '-' + tb(base, -1*number)

def is_happy(i, base):
   if(happy[base][i] == UNKNOWN):
     # need to find out if this is a happy val
     seen = [i]
     item = int(tobase(base, i))
     while True:
       # print "Testing Item: %d" % item
       # sum_square in base 10
       res = sum_squares(item)
       # print "Sum Squares: %s" % res
       if res == 1:
          for val in seen:
             happy[base][val] = HAPPY
          return True
       if res in seen:
          # looped back to start, not a happy value
          for val in seen:
             happy[base][val] = SAD
          return False
       seen.append(res)
       item = int(tobase(base, res))
   else:
     return happy[base][i] == HAPPY
  
def smallest_happy(base):
   for i in range(2,MAX):
     if is_happy(i, base):
        print "smalled for base: %d = %d" % (base, i)
        return i

def square(x): 
  res = x * x
  # print "square(%d): %d" % (x, res)
  return res

def add(x,y): return x + y

def sum_squares(n):
  """break n into its digits and sum their squares"""
  # print "Sum_Squares(%d)" % n
  vals = tokenize(n)
  sqs = []
  sum = 0
  # print "   sqs: " % sqs
  # print "   vals: %s" % vals
  for v in vals:
     sum += square(v)
  # sqs = map(square, vals)
  # print "   sqs: " % sqs
  # res = reduce(add, sqs)
  # print "   res: " % res
  # return res
  # print "   sum: %d" % sum
  return sum

def all_happy(bases_list, val):
  for base in bases_list:
    if not is_happy(val, base):
      return False
  return True

case = 1
for line in infile:
  bases = map(int, line.split())
  val = 2
  found = False
  while(not found and val < MAX):
    if all_happy(bases, val):
      print "Case #%d: %d" % (case, val)
      outfile.write("Case #%d: %d\n" % (case, val))
      case += 1
      found = True
    else:
      val += 1

# for base in range(2,11):
#   for val in range(2,MAX):
#     is_happy(val, base)

# is_happy(2,3)
# print happy[3]
# smallest_happy(3)
# smallest_happy(4)
# smallest_happy(5)
# smallest_happy(6)
# smallest_happy(7)
# smallest_happy(8)
# smallest_happy(9)
# smallest_happy(10)

  # Starting from high base, find first happy val, check if happy in
  # all other bases, repeat till a happy is found everywhere
