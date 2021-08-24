import sys, os

filename = "A-small-attempt0"

path = os.path.normpath(os.path.join(os.path.dirname(__file__), filename+".in"))
reader = open(path, "rb")
path = os.path.normpath(os.path.join(os.path.dirname(__file__), filename+".out"))
writer = open(path,"w")

T = int(reader.readline().rstrip())

map = [None for i in range(11)]

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
	

caseno = 1
while caseno<=T:
	bases = sorted([int(x) for x in reader.readline().rstrip().split(' ')])
	initMap(bases)
	
	i = 2
	while i<1000000:
		ism = True
		for b in bases:
			if b==2:
				continue
			if not isMagic(i,b):
				ism = False
				break
		if ism:
			break
		i+=1
	
	if not ism:
		raise RuntimeException("not less than im")	
	
	writer.write("Case #%s: %s\n" % (str(caseno),i))
	caseno+=1

writer.close()