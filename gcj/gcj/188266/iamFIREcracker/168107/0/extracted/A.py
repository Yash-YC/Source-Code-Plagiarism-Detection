def ReadInts():
  return list(map(int, raw_input().strip().split(' ')))

def ChangeBase(n, b):
  target_num = []
  while n:
    n, d = divmod(n, b)
    target_num.append(str(d))
  return ''.join(reversed(target_num))

def IsHappy(n, b):
  s = ChangeBase(n, b)
  hystory = [s]
  for i in xrange(b**3):
    next = sum(int(c)**2 for c in s) 
    s = ChangeBase(next, b)
    if s in hystory: return False
    if s == '1': return True
    hystory.append(s)

def FindHappiness(T, base):
  n = 2
  while True:
    for b in base + [-1]:
      if b == 2: continue
      if (b, n) in memo and memo[(b, n)]: continue
      if (b, n) in memo and not memo[(b, n)]: break
      if b == -1:
        print 'Case #%d: %d' % (T, n)
        return
      if IsHappy(n, b):
        memo[(b, n)] = True
      else:
        memo[(b, n)] = False
        break
    n += 1

memo = {}
for T in xrange(1, input() + 1):
  FindHappiness(T, ReadInts())
