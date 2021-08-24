T=int(raw_input())
def   nr(n,   r):
    if   r   ==   0   or   r   ==   n   or   n   ==   0:
        return   1
    return   nr(n-1,   r)   +   nr(n-1,   r-1)

for line in range(T):

    s=raw_input().split(' ')
    n=int(s[0])
    r=int(s[1])
    if n==r:
        result=1
    else:
        result=1.0
        top=nr(n,r)
        for i in range(n-r):
            if top==nr(n,i):
                continue
            
            result+=top/float(top-nr(n,i))
    

    print "Case #%d: %.7f"%(line+1,result)

    
        
    
    
    

