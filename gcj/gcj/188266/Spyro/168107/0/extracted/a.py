
def convert(n,base):
	final = ""
	if n == 0:
		final = "0"
	while n>0:
		final = str(n%base)+final
		n = n/base
	return int(final)

def happy(n,base):
	calc = []

	while True:
		n = str(n)
		a = 0
		#print n,base
		for d in n:
			tmp = convert(int(d)*int(d),base)
			a += int(str(tmp),base)
		a = convert(a,base)
		#print a
		if a in calc:
			break
		calc.append(a)
		n = a
	if int(a) == 1:
		return True
	return False

def test(j,bases):
	for i in bases:
		n = convert(j,i)
		if not happy(n,i):
			return False
	return True

t = int(raw_input())

for i in xrange(t):
	bases = [int(b) for b in raw_input().split()]
	j = 2
	while True:
		if test(j,bases):
			break
		j += 1
	print "Case #"+str(i+1)+":",j
