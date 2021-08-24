import sys, os

filename = "A-large"

path = os.path.normpath(os.path.join(os.path.dirname(__file__), filename+".in"))
reader = open(path, "rb")
path = os.path.normpath(os.path.join(os.path.dirname(__file__), filename+".out"))
writer = open(path,"w")

path = os.path.normpath(os.path.join(os.path.dirname(__file__), "memo.out"))
writer2 = open(path,"w")

T = int(reader.readline().rstrip())

map = [None for i in range(11)]
memo = None
def checkMagic(num,base):
	c = num
	for i in range(100):
		if c==0:
			return False
		if c==1:
			return True
		nc = 0
		while c > 0:
			nc+=(c%base)**2
			c//=base
		c = nc
	return False

def initMap(bases):
	for base in bases:
		map[base] = [checkMagic(i,base) for i in range(2*base*base+10)]

def isMagic(num,base):
	c = num
	while True:
		if c<2*base*base:
			return map[base][c]
		nc = 0
		while c > 0:
			nc+=(c%base)**2
			c//=base
		c = nc

B = 8

ibases = [i for i in range(3,11)]
initMap(ibases)
memo = [-1 for i in range(1<<B)]

for memi in range(1,(1<<B)):
	print memi
	bases = []
	for i in range(8):
		if memi&(1<<i):
			bases.append(3+i)
	start = 2
	ci = (memi-1)&memi
	while ci:
		if memo[ci]>start:
			start = memo[ci]
		ci = (ci-1)&memi
	
	i = start
	while i<100000000:
		ism = True
		for b in bases:
			if not isMagic(i,b):
				ism = False
				break
		if ism:
			break
		i+=1
	
	if not ism:
		raise RuntimeException("not less than im")
	
	memo[memi] = i

for mval in range(len(memo)):
	writer2.write("%s %s\n" % (mval,memo[mval]))
writer2.close()

caseno = 1
while caseno<=T:
	memi = 0
	for x in reader.readline().rstrip().split(' '):
		if int(x)>2:
			memi|=(1<<(int(x)-3))
		
	
	writer.write("Case #%s: %s\n" % (str(caseno),memo[memi]))
	caseno+=1

writer.close()