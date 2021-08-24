T=int(raw_input())
def strc(input, base):
    tmp=[]
    while input>=base:
        tmp.append(str(input%base))
        input/=base
    tmp.append(str(input))
    tmp.reverse()
    return ''.join(tmp)

def ishappy(num,base,chain,tf):
    #num always 10 base
    tmp=strc(num,base)
    #print tmp
    result=0
    for i in range(len(tmp)):
        result+=int(tmp[i])**2
    res=strc(result,base)

    if int(res)==1:
        return 'Find'
    elif result in chain:
        return 'Not'
    else:
        chain.append(result)
        tt=ishappy(result,base,chain,'Finding')
        if tt=='Find':
            return 'Find'
        elif tt=='Not':
            return 'Not'
        
for line in range(T):

    s=raw_input().split(' ')
    b=[]
    for i in s:
        b.append(int(i))
    found=True
    i=2
    #print strc(4,2)
    #print ishappy(3,2,[3],'Finding')
    
    while found:
        t=True
        for j in b:
            if ishappy(i,j,[i],'Finding')!='Find':
                t=False
                continue
        if t:
            print "Case #%d: %s"%(line+1,i)
            found=False
        else:
            i+=1
    
        
    
    
    

