import psyco
psyco.full()

lines = open("A-small-attempt0.in").read().split("\n")
#print lines

t = int(lines[0])

h = {}
for i in xrange(2,11):
    h[i]={}

def compute(n, b):
    s = 0
    k = n
    while k>0:
        k, c = divmod(k,b)
        s+= c*c
    return s

def isHappy(n,b):
    global h
    if h[b].has_key(n):
        return h[b][n]
    else:
        k = n
        d = {}
        while not h[b].has_key(k) and not d.has_key(k) and k>1:
            d[k] = None
            k = compute(k, b)
            #print k
        ret = k==1 or h[b].has_key(k) and h[b][k]
        for x in d.keys():
            h[b][x] = ret
        return h[b][n]

canRun = True
output = []
if canRun:
   for q in xrange(1, t+1):
      bases = [int(x) for x in lines[q].split()]
      isTotalHappy = False
      k = 1
      while not isTotalHappy:
          k+=1
          hArray = [isHappy(k,b) for b in bases]
          isTotalHappy = reduce(lambda x,y: x and y, hArray)
          #print k, hArray
      #print k,bases
      output.append("Case #"+str(q)+": "+str(k))

open("result.txt","w").write("\n".join(output))
