"""
Author: Greg Harfst (gharfst@gmail.com)
Date:   9/11/2009
Notes:

"""

import sys
import re

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

def isHappy(num, base, past):
    baseNum = base10toN(num, base)
    for iter in xrange(100000):
        newNum = sum([int(x)*int(x) for x in baseNum])
        if newNum == 1:
#            print "isHappy!!"
            return True
        elif newNum in past:
#            print "cycle!"
            return False
        else:
            if len(past) > 15:
                past.pop(0)
            past.append(newNum)
            baseNum = base10toN(newNum, base)
    return False

def main():
    input = [l.strip() for l in sys.stdin.readlines()]
    for testNum, testLine in enumerate(input):
#        print "testLine", testLine
        if testNum < 1:
            continue
        bases = map(int, testLine.split())
        guessNum = 2
        while True:
            if all(isHappy(guessNum, base, []) for base in bases):
                break
            else:
#                print "guess", guessNum
                guessNum += 1
        print "Case #%d: %d" % (testNum, guessNum)

if __name__ == "__main__":
    main()
