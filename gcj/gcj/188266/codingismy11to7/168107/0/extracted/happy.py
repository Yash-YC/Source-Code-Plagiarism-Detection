
import sys

sys.setrecursionlimit(10000)

cache = {}

smallestcache = {}

def join(l):
	x = []
	for i in l:
		x.append(str(i))
	return ','.join(x)

def findSmallest(bases):
	i = 2
	bases = list(set(bases))
	if join(bases) in smallestcache:
		return smallestcache[join(bases)]
	if len(bases) == 2:
		while True:
			#print i
			if isHappy(i, bases[0],set()) and isHappy(i, bases[1], set()):
				#print '%s : %d' % (join(bases), i)
				smallestcache[join(bases)] = i
				return i
			i = i + 1
	else:
		i = findSmallest(bases[1:])
		while True:
			found = True
			for base in bases:
				if not isHappy(i, base,set()):
					found = False
					break
			if found:
				smallestcache[join(bases)] = i
				return i
			i = i + 1
		

def isHappy(num, base, tried):
	if base == 2: return True
	if base not in cache:
		cache[base] = {}
	if num in cache[base]:
		return cache[base][num]
	str = numToBase(num, base)
	if len(str) == 1:
		if str == '1':
			cache[base][num] = True
			return True
	t = 0
	for c in str:
		ci = int(c)
		t = t + (ci * ci)
	if t in tried:
		cache[base][num] = False
		return False
	try:
		tried.add(num)
		ret = isHappy(t, base, tried)
	except:
		#print 'num=%d, t=%d, base=%d' % (num, t, base)
		ret = False
	cache[base][num] = ret
	#print '%d,%s - %s' % (base, str, ret)
	return ret

def numToBase(num, base):
	ret = ''
	while num > 0:
		ret = str(num % base) + ret
		num = num / base
	return ret


def findSmallestS(nums):
	n = []
	for i in nums:
		n.append(int(i))
	return findSmallest(n)

def parseFile(fname):
	lines = open(fname).read().split('\n')
	count = int(lines[0])
	lines = lines[1:]
	for i in range(count):
		val = findSmallestS(lines[i].split(' '))
		print 'Case #%d: %d' % (i+1, val)

if __name__ == '__main__':
	parseFile(sys.argv[1])

