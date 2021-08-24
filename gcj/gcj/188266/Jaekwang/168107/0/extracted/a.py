#!/usr/bin/python
import sys
import copy
import math

szfile = './A-small-attempt1.in'
szfile_output = './A-small.output.txt'
##szfile = './A-large-practice.in.txt'
##szfile_output = './A-large.output.txt'

NRANGE = 100000
class GCJ:
    def __init__(self):
        pass

    def RunFile(self) :
# using file set
        f = open(szfile,'rb')
        fw = open(szfile_output,'wb')
# ---
        szline = f.readline()
        ncase = int(szline)
        l_output = []

        self.D = [ [-1] * NRANGE for i in xrange(11) ]
        for i in xrange(2, 11): self.D[i][1] = 1
        self.U = [ [False] * NRANGE for i in xrange(11) ]

        self.SetData()
##        sys.exit(0)

        for i in xrange(0, ncase):
            l_tag = f.readline().split()
            l_data = []
            for x in l_tag:
                l_data.append(int(x))
            val = self.GetNumber(l_data)
            num = i+1
            l_output.append('Case #%(num)d: %(val)d'%locals())
        print '\n'.join(l_output)
        fw.write('\n'.join(l_output))


    def SetData(self):
        for nbase in xrange(2, 11):
            for i in xrange(1,NRANGE):
                self.Trace(i, nbase)
        for x in xrange(2, 11):
            print x,':',self.D[x][0:20]
            

    def GetNumber(self, l_data):
        ret = 0
        for i in xrange(2,NRANGE):
            bCheck = True
            for x in l_data:
                if(self.D[x][i] < 1):
                    bCheck=False
                    break;
            if(bCheck == True):
                return i
        return -1


    def Trace(self, x, base):
##        print x
        if(x == 1): return 1
        if(self.D[base][x] != -1): return self.D[base][x];
        if(self.U[base][x] == True): return 0
        self.U[base][x] = True
    
        l_t = self.encode(x, base)
        k = 0;
        for v in l_t:
            k += v*v
        ret = self.Trace(k, base)
        self.D[base][x] = ret
        return ret


    def encode(self, decNum, base):
        t = decNum
        l_t = []
        while(t>0):
##            print 'aa', t%base
            l_t.append(t%base)
            t /= base;
        l_t.reverse()
##        l_t = reversed(l_t)

        return l_t


import time
if __name__ == "__main__":
    cm = GCJ()
    cm.RunFile()
##    print cm.GetCount(7, 10, [[1,2], [7,1]])
##    print cm.GetCount(4, 4, [[3,2]])



