def baseN(num, b):
  return ((num == 0) and  "0" ) or ( baseN(num // b, b).lstrip("0") + "0123456789abcdefghijklmnopqrstuvwxyz"[num % b])

def happy(n, b):
  ishappy = 0
  buf = []
  while ishappy == 0:
    if n == 0:
      return 0
    if n == 1:
      ishappy = 1
      return 1
    sstr = baseN(n, b)
    total = 0
    for i in sstr:
      total += pow(int(i), 2)
    n = total
    if n in buf:
      return 0
    else:
      buf.append(n)
  return 0

#f = open('./a_pre.out', 'w')
#for i in range(2, 10):
#  for j in range(999999):
#    print str(happy(j, i))

f = open('./A-small-attempt0.in', 'r')
t = int(f.readline())
for i in range(t):
  bases_str = f.readline().split(' ')
  bases = []
  for j in range(len(bases_str)):
    bases.append(int(bases_str[j]))

  k = 2
  ishappy = 0
  while ishappy == 0:
    tmphappy = 0
    for j in range(len(bases)):
      if happy(k, bases[j]) == 1:
        tmphappy += 1
      else:
        break
    if tmphappy == len(bases):
      break
    else:
      k += 1

  print 'Case #' + str(i + 1) + ': ' + str(k)

