def tobase(n, b):
    s = ""
    while n >= b:
        s = str(n % b) + s
        n /= b
    return str(n%b) + s

def next(n, b):
    s = tobase(n, b)
    return sum([int(c)**2 for c in s])
    

def conv(n, b):
    l = []
    while not n in l:
        l += [n]
        n = next(n, b)
    return n == 1


def resolve(bs):
    n = 2
    while True:
        valid = True
        for b in bs:
            if not conv(n, b):
                valid = False
                break
        if valid: return n
        n += 1

f = open("bases_in.txt")
data = f.read()
f.close()


data = data.split("\n")
t = int(data[0])
data = data[1:]

for i in xrange(t):
    A = data[i].split(" ")
    data[i] = [int(c) for c in A]

s = ""
for i in xrange(t):
    if i % 10 == 0:
        print float(i) / t * 100.0
    s += "Case #%d: %d" % (i+1, resolve(data[i])) + "\n"

print s

f = open("bases_out.txt", "w")
f.write(s)
f.close()
