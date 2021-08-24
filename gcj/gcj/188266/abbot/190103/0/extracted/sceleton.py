#!/usr/bin/python
# -*- encoding: utf-8 -*-

import sys
import math
#import psyco

def readnumbers(f, dtype=int):
    return [dtype(x) for x in f.readline().strip().split()]

factorials = {}
fact = 1
for n in range(2, 41):
    fact = fact * n
    factorials[n] = fact

def factorial(n):
    global factorials
    if n in factorials:
        return factorials[n]
    return 1

def combinations(n, k):
    return factorial(n) / factorial(k) / factorial(n-k)

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
        C, N = readnumbers(self.dataset_stream)
        self.C = C
        self.N = N
    
    def printcase(self):
        #print "C:", self.C, "N:", self.N
        pass
    
    def solve(self):
        C, N = self.C, self.N
        P = combinations(C, N)
        x = float(P)/float(N)
        Q = combinations(C-1, N-1)
        print "C:", C, "N:", N, "P:", P, "Q:", Q
        sol = 1.0 + float((C-N)*P)/float(N)
        #if C>N:
        #    sol = 1.0 + float(P)/float(C-N)
        #else:
        #    sol = 1.0
        self.solution = "%.11f" % sol
        
    def printsolution(self):
        sys.stdout.flush()
        print >>sys.stderr, "Case #%d: %s" % (self.caseno, str(self.solution))
        sys.stderr.flush()

if __name__ == '__main__':
    #psyco.full()
    filename = sys.argv[1]
    s = Solution()
    s.main(filename)
