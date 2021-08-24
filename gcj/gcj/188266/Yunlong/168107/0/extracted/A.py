#dynamic programming

pat = "welcome to code jam"
n = len(pat)

		
def squaresum(N, base):	
	m = 0
	n = N
	while n > 0:
		m += (n%base)**2
		n = int(n/base)
	#print m
	return m

def happy(N,base):
	visit = []
	visit.append(N)
	n = N
	while n>0:
		n = squaresum(n,base)
		if n in visit:
			return False
		visit.append(n)
		# print n
		if n==1:
			return True

def findhappy(bases):
	N = 2
	while True:
		bad = False
		for base in bases:
			if bad:
				break
			if not happy(N,base):
				bad = True
				break
		if not bad:
			return N
		N += 1
	


if __name__ == '__main__':
	INFILE = 'A-small-attempt0.in'
	IN = open(INFILE)
	LINE = IN.readline()
	DATA = LINE.split()
	T = int(DATA[0]) #number of tests
	for i in range(T):
		LINE = IN.readline()
		DATA = LINE.split()
		bases = []
		for data in DATA:
			bases.append(int(data))
		result = findhappy(bases)
		print 'Case #%d: %d'%(i+1, result)
