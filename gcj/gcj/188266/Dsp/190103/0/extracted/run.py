import sys

def calc(C, N):
	n=1
	rest = C-N
	while 1:
		if rest<N:
			try:
				n+= float(C)/(N*float(rest))
			except:
				pass
			return n
		else:
			n += float(C)/float(rest)
			rest -= N
		

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
		line = f.readline()
		sp = line.split(' ')
		C = int(sp[0])
		N = int(sp[1])
		print '[',C, N,']'
		
		res = calc(C,N)
		print res

		fout.write( "Case #%d: %f\n"%(t+1,res) )
	f.close()
	fout.close()