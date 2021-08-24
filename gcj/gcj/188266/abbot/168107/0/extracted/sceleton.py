#!/usr/bin/python
# -*- encoding: utf-8 -*-

import sys
import math
import psyco

def readnumbers(f, dtype=int):
    return [dtype(x) for x in f.readline().strip().split()]

def happy(number, base=10, seen=None):
    if seen is None:
        seen = []
    digits = []
    while number > 0:
        digit = number % base
        digits.append(digit*digit)
        number = (number - digit) / base

    #print number, digits
    s = reduce(lambda a, b: a+b, digits)
    #print s
    if s == 1:
        #print "found it"
        return True
    if s in seen:
        return False
    if s > 0:
        return happy(s, base, seen + [s])

class Solution:
    def main(self, filename):
        self.dataset_stream = open(filename, 'r')
        line = self.dataset_stream.readline()
        self.cases_left = int(line)
        print "File contains %d testcases." % (self.cases_left)

        self.caseno = 1
        while self.cases_left > 0:
            self.cases_left -= 1
            self.readcase()
            self.printcase()
            self.solve()
            self.printsolution()
            self.caseno += 1

    def readcase(self):
        self.bases = readnumbers(self.dataset_stream)
    
    def printcase(self):
        #print "bases:", self.bases
        pass
    
    def solve(self):
        max_base = max(self.bases)
        n = 3
        while True:
            all_happy = True
            for base in self.bases:
                if not happy(n, base):
                    all_happy = False
                    break
            if all_happy:
                self.solution = n
                return
            n += 1
            if n % 1000 == 0:
                #print n
                pass
        
    def printsolution(self):
        sys.stdout.flush()
        print >>sys.stderr, "Case #%d: %d" % (self.caseno, self.solution)
        sys.stderr.flush()

if __name__ == '__main__':
    psyco.full()
    filename = sys.argv[1]
    s = Solution()
    s.main(filename)
