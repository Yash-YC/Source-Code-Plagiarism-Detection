#!/usr/bin/env python
import sys

def main():
  T = int(sys.stdin.readline().strip())
  for case in range(1, T + 1):
    bases = map(int, sys.stdin.readline().strip().split(' '))
    K = 2
    while (1):
      count = 0
      for b in bases:
        if ishappy(K, b):
          count += 1
      if count == len(bases):
        break
      K += 1
    print 'Case #' + str(case) + ':', K


  
def ishappy(num, base):
  nums = set()
  nums.add(num)
  while (num != 1):
    num_list = base10toN(num, base)
    num = sum(map(lambda x:x * x, num_list))
    if num in nums:
      return False
    else:
      nums.add(num)
  return True
    

def base10toN(num,n):
  num_list = []

  current = num
  
  while current != 0:
    remainder = current % n

    num_list.insert(0, remainder)

    current = current / n

  return num_list


if __name__ == '__main__':
  main()
