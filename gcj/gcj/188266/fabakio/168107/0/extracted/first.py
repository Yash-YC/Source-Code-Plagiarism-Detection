fp = open('input.in', 'r')
parms = [int(x) for x in fp.readline().split()]

def process(n, base):
    sum = 0
    while n > 0:
        sum = sum + ((n % base) * (n % base))
        n /= base
    return sum

def happy(n, base):
    already = []
    n = process(n, base)
    while n != 1:
        if n in already:
            return False
        already.append(n)
        n = process(n, base)
    return True

def happy_list(n, bases):
    for b in bases:
        if (not happy(n, b)):
            return False
    return True

if True:
    case = 1
    for x in range(parms[0]):
        bases = [int(x) for x in fp.readline().split()]
        
        n = 2
        while True:
            if happy_list(n, bases):
                print 'Case #' + str(case) + ': ' + str(n)
                break
            n += 1

        case += 1
