import psyco
psyco.full()
#import pdb

def getint():
  return int(f.readline().strip())

def getstr():
  return f.readline().strip()

def getarr():
  s=f.readline().strip().split()
  for i in range(len(s)):
    s[i]=int(s[i])
  return s

def getwords():
  return f.readline().strip().split()

def convbase(n,b):
  div=1
  while int(n/div)>=b:
    div=div*b
  res=[]
  while n>0:
    tmp=int(n/div)
    n=n-div*tmp
    div=div/b
    if tmp>0:
      res.append(tmp)
  return res

def checkhappy(n,b,maxnum):
  tmp=[]
  cur=convbase(n,b)
  num=0 
  #pdb.set_trace()
  while not num in tmp:
    if num !=0:
      tmp.append(num)
    num=0
    for i in range(len(cur)):
      num+=cur[i]**2
    cur=convbase(num,b)
    if len(cur)==1 and cur[0]==1:
      return 1
    
  return 0

f=open('A-small-attempt0.in','r')
fo=open('A-small-attemp0.out','w')

ncases=getint()

for i in range(ncases):
  bases=getarr()
  bases.sort()
  bases.reverse()
  num=2
  nogood=1
  maxnums=[0]*len(bases)
  for j in range(len(bases)):
    maxnums[j]=bases[j]**3
    #print 'max:'+str(maxnums[j])
  
  while nogood:
    #pdb.set_trace()
    hap=0
    for j in range(len(bases)):
      if bases[j]==2 or bases[j]==4:
        hap+=1
        continue
      if checkhappy(num,bases[j],maxnums[j])==0:
        break
      else:
        hap+=1
    if hap==len(bases):
      break
    num+=1
  
  fo.write('Case #%d: %d\n'% (i+1,num))
    
  
f.close()
fo.close()
