#!/usr/bin/env python
#coding:utf-8
# Author:   --<>
# Purpose: 
# Created: 11/9/2009

import sys

def tb(b,n,result=''):
    if n == 0:
        return result
    else: 
        return tb(b,n/b,str(n%b)+result)


#----------------------------------------------------------------------
def sum_square_digits(n):
    s = 0
    for d in n:
        s += int(d)**2
    return s
        

#----------------------------------------------------------------------
def is_happy_number(b,n):
    """Find happy number"""
    l = []
    x = sum_square_digits(tb(b,n))
    while x not in l:
        l.append(x)
        x = sum_square_digits(tb(b,x))
    return x == 1

#----------------------------------------------------------------------
def main(args):
    """Main"""
    f = open(args[1]).readlines()
    T = f[0]
    t = 1
    out = open(args[1]+'.result','w')
    for line in f[1:]:
        n = 2
        found = False
        while not found:
            found = True
            for base in line.split(' '):
                if not is_happy_number(int(base),n):
                    found = False
                    n += 1
                    break
        out.write('Case #%d: %d\n' % (t,n))
        t += 1
    out.close()
                
if __name__=='__main__':
    main(sys.argv)