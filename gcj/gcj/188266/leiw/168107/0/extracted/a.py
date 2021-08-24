import sys

f = sys.stdin

n = int(f.readline())


def  baselist(i, b):
	ns = []
	while i:
		ns.append(i % b)
		i /= b
	ns.reverse()
	return ns

for n in range(1, n+1):
	bases = [int(s) for s in f.readline().split()]
	v = 2
	while True:
		f0 = True
		for b in bases:
			v1 = v
			flag = False
			known = set([v1])
			while True:
				ns = baselist(v1, b)
				v1 = 0
				for x in ns:
					v1 += x*x
				if v1 == 1:
					flag = True
					break
				elif v1 in known:
					break
				known.add(v1)
			if not flag:
				f0 = False
				break
		if f0:
			break
		v += 1

	print "Case #%s: %s" % (n, v)

