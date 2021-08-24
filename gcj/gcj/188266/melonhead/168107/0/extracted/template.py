#!/usr/bin/python

import sys
import getopt
import re

default_input = """3
2 3
2 3 7
9 10"""

class memoized(object):
   """Decorator that caches a function's return value each time it is called.
   If called later with the same arguments, the cached value is returned, and
   not re-evaluated.
   """
   def __init__(self, func):
      self.func = func
      self.cache = {}
   def __call__(self, *args):
      try:
         return self.cache[args]
      except KeyError:
         self.cache[args] = value = self.func(*args)
         return value
      except TypeError:
         # uncachable -- for instance, passing a list as an argument.
         # Better to not cache than to blow up entirely.
         return self.func(*args)
   def __repr__(self):
      """Return the function's docstring."""
      return self.func.__doc__

@memoized
def base10toN(num,n):
    """Change a  to a base-n number.
    Up to base-36 is supported without special notation."""
    num_rep={10:'a',
         11:'b',
         12:'c',
         13:'d',
         14:'e',
         15:'f',
         16:'g',
         17:'h',
         18:'i',
         19:'j',
         20:'k',
         21:'l',
         22:'m',
         23:'n',
         24:'o',
         25:'p',
         26:'q',
         27:'r',
         28:'s',
         29:'t',
         30:'u',
         31:'v',
         32:'w',
         33:'x',
         34:'y',
         35:'z'}
    new_num_string=''
    current=num
    while current!=0:
        remainder=current%n
        if 36>remainder>9:
            remainder_string=num_rep[remainder]
        elif remainder>=36:
            remainder_string='('+str(remainder)+')'
        else:
            remainder_string=str(remainder)
        new_num_string=remainder_string+new_num_string
        current=current/n
    return new_num_string

@memoized
def get_sum_squares(base, num):
  s = base10toN(num, base)
  sum = 0
  for c in s:
    i = int(c)
    sum += i*i
  return sum

@memoized
def is_happy(base, num):
  d={}
  while True:
    s=get_sum_squares(base, num)
    num=int(s)
    if d.has_key(num): return False
    if (s == 1): return True
    d[num] = True
  
def get_ints(s):
  result = []
  s=s.split()
  for i in s:
    try:
      result.append(int(i))
    except:
      pass
  return tuple(result)

def get_happiest(args):
  i = 2
  while True:
    success = True
    current_base_index = 0
    while success and current_base_index < len(args):
      success = success and is_happy(args[current_base_index], i)
      current_base_index += 1
    if success: break
    i += 1
  return i
  

def process_input(input):
  num_inputs = int(input[0])
  input = input[1:]
  for i in xrange(num_inputs):
    happiest = get_happiest(get_ints(input[i]))
    print "Case #%d: %d" % (i+1,happiest)
  return
      
def main(argv=None):
  if argv is None:
    argv = sys.argv
  if len(argv) == 1:
    input = default_input.split("\n")
  else:
    f=open(argv[1])
    input = f.read().split("\n")
    f.close()
  process_input(input)
  return 0

if __name__ == "__main__":
  sys.exit(main())
  