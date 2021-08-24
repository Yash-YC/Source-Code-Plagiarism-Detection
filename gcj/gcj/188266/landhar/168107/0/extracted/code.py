#! /usr/bin/env python
# code.py (@DESC@)
# Maintainer: Matias Larre Borges <matias@larre-borges.com>
# Last Change: 2009 Sep 11

import sys

STOP = {}
STOP[2] = []
STOP[3] = [2, 12, 22]
STOP[4] = []
STOP[5] = [4, 23, 33]
STOP[6] = [32]
STOP[7] = [2, 34, 13, 23, 63, 44]
STOP[8] = [4, 5, 32, 24, 64]
STOP[9] = [55, 58, 45, 75]
STOP[10] = [4]

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

def check_number(num, base):
    if num == 1:
        return True
    if (base == 2) or (base == 4):
        return True
    num_str = str(tobase(base, num))
    while (int(num_str) != 1) and (int(num_str) not in STOP[base]):
        new_num = 0
        for digit in num_str:
            new_num += int(digit) * int(digit)
        num_str = str(tobase(base, new_num))
    if int(num_str) == 1:
        return True
    return False

def main():
    file = open(sys.argv[1])

    nb_cases = int(file.readline())

    for case_nb in range(1, nb_cases + 1):

        bases = [int(x) for x in file.readline().split(' ')]

        i = 2
        while True:
            happy_count = 0
            for base in bases:
                if check_number(i, base) == True:
                    happy_count += 1
            if happy_count == len(bases):
                break
            i += 1

        print "Case #%d: %d" % (case_nb, i)

    file.close()


if __name__ == "__main__":
    main()
