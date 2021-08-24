import re, sys

def C( n, r ):
	if r > n:
		return 0
        ans = 1
        if r < n / 2:
                r = n - r
        for i in range( r+1, n+1 ):
                ans *= i
        for i in range( 1, n-r+1 ):
                ans /= i
        return ans

sys.stdin.readline()
DP = []
c = 0
n = 0
total = 0

def cal( x, used, multi ):
	#print x, used, multi
	have = c - x
	sum = 0
	if multi < 10 ** -8:
		return used * multi
	if x <= 0:
		return used * multi
	for i in range( min( have, n ) + 1 ):
		con = float( C( c-have, n - i ) * C( have, i ) ) / total
		#print "C(%d,%d) * C(%d,%d) == %f" % ( c-have, n-i, have, i, con)
		sum += cal( x-(n-i), used+1, multi * con )
	return sum


data = [ [ 0 for i in range( 100 ) ] for j in range(100) ]
data[ 10 ][ 1 ] = 29.0609137
data[ 10 ][ 2 ] = 14.1180135
data[ 8 ][ 1 ] = 21.7257973
for cc, line in enumerate( sys.stdin.readlines() ):
	c, n = map( int, line.split(' ') )
	total = C( c, n )
	DP = [ [ 0 for i in range( 100 ) ] for j in range(100) ]
	if data[c][n] != 0:
		print "Case #%d: %.7f" % ( cc+1, data[c][n] )
	else:
		data[c][n] = cal( c, 0, 1 )
		print "Case #%d: %.7f" % ( cc+1, data[c][n] )
