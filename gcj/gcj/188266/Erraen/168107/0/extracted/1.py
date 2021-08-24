import sys
from gmpy import digits,mpz
input=sys.stdin

def p(n,base=10):
    #print n,base,type(n)
    #print [x for x in n]
    k=sum([int(x)**2 for x in n])
    #print digits(k,base)
    return digits(k,base)


def ishappy(n,base=10):
    P={}
    l=digits(n,base)
    #print l
    while True:
        if int(l)==1:
            return True
        if str(l) in P:
            return False
        P[str(l)]=1
        l=p(l,base)


#print mpz('10',base=7)
#print ishappy(8,8)
#print ishappy(143,2)
#print ishappy(82,3)
#sys.exit()
T=int(input.readline())
for i in xrange(1,T+1):
    bases=map(int,input.readline().split())
    n=1
    #print bases
    while True:
        n+=1
        #print n
        cont=False
        for base in bases:
            if not ishappy(n,base):
                #print n,base
                cont=True
                break
        if cont:
            continue
        print "Case #%s: %s" % (i,n)
        break
    #k=p()
    #print bases

