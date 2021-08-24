def conv_base(n,b):
    out=[]
    while True:
        n,r=divmod(n,b)
        out.append(r)
        if n==0:
            out.reverse()
            return "".join(map(str,out))


def ch_happy(n,b):
    digs=list(str(n))
    sum=0
    for i in digs:
        i=int(i)**2
        sum+=int(conv_base(i,b),b)
    return conv_base(sum,b)

def c(n,b):
    got=[]
    while True:
        n=ch_happy(n,b)
        if n in got:
            return False
        got.append(n)
        if int(n,b)==1:
            return True

t=int(raw_input())
for x in xrange(t):
    bases=raw_input().split()
    y=2
    while True:
        ok=True
        for b in bases:
            b=int(b)
            if c(conv_base(y,b),b)==False:
                ok=False
                break
        if ok==True:
            ret=y
            break
        y+=1
    print "Case #%i: %i"%(x+1,ret)
