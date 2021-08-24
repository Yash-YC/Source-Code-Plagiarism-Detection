from math import sqrt, floor


T = int(raw_input (""))

def toBase (number, base):
    exp = base
    while exp <= number:
        exp = exp * base
    exp = exp / base
    result = ""
    nums = "0123456789"
    while exp != 0:
        c = number / exp
        result = result + nums[c]
        number = number % exp
        exp = exp / base
    return int (result)

def happy (number, first, cnt, base):
    used = set()
    while True:
        s = sorted(str(number))
        l = ""
        for j in s:
            l = l + j
        s = l
        if s in used:
            return False
        used.add (s)
        if number == 1:
            return True
        if number == first and cnt != 0:
            return False
        cnt = cnt + 1
        suma = 0
        for x in str(number):
            x = int (x)
            suma = suma + x*x
        number = toBase (suma, base)


cuenta = 0
for i in range(1,T+1):
    linea = [int(x)  for x in raw_input ("").split(' ')]
    result = 2
    while True:
        es = True
        for i in linea:
            if not happy(toBase(result,i), toBase(result,i), 0, i):
                es = False
                break
        if es:
            break
        result = result + 1
    cuenta = cuenta + 1
    print "Case #%d: %d" % (cuenta, result)
