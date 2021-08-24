#!/usr/bin/python
# Python 2.6

import sys
from util import FileReader


def tobase(number, base):

    result = ''
    while number:
        number, i = divmod(number, base)
        result = str(i) + result

    return result or '0'


def isroots(digits):
    n = len(digits)
    if digits.count('1') == 1 and digits.count('0') == n - 1:
        return True
    return False


def happy(number, base):

    num = tobase(number, base)
    seen = set()

    while True:
        if isroots(num):
            return True

        seen.add(num)

        digits = [int(i) for i in num]
        value = sum(i * i for i in digits)
        num = tobase(value, base)

        if num in seen:
            return False



def main():

    if len(sys.argv) < 2:
        print "usage: {0} <input-file>".format(__file__)
        sys.exit(-1)

    with open(sys.argv[1]) as _file:
        file = FileReader(_file)

        T = file.int()
        for t in xrange(T):

            bases = file.ints()
            k = 2

            while True:

                if all(happy(k, i) for i in bases):
                    break

                k += 1

            print "Case #{0}: {1}".format(t + 1, k)


if __name__ == "__main__":
    main()

