import sys
m=50000
maxb=11

def ishappy(b,k):
    global happy,child
    l=[]
    while 1:
        #print k,k==1,k in l,l
        if k==1 or happy[b][k]:
            for i in l: happy[b][i]=True
            return True
        if k in l: return False
        l.append(k)
        child[b][k]=sq(b,k)
        k=sq(b,k)

def sq(b,k):
    #allb=[b**i for i in xrange(maxd)]
    s=0
    while 1:
        if k>0:
            d=k%b
            s+=d*d
            k=k/b
        else:
            break
    return s
    #digits=[(k/allb[i])%b for i in xrange(maxd)]
    #sum(d*d for d in digits)

#print sq(100,10)
happy=[[False for i in xrange(m)] for j in xrange(maxb)]
child=[[None for i in xrange(m)] for j in xrange(maxb)]
for b in xrange(2,maxb):
    for k in xrange(2,m):
        if not happy[b][k]: happy[b][k]=ishappy(b,k)


#for x in happy:
#    print x
#print sq(2,sq(2,3))
#print ishappy(2,3)
hap=[None]*m
for k in xrange(2,m):
    #if sum(happy[b][k] for b in xrange(2,maxb))>2: print k,sum(happy[b][k] for b in xrange(2,maxb)),[b for b in xrange(2,maxb) if happy[b][k]]
    hap[k]=[b for b in xrange(2,maxb) if happy[b][k]]
    #if happy[7][k]: print k,sum(happy[b][k] for b in xrange(2,maxb)),[b for b in xrange(2,maxb) if happy[b][k]]

    #if all(happy[b][k] for b in xrange(2,maxb)):
    #    print "found",k
    #    break

#print hap
allmins={}
for i in xrange(2,maxb):
    for j in xrange(2,i):
        allmins[(j,i)]=min(k for k in xrange(m) if hap[k] is not None if (i in hap[k] and j in hap[k]))

for i in xrange(2,maxb):
    for j in xrange(2,i):
        for l in xrange(2,j):
            print l,j,i
            allmins[(l,j,i)]=min(k for k in xrange(m) if hap[k] is not None if (i in hap[k] and j in hap[k] and l in hap[k]))
        #print i,j,min(k for k in xrange(m) if hap[k] is not None if (i in hap[k] and j in hap[k]))

f=open("data","w")
print >>f,allmins
f.close()
