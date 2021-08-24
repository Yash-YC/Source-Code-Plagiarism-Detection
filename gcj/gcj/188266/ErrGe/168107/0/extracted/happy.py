#!/usr/bin/python

from sys import stdin, stdout, stderr
from collections import defaultdict

def read_int(strLine):
    return map(int,
               strLine.split(' '))

def read_string(strLine):
    return strLine.split(' ')

def read_float(strLine):
    return map(float,
               strLine.split(' '))

def rsreadline():
    return stdin.readline().rstrip('\r\n')

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

happydict = defaultdict(lambda: -1)

def happy(base, num):
    if base == 2 or base == 4:
        return 2
    if num == 1:
        return 2
    if happydict[(base, num)] == 1:
        happydict[(base, num)] = 0
        return 0
    if happydict[(base, num)] == 2:
        return 2
    if happydict[(base, num)] == 0:
        return 0

    sum = 0
    for c in base10toN(num, base):
        sum += int(c)**2
    happydict[(base, num)] = 1
    happydict[(base, num)] = happy(base, sum)
    return happydict[(base, num)]

def main():
    cCase = int(rsreadline())
    for iCase in range(0, cCase):
        bases = read_int(rsreadline())
        i = 2
        while True:
            hap = True
            for b in bases:
                hap = hap and (happy(b, i) == 2)
                if not hap: break
            if hap: break
            i += 1
        print 'Case #%d: %d' % (iCase + 1, i)
        stdout.flush()

main()
