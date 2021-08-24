#dynamic programming

# def expect(C, N):
	# sum = 0
	# print 'Calculating',C,N
	# for i in range(1,C+1):
		# sum += 1.0/i
	# print sum
	# return sum*C/N

def gcd(a,b):
    while b:
        a,b=b,a%b
    return a

def binomial(n,k):
    if k > n/2:
        k=n-k
    return binom_h(n,k) # to avoid unnecessary deep recursion

def binom_h(n,k):
        if k==0: return 1
        else:
            g = gcd(n,k)
            return binomial(n-1,k-1)/(k/g)*(n/g)
	

class NODE:
	def __init__(self, s, w):
		self.s = s #stage
		self.w = w #weight
		

	def __cmp__(self, o):
		if type(o)!=NODE:
			return -1
		diff = self.a - o.a #compare alt
		if diff == 0:
			diff2 = self.h - o.h #compare row
			if diff2 == 0:
				return self.w - o.w #compare col
			else:
				return diff2
		else:
			return diff
			
def expect(C,N):
	node = NODE(N, 1)
	storage = [node]
	total = binomial(C,N)*1.0
	for i in range(N+1, C+1):
		node = NODE(i, 0)
		for j in range(1, N+1):
			if i-j>=N: #used (i-j), want to add j
				pb = binomial(C-i+j, j)*binomial(i-j, N-j)
				fract = binomial(i-j, N-j)*binomial(C-i+j, j)
				node.w += (storage[i-j-N].w+ total/pb)*(fract/total)
		storage.append(node)
	return storage[-1].w


if __name__ == '__main__':
	INFILE = 'C-small-attempt1.in'
	IN = open(INFILE)
	LINE = IN.readline()
	DATA = LINE.split()
	T = int(DATA[0]) #number of tests
	for i in range(T):
		LINE = IN.readline()
		DATA = LINE.split()
		C = int(DATA[0])
		N = int(DATA[1])
		res = expect(C,N)
		print 'Case #%d: %f'%(i+1, res)
