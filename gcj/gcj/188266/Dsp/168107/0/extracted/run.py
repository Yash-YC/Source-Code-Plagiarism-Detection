import sys, math

def check(base, num):
	#convert to the right base
	digit = int( math.log(num,base) )
	res = []
	inp = num
	for n in range(digit,-1,-1):
		t = inp / pow(base,n)
		res.append( int(t) )
		inp -= t*pow(base,n)
	
	#print res
	#calc
	hp = 0
	for r in res:
		hp += r*r
	return hp

def isHappy(base, num):
	results = []
	while 1:
		res = check(base,num)
		#print res
		if res==1: return True
		if results.count(res)<1:
			results.append( res)
		else:
			return False
		num = res

print check(2,3)
print isHappy(2,3)

if __name__=="__main__":
	if len(sys.argv)>1:
		inp = sys.argv[1]
	else:
		print "append an input file param"
		sys.exit()

	f = open( inp, 'rt' )
	nTC = int( f.readline() )
	print 'the number of tc :', nTC

	output_file = inp.split('.')[0]+"_output.txt"
	fout = open( output_file, 'wt')

	for t in range(0, nTC):
		print 'Case #%d'%(t+1)
		inp = f.readline()
		bases = []
		for i in inp.split(' '):
			bases.append( int(i))
			
		print bases
		num = 2
		while 1:
			bHappy = isHappy(bases[0],num)
			#print bases[0], num, bHappy
			if bHappy:
				n=1
				for i,b in enumerate(bases):
					if i==0: 
						continue
					if isHappy(b,num): n+=1
				if n==len(bases):
					break
			num+=1
		print num
		fout.write( "Case #%d: %d\n"%(t+1,num) )
	f.close()
	fout.close()