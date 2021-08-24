t=input()
for i in xrange(1,t+1):
    tmp=raw_input()
    ans=[]
    ans.append(tmp[0])
    for j in xrange(1,len(tmp)):
        if tmp[j] >= ans[0]:
            ans.insert(0,tmp[j])
        else:
            ans.append(tmp[j])
    print 'Case #%d: %s'%(i,''.join(ans))
    


