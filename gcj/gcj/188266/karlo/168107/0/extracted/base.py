import math

def digit_sum(n):
    sum=0
    while n!=0:
        sum+=(n%10)**2
        n=n/10
    return sum

def sum_base(n,k):
    answer=[]
    while n!=0:
        l= int(math.log(n,k))
        x=k**l
        t=n/x
        n=n-t*x
        answer.append(t)
    return sum([i**2 for i in answer])

def happy(b,n):
    ans=[0]*n
    ans[1]=True
    for i in xrange(2,n):
        if ans[i]==0:
            set_i=set([i])
            x=sum_base(i,b)
            while x>=n:
                    x=sum_base(x,b)
            boo=True
            while ans[x]==0:
                x=sum_base(x,b)
                while x>=n:
                    x=sum_base(x,b)
                if x not in set_i:
                    set_i.add(x)
                else:
                    boo=False
                    break
            if not boo or ans[x]==False:
                for x in set_i:
                    ans[x]=False
            else:
                for x in set_i:
                    ans[x]=True
                
                
        else:
            pass
    S=set()
    for i in xrange(1,n):
        if ans[i]:
            S.add(i)  
    return S

def happ(n,b):
    s=set()
    x=sum_base(n,b)
    while x!=1:
        if x not in s:
            s.add(x)
        else:
            return False
        x=sum_base(n,b)
    return True
    
    
def sol(n,bases):
    pass

def main():
    
    f=open('zzz.in','r')
    outfile = open("test_result.out", 'w')
    lines=f.readlines()
    T=int(lines[0])
    d=[0]*11
    for i in xrange(2,11):
        d[i]=happy(i,10**5)
    for i in xrange(1,T+1):
        bases=[int (l) for l in lines[i].rsplit(" ")];
        s=d[bases[0]]
        for b in bases:
            s=s.intersection(d[b])
        s=s.difference(set([1]))
        k=min(s)
        print "Case #" +str(i)+": "+str(k)
        outfile.write('Case #'+str(i)+': '+str(k)+'\n')
    f.close()
    outfile.close()
    
                      
   
if __name__ == "__main__":
    main()
          


            
                
            
        
    
            
