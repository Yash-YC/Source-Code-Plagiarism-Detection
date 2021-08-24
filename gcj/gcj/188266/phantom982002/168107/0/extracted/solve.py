def ss(x,b):
    t=0
    while x > 0: 
        t += (x%b)**2
        x = x/b
    return t
        
t=input()
for x in xrange(0,t):
    bs=map(int,raw_input().split(" "))
    c = 1; q = p = True
    while q:        
        c+=1; z={}; p=True; oc=0
        for b in bs: z[b] = {'_':c}
        while p:
            for b in bs:
                g=z[b]['_']
                if g != 1:
                    g=ss(g,b)
                    z[b]['_'] =g
                    if g == 1: 
                        oc += 1
                        if oc == len(bs): 
                            q=p=False; break
                    if g in z[b]:
                        p=False; break
                    z[b][g]=1
    print "Case #%d: %d" %(x+1, c)

