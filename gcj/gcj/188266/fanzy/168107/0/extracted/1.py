import sys

data = [{} for i in range(11)]

def func(n,base):
    s = 0
    while n > 0:
        m = n % base
        n = int(n / base)
        s += pow(m,2)
    return s

def happynum(n, base):
    if n in data[base]:
        return data[base][n]
    rec = set()
    while True:
        s = func(n, base)
        if s == 1:
            data[base][n] = True
            return True
        elif s not in rec:
            rec.add(s)
            n = s
        else:
            data[base][n] = False
            return False

def find(start, base):
    num = start
    while True:
        if happynum(num,base):
            return num
        else:
            num += 1

def testcase(bases):
    num = 2
    rec = {}
    for base in bases:
        rec[base] = find(num, base)
    while True:
        maxnum = max(rec.values())
        if maxnum == min(rec.values()):
            return maxnum
        else:
            for base, h in rec.items():
                if h < maxnum:
                    rec[base] = find(maxnum, base)
                    
            
            
                

f = open(sys.argv[1])
T = int(f.readline())

for tc in range(1,T+1):
    bases = [int(i) for i in f.readline().split()]
    print("Case #%d: %d" % (tc, testcase(bases)))
