import sys,re
import string
f=open( sys.argv[1])
N=int(f.readline().strip())
def sds (num ,base):
    r=0
    while num:
        r += pow(num%base,2)
        num /= base
    return r
def happy (num,base):
    seen=set()
    while num != 1:
        if num in seen: return False
        seen.add(num)
        num = sds(num,base)
    return True

for i in xrange(N):
    bases = f.readline().strip().split()
    bases = map (int, bases)
    j=1
    while True:
        j+=1
        good = True
        for k in bases:
            if not happy(j,k):
                good=False
                break
        if good:
            break
                
    print "Case #"+str(i+1)+": "+str(j)


