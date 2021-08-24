
def wf(fileName,ls):
    f = open(fileName,'w')
    for i,l in enumerate(ls):
        f.write('Case #%d: %d\n'%(i+1,l))

impossible = [[] for i in range(11)]
possible = [[] for i in range(11)]
def isHappyNumber(num,base):
    #print 'if ',num,base
    lsRoute = []
    s = 0
    while s!=1:
        s = 0
        lsRoute.append(num)
        while num>0:
            m = num%base
            s += m*m
            num = (num-m)/base
        #print s
        if s in impossible[base] or s in lsRoute:
            impossible[base].extend(lsRoute)
            #print 'false:',s
            return False
        if s in possible[base]:
            possible[base].extend(lsRoute)
            return True
        num = s
    possible[base].extend(lsRoute)
    return True

filename = 'Sample.in'
filename = 'A-small-attempt0.in'
#filename = 'Large.in'
f = open(filename)
contents = f.readlines()
s =contents[0].strip()
n = int(s)
print n
lsResult = []
for i in range(1,len(contents)):
    print i,'\t:',contents[i]
    nums = contents[i].strip().split()
    nums = [int(x.strip()) for x in nums]
    #print nums
    happy = 2
    while True:
        allHappy = True
        for x in nums:
            if isHappyNumber(happy,x):
                pass
            else:
                happy += 1
                allHappy = False
                break
        if allHappy:
            lsResult.append(happy)
            break
        
                    
    #lsResult.append(len([l for l in ls if l]))
    
    #print '\n\n\n\n'
    

#print lsResult

'''
for i  in impossible:
    print i
for i in possible:
    print i
'''
    
wf(filename.split('.')[0]+'.out',lsResult)