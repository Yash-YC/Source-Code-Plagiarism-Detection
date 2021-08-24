
import sys
from sets import Set

def readstr():
	return sys.stdin.readline().strip()

def readint():
	return int(readstr())

def tolist( stri, delim='' ):
	if delim == '':
		return stri.split()
	else:
		return stri.split( delim )

def readlist( delim='' ): return tolist( readstr(), delim )

def evallist( l, f ):
	v = []
	for i in l:
		v.append( f(i) )
	return v

def readevallist( f, delim='' ):
	return evallist( readlist(delim), f )

def readints( delim='' ): return readevallist( int, delim )

def str_base( n, b ):
	s = ''
	while n > 0:
		s = str(n % b) + s
		n /= b
	return s

def transf( n, b ):
	p = 0
	s = str_base( n, b )
	for d in s:
		p += int(d)*int(d)
	 #print n,"_",b,"=",s,"->",p
	return p

N = readint()

for i in range(N):
	
	C = readints()

	tested = []
	happy = []
	indices = []

	for ci in xrange(len(C)):
		tested.append(Set([]))
		happy.append(Set([]))
		indices.append(len(C)-ci-1)

	n = 2
	num_tests = [0]*len(C)

	while True:
		hg = True

		for cii in xrange(len(C)):
			ci = indices[cii]
			t = n
			path = Set([])
			h = False
			while True:
				#num_tests[ci] += 1
				if (t in happy[ci] or t==1):
					h = True
					break
				if (t in tested[ci] or t in path):
					break

				path.add(t)
				t = transf(t, C[ci])

			if h:
				for p in path:
					happy[ci].add(p)
			else: 
				for p in path:
					tested[ci].add(p)

				hg = False
				break

		if hg:
			break

		if (n % 100) == 0:
			for cii in xrange(len(C)):
				for cij in xrange(cii+1,len(C)):
					if num_tests[indices[cii]] < num_tests[indices[cij]]:
						swap( indices[cii], indices[cij] )

		n += 1

	print "Case #"+str(i+1)+": "+str(n)

