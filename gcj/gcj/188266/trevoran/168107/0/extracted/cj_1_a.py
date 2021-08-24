# Code Jam Round 1
# 11/9/2009

def expand(number, base):
    i = 0
    while number >= 1:
        i += (number % base)*(number % base)
        number /= base
    return i

def happy_backtrack(is_happy, comes_from, i):
    is_happy.add(i)
    if i in comes_from:
        for j in comes_from[i]:
            happy_backtrack(is_happy, comes_from, j)

def make_happy_spansions():
    comes_from = {}
    is_happy = {}

    for base in range(2, 11):
        comes_from[base] = {}
        for i in range(2, 1000):
            comes_from[base][i] = set()
        is_happy[base] = set([1])

    for i in range(2, 1000):
        for base in range(2, 11):
            exp = expand(i, base)            
            if exp == 1:
                is_happy[base].add(i)
            else:
                comes_from[base][exp].add(i)
                
    for base in range(2, 11):
        for i in set(is_happy[base]):
            happy_backtrack(is_happy[base], comes_from[base], i)        
                
    return is_happy

def fmb2(bases):
    if len(bases) == 9:
        return 11814485 # precomputed, otherwise takes long enough to annoy me    
    is_happy = make_happy_spansions()
    done = False
    minn = 2
    upto = {}
    i = 1
    for b in bases:
        upto[b] = 2
        while not expand(upto[b], b) in is_happy[b]:
            upto[b] += 1
    while not done:
        max_v = 0
        done = True
        for b in bases:            
            while upto[b] < minn:
                upto[b] += 1
                while not expand(upto[b], b) in is_happy[b]:
#                    print((b, expand(upto[b], b), upto[b]))
                    upto[b] += 1
            max_v = max(max_v, upto[b])
            if upto[b] != minn:
                done = False
        minn = max_v
#        i += 1
#        if (i % 100 == 0):
#            print(minn)
#        print(minn)
    return minn

inname = 'E:\A.in.txt'

fin = open(inname, 'r')
fout = open('E:\A.out.txt', 'w')

lines = fin.readlines()
count = int(lines[0].strip())
ints = [0]
for l in lines[1:]:
    split = l.split()
    ints.append([int(x) for x in split])
    
for i in range(1, count + 1):
    f = fmb2(ints[i])
    fout.write('Case #' + str(i) + ': ' + str(fmb2(ints[i])) + '\n')
    print(ints[i], f)

fout.close()
fin.close()   
    
