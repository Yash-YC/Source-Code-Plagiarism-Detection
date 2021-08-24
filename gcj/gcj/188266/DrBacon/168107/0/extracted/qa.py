#!/usr/bin/python

import os
import sys
import math

def read_input_NN(fn =""):
  fh = open(fn, "r")
  lines = map(lambda x: x.strip(), fh.readlines())
  fh.close()
  goog_N = map(int, lines[0].split())[0]
  l_dict = map(lambda x: map(int,x.split()), lines[1:])
  return(l_dict)

def sum_square(str1="123"):
  sum1 = 0
  for i in str1:
    sum1 += int(i)*int(i)
  return(sum1)

def tobase(base,number):
    global tb
    #http://myphotoblogbeta.blogspot.com/2007/07/python-convert-to-and-from-base-b.html
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

def determine_happy(base1 = 10,num1 = "83"):
  last_num="0"
  d_found = {}
  num1 = tobase(base1,int(num1))
  #print num1
  while(num1!="1"):
    num1 = tobase(base1,sum_square(num1))
    #print num1
    if last_num == num1:
      break
    if num1 == "1":
      break
    last_num = num1
    if num1 in d_found.keys():
      break
    d_found[num1]=1
  if num1 == "1":
    return(1)
  return(0)

def find_smallest(l2=[1,2,3]):
  i_c=1
  l2 = filter(lambda x: x!=2, l2)
  if len(l2) == 0:
    return(1)
  for i in xrange(2,1000000):
    #print i
    #print l2
    i_c=i
    i_s = str(i)
    is_happy = map(lambda x: determine_happy(x,str(i)),l2)
    #print is_happy
    prod = 1
    for j in is_happy:
      prod *= j
    if prod == 1:
      break
  return(i_c)

def qa(fn="sample"):
  l1 = read_input_NN(fn)
  #print l1
  return(l1)

l1 = qa(fn="A-small-attempt.in.txt")
#l1 = qa(fn="a_test.txt")
fh = open("out.txt","w")
for (ctr,sol) in enumerate(l1):
  print >> fh, "Case #"+str(ctr+1)+": "+str(find_smallest(sol))
  #print find_smallest(sol)

#fh.close()
