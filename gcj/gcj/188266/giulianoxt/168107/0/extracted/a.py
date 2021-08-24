T = input() 
mem = {}

def to_base(b, n):
  if (n == 0): return 0
  
  i, x, f = 0, 0, 1
  while n:
    x += (n % b) * f
    n /= b
    f *= 10
  
  return x
  
def is_happy(b, n, c):
  if (b,n) in mem:
    return mem[(b,n)]
    
  if (n == 1):
    mem[(b,n)] = True
    return True
    
  if (n in c):
    mem[(b,n)] = False
    return False
  
  c.add(n)
  s = 0
  while n:
    d = n % 10
    s += d * d
    n /= 10
  
  s = to_base(b, s)
  
  res = is_happy(b,s,c)
  mem[(b,n)] = res
  return res
  
for t in xrange(1, T+1):
  bases = map(int, raw_input().split())
  i = 1
  
  while True:
    i += 1
    
    ok = True
    for b in bases:
      if (is_happy(b, to_base(b, i), set())): continue
      ok = False
      break
    
    if (ok): break
  
  print 'Case #%d: %d' % (t, i)
  