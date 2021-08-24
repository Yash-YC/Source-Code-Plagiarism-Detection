t=int(raw_input())
for i in xrange(t):
    s=raw_input()
    l=[]
    for j in s:
        if len(l)==0:
            l.append(j)
        else:
            if(l[0]<=j):
                l=[j]+l
            else:
                l.append(j)
    print "Case #"+str(i+1)+": "+''.join(l)
