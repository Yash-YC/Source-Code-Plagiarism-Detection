import sys
import string

def readInts():
    return list(map(int, sys.stdin.readline().strip().split(" ")))


def convDecToBase(num, base, dd=False):
    if not 2 <= base <= 36:
        raise ValueError, 'The base number must be between 2 and 36.'
    if not dd:
        dd = dict(zip(range(36), list(string.digits+string.ascii_lowercase)))
    if num == 0: return ''
    num, rem = divmod(num, base)
    return convDecToBase(num, base, dd)+dd[rem]


mm={}
cycle=set()

def happy(n, base):
    cycle.add(n)

    if (n,base) in mm:
        return mm[(n,base)]

    nn = convDecToBase(n, base)


    res = 0
    for ch in nn:
        res += int(ch)**2


    if n==res or res in cycle:
        mm[(n,base)] = False
        return False

    if res==1:
        mm[(n,base)] = True
        return True

    b = happy(res, base)
    mm[(res,base)] = b
    return b

T = readInts()[0]
for case in xrange(1,T+1):
    bases = readInts()

    n = 2
    while True:
        flag = True
        for base in bases:
            cycle=set()
            if happy(n, base) == False:
                flag = False
                break

        if flag == True:
            print 'Case #%d: %d' % (case, n)
            break

        n = n+1
