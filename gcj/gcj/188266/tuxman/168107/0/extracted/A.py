import sys

HAPPYNESS = {}

def Potences(base, number):
  i = 1
  while i <= number:
    yield i
    i *= base


def TransformToBase(number, base):
  digits = []
  for p in reversed(list(Potences(base, number))):
    digit = number // p
    digits.append(digit)
    number -= digit * p

  return tuple(digits)


def IsHappy(number, base, visited):
  if number in visited:
    if number == (1,):
      return True
    else:
      return False

  str_number = int("".join(str(x) for x in number))
  if (str_number, base) in HAPPYNESS:
    return HAPPYNESS[str_number, base]

  summ = sum(x * x for x in number)
  new_number = TransformToBase(summ, base)
  result = IsHappy(new_number, base, visited + [number])
  HAPPYNESS[str_number, base] = result
  return result

T = int(sys.stdin.readline().strip())
for i in xrange(T):
  bases = [int(x) for x in sys.stdin.readline().strip().split()]

  j = 2
  while True:
    minimum = min(IsHappy(TransformToBase(j, base), base, []) for base in bases)
    if minimum:
      print "Case #%d: %d" % (i + 1, j)
      break
    j += 1
