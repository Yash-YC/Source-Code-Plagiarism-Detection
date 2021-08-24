


def step(n, b):
    s = []
    while n > 0:
        s.append(n % b)
        n /= b

    n = 0
    for c in s:
        n += c ** 2

    return n

def calc(base):
    list = [set() for i in range(len(base))]
    i = 2
    while True:
        ret = True
        for k in range(len(base)):
            b = base[k]

            dup = set()
            n = i
            while n != 1:
                if n in dup:
                    ret = False
                    break
                dup.add(n)
                n = step(n, b)
            else:
                list[k] |= dup
            if not ret:
                break
        else:
            n = min(reduce(lambda a,b:a & b, list))
            break
        i += 1
    return n




Problem = 'A-small-attempt1.in'
#Problem = 'test.in'
Answer = Problem.replace('.in', '.out')
Case = 0

fin = open(Problem, 'r')
fout = open(Answer, 'w')

N = int(fin.readline()[:-1])

for Case in range(N):
    BASE = []
    for b in fin.readline()[:-1].split(' '):
        BASE.append(int(b))
    ret = calc(BASE)
    del BASE

    print "Case #%d: %s" % (Case + 1, str(ret))
    fout.write("Case #%d: %s\n" % (Case + 1, str(ret)))


