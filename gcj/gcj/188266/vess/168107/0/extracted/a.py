import sys

def strbase(val, base):
    val_digits = []
    while val:
        val, digit = divmod(val, base)
        val_digits.append(digit)
    return [x for x in reversed(val_digits)]


def happy_a(a, base, checked):
    if a in checked:
        return False
    checked.append(a)
    tot = sum([x * x for x in a])
    if (len(a) == 1) and (tot < base):
        return tot == 1
    return happy_a(strbase(tot, base), base, checked)

def happy(i, base, cache):
    kb = cache[base]
    while len(kb) <= i:
        kb.append(None)
    if kb[i] is None:
        a = strbase(i, base)
        result = happy_a(a, base, [])
        kb[i] = result
        return result
    else:
        return kb[i]

def process(bases, cache):
    i = 1
    while True:
        done = True
        i += 1
        for base in bases:
            if not happy(i, base, cache):
                done = False
                break
        if done:
            break
    return i

lines = sys.stdin.readlines()
#lines = """1
#7 8 10""".split("\n")

cache = [[],[],[],[],[],[],[],[],[],[],[]]

case_no = 0
for l in lines[1:]:
    case_no += 1
    bases = [int(x) for x in l.split(' ')]
    print "Case #%d: %d" % (case_no, process(bases, cache))