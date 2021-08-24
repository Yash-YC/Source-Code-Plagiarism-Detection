def getDigitSquareSum(base, n):
	sum = 0
	while n > 0:
		sum += (n % base)**2
		n = n / base
	return sum

def isHappy(base, n):
	tempset = set()
	tempset.add(n)
	while True:
		n = getDigitSquareSum(base, n)
		if n == 1:
			return True
		elif n in tempset:
			return False
		else:
			tempset.add(n)

def getHappyNumberForAllBase(bases):
	baseCnt = len(bases)
	r = range(baseCnt)
	n = 2
	while True:
		happy = True
		for i in r:
			if not isHappy(bases[i], n):
				happy = False
				break
		if happy:
			return n
		n += 1

import sys

fileNamePrefix = sys.argv[1]
fileNameIn = fileNamePrefix + ".in"
fileNameOut = fileNamePrefix + ".out"

fileIn = open(fileNameIn, 'r')
lines = fileIn.readlines()
fileOut = open(fileNameOut, 'w')

testCnt = int(lines[0])
idx = 1

for test in range(testCnt):

	baseStrs = lines[idx].split(' ')
	idx += 1

	bases = []
	for i in range(len(baseStrs)):
		bases.append(int(baseStrs[i]))
	#print bases

	n = getHappyNumberForAllBase(bases)
	#print "Case #{0}: {1}\n".format(test + 1, n)
	fileOut.write("Case #{0}: {1}\n".format(test+1, n))
