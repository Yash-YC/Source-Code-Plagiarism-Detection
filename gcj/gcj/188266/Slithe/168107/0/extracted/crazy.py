import sys
cachedBaseFails = {}

def crazySum(x, b):
	num = x % b
	num = num * num
	nextX = x / b
	if nextX==0:
		return num
	return num + crazySum(nextX, b)

def recursiveCrazy(x, b):
	num = x
	alreadySeen = {}
	while not (num==0 or num==1):
		if num in alreadySeen:
			return False
		else:
			alreadySeen[num] = True
		num = crazySum(num, b)
	if num==1:
		return True
	else:
		return False
	

if __name__ == "__main__":
	lines = sys.stdin.read().split("\n")
	
	numText = int(lines[0])
	
	i = 0
	for line in lines[1:]:
		if i >= numText:
			break
		i += 1
		
		bases = [int(x) for x in line.split(" ")]
		
		j = 2
		while True:
			isHappy = True
			for base in bases:
				if base in cachedBaseFails:
					if j in cachedBaseFails[base]:
						isHappy = False
						break
				else:
					cachedBaseFails[base] = {}
				if not recursiveCrazy(j, base):
					cachedBaseFails[base][j] = True
					isHappy = False
					break
			if isHappy:
				output = "Case #" + str(i) + ": " + str(j)
				print output
				break
			j += 1