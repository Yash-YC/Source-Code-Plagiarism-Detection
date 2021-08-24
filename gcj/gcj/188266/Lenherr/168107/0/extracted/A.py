import sys

def SumOfDigits(base, x):
  res = 0
  while x > 0:
    digit = x % base
    x = (x - digit) / base
    res += digit * digit
  return res

def happy(base):
  x = 1
  while True:
    x += 1
    seen = set()
    next = x
    while True:
      next = SumOfDigits(base, next)
      if next in seen:
        break
      seen.add(next)
      if next == 1:
        yield x
        break

def Handle(bases):
  iters = [happy(base) for base in bases]
  elems = [iter.next() for iter in iters]
  min_elem = min(elems)
  max_elem = max(elems)
  while min_elem != max_elem:
    for (pos, iter) in enumerate(iters):
      while elems[pos] < max_elem:
        elems[pos] = iter.next()
    min_elem = min(elems)
    max_elem = max(elems)
  return min_elem
  
T = int(sys.stdin.readline().strip())

for i in xrange(0, T):
  bases = [int(x) for x in sys.stdin.readline().strip().split(" ")]
  num = Handle(bases)
  print "Case #%d: %d" % (i + 1, num)

