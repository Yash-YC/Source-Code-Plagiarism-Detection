def getbase(n, base):
    ret=[]
    while (True):
        if (n<base):
            ret.append(n)
            break
        r=n%base
        n=n/base
        ret.append(r)
    ret.reverse()
    return ret

def check(num, baselist):

    for e in baselist:
        circle=[]
        sqrsum=num 
        while (True):
            k=getbase(sqrsum,e)
            sqrsum=sum([w**2 for w in k])
            #print sqrsum
            if sqrsum ==1:
                #print "abc"
                break
            elif not sqrsum in circle:
                circle.append(sqrsum)
            else:
                return False
    return True
                
       
casenum=int(raw_input())
for caseid in xrange(casenum):
    baselist=[int(e) for e in raw_input().split()]
    for i in xrange(2,200000):
        if check(i, baselist):
            print "Case #%d: %d" % (caseid+1, i)
            break

#print check(3, [2])
#print getbase(3,2)
#print getbase( 4, 2)
