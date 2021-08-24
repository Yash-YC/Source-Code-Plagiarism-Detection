import time
import pprint

filename = "test"
filename = "A-small-attempt0"
#filename = "A-large"

pp = pprint.PrettyPrinter(indent=4)
def make_it_num( v ):
	for n in range( len(v) ) :
		v[n] = int( v[n] )

def next( n, base ):
	ret = 0
	while n > 0 :
		ret += (n%base)*(n%base)
		n = int(n/base)
	return ret
	
def solve( v ) :
	global pp
	make_it_num(v)
	l = len(v)
	max_v = max(v)
	
	bad = [0 for x in range( 100000 )]
	bad[0] = 1
	bad[1] = 1
	c = 0	
	n = 0
	while 1 :
		n=n+1
		for t in v :
			if bad[n] != 0 : 
				continue
			test = []
			x=n
			while x != 1 :
				if test.count(x) > 0 :
					break
				test.append(x)
				c = c+1
				x = next(x,t)
				
			if x != 1 :
				for y in test :
					bad[y] = 1
			else :
				if t == v[-1] :
					return n
				
	return 0
	

	
ps_time = time.time()

in_file = open("./"+filename+".in")
out_file = open("./"+filename+".out","w")

#getting data
T = int(in_file.readline().strip())

for t in range( 1, T+1 ) :	
	v1 = in_file.readline().strip().split(' ')
	
	#solving a problem
	out =  'Case #' + str(t)
	out += ': ' + str( solve(v1) ) + '\n'
	out_file.write( out )
	print (out)

in_file.close()
out_file.close()

ps_time = time.time() - ps_time
print (ps_time)