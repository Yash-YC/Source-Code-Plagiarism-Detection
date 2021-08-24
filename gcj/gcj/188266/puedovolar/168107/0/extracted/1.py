def cambio(n,b):
	res = ""
	if n==0:
		return 0
	while n > 0:
		res = str(n%b) + res
		n = n/b
	return res

def isHappy(n,bases):
	for b in bases:
		leave = False
		l = []
		sum = n
		while(not leave):
			nEnB = cambio(sum,b)
			sum = 0
			for c in nEnB:
				sum += int(c)**2
			if sum==1:
				leave = True
			elif sum in l:
				return False;
			else:
				l.append(sum)
	return n;

f = open("A-small-attempt0.in",'r')
f_out = open("out",'w')
f.readline()
case = 1
for line in f:
	bl = map(int,line.split())
	x=2
	if bl:
		while True:
			res = isHappy(x,bl)
			if res:
				f_out.write("Case #" + str(case) + ": " + str(res) + "\n")
				break
			x+=1
	case+=1
