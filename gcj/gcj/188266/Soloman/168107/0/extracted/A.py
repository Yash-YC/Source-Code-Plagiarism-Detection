def saveHappy(seq, V, base, happy):
    n = len(happy[base])
    for s in seq:
        if s < n:
            happy[base][s]=V

def isHappy(V, base, happy):
    if base == 2:
        return True
    
    v = V
    circle = set()
    circle.add(v)
    while True:
        if v < len(happy[base]) and happy[base][v] is not None:
            return happy[base][v]
        
        seq = []
        l = v // base
        s = v % base
        seq.append(s)
        while l>0:
            s=l%base
            l=l//base
            seq.append(s)
        v = sum([x**2 for x in seq])
        if v==1: # is happy
            saveHappy(circle, True, base, happy)
            return True
        elif v in circle: #unhappy
            saveHappy(circle, False, base, happy)            
            return False
        circle.add(v)


def solve(bases):
    k = 1000000
    happy = [[None for _ in range(10000)] for _ in range(11)]
    for i in range(2, k):
        ans = all([isHappy(i, b, happy) for b in bases])
        if ans:
            return i

#h = [[None for _ in range(100000)] for _ in range(10)]        
#print(all([isHappy(143, b, h) for b in [2,3,7]]))      
#print(solve([2,3, 7]))

#fin = open('test.txt')
fin = open('A-small-attempt0.in')
fout = open('out.txt', 'w')
N=int(fin.readline())
for i in range(1, N+1):
    bases = [int(s) for s in fin.readline().split()]
    ans = solve(bases)
    line = 'Case #%d: %d'%(i,ans)
    print(line)
    fout.write(line+'\n')
    
fin.close()
fout.close()
    
