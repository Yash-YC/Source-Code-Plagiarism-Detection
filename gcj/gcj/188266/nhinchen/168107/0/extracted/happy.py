def read_file(filename):
    fp = open(filename)
    lines = fp.readlines()
    return lines

def find_happy(filename):
    s = ""
    lines = read_file(filename)
    n = int(lines[0])
    for x in range(n):
        bases = lines[x+1].split()
        for r in range(len(bases)):
            bases[r] = int(bases[r])
        h = minhappy(bases)
        s = s + "Case #" + str(x+1) + ": " + str(h) + "\n"
    print s
    return s

def minhappy(bases):
    test_val = 1
    happy = False
    while not happy:
        test_val = test_val + 1
        happy = True
        for b in bases:
           # print [test_val, b]
            if not is_happy(test_val,b):
                happy = False
    return test_val

def is_happy(num, base):
    calls = 0
    while calls < 100:
        d = digits(num, base)
        num = sumsq(d)
        calls = calls + 1
        if num == 1:
            return True
    return False
        
def sumsq(l):
    t = 0
    for x in l:
        t = t + x*x
    return t

def digits(num, base):
    if num < base:
        return [num]
    else:
        rem = num % base
        q = (num - rem) / base
        d = digits(q, base)
        d.extend([rem])
        return d




def run(filename):
    a = open("output.txt","w")
    a.write(find_happy(filename))

run("A-small-attempt1.txt")
